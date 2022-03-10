#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "current_measurements.h"

TEST_CASE("test low current ranges") {
  int currentValues[2] = {4,5};
  REQUIRE(detectRange(currentValues, 2) == 2);
}