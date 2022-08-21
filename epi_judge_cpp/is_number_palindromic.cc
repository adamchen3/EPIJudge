// Description:
// Write a program that takes an integer and determines if that integer's representation
// as a decimal string is a palindrome.
// 
// A palindromic string is one which reads the same forwards and backwards, e.g.,
// "redivider". In this problem, you are to write a program which determines if 
// the decimal representation of an integer is a palindromic string. For example,
// your program should return true for the inputs 0, 1, 7, 11, 121, 333, and 
// 214747412, and false for the inputs -1, 12, 100, and 2147483647.
// 
// Hint: It's easy to come up with a simple expression that extracts the least significant digit.
// Can you find a simple expression for the most significant digit?


#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
