#pragma once
#include "System/Base.h"

namespace SimpleOS
{ 
  class Methods
  {
  public:
    template <typename T>
    static constexpr T getArgs(void *args, int index = 0) { return reinterpret_cast<T>(reinterpret_cast<void **>(args)[index]); }
    static constexpr bool hasArgs(void *args) { return args != nullptr; }
    virtual const char *version() { return SYS_VERSION; }
  };
} // namespace SimpleOS
