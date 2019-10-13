#include "department_budget.hpp"
#include <fstream>
#include <iostream>
DepartmentBudget::DepartmentBudget(std::string filename) {
  std::ifstream inFile;
  inFile.open(filename);
  double num;
  if (inFile.fail()) {
    name_ = "Error";
    budget_ = -1;
    current_balance_ = -1;
    std::cout << "Error with the spending report" << std::endl;
  } else {
    getline(inFile, name_);
    inFile >> budget_;
    current_balance_ = budget_;
    while (inFile >> num) {
      current_balance_ += num;
    }
    inFile.close();
  }
};
