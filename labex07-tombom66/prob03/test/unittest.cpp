#include "../product_array.hpp"
#include "gtest_ext.h"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>
#include <vector>


class ProductArray : public ::testing::Test {
protected:
  void SetUp() override {
    std::fstream my_empty_file;
    my_empty_file.open("data.txt", std::ios::in);
    if (my_empty_file.good()) {
      rename("data.txt", "user_data.txt");
      file_exists = true;
    }
    my_empty_file.close();

    std::fstream file1, file2;
    file1.open("test/data2.txt", std::ios::out);
    file2.open("test/data3.txt", std::ios::out);

    std::vector<int> data2 = {7, 12, 3, 5, 9, 2, 1, 4};
    for (int i = 0; i < data2.size(); i++) {
      file1 << data2[i] << std::endl;
    }

    std::vector<int> data3 = {10, 5, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < data3.size(); i++) {
      file2 << data3[i] << std::endl;
    }

    file1.close();
    file2.close();
    data2.clear();
    data3.clear();
  }

  void TearDown() override {
    if (file_exists) {
      rename("user_data.txt", "data.txt");
    } else {
      remove("data.txt");
    }
    remove("test/data2.txt");
    remove("test/data3.txt");
  }

  bool file_exists = false;
};

TEST_F(ProductArray, OutputFormat) {
  std::string unittest_output =
      "Enter the file name: The total product is: 268800\n";
  std::string input = "user_data.txt\n";
  ASSERT_EXECIO_EQ("main", input, unittest_output);
}

TEST_F(ProductArray, TestData1) {
  std::string unittest_file_name = "user_data.txt";
  int unittest_output = 268800;
  ASSERT_DURATION_LE(
      3, { ASSERT_EQ(product_array(unittest_file_name), unittest_output); });
}

TEST_F(ProductArray, TestData2) {
  std::string unittest_file_name = "test/data2.txt";
  int unittest_output = 12960;
  ASSERT_DURATION_LE(
      3, { ASSERT_EQ(product_array(unittest_file_name), unittest_output); });
}

TEST_F(ProductArray, TestData3) {
  std::string unittest_file_name = "test/data3.txt";
  int unittest_output = 18144000;
  ASSERT_DURATION_LE(
      3, { ASSERT_EQ(product_array(unittest_file_name), unittest_output); });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
