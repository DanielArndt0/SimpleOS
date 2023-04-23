#include "SimpleOS/System.h"

SimpleOS::System sys;
int main()
{
  sys.startup();
  while (true)
    sys.run();

  return 0;
}