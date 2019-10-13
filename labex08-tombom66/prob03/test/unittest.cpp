#include "../array_max.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(ArrayMax, OutputFormat) {
  std::string unittest_output = "Array: 10 9 6 1 2 4 16 8 7 5\n"
                                "The largest number in the array is 16\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "", unittest_output); });
}

TEST(ArrayMax, GetMax) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int unittest_array_size = rand() % 10 + 1;
    int unittest_arr[unittest_array_size];
    int unittest_output = rand() % 10 + 7;
    bool has_max = false;
    int j;
    std::string unittest_arr_str = "[";
    for (j = 0; j < unittest_array_size - 1; j++) {
      int n;
      if (!has_max && (rand() % 2) == 0) {
        n = unittest_output;
        has_max = true;
      } else {
        n = (rand() % 5);
      }
      unittest_arr[j] = n;
      unittest_arr_str += std::to_string(unittest_arr[j]) + " ";
    }

    if (!has_max) {
      unittest_arr[j] = unittest_output;
      unittest_arr_str = "[" + std::to_string(unittest_arr[j]) + "]";
    } else {
      unittest_arr[j] = rand() % 5;
      unittest_arr_str += std::to_string(unittest_arr[j]) + "]";
    }
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(arrayMax(unittest_arr, unittest_array_size),
                unittest_output) << "   Input: " << unittest_arr_str << " " << unittest_array_size;
    });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
