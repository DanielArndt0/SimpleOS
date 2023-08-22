#pragma once
#include "System/Base.h"
#include "Time/Counter/Counter.h"
#include "DataTypes/String/SimpleString/SimpleString.h"

namespace SimpleOS
{
  namespace Root
  {
    class Thread
        : implements Concepts::Executable<void>,
          implements Concepts::Equatable<Thread>,
          implements Concepts::Identifiable<Thread>
    {
    private:
      void (*threadFunction)(void *);
      void (*destructor)(void) = nullptr;
      void *threadParams;
      unsigned long intermittency;
      bool resumed;

    public:
      Time::Counter ticks;

    public:
      Thread();
      ~Thread();

    public:
      Thread(void (*taskFunction)(void *), unsigned long intermittency = 1, void *params = nullptr);
      Thread(const Thread &other);
      Thread(Thread &&other);

    public:
      Thread &operator=(const Thread &other);
      Thread &operator=(Thread &&other);

      unsigned long getIntermittency() const;
      void setIntermittency(unsigned long intermittency);

      void stop();
      void resume();

      void setDestructor(void (*destructor)(void));

      void execute() override;
      bool equals(const Thread &cmp) const override;
    }; // class Thread
  }    // namespace Root
} // namespace SimpleOS
