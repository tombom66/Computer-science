#include <iostream>
int main() {
  int cut, onepm, twopm, threepm, total;
  char options;
  std::cout << "How many cookies do you need to cut? ";
  std::cin >> cut;
  std::cout << "Cookie-cutting-machine Options\n";
  std::cout << "1. Slow and steady\n";
  std::cout << "2. Well-paced\n";
  std::cout << "3. Hi-speed\n";
  std::cout << "Which cookie cutter machine do you want to use?\n";
  std::cin >> options;
  switch (options) {
  case '1':
    std::cout << "You chose slow and steady\n";
    onepm = cut;
    std::cout << "It will take " << onepm << " minutes to cut " << cut
              << " cookies" << std::endl;
    break;
  case '2':
    std::cout << "You chose well-paced\n";
    twopm = cut / 2;
    std::cout << "It will take " << twopm << " minutes to cut " << cut
              << " cookies" << std::endl;
    break;
  case '3':
    std::cout << "you chose hi-speed\n";
    threepm = cut / 3;
    std::cout << "It will take " << threepm << " minutes to cut " << cut
              << " cookies" << std::endl;
    break;
  default:
    std::cout << "No such machine. Please try again.\n";
    break;
  }
  return 0;
}
