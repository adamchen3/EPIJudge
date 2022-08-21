### 1
一种很简单的解法就是，先判断对应的位是否相等，相等就不用管，直接返回即可。如果不相等，各自的位取反即可。
```c++
long long SwapBits(long long x, int i, int j) {
  if (((x >> i) & 0b1) != ((x >> j) & 0b1)) {
    x ^= (1LL << i);
    x ^= (1LL << j);
  }
  return x;
}
```
另外一种写法（书上的写法）:
```c++
long long SwapBits(long long x, int i, int j) {
  if (((x >> i) & 0b1) != ((x >> j) & 0b1)) {
    long long bit_mask = 1LL << i | 1LL << j;
    x ^= bit_mask;
  }
  return x;
}
```