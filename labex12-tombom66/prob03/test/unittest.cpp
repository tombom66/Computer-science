#include "../athlete.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(Athlete, OutputFormat) {
  std::ostringstream s, input;

  s << "Please enter the athlete's sport (q to quit): ";
  input << "Baseball\n";
  s << "Please enter the athlete's name: ";
  input << "Tuffy One\n";
  s << "Please enter the athlete's height (in): ";
  input << "74\n";
  s << "Please enter the athlete's weight (lbs): ";
  input << "195\n";
  s << "Please enter the shoe style: ";
  input << "Cleats\n";
  s << "Please enter the shoe color: ";
  input << "Red & White\n";
  s << "Please enter the shoe size (in): ";
  input << "12.5\n";
  s << "Please enter the athlete's sport (q to quit): ";
  input << "Basketball\n";
  s << "Please enter the athlete's name: ";
  input << "Tuffy Two\n";
  s << "Please enter the athlete's height (in): ";
  input << "66\n";
  s << "Please enter the athlete's weight (lbs): ";
  input << "150\n";
  s << "Please enter the shoe style: ";
  input << "Basketball\n";
  s << "Please enter the shoe color: ";
  input << "Blue & Gold\n";
  s << "Please enter the shoe size (in): ";
  input << "9\n";
  s << "Please enter the athlete's sport (q to quit): ";
  input << "q\n";
  s << "Printing Athletes:\n";
  s << "Athlete 1\n";
  s << "Name:   Tuffy One\n";
  s << "Sport:  Baseball\n";
  s << "Height: 74in\n";
  s << "Weight: 195lbs\n";
  s << "Shoe:\n";
  s << "  Style:  Cleats\n";
  s << "  Color:  Red & White\n";
  s << "  Size:   12.5in\n";
  s << "Athlete 2\n";
  s << "Name:   Tuffy Two\n";
  s << "Sport:  Basketball\n";
  s << "Height: 66in\n";
  s << "Weight: 150lbs\n";
  s << "Shoe:\n";
  s << "  Style:  Basketball\n";
  s << "  Color:  Blue & Gold\n";
  s << "  Size:   9in\n";

  std::string unittest_output = s.str();
  std::string unittest_input = input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(Athlete, DefaultConstructor) {
  Athlete your_athlete;
  ASSERT_EQ(your_athlete.getShoe()->getStyle(), "Running");
  ASSERT_EQ(your_athlete.getShoe()->getColor(), "Blue");
  ASSERT_EQ(your_athlete.getShoe()->getSize(), 12.0);
  ASSERT_EQ(your_athlete.getSport(), "Cross-Country");
  ASSERT_EQ(your_athlete.getHeight(), 72);
  ASSERT_EQ(your_athlete.getWeight(), 180);
  std::string unittest_output = "Name:   Tuffy Default\n"
                                "Sport:  Cross-Country\n"
                                "Height: 72in\n"
                                "Weight: 180lbs\n"
                                "Shoe:\n"
                                "  Style:  Running\n"
                                "  Color:  Blue\n"
                                "  Size:   12in\n";
  ASSERT_SIO_EQ("", unittest_output, { your_athlete.print(); });
}

TEST(Athlete, NonDefaultConstructor) {
  std::string unittest_style = "Tennis", unittest_color = "Black",
              unittest_sport = "Tennis", unittest_name = "Tuffy";
  int unittest_height = 70, unittest_weight = 170;
  double unittest_size = 11.5;
  AthleticShoe *your_athletic_shoe =
      new AthleticShoe(unittest_style, unittest_color, unittest_size);
  Athlete your_athlete(unittest_name, unittest_sport, unittest_height, unittest_weight,
                       your_athletic_shoe);
  ASSERT_EQ(your_athlete.getShoe()->getStyle(), unittest_style);
  ASSERT_EQ(your_athlete.getShoe()->getColor(), unittest_color);
  ASSERT_EQ(your_athlete.getShoe()->getSize(), unittest_size);
  ASSERT_EQ(your_athlete.getName(), unittest_name);
  ASSERT_EQ(your_athlete.getSport(), unittest_sport);
  ASSERT_EQ(your_athlete.getHeight(), unittest_height);
  ASSERT_EQ(your_athlete.getWeight(), unittest_weight);
  std::string unittest_output = "Name:   Tuffy\n"
                                "Sport:  Tennis\n"
                                "Height: 70in\n"
                                "Weight: 170lbs\n"
                                "Shoe:\n"
                                "  Style:  Tennis\n"
                                "  Color:  Black\n"
                                "  Size:   11.5in\n";
  ASSERT_SIO_EQ("", unittest_output, { your_athlete.print(); });
}

TEST(Athlete, AccessorAndMutator) {
  Athlete your_athlete;
  AthleticShoe *your_athletic_shoe = new AthleticShoe;
  std::string unittest_style = "Flats", unittest_color = "Beige",
              unittest_sport = "Ballet", unittest_name = "Tuffy";
  int unittest_height = 62, unittest_weight = 110;
  double unittest_size = 6.5;
  your_athletic_shoe->setStyle(unittest_style);
  your_athletic_shoe->setColor(unittest_color);
  your_athletic_shoe->setSize(unittest_size);
  your_athlete.setName(unittest_name);
  your_athlete.setSport(unittest_sport);
  your_athlete.setShoe(your_athletic_shoe);
  your_athlete.setHeight(unittest_height);
  your_athlete.setWeight(unittest_weight);
  ASSERT_EQ(your_athlete.getShoe()->getStyle(), unittest_style);
  ASSERT_EQ(your_athlete.getShoe()->getColor(), unittest_color);
  ASSERT_EQ(your_athlete.getShoe()->getSize(), unittest_size);
  ASSERT_EQ(your_athlete.getName(), unittest_name);
  ASSERT_EQ(your_athlete.getSport(), unittest_sport);
  ASSERT_EQ(your_athlete.getHeight(), unittest_height);
  ASSERT_EQ(your_athlete.getWeight(), unittest_weight);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
