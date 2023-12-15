#include "Thread.h"

SimpleOS::Core::Thread::Thread() : threadFunction(nullptr), threadParams(nullptr), intermittency(0), resumed(false) {}

SimpleOS::Core::Thread::~Thread()
{
  if (destructor != nullptr)
    destructor();
}

SimpleOS::Core::Thread::Thread(void (*threadFunction)(void *), unsigned long intermittency, void *threadParams) : intermittency(intermittency), resumed(true)
{
  this->threadFunction = threadFunction;
  this->threadParams = threadParams;
}

SimpleOS::Core::Thread::Thread(const SimpleOS::Core::Thread &other) : intermittency(other.intermittency), resumed(other.resumed)
{
  this->threadFunction = other.threadFunction;
  this->threadParams = other.threadParams;
}

SimpleOS::Core::Thread::Thread(SimpleOS::Core::Thread &&other) : intermittency(other.intermittency), resumed(other.resumed)
{
  this->threadFunction = other.threadFunction;
  this->threadParams = other.threadParams;
  other.threadFunction = nullptr;
  other.threadParams = nullptr;
}

SimpleOS::Core::Thread &SimpleOS::Core::Thread::operator=(const SimpleOS::Core::Thread &other)
{
  if (this != &other)
  {
    resumed = other.resumed;
    intermittency = other.intermittency;
    threadFunction = other.threadFunction;
    threadParams = other.threadParams;
  }
  return *this;
}

SimpleOS::Core::Thread &SimpleOS::Core::Thread::operator=(SimpleOS::Core::Thread &&other)
{
  if (this != &other)
  {
    resumed = other.resumed;
    intermittency = other.intermittency;
    threadFunction = other.threadFunction;
    threadParams = other.threadParams;
    other.intermittency = 0;
    other.resumed = 0;
    other.threadFunction = nullptr;
    other.threadParams = nullptr;
  }
  return *this;
}

unsigned long SimpleOS::Core::Thread::getIntermittency() const { return intermittency; }

void SimpleOS::Core::Thread::setIntermittency(unsigned long intermittency) { this->intermittency = intermittency; }

void SimpleOS::Core::Thread::stop() { resumed = false; }

void SimpleOS::Core::Thread::resume() { resumed = true; }

void SimpleOS::Core::Thread::setDestructor(void (*destructor)()) { this->destructor = destructor; }

void SimpleOS::Core::Thread::execute()
{
  if (threadFunction != nullptr && resumed)
    threadFunction(threadParams);
}

bool SimpleOS::Core::Thread::equals(const Thread &other) const { return this->id == other.id; }
