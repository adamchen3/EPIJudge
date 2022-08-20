// Description:
// Write a program to count the number of bits that are set to 1 in an integer.

#include "test_framework/generic_test.h"

short CountBits(unsigned int x) {
  // TODO - you fill in here.
  int bits_num = 0;
  while (x) {
    bits_num += x & 1;
    x >>= 1;
  }
  return bits_num;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
