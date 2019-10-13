#include "find_number.hpp"
#include <iostream>
int main() {
  // create an instance of the Numbers object
  Numbers n;

  n.addIntoArray();
  n.displayArray();

  n.findNumber(2);
  n.findNumber(3);
  n.findNumber(10);
  n.findNumber(15);
  n.findNumber(16);
  n.findNumber(21);

  return 0;
}
