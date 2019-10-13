#include "../pet.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Pet, OutputFormat) {
  std::ostringstream s, input;

  s << "Please enter the pet's name (q to quit): ";
  input << "AirBud\n";
  s << "Please enter the pet's species: ";
  input << "Dog\n";
  s << "Please enter the pet's breed: ";
  input << "Golden Retriever\n";
  s << "Please enter the pet's color: ";
  input << "Blonde\n";
  s << "Please enter the pet's weight (lbs): ";
  input << "44.5\n";
  s << "Please enter the pet's name (q to quit): ";
  input << "Cookie\n";
  s << "Please enter the pet's species: ";
  input << "Dog\n";
  s << "Please enter the pet's breed: ";
  input << "English Bulldog\n";
  s << "Please enter the pet's color: ";
  input << "Brown & White\n";
  s << "Please enter the pet's weight (lbs): ";
  input << "31.2\n";
  s << "Please enter the pet's name (q to quit): ";
  input << "q\n";
  s << "Printing Pets:\n";
  s << "Pet 1\n";
  s << "Name:   AirBud\n";
  s << "Species:Dog\n";
  s << "Breed:  Golden Retriever\n";
  s << "Color:  Blonde\n";
  s << "Weight: 44.5 lbs\n";
  s << "Pet 2\n";
  s << "Name:   Cookie\n";
  s << "Species:Dog\n";
  s << "Breed:  English Bulldog\n";
  s << "Color:  Brown & White\n";
  s << "Weight: 31.2 lbs\n";
  std::string unittest_input = input.str();
  std::string unittest_output = s.str();
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(Pet, DefaultConstructor) {
  Pet your_pet;
  ASSERT_EQ(your_pet.getBreed().getSpecies(), "Dog");
  ASSERT_EQ(your_pet.getBreed().getName(), "Pug");
  ASSERT_EQ(your_pet.getName(), "Doug");
  ASSERT_EQ(your_pet.getBreed().getColor(), "Fawn");
  ASSERT_EQ(your_pet.getWeight(), 15.6);
  std::string unittest_output = "Name:   Doug\n"
                                "Species:Dog\n"
                                "Breed:  Pug\n"
                                "Color:  Fawn\n"
                                "Weight: 15.6 lbs\n";
  ASSERT_SIO_EQ("", unittest_output, { your_pet.print(); });
}

TEST(Pet, NonDefaultConstructor) {
  Breed your_breed("Cat", "Tabby", "Orange");
  Pet your_pet("Pumpkin", your_breed, 16.8);
  ASSERT_EQ(your_pet.getBreed().getSpecies(), "Cat");
  ASSERT_EQ(your_pet.getBreed().getName(), "Tabby");
  ASSERT_EQ(your_pet.getName(), "Pumpkin");
  ASSERT_EQ(your_pet.getBreed().getColor(), "Orange");
  ASSERT_EQ(your_pet.getWeight(), 16.8);
  std::string unittest_output = "Name:   Pumpkin\n"
                                "Species:Cat\n"
                                "Breed:  Tabby\n"
                                "Color:  Orange\n"
                                "Weight: 16.8 lbs\n";
  ASSERT_SIO_EQ("", unittest_output, { your_pet.print(); });
}

TEST(Pet, AccessorsAndMutators) {
  Pet your_pet;
  Breed your_breed("Dog", "American Pitbull Terrier", "Blonde");
  your_pet.setBreed(your_breed);
  your_pet.setName("Mimi");
  your_pet.setWeight(38.4);
  ASSERT_EQ(your_pet.getBreed().getSpecies(), "Dog");
  ASSERT_EQ(your_pet.getBreed().getName(), "American Pitbull Terrier");
  ASSERT_EQ(your_pet.getName(), "Mimi");
  ASSERT_EQ(your_pet.getBreed().getColor(), "Blonde");
  ASSERT_EQ(your_pet.getWeight(), 38.4);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
