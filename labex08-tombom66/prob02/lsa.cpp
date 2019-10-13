#include "lsa.hpp"
#include <iostream>
int linear_search(int array[], int size, int searchvalue) {
  int x = size - 1;
  if (array[x] == searchvalue) {
    return x;
  } else if (size == 1) {
    return -1;
  } else {
    return linear_search(array, size - 1, searchvalue);
  }
}
