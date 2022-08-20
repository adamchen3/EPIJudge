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
时间复杂度：$O(n)$，$n$为unsigned int的位数

空间复杂度：$O(1)$