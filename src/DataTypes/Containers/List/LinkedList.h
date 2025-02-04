#pragma once
#include "System/Base.h"
#include "List.h"

namespace SimpleOS
{
  namespace Data
  {
    /**
     * @brief Node for linked list.
     *
     * @tparam T The generic type requires the implementation of the ComparisonConcept and CopyConcept.
     */
    template <typename T>
    struct Node
    {
      T data;
      Node *next;
      virtual ~Node() = default;
    };

    /**
     * @brief Linked list.
     *
     * @tparam T Requires the implementation of the ComparisonConcept and CopyConcept.
     */
    template <typename T>
    class LinkedList : implements List<T>
    {
    private:
      Node<T> *first;
      unsigned int size;
      T defaultValue;

    public:
      LinkedList() : first(nullptr), size(0)
      {
      }

      ~LinkedList()
      {
        Node<T> *current = first;
        while (current != nullptr)
        {
          Node<T> *next = current->next;
          delete current;
          current = next;
        }
      }

    private:
      bool hasNext(Node<T> *node) { return node->next != nullptr; }

    public:
      void add(const T &element) override
      {
        Node<T> *node = new Node<T>;
        node->data = element;
        node->next = first;
        first = node;
        size++;
      }

      void insert(const T &element, unsigned int index) override
      {
        if (index >= size)
          return;
        Node<T> *current = first;
        unsigned int cntr = 0;
        while (current != nullptr && current->data != element)
        {
          if (index == cntr)
            break;
          current = current->next;
          cntr++;
        }
        if (current != nullptr)
          current->data = element;
      }

      T remove(unsigned int index) override
      {
        T temp = getErrorValue();
        if (index < size)
        {
          Node<T> *current = first;
          Node<T> *previous = nullptr;
          unsigned int currentIndex = 0;
          while (current != nullptr && currentIndex != index)
          {
            previous = current;
            current = current->next;
            currentIndex++;
          }
          if (current != nullptr)
          {
            if (previous == nullptr)
              first = current->next;
            else
              previous->next = current->next;
            temp = current;
            delete current;
            size--;
            return temp;
          }
        }
        return temp;
      }

      T removeFirst(T &element) override
      {
        // TODO
        return getErrorValue();
      }

      T removeWhere(bool (*func)(T element)) override
      {
        T temp = getErrorValue();
        for (unsigned int i = 0; i < size; i++)
        {
          if (func(get(i)))
          {
            remove(i);
            return temp;
          }
        }
        return temp;
      }

      T get(unsigned int index) override
      {
        if (index >= size)
          return defaultValue;
        Node<T> *current = first;
        unsigned int currentIndex = 0;
        while (current != nullptr && currentIndex != index)
        {
          current = current->next;
          currentIndex++;
        }
        return current != nullptr ? current->data : defaultValue;
      }

      T getWhere(bool (*func)(T element)) override
      {
        T temp;
        for (unsigned int i = 0; i < size; i++)
          if (func((temp = get(i))))
            return temp;
        return getErrorValue();
      }

      void foreach (void (*func)(T element))
      {
        Node<T> *current = first;
        while (current != nullptr)
        {
          func(current->data);
          current = current->next;
        }
      }

      bool exists(T element) const override
      {
        Node<T> *current = first;
        while (current != nullptr && current->data != element)
          current = current->next;
        return current != nullptr;
      }

      const char* toString() const
      {
        if (Utils::IsSame<T, char>::check)
        {
          char* str = new char[size + 1];
          Node<T> *current = first;
          unsigned int index = 0;
          while (current != nullptr && index < size)
          {
            str[index++] = current->data;
            current = current->next;
          }
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

      void setErrorValue(T defaultValue) override { this->defaultValue = defaultValue; }
    };
  }
}
