#include "car.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  const int carobjects_ = 3;
  Car objects[carobjects_];
  // Create an array of car objects with a maximum of 3 elements

  for (int i = 0; i < carobjects_; i++) {
    std::string name;
    double price;
    int milage;
    std::cout << "Car #" << i + 1 << "\n";
    std::cout << "Please enter the name: ";
    std::cin >> name;
    std::cout << "Please enter the milage: ";
    std::cin >> milage;
    std::cout << "Please enter the price: ";
    std::cin >> price;
    objects[i].set_name(name);
    objects[i].set_price(price);
    objects[i].set_mileage(milage);
    // Create a car object and set its name, price and mileage according to
    // user input.

    // Store the car object in the car array. Make sure it is in the first
    // available location
  }
  int lowest_index = lowerst_price(objects, carobjects_);
  // Create a car whose name is lowest.
  // Call the lowerst_price function to get the car with the lowest price
  // from the array then assign that car object to lowest.

  std::cout << "\nThe car with the lowest price is ";
  std::cout << objects[lowest_index].name();
  // Display the name of the car with the lowest price (use the lowest
  // variable)

  std::cout << " with a milage of ";
  std::cout << objects[lowest_index].mileage();
  // Display the milage of the car with the lowest price (use the lowest
  // variable)

  std::cout << " and a price of $" << std::fixed << std::setprecision(2);
  std::cout << objects[lowest_index].price();
  // Display the price of the car with the lowest price (use the lowest
  // variable)

  std::cout << std::endl;

  return 0;
}
