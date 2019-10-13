#include "print_array_reverse.hpp"
#include <iostream>
void printArrayReverse(int *array, int size)
{
  if(array[size] <=  0)
  {
    std::cout << "There are no contents in this array";
  }
  else{
    for(int i = size-1; i>=0; i--)
    {
      //numPtr--;
      std::cout << "The contents of the array in reverse are:";
      std::cout << *(array+i) << "\n";
    }
  }
}
//Array    { 1, 2, 3}
//Indicies   0  1  2
