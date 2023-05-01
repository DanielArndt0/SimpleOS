#pragma once
#include "Operators/RValueReference.h"

namespace SimpleOS
{
  template <typename T>
  typename RvalueReference<T>::type declval() noexcept;
}