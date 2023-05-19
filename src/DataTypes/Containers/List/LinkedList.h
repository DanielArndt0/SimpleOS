#pragma once
#include "SimpleOS/Base.h"
#include "Root/RamAllocator/RamAllocator.h"

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
    class LinkedList
    {
    private:
      Node<T> *first;
      SimpleOS::Data::UInt size;
      T sentinelValue;

    private:
      Root::RamAllocator<SYSM_HEAP_SIZE> vram;

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
          vram.free(current);
          current = next;
        }
      }

    private:
      bool hasNext(Node<T> *node) { return node->next != nullptr; }

    public:
      void add(T value)
      {
        Node<T> *node = (Node<T> *)vram.malloc(sizeof(Node<T>));
        node->data = value;
        node->next = first;
        first = node;
        size++;
      }

      void set(SimpleOS::Data::Index index, T value)
      {
        if (index >= size)
          return;
        Node<T> *current = first;
        SimpleOS::Data::Index cntr = 0;
        while (current != nullptr && current->data != value)
        {
          if (index == cntr)
            break;
          current = current->next;
          cntr++;
        }
        if (current != nullptr)
          current->data = value;
      }

      void remove(T value)
      {
        Node<T> *current = first;
        Node<T> *previous = nullptr;
        while (current != nullptr && current->data != value)
        {
          previous = current;
          current = current->next;
        }
        if (current != nullptr)
        {
          if (previous == nullptr)
            first = current->next;
          else
            previous->next = current->next;
          vram.free(current);
          size--;
        }
      }

      T &get(SimpleOS::Data::Index index)
      {
        if (index >= (signed)size)
          return sentinelValue;
        Node<T> *current = first;
        SimpleOS::Data::Index cntr = 0;
        while (current != nullptr)
        {
          if (index == cntr)
            break;
          current = current->next;
          cntr++;
        }
        return current != nullptr ? current->data : sentinelValue;
      }

      bool exists(T value)
      {
        Node<T> *current = first;
        while (current != nullptr && current->data != value)
          current = current->next;
        return current != nullptr;
      }

      void foreach (void (*operacao)(T &value))
      {
        Node<T> *current = first;
        while (current != nullptr)
        {
          operacao(current->data);
          current = current->next;
        }
      }

      LinkedList<T> &setDefaultValue(T defaultValue)
      {
        sentinelValue = defaultValue;
        return *this;
      }

      T getDefaultValue() { return sentinelValue; }

      SimpleOS::Data::UInt getSize() const { return size; }
    };
  }
}
