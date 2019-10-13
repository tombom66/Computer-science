#include <iostream>
class Bubble {

private:
  double radius_;

public:
  double radius() { return radius_; }
  void set_radius(double radius) { radius_ = radius; }
  double volume() {
    double volume_ = (4.0 / 3.0) * 3.1415 * radius_ * radius_ * radius_;
    return volume_;
  }
};
Bubble combine_bubble(Bubble bubble1, Bubble bubble2);

