#include "../bubble.hpp"
#include "gtest_ext.h"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

double compute_volume(double radius) {
  return 4.0 / 3 * 3.1415 * radius * radius * radius;
}

TEST(DoubleBubble, OutputFormat) {
  std::string unittest_output =
      "Please enter the radius of the first bubble: Please enter the radius of "
      "the second bubble: The bubbles have now combined and create a bubble "
      "with the volume of: ";
  double int1 = rand() % 50;
  double int2 = rand() % 50;
  unittest_output += to_string_double(compute_volume(int1 + int2));
  unittest_output += '\n';
  std::string input = "";
  std::string input1 = to_string_double(int1);
  std::string input2 = to_string_double(int2);
  input += input1 + " " + input2;
  ASSERT_EXECIO_EQ("main", input, unittest_output);
}

TEST(DoubleBubble, PublicMethodPresent) {
  Bubble b;
  b.radius();
  b.volume();
  b.set_radius(5);
}

TEST(DoubleBubble, MutatorsAndAccessors) {
  srand(time(NULL));
  Bubble your_bubble;

  double unittest_output = (double)rand() / RAND_MAX;

  your_bubble.set_radius(unittest_output);
  ASSERT_EQ(your_bubble.radius(), unittest_output);
}

TEST(DoubleBubble, BubbleVolumeTest) {
  srand(time(NULL));
  for (int i = 0; i < 8; i++) {
    Bubble your_bubble;
    double random_double = rand() % 50;
    your_bubble.set_radius(random_double);
    double unittest_volume = compute_volume(random_double);
    ASSERT_EQ(your_bubble.volume(), unittest_volume);
  }
}

TEST(DoubleBubble, Combine_bubbles) {
  srand(time(NULL));
  for (int i = 0; i < 8; i++) {
    Bubble your_bubble1;
    Bubble your_bubble2;
    double r1 = rand() % 50;
    double r2 = rand() % 50;
    your_bubble1.set_radius(r1);
    your_bubble2.set_radius(r2);
    Bubble your_bubble = combine_bubble(your_bubble1, your_bubble2);
    double unittest_volume = compute_volume(static_cast<double>(r1 + r2));
    ASSERT_EQ(your_bubble.volume(), unittest_volume);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
