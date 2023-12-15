#pragma once
#include "Utils/RValueReference.h"

namespace SimpleOS
{
  template <typename T>
  typename RValueReference<T>::type declval() noexcept;
}