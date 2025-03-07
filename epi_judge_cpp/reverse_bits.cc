// Description:
// Write a program that takes a 64-bit word and returns the 64-bit word consisting of
// the bits of the input word in reverse order.
// 
// Hint: Use a lookup table.

#include "test_framework/generic_test.h"

unsigned long long precomputed_reverse_bits[] = {
  0b0000, // 0b0000
  0b1000, // 0b0001
  0b0100, // 0b0010
  0b1100, // 0b0011
  0b0010, // 0b0100
  0b1010, // 0b0101
  0b0110, // 0b0110
  0b1110, // 0b0111
  0b0001, // 0b1000
  0b1001, // 0b1001
  0b0101, // 0b1010
  0b1101, // 0b1011
  0b0011, // 0b1100
  0b1011, // 0b1101
  0b0111, // 0b1110
  0b1111, // 0b1111
};

unsigned long long divide_and_conquer_helper(unsigned long long x, short bits_len) {
  if (bits_len == 4) {
    return precomputed_reverse_bits[x & 0xf];
  }

  short half_bits_len = bits_len >> 1;
  unsigned long long reverse_high = divide_and_conquer_helper(x >> half_bits_len, half_bits_len);
  unsigned long long reverse_low = divide_and_conquer_helper(x, half_bits_len);

  return reverse_low << half_bits_len | reverse_high;
}

unsigned long long ReverseBits(unsigned long long x) {
  // TODO - you fill in here.
  return divide_and_conquer_helper(x, 64);

  short size = sizeof(x) * 8;
  unsigned long long ret = 0;
  for (int i = 0; i < size; i++) {
    ret <<= 1;
    ret ^= (x & 1);
    x >>= 1;
  }
  return ret;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
