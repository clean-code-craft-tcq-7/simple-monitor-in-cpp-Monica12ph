#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, TemperatureNormalRange) {
  ASSERT_TRUE(isTemperatureNormal(98.6));
  ASSERT_TRUE(isTemperatureNormal(95));
  ASSERT_TRUE(isTemperatureNormal(102));
  ASSERT_FALSE(isTemperatureNormal(94.9));
  ASSERT_FALSE(isTemperatureNormal(102.1));
}
