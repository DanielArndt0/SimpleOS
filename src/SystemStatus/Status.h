#pragma once
#include "SystemStatus/ErrorCode.h"

namespace SimpleOS
{
  namespace Handler
  {
    class Status
    {
    private:
      Error::ErrorCode error;
      void (*errFunc)(void *params);
      void *params;

    public:
      Status(Error::ErrorCode error, void (*errFunc)(void *params), void *params) : error(error), errFunc(errFunc), params(params) {}
      Status(Error::ErrorCode error) : error(error), errFunc(nullptr), params(nullptr) {}
      Status() : error(Error::ErrorCode::NO_ERROR), errFunc(nullptr), params(nullptr) {}

    public:
      Error::ErrorCode getError() { return error; }

      void runTreatment()
      {
        if (hasTreatment())
          errFunc(params);
      }

      bool hasTreatment() { return errFunc != nullptr; }
    }; // class Status
  }    // namespace Handler
} // namespace SimpleOS
