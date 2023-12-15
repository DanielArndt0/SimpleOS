#pragma once
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Concepts
  {
    class Printable
    {
    public:
      // Methods
      virtual SimpleOS::Data::CString print() const = 0;

      // Destructor
      virtual ~Printable() = default;

    protected:
      Printable() = default;
    };
  }
}