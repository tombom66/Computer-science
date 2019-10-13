#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CookieCutter, OutputFormat) {
  std::string unittest_output =
      "How many cookies do you need to cut? "
      "Cookie-cutting-machine Options\n"
      "1. Slow and steady\n"
      "2. Well-paced\n"
      "3. Hi-speed\n"
      "Which cookie cutter machine do you want to use? "
      "It will take 5 minutes to cut 5 cookie(s).\n";
  ASSERT_EXECIO_EQ("main", "5 1", unittest_output);
}

TEST(CookieCutter, ValidMachines) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int num_cookies = rand() % 5000 + 1;
    int type = rand() % 3 + 1;
    std::string input =
        std::to_string(num_cookies) + " " + std::to_string(type);
    int duration = num_cookies / type;
    std::string unittest_output =
        "How many cookies do you need to cut? "
        "Cookie-cutting-machine Options\n"
        "1. Slow and steady\n"
        "2. Well-paced\n"
        "3. Hi-speed\n"
        "Which cookie cutter machine do you want to use? ";
    unittest_output += "It will take " + std::to_string(duration) +
                       " minutes to cut " + std::to_string(num_cookies) +
                       " cookie(s).\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
