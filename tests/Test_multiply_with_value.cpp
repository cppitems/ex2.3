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
  double value = 3.1415;
  multiply_with_value(c, value);
  std::size_t counter = 1;
  for(auto it = c.begin(); it != c.end(); ++it) {
    TEST_ASSERT(*it == value * counter, containerName + ": Element is not correct: " + std::to_string(*it) + " != " + std::to_string(value * counter));
    ++counter;
  }
}

int main() {

  std::vector<value_type> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<value_type> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  runTest(vec, "Vector");
  runTest(list, "List");

  return EXIT_SUCCESS;
}