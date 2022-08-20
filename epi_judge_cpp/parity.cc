// Description:
// Write code that computes the parity of a single 64-bit word.
// The parity of a binary word is 1 if the number of 1s in the word is odd; otherwise, it is 0.
// For example, the parity of 1011 is 1, and the parity of 101 is 0.

#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
