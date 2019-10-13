#include "../power.hpp"
#include "gtest_ext.h"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(Power, OutputFormat) {
  std::string unittest_output = "Enter a base: "
                                "Enter an exponent: "
                                "5 ^ 3 = 125\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "5 3", unittest_output); });
}

TEST(Power, PowerTest) {
  for (int i = 0; i < 10; i++) {
    int unittest_random_base = (rand() % 10) + 1;
    int unittest_random_exp = (rand() % 5) + 1;
    ASSERT_DURATION_LE(3, {
      int unittest_output =
          static_cast<int>(pow(unittest_random_base, unittest_random_exp));
      ASSERT_EQ(power(unittest_random_base, unittest_random_exp),
                unittest_output)
          << "   Input: " << unittest_random_base << " " << unittest_random_exp;
    });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
