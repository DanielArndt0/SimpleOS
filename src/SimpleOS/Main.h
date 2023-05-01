#pragma once
#include "SimpleOS/System.h"
#include "Models/Person.h"

namespace SimpleOS
{
  using namespace Com;
  using namespace Memory;
  using namespace Data;
  using namespace Operators;
  using namespace Hardware;
  using namespace Native;

  class Main : extends System<SYSM_HEAP_SIZE>
  {

  public:
    Int startup() override
    {
      Number<int> i = -32;
      Number<float> f = 43.32;
      Number<unsigned char> c = -15;
      Number<unsigned int> g = 156;
      Number<unsigned char> h = 22;
      int r = 1231;

      serial << r << endl;
      serial << i << endl;
      serial << f << endl;
      serial << c << endl;
      serial << g << endl;
      serial << h << endl;
      serial << &h << endl;

      return 0;
    }

    Int run() override
    {
      return 0;
    }
  };
}