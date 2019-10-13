#include "candy_shop.hpp"
#include <iomanip>
#include <iostream>
void CandyShop::addCandy(Candy c) {
  if (size_ < 10) {
    candyarray[size_] = c;
    size_++;
  } else {
    std::cout << "Error, bag is full!";
  }
}
void CandyShop::printBag() {
  for (int i = 0; i < size_; i++) { // needs fixing
    std::cout << (i + 1) << ". Brand: " << candyarray[i].getBrand()
              << std::endl;
    std::cout << (i + 1) << ". Flavor: " << candyarray[i].getFlavor()
              << std::endl;
    std::cout << std::fixed << std::setprecision(2) << (i + 1) << ". Cost: $"
              << candyarray[i].getCost() << std::endl;
  }
}
double CandyShop::totalPrice() {
  double total_ = 0;
  for (int i = 0; i < size_; i++) {
    total_ += candyarray[i].getCost();
  }
  return total_;
}
