#pragma once
#include "System/Base.h"
#include "Interrupt/Executors/ThreadExecutor.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class WatchdogExecutor : extends ThreadExecutor
    {
    private:
      Data::ArrayList<Root::Thread *> threadList;
      Data::ArrayList<Root::Thread *> &list() override { return threadList; }

      // private:
      //   static Data::ArrayList<Root::Thread *> threadList;
      //   static bool enabled;

      // private:
      //   WatchdogExecutor() = default;
      //   ~WatchdogExecutor() = default;

      // private:
      //   static Data::Index getIndexByThreadId(Data::ID threadId)
      //   {
      //     for (Data::Size i = 0; i < threadList.getSize(); i++)
      //       if (threadList.get(i)->id == threadId)
      //         return i;
      //     return -1;
      //   }

      // public:
      //   static bool isEnabled() { return enabled; }

      //   static bool setEnabled(bool enabled) { return WatchdogExecutor::enabled = enabled; }

      //   static void execute()
      //   {
      //     if (!threadList.isEmpty())
      //     {
      //       for (unsigned int i = 0; i < threadList.getSize(); i++)
      //       {
      //         auto th = threadList.get(i);
      //         th->ticks.increment();
      //         if (th->ticks == th->getIntermittency())
      //         {
      //           th->execute();
      //           th->ticks.reset();
      //         }
      //       }
      //     }
      //   }

      //   static bool add(Root::Thread *thread)
      //   {
      //     bool temp;
      //     if (!(temp = threadList.exists(thread)))
      //       threadList.add(thread);
      //     return temp;
      //   }

      //   static bool remove(Data::ID threadId)
      //   {
      //     int index = getIndexByThreadId(threadId);
      //     if (index < 0)
      //       return false;
      //     delete threadList.remove(index);
      //     return true;
      //   }

      //   static bool stop(Data::ID threadId)
      //   {
      //     int index = getIndexByThreadId(threadId);
      //     if (index < 0)
      //       return false;
      //     threadList.get(index)->stop();
      //     return true;
      //   }

      //   static void stopAll()
      //   {
      //     threadList.foreach ([](Root::Thread *element) -> void
      //                         { element->stop(); });
      //   }

      //   static bool resume(Data::ID threadId)
      //   {
      //     int index = getIndexByThreadId(threadId);
      //     if (index < 0)
      //       return false;
      //     threadList.get(index)->resume();
      //     return true;
      //   }

      //   static void resumeAll()
      //   {
      //     threadList.foreach ([](Root::Thread *element) -> void
      //                         { element->resume(); });
      //   }
    }; // class WatchdogExecutor
  }    // namespace Interrupt
} // namespace SimpleOS
