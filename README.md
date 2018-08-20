# Introduction

With the advent of the commonly known as "Modern C++", new features for
generic programming were added, whilst the standard libray got many new
types.

Most notably, the change of the meaning of the `auto` keyword greatly
simplifies code maintainance and refactoring.

The aim of this small library is to provide a simple way to print in a
human-readable form the unit used in
[convenience typedefs](https://en.cppreference.com/w/cpp/numeric/ratio/ratio)
of `std::ratio`. It provides a number of specializations of the
`strratio` template function that work similarly to the `std::strerror`
standard-library function.

A special focus on efficiency has been put in the design and
implementation of the library.

# How to use
Simply `#include` the library into your C++ program and call the
`budda::strratio<ratio>()` template function on the ratio type.

```cpp
#include <iostream>
#include <chrono>
#include <strratio.hpp>

void process() {
  using clock = std::chrono::system_clock; // here you decide the type
  // from now on there is only generic code :)

  auto const start = clock::now();

  do_stuff();
  auto const stop = clock::now();
  auto const delta = stop - start;

  std::cout
    << "lasted "
    << delta.count() << ' '
    << budda::strratio<decltype(delta)::period>() << "seconds\n";
}
```

See the `example` folder for other examples.

# Supported standards
The library is compatible with C++11, 14, and 17.

