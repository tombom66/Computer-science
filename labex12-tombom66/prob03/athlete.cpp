#include "athlete.hpp"
#include <iomanip>
#include <iostream>
void Athlete::print() {
  std::cout << std::setw(8) << std::left << "Name: " << getName()
            << std::setw(8) << std::left << "\nSport: " << sport_
            << std::setw(8) << std::left << "\nHeight: " << height_ << "in"
            << std::setw(8) << std::left << "\nWeight: " << weight_ << "lbs"
            << std::setw(8) << std::left << "\nShoe:" << std::setw(10)
            << "\n Style: " << shoe_->getStyle() << std::setw(10)
            << "\n Color: " << shoe_->getColor() << std::setw(10)
            << "\n Size:" << shoe_->getSize() << "in\n";
}
// Use `std::setw(8)` and `std::left` to print the name, sport, height, and
// weight values of the athlete Use `std::setw(10)` to print the style, color,
// and size of its associated `AthleticShoe` object
