#include <iostream>
#include "print_array_reverse.hpp"
int main()
{
  const int MAX = 10;

  int size;
  int array[MAX];
  int *numPtr;
  numPtr = &array[MAX];

  std::cout << "Enter an integer from 1 to 10 for the size of the array: ";
  std::cin >> size;

  std::cout << "Inputs for the array:\n";

  if (size > MAX || size < 0) {
    std::cout << "Invalid size." << std::endl;
  }
  else {
    for (int i = 0; i < size; i++) {
      std::cout << "Enter the integer for index " << i << ": ";
      std::cin >> *(numPtr+i);
      // Assign values from cin into each of the indicies of the array.
    }
    printArrayReverse(numPtr, size);
    // Call to print the array here.
  }

  return 0;
}
