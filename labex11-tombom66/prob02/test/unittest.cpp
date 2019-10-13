#include "../candy_shop.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(CandyShop, OutputFormat) {
  std::ostringstream ss, input;
  ss << "Welcome to the Candy Shop!\n";
  ss << "Enter the brand of candy (q to quit): ";
  input << "Skittles\n";
  ss << "Enter the flavor of candy: ";
  input << "Fruity\n";
  ss << "Enter the cost of candy: ";
  input << "4.25\n";
  ss << "Enter the brand of candy (q to quit): ";
  input << "Snickers\n";
  ss << "Enter the flavor of candy: ";
  input << "Chocolate\n";
  ss << "Enter the cost of candy: ";
  input << "5.13\n";
  ss << "Enter the brand of candy (q to quit): ";
  input << "Sour Patch Kids\n";
  ss << "Enter the flavor of candy: ";
  input << "Sour-Fruity\n";
  ss << "Enter the cost of candy: ";
  input << "10.12\n";
  ss << "Enter the brand of candy (q to quit): ";
  input << "Q\n";
  ss << "Contents of bag:\n";
  ss << "1. Brand: Skittles\n";
  ss << "1. Flavor: Fruity\n";
  ss << "1. Cost: $4.25\n";
  ss << "2. Brand: Snickers\n";
  ss << "2. Flavor: Chocolate\n";
  ss << "2. Cost: $5.13\n";
  ss << "3. Brand: Sour Patch Kids\n";
  ss << "3. Flavor: Sour-Fruity\n";
  ss << "3. Cost: $10.12\n";
  ss << "The total cost of all the candy in the bag is: $19.50\n";
  std::string unittest_output = ss.str();
  std::string unittest_input = input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(CandyShop, PublicMethodPresent) {
  Candy your_candy;
  CandyShop your_candy_shop;
  your_candy_shop.getSize();
  your_candy_shop.addCandy(your_candy);
  your_candy_shop.totalPrice();
  std::string unittest_output = "Contents of bag:\n"
                                "1. Brand: Skittles\n"
                                "1. Flavor: Fruity\n"
                                "1. Cost: $1.00\n";
  ASSERT_SIO_EQ("", unittest_output, { your_candy_shop.printBag(); })
}

TEST(CandyShop, DefaultConstructor) {
  CandyShop your_candy_shop;
  ASSERT_EQ(your_candy_shop.getSize(), 0);
}

TEST(CandyShop, AddCandy) {
  CandyShop your_candy_shop;
  Candy your_candy;
  for (int i = 0; i < 10; i++) {
    your_candy_shop.addCandy(your_candy);
    ASSERT_EQ(your_candy_shop.getSize(), i + 1);
  }
  std::string unittest_output = "Error, bag is full!\n";
  ASSERT_SIO_EQ("", unittest_output,
                { your_candy_shop.addCandy(your_candy); });
}

TEST(CandyShop, PrintBag) {
  CandyShop your_candy_shop;
  Candy your_candy;
  std::string unittest_output = "Contents of bag:\n";
  for (int i = 0; i < 10; i++) {
    your_candy_shop.addCandy(your_candy);
    std::string temp = std::to_string(i + 1);
    unittest_output += temp + ". Brand: Skittles\n" + temp +
                       ". Flavor: Fruity\n" + temp + ". Cost: $1.00\n";
  }
  ASSERT_SIO_EQ("", unittest_output, { your_candy_shop.printBag(); });
}

TEST(CandyShop, TotalPrice) {
  srand(time(NULL));
  CandyShop your_candy_shop;
  double unittest_total = 0.0;
  for (int i = 0; i < 10; i++) {
    Candy your_candy;
    double f = (double)rand() / RAND_MAX;
    double random_double = 0.0 + f * (10.0 - 0.0);
    unittest_total += random_double;
    your_candy.setCost(random_double);
    your_candy_shop.addCandy(your_candy);
  }
  ASSERT_EQ(your_candy_shop.totalPrice(), unittest_total);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
