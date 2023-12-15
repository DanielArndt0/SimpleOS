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
    [[nodiscard]] static constexpr SimpleOS::Data::CString Typeof() { return strtok(strpbrk(strpbrk(__PRETTY_FUNCTION__, "="), " "), ";") + 1; }

    /**
     * @brief Identifies the data type of a variable.
     *
     * @tparam Type to be checked
     * @return Returns a string with the type name.
     */
    template <typename T>
    [[nodiscard]] static constexpr SimpleOS::Data::CString Typeof(T type) { return Typeof<T>(); }
  }
}