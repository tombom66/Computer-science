#include "product_array.hpp"
#include <fstream>
#include <iostream>
#include <string>

double product_array(std::string txtfile) {
  double total = 1;
  std::ifstream array_file;
  int size;
  array_file.open(txtfile);
  int counter = 0;
  if (array_file) {
    array_file >> size;
    int array[size];
    while (array_file >> array[counter]) {
      total *= array[counter];
      if (counter >= size)
        break;
    }
    array_file.close();
  }
  return total;
}
