#pragma once
#include "DataTypes/Typedefs.h"
#include "DataTypes/Duet.h"
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Addons
  {
    class EEProperties
    {
    private:
      Data::Char name;
      Data::ULong size;
      Data::ULong addr_start;
      Data::ULong addr_final;

    public:
      EEProperties();
      EEProperties(Data::Char name, Data::ULong addr_start, Data::ULong addr_final);
      virtual ~EEProperties() = default;

    public:
      Data::Char getName();
      Data::ULong getSize();
      Data::ULong getStartAddr();
      Data::ULong getEndAddr();
      // Data::UChar *getData();
    };
  }
}