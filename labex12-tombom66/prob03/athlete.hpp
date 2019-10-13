#ifndef ATHLETE_HPP
#define ATHLETE_HPP
#include <iostream>
#include <string>
class Person {
private:
  std::string name_;

public:
  std::string getName() const { return name_; }
  void setName(const std::string &n) { name_ = n; }

  Person(const std::string &n) : name_(n) {}
};
class AthleticShoe {
private:
  std::string style_, color_;
  double size_;

public:
  AthleticShoe() : style_("Running"), color_("Blue"), size_(12.0) {}
  AthleticShoe(std::string style, std::string color, double size) {
    style_ = style;
    color_ = color;
    size = size_;
  }
  std::string getStyle() { return style_; }
  std::string getColor() { return color_; }
  double getSize() { return size_; } // accessors
  void setStyle(std::string style) { style_ = style; }
  void setColor(std::string color) { color_ = color; }
  void setSize(double size) { size_ = size; } // mutators
};
class Athlete : public Person {
private:
  std::string sport_;
  int height_, weight_;
  AthleticShoe *shoe_;

public:
  Athlete()
      : sport_("Cross-Country"), height_(72), weight_(180),
        Person("Tuffy Default") {
    shoe_ = new AthleticShoe;
  }
  Athlete(std::string &name, std::string sport, int height, int weight,
          AthleticShoe *shoe)
      : sport_(sport), height_(height), weight_(weight), shoe_(shoe),
        Person(name) {}
  std::string getSport() { return sport_; }
  int getHeight() { return height_; }
  int getWeight() { return weight_; }
  AthleticShoe *getShoe() { return shoe_; } // accessors
  void setSport(std::string sport) { sport_ = sport; }
  void setHeight(int height) { height_ = height; }
  void setWeight(int weight) { weight_ = weight; }
  void setShoe(AthleticShoe *shoe) { shoe_ = shoe; } // mutators
  void print();
};
// Create the `AthleticShoe` class below...

// Create the `Athlete` class below...

#endif
