#include "../find_number.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(FindNumber, OutputFormat) {
  std::string unittest_output = "2 4 6 8 10 12 14 16 18 20 \n"
                                "2 is in the array\n"
                                "3 is not in the array\n"
                                "10 is in the array\n"
                                "15 is not in the array\n"
                                "16 is in the array\n"
                                "21 is not in the array\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "", unittest_output); });
}

TEST(FindNumber, PublicMethodPresent) {
  Numbers your_numbers;
  your_numbers.getSize();
  your_numbers.getValues();
  int *x = new int[1];
  *x = 1;
  your_numbers.setSize(1);
  your_numbers.setValues(x);
  std::string unittest_output = "1 \n1 is in the array\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", unittest_output, {
      your_numbers.displayArray();
      your_numbers.findNumber(1);
    });
  });
}

TEST(FindNumber, DefaultConstructor) {
  Numbers your_numbers;
  ASSERT_EQ(your_numbers.getSize(), 10);
}

TEST(FindNumber, DisplayArray) {
  Numbers your_numbers;
  int *x = new int[10];
  std::string unittest_output;
  for (int i = 0; i < 10; i++) {
    x[i] = i;
    unittest_output += std::to_string(i) + " ";
  }
  unittest_output += "\n";
  your_numbers.setValues(x);
  ASSERT_DURATION_LE(
      3, { ASSERT_SIO_EQ("", unittest_output, your_numbers.displayArray()); });
}

TEST(FindNumber, FindNumberInArray) {
  Numbers your_numbers;
  int *x = new int[10];
  std::string unittest_output;
  for (int i = 0; i < 10; i++) {
    x[i] = 5;
  }
  your_numbers.setSize(10);
  your_numbers.setValues(x);
  unittest_output += std::to_string(5) + " is in the array\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_SIO_EQ("", unittest_output, your_numbers.findNumber(5)); });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
