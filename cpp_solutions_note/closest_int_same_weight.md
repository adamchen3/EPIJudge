### 1
该问题如果使用暴力法解决的话，思路就是从最接近x的整数开始遍历（如，x-1, x+1, x-2,x+2,...），直到找到相同weight的整数为止。

感觉这是一道规律题，当发现规律之后就特别好解决，我自己的解法就是，从最低有效位开始，如果发现相邻的两个有效位不一样，然后就交换这两个有效即可。
```c++
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  if (x == 0 || x == 0xffffffff) {
    return 0;
  }

  short bit_pos = 0;
  auto lower_bit = 0ull;
  auto higher_bit = 0ull;
  do {
    lower_bit = x & (1ull << bit_pos);
    higher_bit = x & (1ull << (bit_pos + 1));
    bit_pos++;
  } while ((lower_bit << 1) == higher_bit);
 
  // swap bits
  x ^= (1ull << (bit_pos - 1));
  x ^= (1ull << bit_pos);
  return x;
}
```
书上的解法也是这个方法，而且书上还有推导过程，书上的解法代码如下：
```c++
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  const static int kNumUnsignedBits = 64;
  for (int i = 0; i < kNumUnsignedBits - 1; ++i) {
    if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
      x ^= (1UL << i) | (1UL << (i + 1));  // Swaps bit-i and bit-(i + 1).
      return x;
    }
  }
```
时间复杂度：$O(n)$，$n$是输入的字长。

空间复杂度：$O(1)$

 <br>

 ### 2
 时间和空间复杂度为$O(1)$的解法？？？