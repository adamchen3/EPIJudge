// Description:
// The quicksort algorithm for sorting arrays proceeds recursively --- it selects an elements
// (the "pivot"), reorders the array to make all the elments less than or equal to the pivot
// appear first, followed by all the elements greater than the pivot. The two subarrays are
// then sorted recursively.
// 
// Implemented naively, quicksort has large run times and deep function call stacks
// on arrays with many duplicates because the subarrays may differ greatly in size.
// One solution is reorder the array so that all elements less than the pivot apper first,
// followed by elements equal to the pivot, followed by elments greater than the pivot.
// This is known as Dutch national flag partitioning, because the Dutch national flag
// consists of three horizontal bands, each in a different color.
// 
// As an example, suppose A = <0,1,2,0,2,1,1>, and the pivot index is 3. The A[3] = 0,
// so <0,0,1,2,2,1,1> is a valid partitioning. For the same array, if the pivot index is 2,
// then A[2] = 2, so the arrays <0,1,0,1,1,2,2> as well as <0,0,1,1,1,2,2> are valid partitioning.
// 
// Write a program that takes an array A and an index i into A, and rearranges the
// elements such that all elements less than A[i](the "pivot") appear first, followed by
// elements equal to the pivot, followed by elements greater than the pivot.
// 
// Hint: Think about the partition step in quicksort.

#include <array>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;
enum class Color { kRed, kWhite, kBlue };

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr) {
  // TODO - you fill in here.
  return;
}
void DutchFlagPartitionWrapper(TimedExecutor& executor, const vector<int>& A,
                               int pivot_idx) {
  vector<Color> colors;
  colors.resize(A.size());
  std::array<int, 3> count = {0, 0, 0};
  for (size_t i = 0; i < A.size(); i++) {
    count[A[i]]++;
    colors[i] = static_cast<Color>(A[i]);
  }
  Color pivot = colors[pivot_idx];

  executor.Run([&] { DutchFlagPartition(pivot_idx, &colors); });

  int i = 0;
  while (i < colors.size() && colors[i] < pivot) {
    count[static_cast<int>(colors[i])]--;
    ++i;
  }

  while (i < colors.size() && colors[i] == pivot) {
    count[static_cast<int>(colors[i])]--;
    ++i;
  }

  while (i < colors.size() && colors[i] > pivot) {
    count[static_cast<int>(colors[i])]--;
    ++i;
  }

  if (i != colors.size()) {
    throw TestFailure("Not partitioned after " + std::to_string(i) +
                      "th element");
  } else if (count != std::array<int, 3>{0, 0, 0}) {
    throw TestFailure("Some elements are missing from original array");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A", "pivot_idx"};
  return GenericTestMain(args, "dutch_national_flag.cc",
                         "dutch_national_flag.tsv", &DutchFlagPartitionWrapper,
                         DefaultComparator{}, param_names);
}
