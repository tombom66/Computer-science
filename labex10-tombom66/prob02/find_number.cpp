// DO NOT CHANGE/EDIT THIS MEMBER FUNCTION
#include "find_number.hpp"
#include <iostream>
void Numbers::addIntoArray() {
  // numer
  for (int i = 0; i < size_; i++) {
    *(values_ + i) = i * 2 + 2;
  }
}
void Numbers::displayArray() {
  for (int i = 0; i < size_; i++) {
    std::cout << *(values_ + i) << " ";
  }
}

void Numbers::findNumber(int number) {
  int a = number;
  for (int i = 0; i < getSize_(); i++) {

    if (*(values_ + i) == a) {
      std::cout << " \n" << a << " is in the array";
    }
  }
}

// int a = number;
// for from 0 to < getsize
// if a == get value;
// cout a "is in the array"

//  if (array[number] == i) {    std::cout << "dsa";
// Initialize all elements to zero.

// ADD REMAINING MEMBER FUNCTIONS
