// Description:
// Implement code that takes as input a 64-bit integer and swaps the bits at indices i and j.
// 
// Hint: When is the swap necessary?

#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
  // TODO - you fill in here.

  if (((x >> i) & 0b1) != ((x >> j) & 0b1)) {
    long long bit_mask = 1LL << i | 1LL << j;
    x ^= bit_mask;
  }
  return x;

  if (((x >> i) & 0b1) != ((x >> j) & 0b1)) {
    x ^= (1LL << i);
    x ^= (1LL << j);
  }
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
