#pragma once
#include "DataTypes/String/String.h"


namespace lib_davi
{
  void soma();
}

namespace lib_dani
{
  void soma();
}


namespace SimpleOS
{
  namespace Operators
  {
    /**
     * @brief Identifies the data type of a variable.
     *
     * @tparam Type to be checked
     * @return Returns a string with the type name.
     */
    template <typename T>
    [[nodiscard]] constexpr SimpleOS::Data::String Typeof() { return SimpleOS::Data::String(__PRETTY_FUNCTION__).findBetween("= ", "]").remove(0, 1); }

    /**
     * @brief Identifies the data type of a variable.
     *
     * @tparam Type to be checked
     * @return Returns a string with the type name.
     */
    template <typename T>
    [[nodiscard]] constexpr SimpleOS::Data::String Typeof(T type) { return Typeof<T>(); }
  }
}