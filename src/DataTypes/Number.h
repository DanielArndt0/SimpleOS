#pragma once
#include "DataTypes/Typedefs.h"
#include "Operators/Convert.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class Number
    {
    private:
      T number;

    public:
      Number() : number(0) {}
      Number(T n) : number(n) {}
      Number(const Number &number) { this->number = number.number; }
      Number(Number &&number)
      {
        this->number = number.number;
        number.number = 0;
      }
      ~Number() = default;

    public:
      // Operadores de cópia
      Number &operator=(T other)
      {
        number = other;
        return *this;
      }

      Number &operator=(const Number &other)
      {
        number = other.number;
        return *this;
      }

      Number &operator=(Number &&other)
      {
        number = other.number;
        other.number = 0;
        return *this;
      }

      // Operadores de atribuição
      Number &operator+=(const Number &other)
      {
        number += other.number;
        return *this;
      }
      Number &operator+=(T other)
      {
        number += other;
        return *this;
      }

      Number &operator-=(const Number &other)
      {
        number -= other.number;
        return *this;
      }
      Number &operator-=(T other)
      {
        number -= other;
        return *this;
      }

      Number &operator*=(const Number &other)
      {
        number *= other.number;
        return *this;
      }
      Number &operator*=(T other)
      {
        number *= other;
        return *this;
      }

      Number &operator/=(const Number &other)
      {
        number /= other.number;
        return *this;
      }
      Number &operator/=(T other)
      {
        number /= other;
        return *this;
      }

      Number operator+(const Number &other) const { return Number(number + other.number); }
      Number operator+(T other) const { return Number(number + other); }

      Number operator-(const Number &other) const { return Number(number - other.number); }
      Number operator-(T other) const { return Number(number - other); }

      Number operator*(const Number &other) const { return Number(number * other.number); }
      Number operator*(T other) const { return Number(number * other); }

      Number operator/(const Number &other) const { return Number(number / other.number); }
      Number operator/(T other) const { return Number(number / other); }

      bool operator==(const Number &other) const { return number == other.number; }
      bool operator==(T other) const { return number == other; }

      bool operator!=(const Number &other) const { return number != other.number; }
      bool operator!=(T other) const { return number != other; }

      bool operator<(const Number &other) const { return number < other.number; }
      bool operator<(T other) const { return number < other; }

      bool operator>(const Number &other) const { return number > other.number; }
      bool operator>(T other) const { return number > other; }

      bool operator<=(const Number &other) const { return number <= other.number; }
      bool operator<=(T other) const { return number <= other; }

      bool operator>=(const Number &other) const { return number >= other.number; }
      bool operator>=(T other) const { return number >= other; }

      operator T() const { return number; }

      T get() const { return number; }

      const char *toString() const
      {
        static char buffer[9];
        return Operators::convert<T>::toString(number, buffer);
      }
    };
  }
}