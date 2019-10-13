#include "appfile.hpp"
#include <iostream>

int main() {
  std::string name;
  do {
    std::cout << "Please enter the name you'd like to append to the file "
                 "(enter quit to quit): ";
    std::getline(std::cin, name);
    if (name != "quit") {

      appendToFile(name);
    }
  } while (name != "quit");

  return 0;
}
