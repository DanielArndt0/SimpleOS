#pragma once

namespace SimpleOS
{
  namespace Utils
  {
    /**
     * @brief Identifies whether the data type is primitive.
     */
    template <typename T>
    [[nodiscard]] static constexpr bool IsPrimitive() { return false; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<bool>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<char>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<unsigned char>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<int>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<unsigned int>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<long>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<unsigned long>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<long long>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<unsigned long long>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<float>() { return true; }

    template <>
    [[nodiscard]] constexpr bool IsPrimitive<double>() { return true; }

    /**
     * @brief Identifies whether the data type is primitive.
     */
    template <typename T>
    [[nodiscard]] static constexpr bool IsPrimitive(T type) { return IsPrimitive<T>(); }
  }
}