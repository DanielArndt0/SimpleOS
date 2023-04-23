#include "DataTypes/Buffer/Buffer.h"

SimpleOS::Data::Buffer::Buffer(SimpleOS::Data::UChar *buffer, SimpleOS::Data::UInt bufferSize) : buffer(buffer), bufferSize(bufferSize) {}

SimpleOS::Data::Buffer::Buffer(const SimpleOS::Data::Buffer &buffer) : buffer(buffer.buffer), bufferSize(buffer.bufferSize) {}

SimpleOS::Data::Buffer::Buffer(const SimpleOS::Data::Buffer &&buffer) : buffer(buffer.buffer), bufferSize(buffer.bufferSize){}

SimpleOS::Data::Buffer::~Buffer() { freeBuffer(); }

SimpleOS::Data::UInt SimpleOS::Data::Buffer::size() { return bufferSize; }

SimpleOS::Data::UChar *SimpleOS::Data::Buffer::getBuffer() { return buffer; }

void SimpleOS::Data::Buffer::freeBuffer()
{
  if (buffer)
  {
    delete[] buffer;
    buffer = nullptr;
  }
}