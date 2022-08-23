### 1
最简单的方法，暴力法：
```c++
unsigned long long ReverseBits(unsigned long long x) {
  short size = sizeof(x) * 8;
  unsigned long long ret = 0;
  for (int i = 0; i < size; i++) {
    ret <<= 1;
    ret ^= (x & 1);
    x >>= 1;
  }
  return ret;
}
```
其实也不用非要遍历64次，也可以遍历32次，每次交换对应的高低两位，换位操作可参考[swap_bits](./swap_bits)。

<br>

### 2
另外一种方法就是lookup table的方法，思路很简单的，就是看愿意用多少的空间来换时间而已。
```c++
unsigned long long precomputed_reverse_bits[] = {
  0b0000, // 0b0000
  0b1000, // 0b0001
  0b0100, // 0b0010
  0b1100, // 0b0011
  0b0010, // 0b0100
  0b1010, // 0b0101
  0b0110, // 0b0110
  0b1110, // 0b0111
  0b0001, // 0b1000
  0b1001, // 0b1001
  0b0101, // 0b1010
  0b1101, // 0b1011
  0b0011, // 0b1100
  0b1011, // 0b1101
  0b0111, // 0b1110
  0b1111, // 0b1111
};

unsigned long long divide_and_conquer_helper(unsigned long long x, short bits_len) {
  if (bits_len == 4) {
    return precomputed_reverse_bits[x & 0xf]; // use lookup table to find the result
  }

  short half_bits_len = bits_len >> 1;
  unsigned long long reverse_high = divide_and_conquer_helper(x >> half_bits_len, half_bits_len);
  unsigned long long reverse_low = divide_and_conquer_helper(x, half_bits_len);

  return reverse_low << half_bits_len | reverse_high;
}

unsigned long long ReverseBits(unsigned long long x) {
  return divide_and_conquer_helper(x, 64);
}
```
时间复杂度和空间复杂度取决于lookup table的大小。