#[path = "../../Rust/src/memory.rs"]
mod memory;

#[test]
fn copy_fill_and_compare_keep_guards_and_unsigned_byte_order() {
    let input = [0x80u8, 0xff, 2, 4, 9];
    let mut output = [0x5au8; 9];
    unsafe {
        memory::memcpy(output.as_mut_ptr().add(2).cast(), input.as_ptr().cast(), 5);
    }
    assert_eq!(&output[..2], &[0x5a; 2]);
    assert_eq!(&output[2..7], &input);
    assert_eq!(&output[7..], &[0x5a; 2]);
    unsafe {
        memory::memset(output.as_mut_ptr().add(2).cast(), 0x1ee, 5);
    }
    assert_eq!(&output[2..7], &[0xee; 5]);
    assert_eq!(output[1], 0x5a);
    assert_eq!(output[7], 0x5a);
    unsafe {
        assert_eq!(
            memory::memcmp(input.as_ptr().cast(), input.as_ptr().cast(), 5),
            0
        );
        assert!(memory::memcmp([0xffu8].as_ptr().cast(), [0x80u8].as_ptr().cast(), 1) > 0);
        assert!(memory::bcmp([1u8].as_ptr().cast(), [2u8].as_ptr().cast(), 1) < 0);
    }
}

#[test]
fn overlapping_moves_both_directions_and_empty_ranges() {
    let mut right = *b"0123456789";
    unsafe {
        memory::memmove(right.as_mut_ptr().add(2).cast(), right.as_ptr().cast(), 6);
    }
    assert_eq!(&right, b"0101234589");
    let mut left = *b"0123456789";
    unsafe {
        memory::memmove(left.as_mut_ptr().cast(), left.as_ptr().add(2).cast(), 6);
    }
    assert_eq!(&left, b"2345676789");
    unsafe {
        memory::memmove(left.as_mut_ptr().cast(), left.as_ptr().cast(), 10);
        memory::memcpy(left.as_mut_ptr().cast(), right.as_ptr().cast(), 0);
        memory::memset(left.as_mut_ptr().cast(), 0, 0);
        assert_eq!(
            memory::memcmp(left.as_ptr().cast(), right.as_ptr().cast(), 0),
            0
        );
    }
    assert_eq!(&left, b"2345676789");
}
