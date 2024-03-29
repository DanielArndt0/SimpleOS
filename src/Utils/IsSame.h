#pragma once

namespace SimpleOS
{
  namespace Utils
  {
    template <typename T, typename U>
    struct IsSame
    {
      static constexpr bool check = false;
    };

    template <typename T>
    struct IsSame<T, T>
    {
      static constexpr bool check = true;
    };
  }
}
