#pragma once
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Root
  {
    class Object
    {
    private:
      static SimpleOS::Data::ID totalIDs;
      SimpleOS::Data::ID thisID;

    public:
      Object();

    public:
      virtual SimpleOS::Data::C_String toString();
      virtual SimpleOS::Data::Hashcode hashCode();
      virtual SimpleOS::Data::ID objectId();
    };
  }
}