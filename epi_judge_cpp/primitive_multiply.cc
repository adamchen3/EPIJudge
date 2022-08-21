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
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
