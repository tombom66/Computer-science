#include "../car.hpp"
#include "gtest_ext.h"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>


TEST(CarChecker, OutputFormat) {
  srand(time(NULL));
  std::ostringstream unittest_output;
  std::ostringstream input;
  double lowest_price = 0;
  std::string lowest_name = "";
  int lowest_mileage = 0;
  for (int i = 0; i < 3; i++) {
    unittest_output << "Car #" << i + 1 << "\n";
    unittest_output << "Please enter the name: ";
    int stringLength = rand() % 30 + 1;
    std::string name = generate_string(stringLength);
    input << name << std::endl;

    unittest_output << "Please enter the mileage: ";
    int mileage = rand() % 100000;
    input << mileage << std::endl;

    unittest_output << "Please enter the price: ";
    double price = rand() % 100000 + 1;
    price /= static_cast<double>(rand() % 100 + 1);
    input << price << std::endl;
    if (i == 0 || lowest_price > price) {
      lowest_price = price;
      lowest_name = name;
      lowest_mileage = mileage;
    }
  }
  unittest_output << "\nThe car with the lowest price is " << lowest_name
                  << " with a mileage of " << lowest_mileage
                  << " and a price of $" << std::fixed << std::setprecision(2)
                  << lowest_price << std::endl;

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", input.str(), unittest_output.str()); });
}

TEST(CarChecker, MemberFunctionsTest) {
  // Test Default contructor
  Car your_car;
  int stringLength = rand() % 30 + 1;
  std::string unittest_name = generate_string(stringLength);
  your_car.set_name(unittest_name);

  double unittest_price_double = rand() % 100000 + 1;
  unittest_price_double /= static_cast<double>(rand() % 100 + 1);
  your_car.set_price(unittest_price);

  int unittest_mileage = rand() % 100000;
  your_car.set_mileage(unittest_mileage);

  ASSERT_EQ(your_car.name(), unittest_name)
      << "\nDid you properly make the set_name member function? \n";
  std::string unittest_price = to_string_double(unittest_price_double);
  ASSERT_EQ(to_string_double(your_car.price()), unittest_price)
      << "Did you properly make the set_price member function?\n";
  ASSERT_EQ(your_car.mileage(), unittest_mileage)
      << "Did you properly make the set_mileage member function?\n";
}

TEST(CarChecker, FindLowest) {
  Car unittest_car_arr[5];
  double lowest_pricetest;

  int stringLength1 = rand() % 30 + 1;
  std::string name1 = generate_string(stringLength1);
  unittest_car_arr[0].set_name(name1);

  double price1 = rand() % 100000 + 1;
  price1 /= static_cast<double>(rand() % 100 + 1);

  unittest_car_arr[0].set_price(price1);

  int mileage1 = rand() % 100000;
  unittest_car_arr[0].set_mileage(mileage1);

  int index = 0;
  lowest_pricetest = price1;
  for (int i = 1; i < 5; i++) {
    int stringLength = rand() % 30 + 1;
    std::string name = generate_string(stringLength);
    unittest_car_arr[i].set_name(name);

    double price = rand() % 100000 + 1;
    price /= static_cast<double>(rand() % 100 + 1);
    if (price < lowest_pricetest) {
      lowest_pricetest = price;
      index = i;
    }
    unittest_car_arr[i].set_price(price);

    int mileage = rand() % 100000;
    unittest_car_arr[i].set_mileage(mileage);
  }

  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(lowest_price(unittest_car_arr, 5).name(),
              unittest_car_arr[index].name());
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(lowest_price(unittest_car_arr, 5).price(),
              unittest_car_arr[index].price());
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(lowest_price(unittest_car_arr, 5).mileage(),
              unittest_car_arr[index].mileage());
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
