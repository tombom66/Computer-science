#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include "gtest_ext.h"
#include "../power.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(Power, OutputFormat)
{
  std::string unittest_output = "Please enter the base number: "
                      "Please enter the power: "
                      "5 ^ 3 = 125\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("main", "5 3", unittest_output);
  });
}

TEST(Power, PositiveBase)
{
  srand (time(NULL));
  for(int i = 0; i < 30; i++)
  {
    int random_positive_base = (rand() % 15) + 1,
        random_positive_power = (rand() % 5) + 1;
    int unittest_output = static_cast<int>(pow(random_positive_base,random_positive_power));
    std::string message = "Input: " + std::to_string(random_positive_base) +
                          " " + std::to_string(random_positive_power) + "\n";
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(power(random_positive_base, random_positive_power), unittest_output)
      << message;
    });
  }
}

TEST(Power, NegativeBase)
{
  srand (time(NULL));
  for(int i = 0; i < 30; i++)
  {
    int random_negative_base = -(rand() % 15) + 1,
        random_positive_power = (rand() % 5) + 1;
    int unittest_output = static_cast<int>(pow(random_negative_base,random_positive_power));
    std::string message = "Input: " + std::to_string(random_negative_base) +
                          " " + std::to_string(random_positive_power) + "\n";
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(power(random_negative_base, random_positive_power),
                unittest_output)
          << message;
    });
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
