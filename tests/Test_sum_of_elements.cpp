#include <algorithms.hpp>
#include <cstddef>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "testasserts.hpp"

using value_type = double;


template <class C> void runTest(C &c, std::string containerName) {
  auto sum = sum_of_elements(c);

  TEST_ASSERT(sum == 40, containerName + ": Sum is not correct: " + std::to_string(sum) + " != 40");
}

int main() {

  std::vector<value_type> vec = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<value_type> list = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<value_type> set = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  runTest(vec, "Vector");
  runTest(list, "List");
  runTest(set, "Set");

  return EXIT_SUCCESS;
}