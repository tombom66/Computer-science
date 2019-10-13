#ifndef CANDY_SHOP_HPP
#define CANDY_SHOP_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Candy {
private:
  std::string brand_;
  std::string flavor_;
  double cost_;

public:
  Candy() : Candy("Skittles", "Fruity", 1.00) {}

  Candy(const std::string &brand, const std::string &flavor, double cost)
      : brand_(brand), flavor_(flavor), cost_(cost) {}

  std::string getBrand() const { return brand_; }
  std::string getFlavor() const { return flavor_; }
  double getCost() const { return cost_; }

  void setBrand(const std::string &brand) { brand_ = brand; }
  void setFlavor(const std::string &flavor) { flavor_ = flavor; }
  void setCost(double cost) { cost_ = cost; }
};
class CandyShop {
private:
  Candy candyarray[10];
  int size_; // need help on keep count of the elements in an array

public:
  int getSize() { return size_; }
  void addCandy(Candy c);
  void printBag();
  double totalPrice();
  CandyShop() : size_(0) {}
};

#endif
