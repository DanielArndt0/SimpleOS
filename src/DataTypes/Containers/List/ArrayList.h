#pragma once

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class ArrayList
    {
    private:
      T *elements;
      T defaultValue;
      int capacity;
      int size;

    public:
      ArrayList()
      {
        capacity = 10;
        size = 0;
        elements = new T[capacity];
      }

      ~ArrayList()
      {
        delete[] elements;
      }

      void add(const T &element)
      {
        if (size == capacity)
          resize();
        elements[size++] = element;
      }

      void insert(const T &element, int index)
      {
        if (index < 0 || index > size)
          return;

        if (size == capacity)
          resize();

        for (int i = size; i > index; i--)
          elements[i] = elements[i - 1];

        elements[index] = element;
        size++;
      }

      void remove(int index)
      {
        if (index < 0 || index >= size)
          return;

        for (int i = index; i < size - 1; i++)
          elements[i] = elements[i + 1];

        size--;
      }

      T get(int index) const
      {
        if (index < 0 || index >= size)
          return defaultValue;
        return elements[index];
      }

      int getSize() const { return size; }

    private:
      void resize()
      {
        capacity *= 2;
        T *newElements = new T[capacity];
        for (int i = 0; i < size; i++)
          newElements[i] = elements[i];
        delete[] elements;
        elements = newElements;
      }
    };
  } // namespace Data

} // namespace SimpleOS
