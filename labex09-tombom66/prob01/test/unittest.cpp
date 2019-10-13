#include "../print_array_reverse.hpp"
#include "gtest_ext.h"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(PrintArrayReverse, OutputFormat) {
  std::ostringstream c_inputs;
  std::ostringstream expected;
  int ar1[10] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  int reverse[10] = {21, 19, 17, 15, 13, 11, 9, 7, 5, 3};
  expected << "Enter an integer from 1 to 10 for the size of the array: ";
  expected << "Inputs for the array:\n";
  c_inputs << 10 << "\n";
  for (int i = 0; i < 10; i++) {
    expected << "Enter the integer for index " << i << ": ";
    c_inputs << ar1[i] << "\n";
  }
  expected << "The contents of the array in reverse are:\n";
  for (int i = 0; i < 10; i++) {
    expected << reverse[i] << "\n";
  }
  std::string unittest_output = expected.str();
  std::string unittest_input = c_inputs.str();

  ASSERT_EXECIO_EQ("main", unittest_input, unittest_output);
}

TEST(PrintArrayReverse, ZeroTest) {
  int unittest_arr1[10] = {4, 7, 2, 7, 10, 2, 7, 5, 56, 1};
  int unittest_arr2[10];
  int unittest_arr3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  ASSERT_SIO_EQ("", "There are no contents in this array!\n",
                { printArrayReverse(unittest_arr1, 0); });

  ASSERT_SIO_EQ("", "There are no contents in this array!\n",
                { printArrayReverse(unittest_arr2, 0); });

  ASSERT_SIO_EQ("", "There are no contents in this array!\n",
                { printArrayReverse(unittest_arr3, 0); });
}

TEST(PrintArrayReverse, ReverseTest) {
  srand(time(NULL));
  std::ostringstream parameter1;
  std::ostringstream expected;
  int unittest_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int reverse[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  expected << "The contents of the array in reverse are:\n";
  for (int i = 0; i < 10; i++) {
    parameter1 << unittest_arr[i] << "\n";
    expected << reverse[i] << "\n";
  }
  std::string unittest_input = parameter1.str();
  std::string unittest_output = expected.str();

  ASSERT_SIO_EQ(unittest_input, unittest_output,
                { printArrayReverse(unittest_arr, 10); });
}

TEST(PrintArrayReverse, RandomInput) {
  std::ostringstream parameter1;
  std::ostringstream expected;
  int unittest_arr[20];
  int reverse[20];
  expected << "The contents of the array in reverse are:\n";
  for (int i = 0; i < 20; i++) {
    unittest_arr[i] = rand() % 100;
    reverse[20 - 1 - i] = unittest_arr[i];
    parameter1 << unittest_arr[i] << "\n";
  }
  for (int i = 0; i < 20; i++) {
    expected << reverse[i] << "\n";
  }

  std::string unittest_input = parameter1.str();
  std::string unittest_output = expected.str();

  ASSERT_SIO_EQ(unittest_input, unittest_output,
                { printArrayReverse(unittest_arr, 20); });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
