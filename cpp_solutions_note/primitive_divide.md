### 1
没什么好说的，最简单易懂的暴力法：
```c++
int Divide(int x, int y) {
  int ret = 0;
  while (x >= y) {
    ret++;
    x -= y;
  }
  return ret;
}
```
缺点就是，如果$x = 2^{31} - 1, y=1$，那么运算量就非常大了。


### 2
优化思路：上面的解法中每次循环只减一个y，然后ret加一次。但是，如果x >= 10*y，那么x就可以一次减去10
*y，然后ret += 10。利用这个思路就可以对解法进行优化。y的系数可以选择$2^k$的形式，因为这样可以使用位移操作。

所以，新解法就是，如果$x >= y$, 那么找到到最大的$k$，使得$x >= 2^k *y$（又或者说，找到最小的$k$，使得$2^k * y > x$）, 然后$x = x - 2^k * y, ret = ret + 2^k$，循环这两步直到$x < 2^k *y$。再从判断$x >= y$那里重新开始，直到$x < y$为此。
```c++
int Divide(int x, int y) {
  int ret = 0;
  int power = 32;
  auto y_power = static_cast<unsigned long long>(y) << power;
  while (x >= y) {
    while (y_power > x) {
      power--;
      y_power >>= 1;
    }
    x -= y_power;
    ret += (1u << power);
  }
  return ret;
}
```
