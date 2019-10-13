#include "../appfile.hpp"
#include "gtest_ext.h"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class AppendFile : public ::testing::Test {
protected:
  void SetUp() override {
    std::ifstream my_empty_file;
    my_empty_file.open("names.txt");
    if (my_empty_file.good()) {
      rename("names.txt", "user_names.txt");
      file_exists = true;
    }
    my_empty_file.close();
  }

  void TearDown() override {
    if (file_exists) {
      rename("user_names.txt", "names.txt");
    } else {
      remove("names.txt");
    }
  }

  bool file_exists = false;
};

TEST_F(AppendFile, OutputFormat) {
  std::string unittest_output = "Please enter the name you'd like to append to "
                                "the file (enter quit to quit): ";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("main", "quit", unittest_output);
  });
}

TEST_F(AppendFile, SingleAppend) {
  std::string unittest_file_output = generate_string(20);
  append_to_file(unittest_file_output);

  std::ifstream the_file;
  the_file.open("names.txt");
  std::string your_file_output = "";
  std::getline(the_file, your_file_output);
  the_file.close();
  ASSERT_EQ(your_file_output, unittest_file_output);
}

TEST_F(AppendFile, MultipleAppend) {
  append_to_file("Geddy Lee");
  append_to_file("Natalie Peart");
  append_to_file("Alex Lifeson");

  std::ifstream ifs;
  ifs.open("names.txt");
  bool your_file_exists = ifs.is_open();
  ASSERT_TRUE(your_file_exists);

  std::vector<std::string> namelist;
  while (!ifs.eof()) {
    std::string name;
    std::getline(ifs, name);
    namelist.push_back(name);
  }

  bool string1_found = false, string2_found = false, string3_found = false;

  for (std::string n : namelist) {
    if (n == "Geddy Lee")
      string1_found = true;
    else if (n == "Natalie Peart")
      string2_found = true;
    else if (n == "Alex Lifeson")
      string3_found = true;
  }
  ASSERT_TRUE(string1_found);
  ASSERT_TRUE(string2_found);
  ASSERT_TRUE(string3_found);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
