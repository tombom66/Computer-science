#include <iostream>
int main() {
  int credit;
  std::cout << "Thank you for applying for the Tuffy Credit card. Please enter "
               "your credit score\n";
  std::cin >> credit;
  if (credit >= 0 && credit <= 579) {
    std::cout
        << " Sorry, we cannot approve you for any credit card at the moment\n";
  } else if (credit >= 580 && credit <= 669) {
    std::cout << "We can approve you for the SILVER Tuffy Card\n";
  } else if (credit >= 670 && credit <= 799) {
    std::cout << "We can approve you for the GOLD Tuffy Card\n";
  } else if (credit >= 800 && credit <= 850) {
    std::cout << "We would love to approve you for the PLATINUM Tuffy Card\n";
  } else if ((credit < 0) || (credit > 850)) {
    std::cout << "You have entered in an invalid credit score. Please restart "
                 "the program and try again\n";
  }

  return 0;
}
