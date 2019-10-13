#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Range, OutputFormat) {
  std::string unittest_output =
      "Please enter the low number for this range: Please enter "
      "the high number for this range: Please choose a number to "
      "check in range: 5 is in range [1,10]\n";
  ASSERT_EXECIO_EQ("main", "1 10 5", unittest_output);
}

TEST(Range, InRange) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int low = rand() % 5, high = (rand() % 5) + 10, choice = 5;
    std::string unittest_output =
        "Please enter the low number for this range: Please enter "
        "the high number for this range: Please choose a number to "
        "check in range: ";
    unittest_output += std::to_string(choice) + " is in range [" +
                       std::to_string(low) + "," + std::to_string(high) + "]\n";
    std::string input = std::to_string(low) + " " + std::to_string(high) + " 5";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Range, OutOfRange) {
  for (int i = 0; i < 10; i++) {
    int low = rand() % 5, high = (rand() % 5) + 10, choice = 20;
    std::string unittest_output =
        "Please enter the low number for this range: Please enter "
        "the high number for this range: Please choose a number to "
        "check in range: ";
    unittest_output += std::to_string(choice) + " isn't in range [" +
                       std::to_string(low) + "," + std::to_string(high) + "]\n";
    std::string input =
        std::to_string(low) + " " + std::to_string(high) + " 20";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
