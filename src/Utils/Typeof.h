#pragma once

namespace SimpleOS
{
  namespace Utils
  {
    /**
     * @brief Identifies the data type of a variable.
     *
     * @tparam Type to be checked
     * @return Returns a string with the type name.
     */
    template <typename T>
    [[nodiscard]] constexpr SimpleOS::Data::CString Typeof()
    {
      return "Disabled";
      //return SimpleOS::Data::String(__PRETTY_FUNCTION__).findBetween("= ", "]").remove(0, 1);
    }

    /**
     * @brief Identifies the data type of a variable.
     *
     * @tparam Type to be checked
     * @return Returns a string with the type name.
     */
    template <typename T>
    [[nodiscard]] constexpr SimpleOS::Data::CString Typeof(T type) { return Typeof<T>(); }
  }
}