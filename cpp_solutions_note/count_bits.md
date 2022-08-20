### 1

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

<br>

### 2
参考[parity](./parity.md#4)里的第4种方法，该问题的解法可以优化一下：
```c++
short CountBits(unsigned int x) {
  short result = 0;
  while (x) {
    result += 1;
    x &= (x - 1); // 去掉最低位的1
  }
  return result;
}
```
时间复杂度：$O(k)$，$k$是x中1的个数。比如0b110010，k=3。