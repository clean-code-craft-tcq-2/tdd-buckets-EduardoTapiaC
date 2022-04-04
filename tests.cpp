#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "current_measurements.h"

TEST_CASE("count hits in one range") {
  int arrayValues[2] = {4,5};
  char result[] = "4-5, 2\n";
  REQUIRE(strcmp(detectRanges(arrayValues, 2), result) == 0);
}

TEST_CASE("count hits in multiple ranges") {
  int arrayValues[] = {4, 5, 7, 8, 9};
  char result[] = "4-5, 2\n7-9, 3\n";
  REQUIRE(strcmp(detectRanges(arrayValues, 5), result) == 0);
}

TEST_CASE("repeated value list") {
  int arrayValues[] = {5, 5, 5, 5, 8};
  char result[] = "5-5, 4\n8-8, 1\n";
  REQUIRE(strcmp(detectRanges(arrayValues, 5), result) == 0);
}

TEST_CASE("unorderded list") {
  int arrayValues[] = {15, 5, 50, 80, 45};
  char result[] = "5-5, 1\n15-15, 1\n45-45, 1\n50-50, 1\n80-80, 1\n";
  REQUIRE(strcmp(detectRanges(arrayValues, 5), result) == 0);
}