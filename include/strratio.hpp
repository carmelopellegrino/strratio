#ifndef STRRATIO_HPP
#define STRRATIO_HPP

#include <ratio>

// Forward declarations for **possibly** present types
namespace std {
  class zepto;
  class yocto;
  class zetta;
  class yotta;
} // ns std

namespace budda {

template<class T> constexpr char const* strratio() = delete;

template<> constexpr char const* strratio<std::ratio<1, 1>>() { return "";  }

template<> constexpr char const* strratio<std::yocto>() { return "yocto"; }
template<> constexpr char const* strratio<std::zepto>() { return "zepto"; }
template<> constexpr char const* strratio<std::atto>()  { return "atto";  }
template<> constexpr char const* strratio<std::femto>() { return "femto"; }
template<> constexpr char const* strratio<std::pico>()  { return "pico";  }
template<> constexpr char const* strratio<std::nano>()  { return "nano";  }
template<> constexpr char const* strratio<std::micro>() { return "micro"; }
template<> constexpr char const* strratio<std::milli>() { return "milli"; }
template<> constexpr char const* strratio<std::centi>() { return "centi"; }
template<> constexpr char const* strratio<std::deci>()  { return "deci";  }
template<> constexpr char const* strratio<std::deca>()  { return "deca";  }
template<> constexpr char const* strratio<std::hecto>() { return "hecto"; }
template<> constexpr char const* strratio<std::kilo>()  { return "kilo";  }
template<> constexpr char const* strratio<std::mega>()  { return "mega";  }
template<> constexpr char const* strratio<std::giga>()  { return "giga";  }
template<> constexpr char const* strratio<std::tera>()  { return "tera";  }
template<> constexpr char const* strratio<std::peta>()  { return "peta";  }
template<> constexpr char const* strratio<std::exa>()   { return "exa";   }
template<> constexpr char const* strratio<std::zetta>() { return "zetta"; }
template<> constexpr char const* strratio<std::yotta>() { return "yotta"; }

} // ns budda

#endif
