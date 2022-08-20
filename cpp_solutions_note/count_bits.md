直接暴力法解决，通过shifting和masking操作来计算：
```c++
short CountBits(unsigned int x) {
  int bits_num = 0;
  while (x) {
    bits_num += x & 1;
    x >>= 1;
  }
  return bits_num;
}
```
最坏时间复杂度：$O(n)$，$n$为unsigned int的位数。比如x=0b1111...111（全是1）。

最好时间复杂度：$O(1)$，比如x=0

空间复杂度：$O(1)$