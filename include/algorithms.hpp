#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

// print container elements
template <typename C> auto print(std::ostream &os, const C &ctnr) {
  os << "[";
  std::size_t i = 0;
  std::size_t end = ctnr.size()-1;
  for (; i < end; ++i) {
    os << ctnr[i] << ", ";
  }
  os << ctnr[i] << "]" << std::endl;
};

// populate container with increasing sequence of values
template <typename C>
auto populate_with_sequence(C &ctnr, typename C::value_type start) {
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    ctnr[i] = start++;
  }
};

// multiply each element in container by value
template <typename C>
auto multiply_with_value(C &ctnr, typename C::value_type value) {
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    ctnr[i] *= value;
  }
};

// reverse order of elements
template <typename C> auto reverse_order(C &ctnr) {
  std::size_t lastElement = ctnr.size() - 1;
  for (std::size_t i = 0; i < ctnr.size() / 2; ++i) {
    std::swap(ctnr[i], ctnr[lastElement - i]);
  }
};

// check how many elements fulfill a condition
template <typename C, typename UnaryPredicate>
auto count_fulfills_cond(
    C &ctnr, UnaryPredicate condition) {
  std::size_t count = 0;
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    if (condition(ctnr[i])) {
      ++count;
    }
  }
  return count;
};

// check if two containers are equal in length and content
template <typename C> auto check_are_equal(const C &a, const C &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (std::size_t i = 0; i < a.size(); ++i) {
    if (a != b) {
      return false;
    }
  }
  return true;
};

// sum all elements in the container
template <typename C> auto sum_of_elements(const C &ctnr) {
  typename C::value_type sum{};
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    sum += ctnr[i];
  }
  return sum;
};

// sum of absolute values of elements in the container
template <typename C> auto abssum_of_elements(C &ctnr) {
  typename C::value_type sum{};
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    sum += std::abs(ctnr[i]);
  }
  return sum;
};