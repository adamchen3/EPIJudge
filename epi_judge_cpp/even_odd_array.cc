// Description:
// Your input is an array of integers, and you have to reorder its entries so that even
// entries appear first. This is easy if you use O(n) space, where n is the length of the
// array. However, you are required to solve it without allocating additional storage.
// 
// When working with arrays you should take advantage of the fact that you can
// operate efficiently on both ends. For this problem, we can partition the array into
// three subarrays: Even, Unclassified, and Odd, appearing in that order. Initially
// Even and Odd are empty, and Unclassified is the entire array. We iterate through
// Unclassified, moving its elments to the boundaries of the Even and Odd subarrays
// via swaps, thereby expanding Even and Odd, and shrinking Unclassified.

#include <set>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;

void EvenOdd(vector<int>* A_ptr) {
  // TODO - you fill in here.
  return;
}
void EvenOddWrapper(TimedExecutor& executor, vector<int> A) {
  std::multiset<int> before(begin(A), end(A));

  executor.Run([&] { EvenOdd(&A); });

  bool in_odd = false;
  for (int a : A) {
    if (a % 2 == 0) {
      if (in_odd) {
        throw TestFailure("Even elements appear in odd part");
      }
    } else {
      in_odd = true;
    }
  }

  std::multiset<int> after(begin(A), end(A));
  if (before != after) {
    throw TestFailure("Elements mismatch");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, "even_odd_array.cc", "even_odd_array.tsv",
                         &EvenOddWrapper, DefaultComparator{}, param_names);
}
