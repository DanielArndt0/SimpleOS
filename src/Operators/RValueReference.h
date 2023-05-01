#pragma once

namespace SimpleOS
{
  template <typename T>
  struct RvalueReference
  {
    using type = T &&;
  };

  template <typename T>
  struct RvalueReference<T &>
  {
    using type = T &;
  };

  template <typename T>
  struct RvalueReference<T &&>
  {
    using type = T &&;
  };

  
}