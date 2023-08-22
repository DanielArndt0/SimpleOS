#include "Thread.h"

SimpleOS::Root::Thread::Thread() : threadFunction(nullptr), threadParams(nullptr), intermittency(0), resumed(false) {}

SimpleOS::Root::Thread::~Thread()
{
  if (destructor != nullptr)
    destructor();
}

SimpleOS::Root::Thread::Thread(void (*threadFunction)(void *), unsigned long intermittency, void *threadParams) : intermittency(intermittency), resumed(true)
{
  this->threadFunction = threadFunction;
  this->threadParams = threadParams;
}

SimpleOS::Root::Thread::Thread(const SimpleOS::Root::Thread &other) : intermittency(other.intermittency), resumed(other.resumed)
{
  this->threadFunction = other.threadFunction;
  this->threadParams = other.threadParams;
}

SimpleOS::Root::Thread::Thread(SimpleOS::Root::Thread &&other) : intermittency(other.intermittency), resumed(other.resumed)
{
  this->threadFunction = other.threadFunction;
  this->threadParams = other.threadParams;
  other.threadFunction = nullptr;
  other.threadParams = nullptr;
}

SimpleOS::Root::Thread &SimpleOS::Root::Thread::operator=(const SimpleOS::Root::Thread &other)
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

SimpleOS::Root::Thread &SimpleOS::Root::Thread::operator=(SimpleOS::Root::Thread &&other)
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

unsigned long SimpleOS::Root::Thread::getIntermittency() const { return intermittency; }

void SimpleOS::Root::Thread::setIntermittency(unsigned long intermittency) { this->intermittency = intermittency; }

void SimpleOS::Root::Thread::stop() { resumed = false; }

void SimpleOS::Root::Thread::resume() { resumed = true; }

void SimpleOS::Root::Thread::setDestructor(void (*destructor)()) { this->destructor = destructor; }

void SimpleOS::Root::Thread::execute()
{
  if (threadFunction != nullptr && resumed)
    threadFunction(threadParams);
}

bool SimpleOS::Root::Thread::equals(const Thread &other) const { return this->id == other.id; }
