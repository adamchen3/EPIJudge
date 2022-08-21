// Description:
// Write a program that takes a 64-bit word and returns the 64-bit word consisting of
// the bits of the input word in reverse order.
// 
// Hint: Use a lookup table.

#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
