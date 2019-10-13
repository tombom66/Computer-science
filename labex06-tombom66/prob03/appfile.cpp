#include "appfile.hpp"
#include <fstream>
#include <iostream>
#include <string>

void appendToFile(std::string name) {
  std::ofstream outputFile;
  outputFile.open("names.txt", std::ofstream::out | std::ofstream::app);
  outputFile << name << std::endl;
  outputFile.close();
}
