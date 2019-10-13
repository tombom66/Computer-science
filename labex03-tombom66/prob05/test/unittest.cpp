#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

double round_two_decimals(double x) {
  double value = (int)(x * 100 + 0.5);
  return (double)value / 100;
}

TEST(CashBack, OutputFormat) {
  std::string unittest_output =
      "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): "
      "Please enter amount of money spent: $"
      "Amount of cash back received: $2.11\n";
  ASSERT_EXECIO_EQ("main", "y 42.12", unittest_output);
}

TEST(CashBack, GreenCard) {
  for (int i = 0; i < 10; i++) {
    double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
    money_spent = round_two_decimals(money_spent);
    double cashback;

    std::string output_string;

    std::string input = "g " + to_string_double(money_spent);

    cashback = money_spent * 0.10;
    cashback = round_two_decimals(cashback);
    std::string unittest_output =
        "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): "
        "Please enter amount of money spent: $";
    unittest_output +=
        "Amount of cash back received: $" + to_string_double(cashback) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(CashBack, YellowCard) {
  for (int i = 0; i < 10; i++) {
    double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
    money_spent = round_two_decimals(money_spent);
    double cashback;

    std::string output_string;

    std::string input = "y " + to_string_double(money_spent);

    cashback = money_spent * 0.05;
    cashback = round_two_decimals(cashback);

    std::string unittest_output =
        "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): "
        "Please enter amount of money spent: $";
    unittest_output +=
        "Amount of cash back received: $" + to_string_double(cashback) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(CashBack, RedCard) {
  for (int i = 0; i < 10; i++) {
    double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
    money_spent = round_two_decimals(money_spent);
    double cashback;

    std::string output_string;

    std::string input = "r " + to_string_double(money_spent);

    cashback = money_spent * 0.02;
    cashback = round_two_decimals(cashback);

    std::string unittest_output =
        "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): "
        "Please enter amount of money spent: $";
    unittest_output +=
        "Amount of cash back received: $" + to_string_double(cashback) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(CashBack, FailCase) {
  for (int i = 0; i < 10; i++) {

    int fail_input = rand() % 10;
    double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
    money_spent = round_two_decimals(money_spent);
    double cashback;

    std::string output_string;

    std::string input =
        to_string_double(fail_input) + " " + to_string_double(money_spent);

    std::string unittest_output =
        "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): "
        "Please enter amount of money spent: $";
    unittest_output += "Invalid card type.\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
