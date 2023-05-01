#pragma once
#include "DataTypes/Sequence/ContainerStruct/ContainerAllocator.h"
#include "DataTypes/Typedefs.h"
#include "SimpleOS/Macros.h"
#include "DataTypes/Object/Object.h"

namespace SimpleOS
{
  namespace Data
  {
    template <typename T>
    class ArrayContainer : extends Root::ContainerAllocator<T, 10> ,  Root::Object
    {
    private:
      T m_err;

    protected:
      bool cIsEmpty() const { return (this->m_data_struct == nullptr || !this->m_length); }

      unsigned long cSize() const { return this->m_length; }

      T cError() const { return m_err; }

      bool cExist(T value) const
      {
        if (this->m_data_struct)
        {
          for (Index i = 0; i < this->m_length; i++)
            if (this->m_data_struct[i] == value)
              return true;
        }
        return false;
      }

      unsigned long cGetPoolSize() const { return this->m_buffer_length; }

      T cGet(Index key) const
      {
        if (key < this->m_length)
          return this->m_data_struct[key];
        return m_err;
      }

      Index cGetIndex(T value) const
      {
        for (unsigned long i = 0; i < this->m_length; i++)
          if (value == this->m_data_struct[i])
            return i;
        return 0;
      }

      T cPut(Index key, T value)
      {
        if (key < this->m_length)
          return (this->m_data_struct[key] = value);
        return m_err;
      }

      T cPushFront(T value) { return cPush(0x00, value); }

      T cPushBack(T value) { return cPush(this->m_length, value); }

      T cPush(Index key, T value)
      {
        if (this->m_data_struct)
        {
          this->reallocUp();
          this->shiftPush(key);
          this->m_data_struct[key] = value;
          return this->m_data_struct[key];
        }
        return m_err;
      }

      T cPopFront() { return cPop(0x00); }

      T cPopBack() { return cPop(this->m_length - 1); }

      T cPop(Index key)
      {
        if (this->m_data_struct && key < this->m_buffer_length)
        {
          T tmp = this->m_data_struct[key];
          this->shiftPop(key);
          this->reallocDown();
          return tmp;
        }
        return m_err;
      }

      T cPop(T value)
      {
        for (unsigned long i = 0; i < this->m_length; i++)
          if (value == this->m_data_struct[i])
            return i;
        return m_err;
      }

      void cReset()
      {
        this->Del();
        this->Alloc();
      }

      void cDelete() { this->Del(); }

      private: 
       C_String toString() override;
    };
  }
}
