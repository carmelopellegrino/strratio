#include <iostream>
#include <chrono>

#include <strratio.hpp>

using namespace std::chrono_literals;

namespace {

inline
int dur_i()
{
  auto static const i = std::ios_base::xalloc();
  return i;
}

} // anonymous ns

template<class Rep, class Period>
std::ostream& operator <<(
    std::ostream& stream
  , std::chrono::duration<Rep, Period> const& d
) {
  if (stream.iword(dur_i())) {
    stream.iword(dur_i()) = 0;

    return stream
      << d.count() << ' '
      << budda::strratio<Period>() << "seconds";
  } else {
    return stream << d.count();
  }
}

std::ostream& with_unit(std::ostream& stream)
{
  stream.iword(dur_i()) = 1;
  return stream;
}

int main()
{
  auto const t1 = 3.14s;
  auto const t2 = 4ms;

  auto const relation = t1 > t2 ? " is greater than " : " is less than ";

  std::cout << with_unit << t1 << relation << with_unit << t2 << '\n';
}

