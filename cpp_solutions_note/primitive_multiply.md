### 1
先假设可以使用+操作符来解这个问题。那么如何通过使用加法来实现乘法运算呢？

二进制乘法运算的过程其实跟十进制的乘法运算很相似，甚至更简单。比如11(1011)*13(1101)，将这两个数的二进制形式按十进制的乘法运算去做就会发现，假设一开始积为0，乘数从最低有效位开始遍历，如果该位（第n位）是1，那么被乘数就左移n位然后加到积上，直到乘数遍历到最高有效位结束。
```c++
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  unsigned long long ret = 0;
  for (int i = 0; i < 64; i++) {
    if ((x & (1ull << i)) != 0) {
      ret += (y << i);
    }
  }
  return ret;
}
```
那么现在问题就转化成了如何使用逻辑运算、位移运算等来实现加法的问题了。

加法的实现就很简单了，可以先实现一个不带进位的半加器：
```c++
std::tuple<unsigned long long, unsigned long long> HalfAdder(unsigned long long x, unsigned long long y) {
  return { (x & y) << 1, x ^ y }; // {carry, sum}
}
```

然后使用半加器来实现一个带进位的全加器：
```c++
std::tuple<unsigned long long, unsigned long long> FullAdder(unsigned long long c, unsigned long long x, unsigned long long y) {
  unsigned long long tmp_carry, tmp_sum, tmp_carry2;
  std::tie(tmp_carry, tmp_sum) = HalfAdder(x, y);
  std::tie(tmp_carry2, tmp_sum) = HalfAdder(c, tmp_sum);
  return { tmp_carry | tmp_carry2, tmp_sum };
}
```

最后使用全加器来实现一个64位的加法器:
```c++
unsigned long long Add64(unsigned long long x, unsigned long long y) {
  auto carry = 0ull;
  auto tmp_sum = 0ull;
  auto sum = 0ull;
  for (int i = 0; i < 64; i++) {
    std::tie(carry, tmp_sum) = FullAdder(carry, x & (1ull << i), y & (1ull << i));
    sum |= tmp_sum;
  }
  return sum;
}
```

最后就是用加法器替换+操作符：
```c++
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  unsigned long long ret = 0;
  for (int i = 0; i < 64; i++) {
    if ((x & (1ull << i)) != 0) {
      ret = Add64(ret, y << i);
    }
  }
  return ret;
}
```


如果for循环不能使用，那也可以改成while循环：
```c++
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  unsigned long long ret = 0;
  while (x) {
    if (x & 1ull) {
      ret = Add64(ret, y);
    }
    x >>= 1;
    y <<= 1;
  }
  return ret;
}
```

时间复杂度：$O(n^2)$，n为unsigned long long的字长。