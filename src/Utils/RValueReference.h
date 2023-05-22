#pragma once

namespace SimpleOS
{
  template <typename T>
  struct RValueReference
  {
    using type = T &&;
  };

  template <typename T>
  struct RValueReference<T &>
  {
    using type = T &;
  };

  template <typename T>
  struct RValueReference<T &&>
  {
    using type = T &&;
  };

  
}