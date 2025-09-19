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
TEST_F(Monitor, NotOkWhenTemperatureIsOutOfRange) {
  ASSERT_FALSE(vitalsOk(105, 102, 70));
}

TEST_F(Monitor, NotOkWhenPulseRateIsOutOfRange) {
  ASSERT_FALSE(vitalsOk(98, 120, 95));
}

TEST_F(Monitor, NotOkWhenSpo2IsOutOfRange) {
  ASSERT_FALSE(vitalsOk(98, 80, 80 ));
}

TEST_F(Monitor, OkWhenAllVitalsAreInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}

TEST_F(Monitor, OkWhenTemperatureIsInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}

TEST_F(Monitor, OkWhenPulseRateIsInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}

TEST_F(Monitor, OkWhenSpo2IsInRange) {
  ASSERT_TRUE(vitalsOk(98, 80, 95 ));
}