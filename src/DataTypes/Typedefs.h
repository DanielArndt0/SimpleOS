#pragma once
#include "DataTypes/Number.h"

namespace SimpleOS
{
  namespace Data
  {
    using Char = Number<char>;
    using UChar = Number<unsigned char>;
    using Int = Number<int>;
    using UInt = Number<unsigned int>;
    using Long = Number<long>;
    using ULong = Number<unsigned long>;
    using Float = Number<float>;
    using Double = Number<double>;
    using Bool = Number<bool>;

    typedef int Index;
    typedef unsigned int Size;
    typedef unsigned long ID;
    typedef const char *CString;
  }
}
