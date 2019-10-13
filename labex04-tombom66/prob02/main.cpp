#include <iomanip>
#include <iostream>
int main() {
  int print;
  double total;
  const double dpp = 0.10;
  const double mpp = 0.15;
  const double hpp = 0.20;
  char choose;
  std::cout << "Welcome to Tuffy Printing services\n";
  std::cout << "How many pages do you need printed? ";
  std::cin >> print;
  std::cout << "Select a printing quality fromt the list\n";
  std::cout << " D - draft, $0.10 per page\n";
  std::cout << " M - medium quality, $0.15 per page\n";
  std::cout << " H - high quality, $0.20 per page\n";
  std::cin >> choose;
  switch (choose) {
  case 'D':
  case 'd':
    std::cout << "You chose draft which is $.10 per page\n";
    total = dpp * print;
    std::cout << "Quality: " << choose << std::endl;
    std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << total
              << std::endl;
    break;
  case 'M':
  case 'm':
    std::cout << "You chose draft which is $.15 per page\n";
    total = mpp * print;
    std::cout << "Quality: " << choose << std::endl;
    std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << total
              << std::endl;
    break;
  case 'H':
  case 'h':
    std::cout << "You chose draft which is $.20 per page\n";
    total = hpp * print;
    std::cout << "Quality: " << choose << std::endl;
    std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << total
              << std::endl;
    break;
  default:
    std::cout << "Quality" << choose << std::endl;
    std::cout << "Invalid quality. Please try again.\n";
    break;
  }

  return 0;
}
