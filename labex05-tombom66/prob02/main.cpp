#include <iostream>
int main() {
  char oper;
  do {

    int first, second, total;
    std::cout << "Please enter in the operation (+, -, *, /) or x to exit the "
                 "program: ";
    std::cin >> oper;
    if (oper != 'x') {
      std::cout << "Please input the first number: ";
      std::cin >> first;
      std::cout << "Please input the second number: ";
      std::cin >> second;

      switch (oper) {
      case '+':
        total = first + second;
        std::cout << "You chose to add: " << first << " + " << second << " = "
                  << total << std::endl;

        break;
      case '-':
        total = first - second;
        std::cout << "You chose to subtract: " << first << " - " << second
                  << " = " << total << std::endl;

        break;
      case '*':
        total = first * second;
        std::cout << "You chose to multiply: " << first << " * " << second
                  << " = " << total << std::endl;

        break;
      case '/':
        total = first / second;
        std::cout << "You chose to divide: " << first << " / " << second
                  << " = " << total << std::endl;

        break;
      default:
        std::cout << "Invalid operation type.\n";
      }
    }
  } while ((oper != 'x') && (oper != 'X'));
  return 0;
}
