#include "lsa.hpp"
#include <iostream>
int main() {
  const int MAX_SIZE = 10;

  int arr[MAX_SIZE] = {3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  int choice;
  std::cout << "Array:";
  for (int i = 0; i < MAX_SIZE; i++) {
    std::cout << " " << arr[i];
  }

  std::cout << "\nPlease enter a number you want to search for: ";
  std::cin >> choice;

  // Provide code that calls the linear_search function to find the number
  // that the user input from the array. Return the index of the value in
  // the array or -1 if it is not in the array. Store the value in the
  // variable named index
  int index = linear_search(arr, MAX_SIZE, choice);
  if (index >= 0) {
    std::cout << "The index of " << arr[index] << " in the array is: " << index
              << "\n";
  } else {
    std::cout << choice << " is not in the array\n";
  }

  return 0;
}
