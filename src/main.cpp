#include "SimpleOS/Main.h"

SimpleOS::Main sys;
int main()
{
  sys.startup();
  while (true)
    sys.run();
  return 0;
}