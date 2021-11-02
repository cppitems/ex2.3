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
  auto newCont = c;
  TEST_ASSERT(check_are_equal(c, newCont), containerName + ": Containers should be equal");

  // change one element, which is not allowed for a set since it is an associative container
  // and the order of elements depends on their value
  if constexpr (!std::is_same_v<C, std::set<value_type>>) {
    typename C::iterator it = newCont.begin();
    std::advance(it, 5);

    auto oldVal = *it;
    *it = 42;
    TEST_ASSERT(!check_are_equal(c, newCont), containerName + ": Containers should not be equal, different values");
    // restore old value
    *it = oldVal;
  }

  // check if comparison fails if we add an element at the end
  c.insert(c.end(), 11);
    TEST_ASSERT(!check_are_equal(c, newCont), containerName + ": Containers should not be equal, different lengths");
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