#include <iostream>
int main() {

  int num, iterate;
  int total = 0;
  std::cout << "Please enter a number: ";
  std::cin >> num;

  std::cout << "How many times to be added: ";
  std::cin >> iterate;
  for (int i = 1; i <= iterate; i++) {
    total += num;
  }
  std::cout << "The summation is " << total << '\n';
  return 0;
}
