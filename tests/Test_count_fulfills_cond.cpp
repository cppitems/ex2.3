#include <algorithm>
#include <algorithms.hpp>
#include <cstddef>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "testasserts.hpp"

using value_type = int;

bool isEven(const value_type& val) {
  return !(val % 2);
}

template <class C> void runTest(C &c, std::string containerName) {
  const auto count = count_fulfills_cond(c, &isEven);
  TEST_ASSERT(count == 5, containerName + ": Count of even numbers is " + std::to_string(count) + " but should be 5");
}

int main() {

  std::vector<value_type> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<value_type> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<value_type> set = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  runTest(vec, "Vector");
  runTest(list, "List");
  runTest(set, "Set");

  return EXIT_SUCCESS;
}