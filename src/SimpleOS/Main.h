#pragma once
#include "SimpleOS/System.h"
#include "Models/Person.h"

#define S_ADDR 0x0100
#define E_ADDR 0x08FF
#define VALUE(addr) ((unsigned)(*(volatile unsigned char *)(addr)))

namespace SimpleOS
{
  using namespace Com;
  using namespace Memory;
  using namespace Data;
  using namespace Operators;
  using namespace Hardware;
  using namespace Native;
  using namespace Root::Task;

  class Main : extends System<SYSM_HEAP_SIZE>
  {
  public:
    template <typename T>
    static constexpr T getArgs(void *args, int index = 0) { return reinterpret_cast<T>(reinterpret_cast<void **>(args)[index]); }

    static void task(void *args)
    {
      serial << getArgs<const char *>(args) << getArgs<const char *>(args, 1) << endl;
    }

    Int startup() override
    {
      void *params[] = {(void *)"Hello, ", (void *)"World!"};

      

      TaskExample taskPrint(TaskProperties(1, 128, task, params));
      TaskController controller(taskPrint);
      controller.start();



      return 0;
    }

    Int run() override
    {
      return 0;
    }
  };
}