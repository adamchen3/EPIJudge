// Description:
// Write a program that takes a double x and an integer y and returns x**y.
// 
// Hint: Exploit mathematical properties of exponentiation.

#include "test_framework/generic_test.h"
double Power(double x, int y) {
  // TODO - you fill in here.
  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
