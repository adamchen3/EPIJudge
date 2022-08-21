// Description:
// Write a program which takes an integer and returns the integer corresponding to the
// digits of the input written in reverse order. For example, the reverse of 42 is 24,
// and the reverse of -314 is -413;
// 
// Hint: How would you solve the same problem if the input is presented as string?

#include "test_framework/generic_test.h"
long long Reverse(int x) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
