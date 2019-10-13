#include "bubble.hpp"
#include <iomanip>
#include <iostream>
int main() {
  Bubble bubble1, bubble2, bubble3, output;
  bubble3 = combine_bubble(bubble1, bubble2);

  // Create two bubble objects called bubble1 and bubble2

  double radius1, radius2;
  std::cout << "Please enter the radius of the first bubble: ";
  std::cin >> radius1;
  bubble1.set_radius(radius1);
  // Set the radius of bubble1 to radius1

  std::cout << "Please enter the radius of the second bubble: ";
  std::cin >> radius2;
  bubble2.set_radius(radius2);

  // Set the radius of bubble2 to radius2

  // Create a new bubble object called output
  output = combine_bubble(bubble1, bubble2);
  // Call the combine_bubble function to combine the bubble1 and bubble2 objects
  // then store the result in the output variable

  double volume;
  volume = output.volume();
  // Get the volume of output and store in the the variable called volume

  std::cout
      << "The bubbles have now combined and create a bubble with the volume "
         "of: "
      << std::fixed << std::setprecision(2) << volume << std::endl;

  return 0;
}
