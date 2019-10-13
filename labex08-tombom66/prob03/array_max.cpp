#include "array_max.hpp"
int arrayMax(int array[], int size) {
  int value;
  if (size == 1) {
    return array[size - 1];
  } else {
    int max = arrayMax(array, size - 1);
    if (max > array[size - 1]) {
      return max;
    }
    return array[size - 1];
  }
}
