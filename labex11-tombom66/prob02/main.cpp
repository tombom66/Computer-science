#include "candy_shop.hpp"
#include <iomanip>
#include <iostream>

int main() {
  CandyShop cs;
  // Create an instance of the `CandyShop` object called `cs`

  std::cout << "Welcome to the Candy Shop!\n";
  // Loop to ask the user to enter in `Candy` objects
  do {
    std::string temp;

    // Ask the user to enter in the brand of the candy
    std::cout << "Enter the brand of candy (q to quit): ";
    std::getline(std::cin, temp);

    // If the user enters in "q" or "Q", exit the loop
    if (temp == "q" || temp == "Q") {
      break;
    }
    Candy c;
    // Create a `Candy` object called `c`
    c.setBrand(temp);
    // Set the brand of the candy to `temp`

    // Ask the user to enter in the flavor of the candy
    std::cout << "Enter the flavor of candy: ";
    std::getline(std::cin, temp);
    c.setFlavor(temp);
    // Set the flavor of the candy to `temp`

    double cost;
    // Ask the user to enter in the cost of the candy
    std::cout << "Enter the cost of candy: ";
    std::cin >> cost;
    std::cin.ignore();
    c.setCost(cost);
    // Set the cost of the candy to `cost`
    cs.addCandy(c);
    // Add the `Candy` object to the `CandyShop` bag

  } while (true);
  std::cout << "Contents of bag:" << std::endl;
  // Print all the candy in the `CandyShop` bag
  cs.printBag();
  double price;
  // Get the total price of all the candy in the `CandyShop` bag
  // and initialize it to `price`
  price = cs.totalPrice();
  // Print out the price of all the candy in the `CandyShop` bag
  std::cout << "The total cost of all the candy in the bag is: $" << std::fixed
            << std::setprecision(2) << price << "\n";

  return 0;
}
