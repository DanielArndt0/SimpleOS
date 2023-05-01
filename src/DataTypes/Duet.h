#pragma once
#include "SimpleOS/Macros.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T1, typename T2>
    class Duet 
    {
    public:
      void operator=(Duet &cpy)
      {
        this->key = cpy.key;
        this->value = cpy.value;
      }

      void operator=(Duet &&move)
      {
        this->key = move.key;
        this->value = move.value;
      }

    private:
      T1 key;
      T2 value;

    public:
      Duet() = default;
      Duet(Duet &cpy) noexcept { *this = cpy; }
      Duet(Duet &&move) noexcept { *this = move; }
      Duet(T1 key, T2 value) noexcept : key(key), value(value) {}

    public:
      /**
       * @brief Get the first value of the Duet.
       *
       * @return Returns first object.
       */
      T1 &getFirst() { return key; }

      /**
       * @brief Set first value of the Duet.
       *
       * @param data Data to be defined.
       */
      void setFirst(T1 data) { key = data; }

      /**
       * @brief Get the second value of the Duet.
       *
       * @return Returns second object.
       */
      T2 &getSecond() { return value; }

      /**
       * @brief Set second value of the Duet.
       *
       * @param data Data to be defined.
       */
      void setSecond(T2 data) { value = data; }

      /**
       * @brief Set the Duet.
       *
       * @param d1 Data to be defined in first value.
       *
       * @param d2 Data to be defined in second value.
       */
      void setDuet(T1 d1, T2 d2)
      {
        key = d1;
        value = d2;
      }

      /**
       * @brief Create a new duet.
       *
       * @param d1 Key to be defined.
       *
       * @param d2 Value to be defined.
       *
       * @return Return a new duet with set values.
       */
      static Duet<T1, T2> create(T1 d1, T2 d2) { return Duet<T1, T2>(d1, d2); }
    };
  }
}