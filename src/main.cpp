#include "System/Main.h"

SimpleOS::Main sys;
int main()
{
  sys.boot();
  while (true)
    sys.execute();
  return 0;
}