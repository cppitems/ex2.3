#include <algorithms.hpp>
#include <list>
#include <set>
#include <sstream>
#include <vector>

#include "testasserts.hpp"

using value_type = int;
const std::string correctStr = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n";

template <class C> void runTest(C &c, std::string containerName) {
  std::ostringstream oss;
  print(oss, c);
  const auto returnedStr = oss.str();
  TEST_ASSERT(returnedStr == correctStr,
              containerName +
                  ": Incorrect output for function print. \nExpected:\n" +
                  correctStr + "\nGot:\n" + returnedStr);
}

int main() {

  const std::vector<value_type> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const std::list<value_type> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const std::set<value_type> set = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  runTest(vec, "Vector");
  runTest(list, "List");
  runTest(set, "Set");

  return EXIT_SUCCESS;
}