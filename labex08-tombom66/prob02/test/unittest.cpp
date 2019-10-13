#include "../lsa.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(LSA, OutputFormatExists) {
  std::string unittest_output = "Array: 3 16 22 8 11 0 55 34 27 31\n"
                                "Please enter a number you want to search for: "
                                "The index of 8 in the array is: 3\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "8", unittest_output); });
}

TEST(LSA, OutputFormatNotExists) {
  std::string unittest_output = "Array: 3 16 22 8 11 0 55 34 27 31\n"
                                "Please enter a number you want to search for: "
                                "15 is not in the array\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "15", unittest_output); });
}

TEST(LSA, SuccessTest) {
  int unittest_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++) {
    ASSERT_DURATION_LE(
        3, {
          int unittest_output = unittest_arr[i];
          ASSERT_EQ(linearSearch(unittest_arr, 10, i), unittest_output) << "   Input: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] " << i << " 10"; });
  }
}

TEST(LSA, FailTest) {
  int unittest_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_DURATION_LE(3,
                     { ASSERT_EQ(linearSearch(unittest_arr, 10, -1), -1) << "   Input: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] -1 10"; });
  ASSERT_DURATION_LE(3,
                     { ASSERT_EQ(linearSearch(unittest_arr, 10, 10), -1)  << "   Input: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] 10 10"; });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
