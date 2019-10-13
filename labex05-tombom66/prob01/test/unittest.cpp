#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(Summation, OutputFormat)
{
  std::string unittest_output = "Please enter a number: "
  "How many times to be added: "
  "The summation is 50\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("main", "5 10", unittest_output);
  });
}

TEST(Summation, Summation)
{
  srand(time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string unittest_output = "Please enter a number: "
    "How many times to be added: ";
    int n = rand() % 100 + 1;
    int timesAdded = rand() % 20 + 1;
    int total = 0;
    for(int i = 0; i < timesAdded; i++)
    {
      total += n;
    }
    std::string input = std::to_string(n) + " " + std::to_string(timesAdded);
    unittest_output += "The summation is " + std::to_string(total) + "\n";
    ASSERT_DURATION_LE(3, {
      ASSERT_EXECIO_EQ("main", input, unittest_output);
    });

  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
