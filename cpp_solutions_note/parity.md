### 1
参考[count_bits](count_bits.md/#1)的做法，可直接暴力法解决。先计算出有多少个1，如果是奇数个1则返回1，偶数个1则返回0，而判断一个整数的奇偶性，只需要判断整数的二进制形式的第一位数就可以，第一位是1就是奇数，是0就是偶数：
```c++
short Parity(unsigned long long x) {
  int bits_num = 0;
  while (x) {
    bits_num += x & 1;
    x >>= 1;
  }
  return bits_num & 1; // 第一位是1就是odd，是0就是even
```
最坏时间复杂度：$O(n)$，$n$为unsigned long long的位数。比如x=0b1111...111（全是1）。

最好时间复杂度：$O(1)$，比如x=0

空间复杂度：$O(1)$

<br>

### 2
还可以使用分治法来解决，思路很简单，就是将整数分成两部分（比如左右），分别各自计算左右部分的parity，然后将左右部分的结果再进行一次异或运算就可以得出最终的结果。然后，左右部分可以继续分而治之：
```c++
short divide_and_conquer_helper(unsigned long long x, int bits_len) {
  if (bits_len == 1) {
    return x & 1;
  }

  int half_bits_len = bits_len >> 1;
  int left_parity = divide_and_conquer_helper(x >> (half_bits_len), half_bits_len);
  int right_parity = divide_and_conquer_helper(x, half_bits_len);
  return left_parity ^ right_parity;
}

short Parity(unsigned long long x) {
  return divide_and_conquer_helper(x, 64);
}
```
时间复杂度分析主要看divide_and_conquer_helper的调用次数吧。当bits_len=1时，调用1次；当bits_len=2时，分两次bits_len=1来处理，调用了2\*1=2次；当bits_len=4时，分两次bits_len=2来处理，调用了2\*2\*1=4次；当bits_len=8时，分两次bits_len=4来处理，调用了2\*2\*2\*1=8次；...；以此类推，当bits_len=n时，分两次bits_len = n/2次来处理，调用了$\underbrace{2*2*2*...*2}_{log_2(n)} = 2 ^ {log_2(n)} = n$次。

所以，最好最坏的时间复杂度都是$O(n)$，$n$是unsigned long long的字长。

空间复杂度：$O(log_2n)$，$n$是unsigned long long的字长。因为每层递归是$O(1)$，共$log_2n$层？

这么看来，分治法的平均性能应该还没暴力法好。但是，分治法还可以进一步优化一下，比如，分治结束的条件不一定是要到bits_len = 1时才结束，其实bits_len = 2时也可以结束了：
```c++
if (bits_len == 2) {
    return ((x & 0b10) >> 1) ^ (x & 1);
}
```
此时，divide_and_conquer_helper的调用次数为$\underbrace{2*2*2*...*2}_{log_2(n)-1} = 2 ^ {log_2(n) - 1} = \frac{n}{2}$次。
甚至bits_len = 4时，分治业可以结束：
```c++
if (bits_len == 4) {
    return ((x & 0b1000) >> 3) ^ ((x & 0b100) >> 2) ^ ((x & 0b10) >> 1) ^ (x & 1);
}
```
此时divide_and_conquer_helper的调用次数为$\frac{n}{4}$次。

<br>

### 3
使用lookup table的方法：
```c++
short precomputed_parity[] = {
  0,  // 0b0000
  1,  // 0b0001
  1,  // 0b0010
  0,  // 0b0011
  1,  // 0b0100
  0,  // 0b0101
  0,  // 0b0110
  1,  // 0b0111
  1,  // 0b1000
  0,  // 0b1001
  0,  // 0b1010
  1,  // 0b1011
  0,  // 0b1100
  1,  // 0b1101
  1,  // 0b1110
  0,  // 0b1111
};

short Parity(unsigned long long x) {
  return precomputed_parity[x & 0xf] ^
    precomputed_parity[(x >> 4) & 0xf] ^
    precomputed_parity[(x >> 8) & 0xf] ^
    precomputed_parity[(x >> 12) & 0xf] ^
    precomputed_parity[(x >> 16) & 0xf] ^
    precomputed_parity[(x >> 20) & 0xf] ^
    precomputed_parity[(x >> 24) & 0xf] ^
    precomputed_parity[(x >> 28) & 0xf] ^
    precomputed_parity[(x >> 32) & 0xf] ^
    precomputed_parity[(x >> 36) & 0xf] ^
    precomputed_parity[(x >> 40) & 0xf] ^
    precomputed_parity[(x >> 44) & 0xf] ^
    precomputed_parity[(x >> 48) & 0xf] ^
    precomputed_parity[(x >> 52) & 0xf] ^
    precomputed_parity[(x >> 56) & 0xf] ^
    precomputed_parity[(x >> 60) & 0xf];
}
```
传说中的打表法？

时间复杂度取决于lookup table的大小。

空间复杂度也是。

<br>

### 4
书上的一种方法：
```c++
short Parity(unsigned long long x) {
  short result = 0;
  while (x) {
    result ^= 1;
    x &= (x - 1);
  }
  return result;
}
```
这是正常人能想出的方法？

时间复杂度取决于1的个数，比如整数有k个1bit，那么复杂度就是$O(k)$。

空间复杂度：$O(1)$

<br>

### 5
还有一种从书上学来的方法，就是高32位与低32位异或之后的结果放在低32位。现在这低32位又可以分成高16位和低16位，然后又进行异或操作，结果放在低16位，以此类推，最后到2位时，高1位和低1位异或出来的结果就是最终结果。
```c++
short Parity(unsigned long long x) {
  x ^= (x >> 32);
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  x ^= (x >> 2);
  x ^= (x >> 1);
  return x & 1;
}
```
时间复杂度：$O(log_2n)$，$n$是unsigned long long的字长。

空间复杂度：$O(1)$