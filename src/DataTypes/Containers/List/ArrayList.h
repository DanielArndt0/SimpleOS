#pragma once
#include "System/Base.h"
#include "Root/RamAllocator/RamAllocator.h"
#include "List.h"


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
        elements = (T *)Root::RamAllocator<SYSM_HEAP_SIZE>::calloc(capacity, sizeof(T));
      }

      ~ArrayList() { Root::RamAllocator<SYSM_HEAP_SIZE>::free(elements); }

    private:
      void resizeUp(bool resizeUp = true)
      {
        if (elements == nullptr)
          return;
        unsigned int cap = resizeUp ? capacity * 2 : capacity / 2;
        T *newElements = (T *)Root::RamAllocator<SYSM_HEAP_SIZE>::calloc(cap, sizeof(T));
        if (newElements == nullptr)
          return;
        capacity = cap;
        for (unsigned int i = 0; i < size; i++)
          newElements[i] = elements[i];
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

      void remove(unsigned int index) override
      {
        if (index < 0 || index >= size || elements == nullptr)
          return;
        for (unsigned int i = index; i < size - 1; i++)
          elements[i] = elements[i + 1];
        size--;
        if (size < (capacity / 2) && capacity > 10)
          resizeUp(false);
      }

      T &get(unsigned int index) override
      {
        if (index < 0 || index >= size || elements == nullptr)
          return defaultValue;
        return elements[index];
      }

      void foreach (void (*func)(T &element)) override
      {
        if (elements == nullptr)
          return;
        for (unsigned int i = 0; i < size; i++)
          func(elements[i]);
      }

      bool exists(T &element) const override
      {
        if (elements == nullptr)
          return false;
        for (unsigned int i = 0; i < size; i++)
          if (element == elements[i])
            return true;
        return false;
      }

      bool isEmpty() const override { return size == 0; }

      unsigned int getSize() const override { return size; }

      const T &getDefaultValue() const override { return defaultValue; }

      void setDefaultValue(T defaultValue) { this->defaultValue = defaultValue; }
    };
  } // namespace Data
} // namespace SimpleOS
