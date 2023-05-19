#pragma once

namespace SimpleOS
{
  namespace Root
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
  } // namespace Root
} // namespace SimpleOS
