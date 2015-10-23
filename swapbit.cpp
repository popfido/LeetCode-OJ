public void swapNumber(int m) {
    return ((m & 0x55555555) << 1) | ((m & 0xaaaaaaaa) >> 1);
}