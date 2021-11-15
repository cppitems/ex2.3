# Exercise EX2.1

This exercise is part **1** of 3 parts of Ex2. See also [Item 000](https://cppitems.github.io/#/item/000) for an overview and deadlines. The submission deadline for EX2 (all three parts) is **Mo 29.11.2021, 4pm**. The sources related to Ex2.3 are available at [Item 011](https://github.com/cppitems/cppitems/tree/master/items/011). You should submit this exercise in a git repository called `ex2.1` at [https://tea.iue.tuwien.ac.at/](https://tea.iue.tuwien.ac.at/).

## Task description

In this exercise it is your task to adopt the implementation of the functions in `include/algorithms.hpp`, which are part of a *header-only* library.

These functions are function templates with a single *type template parameter* `C` and implement algorithms tailored to a "container type" `C` which supports access to elements using the `operator[]` and has a `size()` member, e.g. `std::vector`.

For example, the `populate_with_value` contains the functionality to set all elements in the container to a certain value `value`:
```C++
template <typename C>
auto populate_with_value(C &ctnr, typename C::value_type value) {
  for (std::size_t i = 0; i < ctnr.size(); ++i) {
    ctnr[i] = value;
  }
};
```
This function works fine, when the passed container `ctnr` is an `std::vector`, as in the example `example/VectorAlgorithms.cpp`. However, `C` could be any container and this implementation will not work if it is an `std::list` for example, since this container does not have an implementation for `operator[]()`, so `ctnr[i]` would lead to a compiler error.

**It is your task to change the implementation of all functions in `include/algorithms.hpp` to be compatible with different STL containers**.

For the function `populate_with_value` a reference solution is provided using the function `std::fill` provided by the standard header `<algorithm>`:

```C++
template <typename C>
auto populate_with_value(C &ctnr, typename C::value_type value) {
  std::fill(ctnr.begin(), ctnr.end(), value);
};
```

Similarly, you should change all other functions to use iterators and the functions provided in `<algorithm>` to achieve compatibility with the containers used in the tests.
For an overview and documentation of all algorithms available in the algorithms library of the C++ standard library, see [https://en.cppreference.com/w/cpp/algorithm]([https://en.cppreference.com/w/cpp/algorithm).
This header contains many different functions and **you may use any of them**, however the following functions should be enough to solve the exercise (in no particular order):
- [std::fill](https://en.cppreference.com/w/cpp/algorithm/fill)
- [std::transform](https://en.cppreference.com/w/cpp/algorithm/transform)
- [std::generate](https://en.cppreference.com/w/cpp/algorithm/generate)
- [std::for_each](https://en.cppreference.com/w/cpp/algorithm/for_each)
- [std::reverse](https://en.cppreference.com/w/cpp/algorithm/reverse)
- [std::count_if](https://en.cppreference.com/w/cpp/algorithm/count_if)
- [std::equal](https://en.cppreference.com/w/cpp/algorithm/equal)
- [std::accumulate](https://en.cppreference.com/w/cpp/algorithm/accumulate)



**NOTE: After you finished your modifications in `include/algorithms.hpp`, no explicit `for`-loops should be present.**

Prepare yourself for a discussion of your implementation and try to identify advantages and disadvantages of using "algorithms form the stdlib" vs. "classic `for`-loops".

## Examples and tests

In order to familiarize yourself with the functionality provided by each function, a working example is provided in `examples/VectorAlgorithms.cpp`, which is automatically built when building the project. This example shows what the algorithms do on a `std::vector`, which already works.

The tests should help you extend these functionalities to other standard data structures such as `std::list` and `std::set`, where applicable. There is a test laying out the required functionality for each function and there is no particular order in which to satisfy them:
- Test_abssum_of_elements.cpp
- Test_count_fulfills_cond.cpp
- Test_first_n_equal.cpp
- Test_multiply_with_value.cpp
- Test_populate_with_sequence.cpp
- Test_print.cpp
- Test_reverse_order.cpp
- Test_sum_of_elements.cpp

## Iterators

The STL algorithms in `<algorithms>` rely heavily on iterators, so you are provided some example on how to obtain iterators for STL data structures in `examples/VectorIterators.cpp`.