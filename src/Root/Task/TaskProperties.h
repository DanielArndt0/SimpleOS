#pragma once
#include "SimpleOS/Base.h"
#include "DataTypes/Typedefs.h"
#include "Communication/UART/UART.h"

namespace SimpleOS
{
  namespace Beta
  {
    namespace Tasks
    {
      enum class State
      {
        creating = 0,
        starting,
        resuming,
        running,
        pausing,
        suspending,
        terminating,
        restarting,
        created = 100,
        started,
        resumed,
        paused,
        suspended,
        terminated,
        restarted,
        create = 200,
        start,
        resume,
        pause,
        suspend,
        terminate,
        restart,
        null = 300
      };

      class Properties
      {
      private:
        static Data::ID idCounter;

      public:
        Data::ID id;
        State state;
        Data::UInt priority;
        Data::UChar *stackPointer;
        Data::UInt stackCounter;
        Data::UInt stackSize;
        void (*taskFunction)(void *);
        void *taskParams;

      public:
        Properties()
            : id(0),
              state(State::created),
              priority(0),
              stackPointer(nullptr),
              stackCounter(0),
              stackSize(0),
              taskFunction(nullptr),
              taskParams(nullptr)
        {
        }

        Properties(Data::UInt priority, Data::UInt stackSize, void (*taskFunction)(void *), void *params)
            : id(idCounter++),
              state(State::created),
              priority(priority),
              stackPointer(nullptr),
              stackCounter(0),
              stackSize(stackSize),
              taskFunction(taskFunction),
              taskParams(params)
        {
        }

        Properties(const Properties &other)
            : id(idCounter++),
              state(other.state),
              priority(other.priority),
              stackPointer(other.stackPointer),
              stackCounter(other.stackCounter),
              stackSize(other.stackSize),
              taskFunction(other.taskFunction),
              taskParams(other.taskParams)
        {
        }

        Properties(Properties &&other) noexcept
            : id(idCounter++),
              state(other.state),
              priority(other.priority),
              stackPointer(other.stackPointer),
              stackCounter(other.stackCounter),
              stackSize(other.stackSize),
              taskFunction(other.taskFunction),
              taskParams(other.taskParams)
        {
          other.state = State::null;
          other.priority = 0;
          other.stackPointer = nullptr;
          other.stackCounter = 0;
          other.stackSize = 0;
          other.taskFunction = nullptr;
          other.taskParams = nullptr;
        }

      public:
        Properties &operator=(const Properties &other)
        {
          if (this != &other)
          {
            state = other.state;
            priority = other.priority;
            stackPointer = other.stackPointer;
            stackCounter = other.stackCounter;
            stackSize = other.stackSize;
            taskFunction = other.taskFunction;
            taskParams = other.taskParams;
          }
          return *this;
        }

        Properties &operator=(Properties &&other) noexcept
        {
          if (this != &other)
          {
            state = other.state;
            priority = other.priority;
            stackPointer = other.stackPointer;
            stackCounter = other.stackCounter;
            stackSize = other.stackSize;
            taskFunction = other.taskFunction;
            taskParams = other.taskParams;
            other.state = State::null;
            other.priority = 0;
            other.stackPointer = nullptr;
            other.stackCounter = 0;
            other.stackSize = 0;
            other.taskFunction = nullptr;
            other.taskParams = nullptr;
          }
          return *this;
        }

        ~Properties()
        {
          Root::VRam<SYSM_HEAP_SIZE>::free(stackPointer);
          stackCounter = 0;
          stackSize = 0;
        }
      };
      SimpleOS::Data::ID SimpleOS::Beta::Tasks::Properties::idCounter;

      class Lifecycle
      {
      protected:
        virtual void onCreate() = 0;
        virtual void onStart() = 0;
        virtual void onResume() = 0;
        virtual void onPause() = 0;
        virtual void onSuspend() = 0;
        virtual void onTerminate() = 0;
        virtual void onRestart() = 0;

      protected:
        virtual ~Lifecycle() = default;
      };

      class TaskController : implements Lifecycle
      {
      protected:
        Properties properties;

      protected:
        TaskController(const Properties &properties) : properties(properties) { onCreate(); }

      protected:
        virtual void onCreate() { properties.state = State::created; }
        virtual void onStart() { properties.state = State::starting; }
        virtual void onResume()
        {
          properties.state = State::resumed;
          properties.taskFunction(properties.taskParams);
        }
        virtual void onPause() { properties.state = State::paused; }
        virtual void onSuspend() { properties.state = State::suspended; }
        virtual void onTerminate() { properties.state = State::terminated; }
        virtual void onRestart() { properties.state = State::restarting; }

      public:
        void start()
        {
          onStart();
          onResume();
        }

        void restart()
        {
          onRestart();
          onStart();
          onResume();
        }

        void pause()
        {
          onPause();
        }

        void resume()
        {
          onResume();
        }

        void stop()
        {
          onSuspend();
          onTerminate();
        }

      protected:
        virtual ~TaskController() = default;
      };

      class Task : extends TaskController
      {
      public:
        Task(const Properties &properties) : TaskController(properties) {}
      };
    }
  }
}