// Description:
// Given two positive integers, compute their quotient, using only the addition,
// subtraction, and shifting operators.
// 
// Hint: Relate x/y to (x-y)/y.

#include "test_framework/generic_test.h"
int Divide(int x, int y) {
  // TODO - you fill in here.
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

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
