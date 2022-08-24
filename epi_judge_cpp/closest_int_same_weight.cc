// Description:
// Define the weight of a nonnegative integer x to be the number of bits that are set to
// 1 in its binary representation. For example, sinece 92 in base-2 equals(1011100)2, the
// weight of 92 is 4.
// 
// Write a program which takes as input a nonnegative integer x and returns a number
// y which is not equal to x, but has the same weight as x and their difference, |y - x|, is
// as small as possible. You can assume x is not 0, or all 1s. For example, if x = 6(110), You
// should return 5(101).
// 
// Hint: Start with the least significant bit.

#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  // TODO - you fill in here.
  if (x == 0 || x == 0xffffffff) {
    return 0;
  }
  short bit_pos = 0;
  auto lower_bit = 0ull;
  auto higher_bit = 0ull;
  do {
    lower_bit = x & (1ull << bit_pos);
    higher_bit = x & (1ull << (bit_pos + 1));
    bit_pos++;
  } while ((lower_bit << 1) == higher_bit);
 
  // swap bits
  x ^= (1ull << (bit_pos - 1));
  x ^= (1ull << bit_pos);
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
