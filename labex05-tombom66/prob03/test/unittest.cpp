#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(FanControlLoop, OutputFormat)
{
  std::string unittest_output =
  "Welcome to the fan control system\n"
  "The fans connected to the system:\n"
  "1 - Warehouse Fan A\n"
  "2 - Warehouse Fan B\n"
  "3 - Office Fan system\n"
  "4 - Emergency Ventilation\n"
  "0 - Exit program\n"
  "Please select which fans you want to turn on by entering a number 0-4: "
  "Warehouse Fan A is now turned on\n\n"
  "Welcome to the fan control system\n"
  "The fans connected to the system:\n"
  "1 - Warehouse Fan A\n"
  "2 - Warehouse Fan B\n"
  "3 - Office Fan system\n"
  "4 - Emergency Ventilation\n"
  "0 - Exit program\n"
  "Please select which fans you want to turn on by entering a number 0-4: "
  "Exiting program\n\n"
  "Thank you for using the fan control system!\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "1 0", unittest_output); });
}

TEST(FanControlLoop, MenuTest) {
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string unittest_output;
    std::string input;
    int FanOption;
    do{
      FanOption = rand()%7-2;
      input += (std::to_string(FanOption)+ " ");
      unittest_output += "Welcome to the fan control system\n"
      "The fans connected to the system:\n"
      "1 - Warehouse Fan A\n"
      "2 - Warehouse Fan B\n"
      "3 - Office Fan system\n"
      "4 - Emergency Ventilation\n"
      "0 - Exit program\n"
      "Please select which fans you want to turn on by entering a number "
      "0-4: ";
      unittest_output+=(FanOption ==1 ? "Warehouse Fan A is now turned on\n\n":
      (FanOption ==2 ? "Warehouse Fan B is now turned on\n\n":
      (FanOption ==3 ? "Office Fan system is now turned on\n\n":
      (FanOption ==4 ? "Emergency Ventilation is now turned on - Please Evacuate the building\n\n":
      (FanOption ==0 ? "Exiting program\n\n":
      (FanOption<0||FanOption>4 ? "***Invalid menu option***\nPlease run the program again and "
      "select a valid option!\n\n": "This should never be output\n"))))));
    }while(FanOption!=0);
    unittest_output += "Thank you for using the fan control system!\n";
    ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("main", input, unittest_output);});
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
