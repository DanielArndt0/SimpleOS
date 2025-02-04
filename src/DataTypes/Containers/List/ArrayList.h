#pragma once
#include "System/Base.h"
#include "List.h"
#include "Utils/IsSame.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class ArrayList : implements List<T>
    {
    private:
      T *elements;
      T defaultValue;
      unsigned int capacity;
      unsigned int size;

    public:
      ArrayList()
      {
        capacity = 10;
        size = 0;
        elements = new T[capacity];
      }

      ~ArrayList() { delete[] elements; }

    private:
      void resizeUp(bool resizeUp = true)
      {
        if (elements == nullptr)
          return;
        unsigned int cap = resizeUp ? capacity * 2 : capacity / 2;
        T *newElements = new T[cap];
        if (newElements == nullptr)
          return;
        capacity = cap;
        for (unsigned int i = 0; i < size; i++)
          newElements[i] = elements[i];
        delete[] elements;
        elements = newElements;
      }

    public:
      void add(const T &element) override
      {
        if (elements == nullptr)
          return;
        if (size >= capacity)
          resizeUp();
        elements[size++] = element;
      }

      void insert(const T &element, unsigned int index) override
      {
        if (index < 0 || index > size || elements == nullptr)
          return;
        if (size == capacity)
          resizeUp();
        for (unsigned int i = size; i > index; i--)
          elements[i] = elements[i - 1];
        elements[index] = element;
        size++;
      }

      T removeFirst(T &element) override
      {
        T temp = getErrorValue();
        if (elements != nullptr)
        {
          for (unsigned int i = 0; i < size - 1; i++)
          {
            if (element == elements[i])
            {
              temp = elements[i];
              elements[i] = elements[i + 1];
              size--;
              if (size < (capacity / 2) && capacity > 10)
                resizeUp(false);
              return temp;
            }
          }
        }
        return temp;
      }

      T remove(unsigned int index) override
      {
        T temp = getErrorValue();
        if (index >= 0 || index < size || elements != nullptr)
        {
          temp = elements[index];
          for (unsigned int i = index; i < size - 1; i++)
            elements[i] = elements[i + 1];
          size--;
          if (size < (capacity / 2) && capacity > 10)
            resizeUp(false);
          return temp;
        }
        return temp;
      }

      T removeWhere(bool (*func)(T element)) override
      {
        T temp = getErrorValue();
        if (elements != nullptr)
        {
          for (unsigned int i = 0; i < size; i++)
          {
            if (func(elements[i]))
            {
              temp = elements[i];
              remove(i);
              return temp;
            }
          }
        }
        return temp;
      }

      T get(unsigned int index) override
      {
        if (index < 0 || index >= size || elements == nullptr)
          return getErrorValue();
        return elements[index];
      }

      T getWhere(bool (*func)(T element))
      {
        if (elements == nullptr)
          return getErrorValue();
        for (unsigned int i = 0; i < size; i++)
          if (func(elements[i]))
            return elements[i];
        return getErrorValue();
      }

      void foreach (void (*func)(T element)) override
      {
        if (elements == nullptr)
          return;
        for (unsigned int i = 0; i < size; i++)
          func(elements[i]);
      }

      bool exists(T element) const override
      {
        if (elements == nullptr)
          return false;
        for (unsigned int i = 0; i < size; i++)
          if (element == elements[i])
            return true;
        return false;
      }

      const char* toString() const
      {
        if (Utils::IsSame<T, char>::check)
        {
          char* str = new char[size + 1];
          memcpy(str, elements, size);
          str[size] = '\0';
          return str;
        }
        else
        {
          return "[toString() not implemented for this type]";
        }
      }

      bool isEmpty() const override { return size == 0; }

      unsigned int getSize() const override { return size; }

      const T getErrorValue() const override { return defaultValue; }

      void setErrorValue(T defaultValue) { this->defaultValue = defaultValue; }
    };
  } // namespace Data
} // namespace SimpleOS
