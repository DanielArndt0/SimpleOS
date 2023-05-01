#pragma once
#include "DataTypes/Typedefs.h"
#include "DataTypes/Duet.h"
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Addons
  {
    class PartitionProperties
    {
    private:
      Data::Char _name;
      Data::ULong addr_start;
      Data::ULong addr_final;

    public:
      PartitionProperties();
      PartitionProperties(Data::Char _name, Data::ULong addr_start, Data::ULong addr_final);
      virtual ~PartitionProperties() = default;

    public:
      Data::Char name();
      Data::ULong size();
      Data::ULong startAddr();
      Data::ULong endAddr();
    };
  }
}