#pragma once
#include <stdlib.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Data
  {
    class Buffer
    {
    private:
      Data::UChar *buffer;
      Data::UInt bufferSize;

    public:
      Buffer() = delete;
      Buffer(Data::UChar *buffer, Data::UInt bufferSize);
      Buffer(const Buffer &buffer);
      Buffer(const Buffer &&buffer);
      ~Buffer();

    public:
      template <typename T>
      void write(T data, Data::UInt addr);
      template <typename T>
      T read(Data::UInt addr);

      Data::UInt size();
      Data::UChar *getBuffer();
      void freeBuffer();
    };

    template <class T>
    T Buffer::read(Data::UInt addr)
    {
      T t;
      if (addr >= bufferSize || buffer == nullptr)
        return t;
      for (Data::UInt i = 0x00; i < sizeof(T); i++)
        t |= (T)buffer[addr + i] << (i * 8);
      return t;
    }

    template <class T>
    void Buffer::write(T data, Data::UInt addr)
    {
      if (addr >= bufferSize || buffer == nullptr)
        return;
      for (Data::UInt i = 0x00; i < sizeof(T); i++)
        buffer[addr + i] = data >> (8 * i) & 0xFF;
    }
  }
}