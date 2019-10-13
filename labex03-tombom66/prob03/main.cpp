#include <iomanip>
#include <iostream>
int main() {
  int wage, worked;
  float total;
  std::cout << "Hourly wage: ";
  std::cin >> wage;
  std::cout << "Hours worked: ";
  std::cin >> worked;
  if (worked <= 40) {
    total = wage * worked;
    std::cout << "Total Salary Owed: $" << std::fixed << std::setprecision(2)
              << total << std::endl;
  } else if (worked > 40 && worked < 65) {
    total = (wage * 40) + (worked - 40) * (wage * 1.5);
    std::cout << "Total Salary Owed: $" << std::fixed << std::setprecision(2)
              << total << std::endl;
  } else if (worked > 65) {
    total = (wage * 40) + (wage * 1.5) * 25 + (worked - 65) * (wage * 2);
    std::cout << "Total Salary Owed: $" << std::fixed << std::setprecision(2)
              << total << std::endl;
  }
  return 0;
}
