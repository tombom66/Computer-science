#include <iostream>
#include "min.hpp"
int main()
{
  const int SIZE = 10;
  int array[SIZE] = { -1, 22, 54, 33, -40, 67, 8, 15, -28, 11 };
  int min_value;
int *numPtr;
  std::cout << "Array:";
  for(int i = 0; i <SIZE; i++)
  {
    numPtr = (array+i);
    std::cout << *numPtr << " ";
  }
  // Loop through the array and print out the values.
std::cout <<"\nMin: "<< min(array, SIZE) << "\n";
  // Call the min function and display the value it returns.

  return 0;
}
