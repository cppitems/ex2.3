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
  reverse_order(c);
  std::size_t counter = c.size();
  for(auto it = c.begin(); it != c.end(); ++it) {
    TEST_ASSERT(*it == counter, containerName + ": Element is not correct: " + std::to_string(*it) + " != " + std::to_string(counter));
    --counter;
  }
}

int main() {

  std::vector<value_type> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<value_type> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  runTest(vec, "Vector");
  runTest(list, "List");

  return EXIT_SUCCESS;
}