#pragma once

namespace SimpleOS
{
  namespace Root
  {
    namespace Task
    {
      enum class TaskState
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
    } // namespace Task
  }   // namespace Root
} // namespace SimpleOS
