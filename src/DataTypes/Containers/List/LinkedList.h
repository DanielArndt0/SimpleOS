#pragma once
#include "System/Base.h"
#include "Root/RamAllocator/RamAllocator.h"
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
          Root::RamAllocator<SYSM_HEAP_SIZE>::free(current);
          current = next;
        }
      }

    private:
      bool hasNext(Node<T> *node) { return node->next != nullptr; }

    public:
      void add(const T &element) override
      {
        Node<T> *node = (Node<T> *)Root::RamAllocator<SYSM_HEAP_SIZE>::malloc(sizeof(Node<T>));
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

      // CHECK It works, but causes conflict with index removal if the type of data is numerical
      // void remove(const T &element) 
      // {
      //   Node<T> *current = first;
      //   Node<T> *previous = nullptr;
      //   while (current != nullptr && current->data != element)
      //   {
      //     previous = current;
      //     current = current->next;
      //   }
      //   if (current != nullptr)
      //   {
      //     if (previous == nullptr)
      //       first = current->next;
      //     else
      //       previous->next = current->next;
      //     Root::RamAllocator<SYSM_HEAP_SIZE>::free(current);
      //     size--;
      //   }
      // }

      void remove(unsigned int index) override
      {
        if (index >= size)
          return;
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
          Root::RamAllocator<SYSM_HEAP_SIZE>::free(current);
          size--;
        }
      }

      T &get(unsigned int index) override
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

      void foreach (void (*func)(T &element))
      {
        Node<T> *current = first;
        while (current != nullptr)
        {
          operacao(current->data);
          current = current->next;
        }
      }

      bool exists(T &element) const override
      {
        Node<T> *current = first;
        while (current != nullptr && current->data != element)
          current = current->next;
        return current != nullptr;
      }

      bool isEmpty() const override { return size == 0; }

      unsigned int getSize() const override { return size; }

      const T &getDefaultValue() const override { return defaultValue; }

      void setDefaultValue(T defaultValue) override { defaultValue = defaultValue; }
    };
  }
}
