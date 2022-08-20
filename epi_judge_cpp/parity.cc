// Description:
// Write code that computes the parity of a single 64-bit word.
// The parity of a binary word is 1 if the number of 1s in the word is odd; otherwise, it is 0.
// For example, the parity of 1011 is 1, and the parity of 101 is 0.

#include "test_framework/generic_test.h"

short divide_and_conquer_helper(unsigned long long x, int bits_len) {
  if (bits_len == 8) {
    return ((x & 0b10000000) >> 7) ^ ((x & 0b1000000) >> 6) ^ ((x & 0b100000) >> 5) ^ ((x & 0b10000) >> 4) ^ ((x & 0b1000) >> 3) ^ ((x & 0b100) >> 2) ^ ((x & 0b10) >> 1) ^ (x & 1);
  }

  if (bits_len == 4) {
    return ((x & 0b1000) >> 3) ^ ((x & 0b100) >> 2) ^ ((x & 0b10) >> 1) ^ (x & 1);
  }

  if (bits_len == 2) {
    return ((x & 0b10) >> 1) ^ (x & 1);
  }

  if (bits_len == 1) {
    return x & 1;
  }

  int half_bits_len = bits_len >> 1;
  int left_parity = divide_and_conquer_helper(x >> (half_bits_len), half_bits_len);
  int right_parity = divide_and_conquer_helper(x, half_bits_len);
  return left_parity ^ right_parity;
}

// LookUp Tabel
short precomputed_parity[] = {
  0,  // 0b0000
  1,  // 0b0001
  1,  // 0b0010
  0,  // 0b0011
  1,  // 0b0100
  0,  // 0b0101
  0,  // 0b0110
  1,  // 0b0111
  1,  // 0b1000
  0,  // 0b1001
  0,  // 0b1010
  1,  // 0b1011
  0,  // 0b1100
  1,  // 0b1101
  1,  // 0b1110
  0,  // 0b1111
};

short Parity(unsigned long long x) {
  // TODO - you fill in here.

  // anothor method from the book
  x ^= (x >> 32);
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  x ^= (x >> 2);
  x ^= (x >> 1);
  return x & 1;

  // method from the book
  short result = 0;
  while (x) {
    result ^= 1;
    x &= (x - 1); // 去掉最低位的1
  }

  return result;

  // lookup table method

  return precomputed_parity[x & 0xf] ^
    precomputed_parity[(x >> 4) & 0xf] ^
    precomputed_parity[(x >> 8) & 0xf] ^
    precomputed_parity[(x >> 12) & 0xf] ^
    precomputed_parity[(x >> 16) & 0xf] ^
    precomputed_parity[(x >> 20) & 0xf] ^
    precomputed_parity[(x >> 24) & 0xf] ^
    precomputed_parity[(x >> 28) & 0xf] ^
    precomputed_parity[(x >> 32) & 0xf] ^
    precomputed_parity[(x >> 36) & 0xf] ^
    precomputed_parity[(x >> 40) & 0xf] ^
    precomputed_parity[(x >> 44) & 0xf] ^
    precomputed_parity[(x >> 48) & 0xf] ^
    precomputed_parity[(x >> 52) & 0xf] ^
    precomputed_parity[(x >> 56) & 0xf] ^
    precomputed_parity[(x >> 60) & 0xf];



  // divide and conquer
  return divide_and_conquer_helper(x, 64);

  // brute force
  int bits_num = 0;
  while (x) {
    bits_num += x & 1;
    x >>= 1;
  }
  return bits_num & 1; // 第一位是1就是odd，是0就是even
}



int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
