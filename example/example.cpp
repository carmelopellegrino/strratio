#include <iostream>
#include <chrono>

#include <strratio.hpp>

using namespace std::chrono_literals;

template<class Duration>
struct with_unit
{
  Duration const& internal;

  with_unit(Duration const& d)
  : internal(d)
  {}
};

template<class Duration>
std::ostream& operator <<(
    std::ostream& stream
  , with_unit<Duration> const& wu
) {
  using namespace budda;
  return stream
    << wu.internal.count() << ' '
    << strratio<typename Duration::period>() << "seconds";
}

int main()
{
  auto const t1 = 3.14s;
  auto const t2 = 4ms;

  auto const relation = t1 > t2 ? " is greater than " : " is less than ";

  std::cout << with_unit{t1} << relation << with_unit{t2} << '\n';
}

