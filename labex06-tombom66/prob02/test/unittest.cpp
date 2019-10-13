#include "../identifychar.hpp"
#include "gtest_ext.h"
#include <cmath>
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>
using ::testing::ContainsRegex;
using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(IdentifyChar, OutputFormat) {
  std::string unittest_output = "Please enter a character: "
                                "a is a letter\n";
  ASSERT_EXECIO_EQ("main", "a", unittest_output);
  unittest_output = "Please enter a character: "
                    "1 is a number\n";
  ASSERT_EXECIO_EQ("main", "1", unittest_output);
  unittest_output = "Please enter a character: "
                    "% is a special character\n";
  ASSERT_EXECIO_EQ("main", "%", unittest_output);
}

TEST(IdentifyChar, Letters) {
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    int rand_int;
    do {
      rand_int = rand() % 58 + 65;
    } while (rand_int >= 91 && rand_int <= 96);

    char c = static_cast<char>(rand_int);
    std::string unittest_input = "";
    unittest_input += c;
    std::string unittest_output = "";
    unittest_output += c;
    unittest_output += " is a letter\n";
    ASSERT_SIO_EQ(unittest_input, unittest_output, { identify_char(c); });
  }
}

TEST(IdentifyChar, Numbers) {
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    char c = static_cast<char>(rand() % 10 + 48);
    std::string unittest_input = "";
    unittest_input += c;
    std::string unittest_output = "";
    unittest_output += c;
    unittest_output += " is a number\n";
    ASSERT_SIO_EQ(unittest_input, unittest_output, { identify_char(c); });
  }
}

TEST(IdentifyChar, SpecialCharacter) {
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    int rand_int;
    do {
      rand_int = rand() % 95 + 32;
    } while ((rand_int >= 48 && rand_int <= 57) ||
             (rand_int >= 65 && rand_int <= 90) ||
             (rand_int >= 97 && rand_int <= 122) || rand_int == 34 ||
             rand_int == 92 || rand_int == 96);

    char c = static_cast<char>(rand_int);
    std::string unittest_input = "";
    unittest_input += c;
    std::string unittest_output = "";
    unittest_output += c;
    unittest_output += " is a special character\n";

    ASSERT_SIO_EQ(unittest_input, unittest_output, { identify_char(c); });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
