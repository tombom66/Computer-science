#include "../calculate_avg.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iomanip>
#include <random>

TEST(CalculateAverage, OutputFormat1) {
  srand(time(NULL));
  std::ostringstream c_inputs;
  std::ostringstream expected;
  expected << "How many students are in your class? ";
  // Get the number of students
  c_inputs << 0 << "\n";
  expected << "You have no class!\n";

  std::string unittest_input = c_inputs.str();
  std::string unittest_output = expected.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(CalculateAverage, OutputFormat2) {
  std::ostringstream c_inputs;
  std::ostringstream expected;
  expected << "How many students are in your class? ";
  // Get the number of students
  int size = rand() % 10;
  c_inputs << size << "\n";
  double sum = 0;
  // Allocate the array
  if (size > 0) {
    expected << "Enter the GPA for each student in your class (0.0 - 4.0)\n";
    for (int i = 0; i < size; i++) {
      expected << "Enter the GPA for student #" << i + 1 << ": ";
      // Assign values from cin into indicies of the array.
      double min = 0.0;
      double max = 4.0;
      double f = (double)rand() / RAND_MAX;
      double current = min + f * (max - min);
      c_inputs << current << "\n";
      sum += current;
    }
    // call calculateAverage here.
    expected << "Class average: " << std::setprecision(2) << std::fixed
             << sum / size << "\n";
  } else {
    expected << "You have no class!\n";
  }

  std::string unittest_input = c_inputs.str();
  std::string unittest_output = expected.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(CalculateAverage, ZeroTest) {
  double unittest_arr1[10] = {4, 7, 2, 7, 10, 2, 7, 5, 56, 1};
  double unittest_arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(calculateAverage(unittest_arr1, 0), 0)
        << "   Inputs: [4, 7, 2, 7, 10, 2, 7, 5, 56, 1] 0";
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(calculateAverage(unittest_arr2, 10), 0)
        << "   Inputs: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 10";
  });
}

TEST(CalculateAverage, RandomInput) {
  for (int j = 0; j < 10; j++) {
    double sum = 0.0;
    double unittest_arr[10];
    std::string values = "[";
    for (int i = 0; i < 10; i++) {
      double min = 0.0;
      double max = 4.0;
      double f = (double)rand() / RAND_MAX;
      unittest_arr[i] = min + f * (max - min);

      sum += unittest_arr[i];
      if (i == 9) {
        values += std::to_string(sum) + "]";
      } else {
        values += std::to_string(sum) + " ,";
      }
    }
    double unittest_output = sum / 10;
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(calculateAverage(unittest_arr, 10), unittest_output)
          << "   Inputs: " << values << " 10";
    });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
