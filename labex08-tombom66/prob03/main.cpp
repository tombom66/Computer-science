#include "array_max.hpp"
#include <iostream>
int main() {
  const int MAX_SIZE = 10;

  int arr[MAX_SIZE] = {10, 9, 6, 1, 2, 4, 16, 8, 7, 5};

  std::cout << "Array:";
  for (int i = 0; i < MAX_SIZE; i++) {
    std::cout << " " << arr[i];
  }
  std::cout << std::endl;

  // Provide code that calls the max function and passes the array and its size
  // as arguments. Store the result in the variable called max_value
  int max_value = arrayMax(arr, MAX_SIZE);

  std::cout << "The largest number in the array is " << max_value << "\n";

  return 0;
}
