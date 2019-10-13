#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Salary, OutputFormat) {
  std::string unittest_output = "Hourly Wage: "
                                "Hours Worked: "
                                "Total Salary Owed: $1825.00\n";
  ASSERT_EXECIO_EQ("main", "25 62", unittest_output);
}

TEST(Salary, FourtyOrLessHrs) {
  for (int i = 0; i < 10; i++) {
    int hourlyWage = rand() % 70;
    int hoursWorked = rand() % 40;
    std::string input =
        std::to_string(hourlyWage) + " " + std::to_string(hoursWorked);
    int totalSalary = hourlyWage * hoursWorked;
    std::string unittest_output = "Hourly Wage: "
                                  "Hours Worked: ";
    unittest_output +=
        "Total Salary Owed: $" + to_string_double(totalSalary) + "\n";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Salary, SixtyFiveOrLessHrs) {
  for (int i = 0; i < 10; i++) {
    int hourlyWage = rand() % 70;
    int hoursWorked = rand() % 10 + 55;
    std::string input =
        std::to_string(hourlyWage) + " " + std::to_string(hoursWorked);
    double totalSalary =
        (hourlyWage * 40.0) + (hourlyWage * 1.5) * (hoursWorked - 40);
    std::string unittest_output = "Hourly Wage: "
                                  "Hours Worked: ";
    unittest_output +=
        "Total Salary Owed: $" + to_string_double(totalSalary) + "\n";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Salary, OverSixtyFiveHrs) {
  for (int i = 0; i < 10; i++) {
    int hourlyWage = rand() % 70;
    int hoursWorked = rand() % 20 + 66;
    std::string input =
        std::to_string(hourlyWage) + " " + std::to_string(hoursWorked);
    double totalSalary = (hourlyWage * 40) + (hourlyWage * 1.5) * 25 +
                         (hoursWorked - 65) * (hourlyWage * 2);
    std::string unittest_output = "Hourly Wage: "
                                  "Hours Worked: ";
    unittest_output +=
        "Total Salary Owed: $" + to_string_double(totalSalary) + "\n";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
