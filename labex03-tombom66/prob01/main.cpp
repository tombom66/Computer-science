#include <iostream>
int main() {
  int first, second, total;
  char operation;
  std::cout << "Please enter in the operation (+, -, *, /): ";
  std::cin >> operation;
  std::cout << "Please input the first number: ";
  std::cin >> first;
  std::cout << "Please input the second number: ";
  std::cin >> second;
  switch (operation) {
  case '+':
    total = first + second;
    std::cout << "You chose to add:" << first << " " << operation << second
              << "=" << total << std::endl;
    break;
  case '-':
    total = first - second;
    std::cout << "You chose to subtract:" << first << " " << operation << second
              << "=" << total << std::endl;
    break;
  case '*':
    total = first * second;
    std::cout << "You chose to multiply:" << first << " " << operation << second
              << "=" << total << std::endl;
    break;
  case '/':
    total = first / second;
    std::cout << "You chose to divide:" << first << " " << operation << " "
              << second << " "
              << "= " << total << std::endl;
    break;
  default:
    std::cout << "Invalid operation type.";
  }
  return 0;
}
