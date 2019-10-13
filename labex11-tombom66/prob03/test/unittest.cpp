#include "../department_budget.hpp"
#include "gtest_ext.h"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(DepartmentBudget, OutputFormat1) {
  srand(time(NULL));
  std::ostringstream s;
  std::ostringstream input;
  input << "Spending_Report1.txt\n";

  s << "Enter the name of the Spending Report you want to process: ";
  s << "Product Marketing has $" << 7075.82 << " left on their budget\n";
  std::string unittest_output = s.str();
  std::string unittest_input = input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(DepartmentBudget, OutputFormat2) {
  std::ostringstream s;
  std::ostringstream input;
  input << "Spending_Report2.txt\n";
  s << "Enter the name of the Spending Report you want to process: ";
  s << "Small Project has gone over budget!\n";
  std::string unittest_output = s.str();
  std::string unittest_input = input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(DepartmentBudget, OutputFormat3) {
  std::ostringstream s;
  std::ostringstream input;
  input << "DNE.txt\n";
  s << "Enter the name of the Spending Report you want to process: ";
  s << "Error with the spending report\n";
  s << "Please choose a valid spending report\n";

  std::string unittest_output = s.str();
  std::string unittest_input = input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(DepartmentBudget, DefaultConstructor) {
  DepartmentBudget your_department_budget;

  ASSERT_EQ(your_department_budget.getName(), "NULL");
  ASSERT_EQ(your_department_budget.getBudget(), 100.0);
  ASSERT_EQ(your_department_budget.getCurrentBalance(), 100.0);
}

TEST(DepartmentBudget, AccessorsAndMutators) {
  std::string random_name = generate_string(25);
  double random_budget_value = rand() % 1000;

  DepartmentBudget your_department_budget;

  your_department_budget.setBudget(random_budget_value);
  your_department_budget.setName(random_name);

  ASSERT_EQ(your_department_budget.getName(), random_name);
  ASSERT_EQ(your_department_budget.getBudget(), random_budget_value);
  ASSERT_EQ(your_department_budget.getCurrentBalance(), random_budget_value);
}

TEST(DepartmentBudget, RecordSpending) {
  std::string random_name = generate_string(25);
  double random_budget_value = rand() % 10000;

  DepartmentBudget your_department_budget;

  your_department_budget.setBudget(random_budget_value);
  your_department_budget.setName(random_name);

  ASSERT_EQ(your_department_budget.getName(), random_name);
  ASSERT_EQ(your_department_budget.getBudget(), random_budget_value);
  ASSERT_EQ(your_department_budget.getCurrentBalance(), random_budget_value);

  double spending_value = -14000.00;
  your_department_budget.recordSpending(spending_value);

  ASSERT_EQ(your_department_budget.getName(), random_name);
  ASSERT_EQ(your_department_budget.getBudget(), random_budget_value);
  ASSERT_EQ(your_department_budget.getCurrentBalance(), (random_budget_value + spending_value));
}

TEST(DepartmentBudget, NonDefaultConstructor) {
  const char * file_name = "./test/Spending_Report.txt";
  std::string filename = "./test/Spending_Report.txt";

  std::fstream test;
  test.open(file_name, std::ios::in);
  if (test.good()) {
    remove(file_name);
  }

  std::fstream unittest_file;
  unittest_file.open(filename, std::ios::out);
  unittest_file << "Product "
                   "Department\n10000.00\n-500.00\n200.00\n-3.00\n-15.00\n-6."
                   "18\n-1000.00\n-2000.00\n400.00\n5.13\n-600.52\n";
  unittest_file.close();

  DepartmentBudget your_department_budget(filename);

  ASSERT_EQ(your_department_budget.getName(), "Product Department");
  ASSERT_EQ(your_department_budget.getBudget(), 10000.00);
  ASSERT_EQ(your_department_budget.getCurrentBalance(), 6480.43);

  remove(file_name);
}

TEST(DepartmentBudget, ErrorFile) {
  ASSERT_SIO_EQ("", "Error with the spending report\n", {
    DepartmentBudget your_department_budget("DNE.txt");
    ASSERT_EQ(your_department_budget.getBudget(), -1);
    ASSERT_EQ(your_department_budget.getCurrentBalance(), -1);
    ASSERT_EQ(your_department_budget.getName(), "Error");
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
