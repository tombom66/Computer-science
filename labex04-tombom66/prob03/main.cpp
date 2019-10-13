#include <iomanip>
#include <iostream>
int main() {
  float spent;
  double total;
  const double green = 0.10;
  const double yellow = 0.05;
  const double red = 0.02;
  char card;
  std::cout
      << "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): \n";
  std::cin >> card;
  std::cout << "Please enter amount of money spent: $";
  std::cin >> spent;
  switch (card) {
  case 'G':
  case 'g':

    std::cout << "You chose green card\n";
    total = green * spent;
    std::cout << "Amount of cash back received: $" << std::fixed
              << std::setprecision(2) << total << std::endl;
    break;
  case 'Y':
  case 'y':

    std::cout << "You chose yellow card\n";
    total = yellow * spent;
    std::cout << "Amount of cash back received: $" << std::fixed
              << std::setprecision(2) << total << std::endl;
    break;
  case 'R':
  case 'r':

    std::cout << "You chose red card\n";
    total = red * spent;
    std::cout << "Amount of cash back received: $" << std::fixed
              << std::setprecision(2) << total << std::endl;
    break;
  default:
    std::cout << "Invalid card type\n";
  }

  return 0;
}
