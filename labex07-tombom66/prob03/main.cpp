#include "product_array.hpp"
#include <iostream>
#include <string>
int main() {
  double total;
  std::cout << "Enter the file name: ";
  std::string file_name;
  std::getline(std::cin, file_name);
  total = product_array(file_name);
  // Call product_array and pass the file name provided by the user.
  // Store the result in an integer variable called total

  std::cout << "The total product is: " << total << std::endl;

  return 0;
}

