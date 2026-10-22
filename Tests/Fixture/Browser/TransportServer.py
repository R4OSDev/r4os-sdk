"""Local deterministic counterpart for the original SDK HTTP/job consumers.
Run only for a bounded test; work/logs belong to its temporary directory.
No external site, credentials, production data or browser environment.
"""
import argparse
import http.server
import json
from pathlib import Path
import socket
import threading
import time

PAYLOAD = bytes((i * 17 + 3) & 255 for i in range(200000))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--work", type=Path, required=True)
    parser.add_argument("--port", type=int, default=18163)
    args = parser.parse_args()
    args.work.mkdir(parents=True, exist_ok=True)
    lock = threading.Lock()

    def record(value):
        with lock, (args.work / "requests.jsonl").open("a", encoding="utf-8") as f:
            f.write(json.dumps(value) + "\n")

    class Handler(http.server.BaseHTTPRequestHandler):
        protocol_version = "HTTP/1.1"

        def log_message(self, *_args):
            pass

        def handle(self):
            self.connection.settimeout(8)
            # A controlled TLS failure exercises the original alert mapping;
            # this is deliberately not a certificate/handshake implementation.
            if self.connection.recv(1, socket.MSG_PEEK) == b"\x16":
                self.connection.recv(65536)
                self.connection.sendall(b"\x15\x03\x03\x00\x02\x02\x46")
                record({"kind": "tls_alert_protocol_version"})
                return
            try:
                super().handle()
            except (BrokenPipeError, ConnectionResetError, TimeoutError):
                pass

        def reply(self, status, body=b"", **headers):
            self.send_response(status)
            self.send_header("Content-Length", str(len(body)))
            for key, value in headers.items():
                self.send_header(key.replace("_", "-"), value)
            self.end_headers()
            self.wfile.write(body)
            self.wfile.flush()

        def do_GET(self):
            record({"method": self.command, "path": self.path,
                    "range": self.headers.get("Range"),
                    "cookie": self.headers.get("Cookie")})
            path = self.path.split("?", 1)[0]
            if path == "/redirect":
                self.reply(302, Location="/chunk")
            elif path == "/redirect-blocked":
                self.reply(302, Location="/forbidden")
            elif path == "/chunk":
                self.wfile.write(b"HTTP/1.1 100 Continue\r\n\r\n")
                self.send_response(200)
                self.send_header("Transfer-Encoding", "chunked")
                self.send_header("Content-Type", "text/plain")
                self.end_headers()
                for piece in (b"3\r\na", b"bc\r\n3\r\n", b"DEF\r\n0\r\n", b"\r\n"):
                    self.wfile.write(piece)
                    self.wfile.flush()
                    time.sleep(0.005)
            elif path == "/cookie":
                self.reply(200, self.headers.get("Cookie", "").encode(),
                           Set_Cookie="token=two; Path=/; HttpOnly")
            elif path == "/truncated":
                self.send_response(200)
                self.send_header("Content-Length", "9")
                self.send_header("Connection", "close")
                self.end_headers()
                self.wfile.write(b"abc")
                self.wfile.flush()
                self.close_connection = True
            elif path == "/stall":
                time.sleep(0.75)
                self.reply(200, b"late")
            elif path in ("/range", "/range-cut"):
                start = 0
                requested = self.headers.get("Range")
                if requested:
                    if not requested.startswith("bytes=") or not requested.endswith("-"):
                        self.reply(400)
                        return
                    start = int(requested[6:-1])
                body = PAYLOAD[start:]
                self.send_response(206 if requested else 200)
                self.send_header("Content-Length", str(len(body)))
                if requested:
                    self.send_header("Content-Range", f"bytes {start}-{len(PAYLOAD)-1}/{len(PAYLOAD)}")
                self.end_headers()
                if path == "/range-cut" and not requested:
                    body = body[:50000]
                    self.close_connection = True
                for offset in range(0, len(body), 4096):
                    self.wfile.write(body[offset:offset+4096])
                    self.wfile.flush()
            else:
                self.reply(200, b"transport-body", Cache_Control="max-age=60")

    server = http.server.ThreadingHTTPServer(("127.0.0.1", args.port), Handler)
    (args.work / "ready.json").write_text(json.dumps({"port": server.server_port}), encoding="utf-8")
    try:
        server.serve_forever(poll_interval=0.1)
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
