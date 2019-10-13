#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>
using ::testing::ContainsRegex;
using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(Operations, OutputFormat) {
  std::string unittest_output =
      "Please enter in the operation (+, -, *, /) or x to exit the program: "
      "Please "
      "input the first number: Please input the second "
      "number: You chose to multiply: 5 * 6 = 30\n"
      "Please enter in the operation (+, -, *, /) or x to exit the program: ";

  std::string input = "* 5 6 x";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", input, unittest_output); });
}

TEST(Operations, Addition) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "+";
    int numOne = rand();
    int numTwo = rand();

    std::string unittest_output =
        "Please enter in the operation (+, -, *, /) or x to exit the program: "
        "Please "
        "input the first number: Please input the second number: ";

    std::string input = operation_input + " " + std::to_string(numOne) + " " +
                        std::to_string(numTwo);

    std::string strOne = std::to_string(numOne);
    std::string strTwo = std::to_string(numTwo);
    int sum = numOne + numTwo;

    unittest_output += "You chose to add: " + strOne + " + " + strTwo + " = " +
                       std::to_string(sum) +
                       "\nPlease enter in the operation (+, -, *, /) or x to "
                       "exit the program: ";
    ASSERT_DURATION_LE(
        3, { ASSERT_EXECIO_EQ("main", input + " x", unittest_output); });
  }
}

TEST(Operations, Subtraction) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "-";
    int numOne = rand();
    int numTwo = rand();

    std::string unittest_output =
        "Please enter in the operation (+, -, *, /) or x to exit the program: "
        "Please "
        "input the first number: Please input the second number: ";

    std::string input = operation_input + " " + std::to_string(numOne) + " " +
                        std::to_string(numTwo);

    std::string strOne = std::to_string(numOne);
    std::string strTwo = std::to_string(numTwo);
    int dif = numOne - numTwo;

    unittest_output += "You chose to subtract: " + strOne + " - " + strTwo +
                       " = " + std::to_string(dif) +
                       "\nPlease enter in the operation (+, -, *, /) or x to "
                       "exit the program: ";
    ASSERT_DURATION_LE(
        3, { ASSERT_EXECIO_EQ("main", input + " x", unittest_output); });
  }
}

TEST(Operations, Multiplication) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "*";
    int numOne = rand();
    int numTwo = rand();

    std::string unittest_output =
        "Please enter in the operation (+, -, *, /) or x to exit the program: "
        "Please "
        "input the first number: Please input the second number: ";

    std::string input = operation_input + " " + std::to_string(numOne) + " " +
                        std::to_string(numTwo);

    std::string strOne = std::to_string(numOne);
    std::string strTwo = std::to_string(numTwo);
    int multiply = numOne * numTwo;

    unittest_output += "You chose to multiply: " + strOne + " * " + strTwo +
                       " = " + std::to_string(multiply) +
                       "\nPlease enter in the operation (+, -, *, /) or x to "
                       "exit the program: ";
    ASSERT_DURATION_LE(
        3, { ASSERT_EXECIO_EQ("main", input + " x", unittest_output); });
  }
}

TEST(Operations, Division) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "/";
    int numOne = rand();
    int numTwo = rand();

    std::string unittest_output =
        "Please enter in the operation (+, -, *, /) or x to exit the program: "
        "Please "
        "input the first number: Please input the second number: ";

    std::string input = operation_input + " " + std::to_string(numOne) + " " +
                        std::to_string(numTwo);

    std::string strOne = std::to_string(numOne);
    std::string strTwo = std::to_string(numTwo);
    int divide = numOne / numTwo;

    unittest_output += "You chose to divide: " + strOne + " / " + strTwo +
                       " = " + std::to_string(divide) +
                       "\nPlease enter in the operation (+, -, *, /) or x to "
                       "exit the program: ";
    ASSERT_DURATION_LE(
        3, { ASSERT_EXECIO_EQ("main", input + " x", unittest_output); });
  }
}

TEST(Operations, FailCase) {
  for (int i = 0; i < 10; i++) {
    int fail_input = rand() % 10;
    int numOne = rand();
    int numTwo = rand();

    std::string unittest_output =
        "Please enter in the operation (+, -, *, /) or x to exit the program: "
        "Please "
        "input the first number: Please input the second number: ";

    std::string input = std::to_string(fail_input) + " " +
                        std::to_string(numOne) + " " + std::to_string(numTwo);

    unittest_output += "Invalid operation type.\nPlease enter in the operation "
                       "(+, -, *, /) or x to exit the program: ";
    ASSERT_DURATION_LE(
        3, { ASSERT_EXECIO_EQ("main", input + " x", unittest_output); });
  }
}

TEST(Operations, LoopTest) {
  std::string optionAR[5] = {"x", "+", "/", "*", "-"};
  int randNum;
  std::string input;
  std::string unittest_output;

  do {
    randNum = rand() % 5;
    input += (optionAR[randNum] + " ");

    unittest_output +=
        "Please enter in the operation (+, -, *, /) or x to exit the program: ";

    if (randNum != 0) {
      unittest_output +=
          "Please input the first number: Please input the second number: ";

      int Num1 = rand() % 20000;
      input += (std::to_string(Num1) + " ");
      int Num2 = rand() % 20000;
      input += (std::to_string(Num2) + " ");

      unittest_output +=
          (randNum == 1
               ? ("You chose to add: " + std::to_string(Num1) + " + " +
                  std::to_string(Num2) + " = " + std::to_string(Num1 + Num2) +
                  '\n')
               : (randNum == 2
                      ? ("You chose to divide: " + std::to_string(Num1) +
                         " / " + std::to_string(Num2) + " = " +
                         std::to_string(Num1 / Num2) + '\n')
                      : (randNum == 3
                             ? ("You chose to multiply: " +
                                std::to_string(Num1) + " * " +
                                std::to_string(Num2) + " = " +
                                std::to_string(Num1 * Num2) + '\n')
                             : (randNum == 4
                                    ? ("You chose to subtract: " +
                                       std::to_string(Num1) + " - " +
                                       std::to_string(Num2) + " = " +
                                       std::to_string(Num1 - Num2) + '\n')
                                    : "Nada"))));
    }
  } while (randNum != 0);
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", input, unittest_output); });
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
