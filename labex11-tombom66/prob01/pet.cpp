#include "pet.hpp"
#include <iostream>
#include <iomanip>
void Pet::print()
{
   std::cout << std::setw(8) << std::left << "Name: " << name_ << std::endl;
   std::cout << std::setw(8) << std::left << "Species: " << breed_.getSpecies() << std::endl;
   std::cout << std::setw(8) << std::left << "Breed: " << breed_.getName() << std::endl;
   std::cout << std::setw(8) << std::left << "Color: " << breed_.getColor() << std::endl;
   std::cout << std::setw(8) << std::left << "Weight: " << weight_ << std::endl;
}// Use << setw(8) << left to ensure there are 8 characters to the left
// of the pet information. For example:
// cout << setw(8) << left << "Name:" << the_name << endl;
