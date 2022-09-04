// Description:
// Write a program that multiplies two nonnegative integers. The only operators you
// are allowed to use are
//     · assignment
//     · the bitwise operators >>, <<, |, &, ~, ^ and
//     · equality checks and Boolean combinations thereof.
// You may use loops and functions that you write yourself. These contraints imply,
// for example, that you cannot use increament or decrement, or test if x < y.
// 
// Hint: Add using bitwise operations; multiply using shift-and-add.

#include "test_framework/generic_test.h"
#include <tuple>

std::tuple<unsigned long long, unsigned long long> HalfAdder(unsigned long long x, unsigned long long y) {
  return { (x & y) << 1, x ^ y }; // {carry, sum}

}

std::tuple<unsigned long long, unsigned long long> FullAdder(unsigned long long c, unsigned long long x, unsigned long long y) {
  unsigned long long tmp_carry, tmp_sum, tmp_carry2;
  std::tie(tmp_carry, tmp_sum) = HalfAdder(x, y);
  std::tie(tmp_carry2, tmp_sum) = HalfAdder(c, tmp_sum);

  return { tmp_carry | tmp_carry2, tmp_sum };
}

unsigned long long Add64(unsigned long long x, unsigned long long y) {
  // use c++17 feature
  auto carry = 0ull;
  auto tmp_sum = 0ull;
  auto sum = 0ull;
  for (int i = 0; i < 64; i++) {
    std::tie(carry, tmp_sum) = FullAdder(carry, x & (1ull << i), y & (1ull << i));
    sum |= tmp_sum;
  }
  return sum;
}


unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  // TODO - you fill in here.
  unsigned long long ret = 0;
  for (int i = 0; i < 64; i++) {
    if ((x & (1ull << i)) != 0) {
      ret = Add64(ret, y << i);
    }
  }
  return ret;
}



int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
