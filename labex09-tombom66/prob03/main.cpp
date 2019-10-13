#include "calculate_avg.hpp"
#include <iomanip>
#include <iostream>

int main() {
  int size;
  // Make the appropriate declaration for a variable that can handle a
  // dynamically allocated array of type double.

  std::cout << "How many students are in your class? ";
  std::cin >> size;

  double *array = new double[size];

  // Add error checking to ensure the value entered is valid.
  if (size <= 0) {
    std::cout << "You have no class!\n";
  } else {
    // Allocate the array

    std::cout << "Enter the GPA for each student in your class (0.0 - 4.0)\n";

    for (int i = 0; i < size; i++) {
      std::cout << "Enter the GPA for student #" << i + 1 << ": ";
      // Assign values from cin into indicies of the array.
      std::cin >> *(array + i);
    }

    // Call the function to calclate the average here.
    double avg = calcAvg(array, size);

    // Display the class average with a precision of 2 decimal places.
    std::cout << "Class average: " << std::fixed << std::setprecision(2) << avg
              << std::endl;

    // Deallocate
    delete[] array;
  }

  return 0;
}
