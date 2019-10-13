#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(creditcardapproval, CreditTest) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    std::string unittest_output;
    int credit_input = rand() % 851;
    std::string input = std::to_string(credit_input);
    // If you are a student, and can somehow read and understand this and
    // understand it, then you can do the problem. Why are you even looking in
    // here?
    unittest_output = "Thank you for applying for the Tuffy Credit card. "
                      "Please enter your credit score\n"
                      "Credit Score: ";
    unittest_output +=
        (credit_input <= 580 && credit_input > 0
             ? "Sorry, we cannot approve you for any credit card at the "
               "moment\n"
             : (credit_input >= 580 && credit_input < 670
                    ? "We can approve you for the SILVER Tuffy Card\n"
                    : (credit_input >= 670 && credit_input < 800
                           ? "We can approve you for the GOLD Tuffy Card\n"
                           : (credit_input >= 800 && credit_input <= 850
                                  ? "We would love to approve you for the "
                                    "PLATINUM Tuffy Card\n"
                                  : (credit_input < 0 || credit_input > 850
                                         ? "You have entered in an invalid "
                                           "credit score. Please restart the "
                                           "program and try again\n"
                                         : "This should never be output\n")))));
    unittest_output += "Thank you for using our program, please come again\n";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(creditcardapproval, InvalidInputTest) {
  srand(time(NULL));
  // Loop for negative inputs
  for (int i = 0; i < 5; i++) {
    std::string unittest_output;
    int credit_input = (rand() % 851 + 1) * -1;
    std::string input = std::to_string(credit_input);
    unittest_output = "Thank you for applying for the Tuffy Credit card. "
                      "Please enter your credit score\n"
                      "Credit Score: ";

        // If you are a student, and can somehow read and understand this and
        // understand it, then you can do the problem. Why are you even looking
        // in here?
        unittest_output +=
        (credit_input <= 580 && credit_input > 0
             ? "Sorry, we cannot approve you for any credit card at the "
               "moment\n"
             : (credit_input >= 580 && credit_input < 670
                    ? "We can approve you for the SILVER Tuffy Card\n"
                    : (credit_input >= 670 && credit_input < 800
                           ? "We can approve you for the GOLD Tuffy Card\n"
                           : (credit_input >= 800 && credit_input <= 850
                                  ? "We would love to approve you for the "
                                    "PLATINUM Tuffy Card\n"
                                  : (credit_input < 0 || credit_input > 850
                                         ? "You have entered in an invalid "
                                           "credit score. Please restart the "
                                           "program and try again\n"
                                         : "This should never be output\n")))));
    unittest_output += "Thank you for using our program, please come again\n";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
  // Loop for positive inputs
  for (int i = 0; i < 5; i++) {
    std::string unittest_output;
    int credit_input = rand() % 851 + 851;
    std::string input = std::to_string(credit_input);
    // If you are a student, and can somehow read and understand this and
    // understand it, then you can do the problem. Why are you even looking in
    // here?
    unittest_output = "Thank you for applying for the Tuffy Credit card. "
                      "Please enter your credit score\n"
                      "Credit Score: ";

        // If you are a student, and can somehow read and understand this and
        // understand it, then you can do the problem. Why are you even looking
        // in here?
        unittest_output +=
        (credit_input <= 580 && credit_input > 0
             ? "Sorry, we cannot approve you for any credit card at the "
               "moment\n"
             : (credit_input >= 580 && credit_input < 670
                    ? "We can approve you for the SILVER Tuffy Card\n"
                    : (credit_input >= 670 && credit_input < 800
                           ? "We can approve you for the GOLD Tuffy Card\n"
                           : (credit_input >= 800 && credit_input <= 850
                                  ? "We would love to approve you for the "
                                    "PLATINUM Tuffy Card\n"
                                  : (credit_input < 0 || credit_input > 850
                                         ? "You have entered in an invalid "
                                           "credit score. Please restart the "
                                           "program and try again\n"
                                         : "This should never be output\n")))));
    unittest_output += "Thank you for using our program, please come again\n";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(creditcardapproval, EdgeCases) {
  std::string input, unittest_output;
  std::string base_unittest_output_prefix =
      "Thank you for applying for the Tuffy Credit card. "
      "Please enter your credit score\n"
      "Credit Score: ";
  std::string base_unittest_output_postfix =
      "Thank you for using our program, please come again\n";

  input = std::to_string(579);
  unittest_output =
      base_unittest_output_prefix +
      "Sorry, we cannot approve you for any credit card at the moment\n" +
      base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(580);
  unittest_output = base_unittest_output_prefix +
                    "We can approve you for the SILVER Tuffy Card\n" +
                    base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(669);
  unittest_output = base_unittest_output_prefix +
                    "We can approve you for the SILVER Tuffy Card\n" +
                    base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(670);
  unittest_output = base_unittest_output_prefix +
                    "We can approve you for the GOLD Tuffy Card\n" +
                    base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(799);
  unittest_output = base_unittest_output_prefix +
                    "We can approve you for the GOLD Tuffy Card\n" +
                    base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(800);
  unittest_output =
      base_unittest_output_prefix +
      "We would love to approve you for the PLATINUM Tuffy Card\n" +
      base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(850);
  unittest_output =
      base_unittest_output_prefix +
      "We would love to approve you for the PLATINUM Tuffy Card\n" +
      base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(0);
  unittest_output =
      base_unittest_output_prefix +
      "Sorry, we cannot approve you for any credit card at the moment\n" +
      base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(-1);
  unittest_output = base_unittest_output_prefix +
                    "You have entered in an invalid credit score. Please "
                    "restart the program and try again\n" +
                    base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);

  input = std::to_string(851);
  unittest_output = base_unittest_output_prefix +
                    "You have entered in an invalid credit score. Please "
                    "restart the program and try again\n" +
                    base_unittest_output_postfix;
  ASSERT_EXECIO_EQ("main", input, unittest_output);
}

TEST(creditcardapproval, OutputFormat) {
  std::string unittest_output =
      "Thank you for applying for the Tuffy Credit card. "
      "Please enter your credit score\n"
      "Credit Score: "
      "We can approve you for the GOLD Tuffy Card\n"
      "Thank you for using our program, please come again\n";
  ASSERT_EXECIO_EQ("main", "700", unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
