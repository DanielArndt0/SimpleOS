#pragma once
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Concepts
  {
    template <typename T>
    class Identifiable
    {
    private:
      static Data::ID idCounter;

    public:
      // Methods
      const Data::ID id;
      // Constructor
      Identifiable() : id(idCounter) { idCounter += 1; }
      // Destructor
      ~Identifiable() = default;
    };
    template <class T>
    SimpleOS::Data::ID SimpleOS::Concepts::Identifiable<T>::idCounter = 0;
  }
}