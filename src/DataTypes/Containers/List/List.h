#pragma once
#include "System/Base.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class List
    {
    public:
      virtual void add(const T &element) = 0;
      virtual void insert(const T &element, unsigned int index) = 0;
      virtual T remove(unsigned int index) = 0;
      virtual T removeFirst(T &element) = 0;
      virtual T removeWhere(bool (*func)(T element)) = 0;
      virtual T get(unsigned int index) = 0;
      virtual T getWhere(bool (*func)(T element)) = 0;
      virtual void foreach (void (*func)(T element)) = 0;
      virtual bool exists(T element) const = 0;
      virtual bool isEmpty() const = 0;
      virtual unsigned int getSize() const = 0;
      virtual const T getErrorValue() const = 0;
      virtual void setErrorValue(T defaultValue) = 0;

    public:
      virtual ~List() = default;
    };
  } // namespace Data
} // namespace SimpleOS
