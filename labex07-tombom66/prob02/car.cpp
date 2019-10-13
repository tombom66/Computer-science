#include "car.hpp"
int lowerst_price(Car objects[], int number) {
  int lowest_index = 0;
  for (int i = 1; i < number; i++) {
    if (objects[i].price() < objects[lowest_index].price()) {
      lowest_index = i;
    }
  }
  return lowest_index;
}
