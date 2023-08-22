#include "System/Main.h"


int main()
{
  SimpleOS::Main *sys = new SimpleOS::Main;

  if (sys->boot().getError() != SimpleOS::Error::ErrorCode::NO_ERROR)
    sys->boot().runTreatment();

  while (sys->execute().getError() == SimpleOS::Error::ErrorCode::NO_ERROR)
    ;
  sys->execute().runTreatment();

  return 0;
}
