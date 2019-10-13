#include "../min.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(Min, OutputFormat) {
  std::string unittest_output = "Array: -1 22 54 33 -40 67 8 15 -28 11\n"
                                "Min: -40\n";
  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(Min, ArrayContentsTest) {
  int unittest_arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int unittest_arr2[5] = {0, 0, 0, 1000, -1000};
  int unittest_arr3[3] = {-100, -200, -300};
  ASSERT_EQ(min(unittest_arr1, 10), 0)
      << "   Input: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] 10";
  ASSERT_EQ(min(unittest_arr2, 5), -1000)
      << "   Input: [0, 0, 0, 1000, -1000] 5";
  ASSERT_EQ(min(unittest_arr3, 3), -300) << "   Input: [-100, -200, -300] 3";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
