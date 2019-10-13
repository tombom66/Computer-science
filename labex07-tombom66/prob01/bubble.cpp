#include "bubble.hpp"
#include <iostream>
Bubble combine_bubble(Bubble bubble1, Bubble bubble2) {
  double bubble = bubble1.radius() + bubble2.radius();
  Bubble bubble4;
  bubble4.set_radius(bubble);
  return bubble4;
}
