#pragma once
#include <math.h>
#include "Utils/Convert.h"
#include "Utils/IsSame.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class Number
    {
    private:
      T number;
      char *buffer = nullptr;
      unsigned char base = 10;
      unsigned char precision = 2;

    private:
      unsigned char digitCounter(unsigned long long number)
      {
        unsigned char counter = 0;
        while (number > 0)
        {
          number /= 10;
          counter++;
        }
        return counter;
      }

      void allocBuffer() { buffer = new char[digitCounter(pow(2, sizeof(T) * 8)) * 2]; }

    public:
      Number() : number(0) { allocBuffer(); }
      Number(T n) : number(n) { allocBuffer(); }
      Number(const Number &number) : number(number.number) { allocBuffer(); }
      Number(Number &&number) : number(number.number)
      {
        number.number = 0;
        allocBuffer();
      }
      ~Number() { delete[] buffer; }

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
        old = (T)old;
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

      Number &setPrecision(unsigned char precision)
      {
        this->precision = precision;
        return *this;
      }

      Number &setBase(unsigned char base)
      {
        this->base = base;
        return *this;
      }

      unsigned char getPrecision() { return this->precision; }

      unsigned char getBase() { return this->base; }

      const char *toString() const
      {
        if (Utils::IsSame<T, double>::check || Utils::IsSame<T, float>::check)
          return Utils::Convert<T>::toString(number, buffer, precision);
        else
          return Utils::Convert<T>::toString(number, buffer, base);
      }
    };
  }
}