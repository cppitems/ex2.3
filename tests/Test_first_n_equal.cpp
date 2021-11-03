#include <algorithm>
#include <algorithms.hpp>
#include <cstddef>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "testasserts.hpp"

using value_type = int;

template <class C> void runTest(C &c, std::string containerName) {
  std::size_t n = 7;

  auto newCont = c;
  TEST_ASSERT(first_n_equal(c, newCont, n), containerName + ": First " + std::to_string(n) + " should be equal");

  // adding at the back should not change anything
  c.insert(c.end(), 11);
  TEST_ASSERT(first_n_equal(c, newCont, n), containerName + ": First " + std::to_string(n) + " should be equal, although different lengths");

  // check if comparison fails if we add an element at the start
  c.insert(c.begin(), 0);
  TEST_ASSERT(!first_n_equal(c, newCont, n), containerName + ": First " + std::to_string(n) + " should not be equal, different values and lengths");
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