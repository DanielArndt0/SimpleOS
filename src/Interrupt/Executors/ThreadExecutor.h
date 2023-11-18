#pragma once
#include "System/Base.h"
#include "DataTypes/Containers/List/ArrayList.h"
#include "Core/Thread/Thread.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class ThreadExecutor
    {
    private:
      bool enabled = true;

    protected:
      virtual Data::ArrayList<Core::Thread *> &list() = 0;

      Data::Index
      getIndexByThreadId(Data::ID threadId)
      {
        for (Data::Size i = 0; i < list().getSize(); i++)
          if (list().get(i)->id == threadId)
            return i;
        return -1;
      }

    public:
      ThreadExecutor() = default;
      ~ThreadExecutor() = default;

    public:
      bool isEnabled() { return enabled; }

      bool setEnabled(bool enabled) { return ThreadExecutor::enabled = enabled; }

      void execute()
      {
        if (!list().isEmpty())
        {
          for (unsigned int i = 0; i < list().getSize(); i++)
          {
            auto th = list().get(i);
            th->ticks.increment();
            if (th->ticks == th->getIntermittency())
            {
              th->execute();
              th->ticks.reset();
            }
          }
        }
      }

      bool add(Core::Thread *thread)
      {
        bool temp;
        if (!(temp = list().exists(thread)))
          list().add(thread);
        return temp;
      }

      bool remove(Data::ID threadId)
      {
        int index = getIndexByThreadId(threadId);
        if (index < 0)
          return false;
        delete list().remove(index);
        return true;
      }

      bool stop(Data::ID threadId)
      {
        int index = getIndexByThreadId(threadId);
        if (index < 0)
          return false;
        list().get(index)->stop();
        return true;
      }

      void stopAll()
      {
        list().foreach ([](Core::Thread *element) -> void
                        { element->stop(); });
      }

      bool resume(Data::ID threadId)
      {
        int index = getIndexByThreadId(threadId);
        if (index < 0)
          return false;
        list().get(index)->resume();
        return true;
      }

      void resumeAll()
      {
        list().foreach ([](Core::Thread *element) -> void
                        { element->resume(); });
      }
    }; // class ThreadExecutor
  }    // namespace Interrupt
} // namespace SimpleOS
