#include <iostream>
#include "min.hpp"
int min(int *array, int size)
{
  int mini = *array;
 for (int i=0; i<size; i++)
  {
    if(mini > *(array+i))
    {
      mini = *(array+i);
    }
  }
  return mini;
}
