#include <iostream>

int main() {

  int choice;
  do {
    std::cout << "Welcome to the fan control system\n";
    std::cout << "The fans connected to the system:\n";
    std::cout << "1 - Warehouse Fan A\n";
    std::cout << "2 - Warehouse Fan B\n";
    std::cout << "3 - Office Fan system\n";
    std::cout << "4 - Emergency Ventilation\n";
    std::cout << "0 - Exit program\n";
    std::cout << "Please select which fans you want to turn on by entering a "
                 "number 0-4: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      std::cout << "Warehouse Fan A is now turned on\n\n";
      break;
    case 2:
      std::cout << " Warehouse Fan B is now turned on\n\n";
      break;
    case 3:
      std::cout << " Office Fan system is now turned on\n\n";
      break;
    case 4:
      std::cout << " Emergency Ventilation is now turned on - Please Evacuate "
                   "the building\n\n";
      break;
    case 0:
      std::cout << "Exiting program\n\n";
      break;
    default:
      std::cout << "***Invalid menu option***\nPlease run the program again "
                   "and select a valid option!\n\n";
      break;
    }

  } while (choice != 0);
  std::cout << "Thank you for using the fan control system!\n";

  return 0;
}
