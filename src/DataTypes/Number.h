#pragma once
#include "Utils/Convert.h"

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
      Number(const Number &number) : number(number.number) {}
      Number(Number &&number) : number(number.number) { number.number = 0; }
      ~Number() = default;

    public:
      // Copy operators
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

      // ATTRIBUTION OPERATORS
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

      // Increment and Decrement Operators
      Number &operator++()
      {
        number++;
        return *this;
      }

      Number &operator++(int)
      {
        T old = number;
        operator++();
        return *this;
      }

      Number &operator--()
      {
        number--;
        return *this;
      }

      Number &operator--(int)
      {
        T old = number;
        operator--();
        return *this;
      }

      // Bitwise operators
      Number operator&(const Number &other) const { return Number(number & other.number); }
      Number operator&(T other) const { return Number(number & other); }

      Number operator|(const Number &other) const { return Number(number | other.number); }
      Number operator|(T other) const { return Number(number | other); }

      Number operator^(const Number &other) const { return Number(number ^ other.number); }
      Number operator^(T other) const { return Number(number ^ other); }

      // Shift operators
      Number operator>>(const Number &other) const { return Number(number >> other.number); }
      Number operator>>(T other) const { return Number(number >> other); }

      Number operator<<(const Number &other) const { return Number(number << other.number); }
      Number operator<<(T other) const { return Number(number << other); }

      operator T() const { return number; }
      T get() const { return number; }

      const char *toString() const
      {
        static char buffer[9];
        return Utils::convert<T>::toString(number, buffer);
      }
    };
  }
}