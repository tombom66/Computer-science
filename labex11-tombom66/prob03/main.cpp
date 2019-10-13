#include "department_budget.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string filename;

  std::cout << "Enter the name of the Spending Report you want to process: ";
  std::getline(std::cin, filename);

  // Use the filename input to call the non-default constructor for the
  // `DepartmentBudget` Class
  DepartmentBudget object(filename);
  if (object.getBudget() != -1) {
    if (object.getCurrentBalance() < 0) {
      std::cout << object.getName() << " has gone over budget!" << std::endl;
    } else {
      std::cout << object.getName() << " has $" << object.getCurrentBalance()
                << " left on their budget" << std::endl;
    }
  } else {
    std::cout << "Please choose a valid spending report" << std::endl;
  }
  // If the budget is not -1, then
  // If the Current balance of the department is less than 0
  // The program needs to say.
  // "<department_name> has gone over budget!"
  // else it should just print out
  // "<department_name>" has <current_balance> left on their budget.
  // else if the budget is -1, then we need to output an error message.
  // "Please choose a valid spending report\n";

  return 0;
}
