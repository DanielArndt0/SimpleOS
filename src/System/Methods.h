#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  class Methods
  {
  private:
  protected:
  public:
    virtual Data::C_String version() { return SYSM_VERSION; }

    template <typename T>
    static constexpr T getArgs(void *args, int index = 0) { return reinterpret_cast<T>(reinterpret_cast<void **>(args)[index]); }
  };
} // namespace SimpleOS
