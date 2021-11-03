#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

// populate container with constant value
template <typename C>
auto populate_with_value(C &ctnr, typename C::value_type value) {
  /* classic index-based for loop */
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    ctnr[i] = value;
  }

  /* same functionality using std algorithm */
  // std::fill(ctnr.begin(), ctnr.end(), value);
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
auto count_fulfills_cond(C &ctnr, UnaryPredicate condition) {
  std::size_t count = 0;
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    if (condition(ctnr[i])) {
      ++count;
    }
  }
  return count;
};

// check if two containers are equal in length and content
template <typename C>
auto first_n_equal(const C &a, const C &b, std::size_t n) {
  if (a.size() < n || b.size() < n) {
    return false;
  }

  for (std::size_t i = 0; i < n; ++i) {
    // if j is out of bounds or elements do not match, the ranges are not equal 
    if (a[i] != b[i]) {
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

// print container elements
template <typename C> auto print(std::ostream &os, const C &ctnr) {
  os << "[";
  std::size_t lastElement = ctnr.size() - 1;
  for (std::size_t i = 0; i < lastElement; ++i) {
    os << ctnr[i] << ", ";
  }
  os << ctnr[lastElement] << "]" << std::endl;
};