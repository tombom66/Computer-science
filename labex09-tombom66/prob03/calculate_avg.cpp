#include "calculate_avg.hpp"
#include <iomanip>
#include <iostream>

double calcAvg(double *array, int size) {
  double avg, total = 0;
  for (int i = 0; i < size; i++) {
    total += *(array + i);
  }
  avg = total / size;
  return avg;
}
