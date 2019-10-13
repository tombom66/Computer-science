#include <iostream>
#include "pet.hpp"
const int MAX_SIZE = 100;

int main()
{
  // Create an array of MAX_SIZE Pet objects called `pet_arr`
Pet pet_arr[MAX_SIZE];
  int num_pet = 0;
  std::string name, breed, species, color;
  double weight;

  do {
    std::cout << "Please enter the pet's name (q to quit): ";
    std::getline(std::cin, name);

    if (name == "q") {
      continue;
    }

    std::cout << "Please enter the pet's species: ";
    std::getline(std::cin, species);
    std::cout << "Please enter the pet's breed: ";
    std::getline(std::cin, breed);
    std::cout << "Please enter the pet's color: ";
    std::getline(std::cin, color);
    std::cout << "Please enter the pet's weight (lbs): ";
    std::cin >> weight;
    std::cin.ignore();

    // Create a breed object using the input from the user
  // Create a pet object using the input from the user

  Breed userinput(species, name, color);
  Pet userinput_(name,userinput,weight);
  pet_arr[num_pet] = userinput_;
  num_pet++;
    // Store the newly-created pet object into the array. Use `num_pet` to
    // control the index where the pet object is placed and update it
    // accordingly

  } while (name != "q");

  std::cout << "Printing Pets:\n";
// Create a pet object using the input from the user
  for (int i = 0; i < num_pet; i++) {
    std::cout << "Pet " << i + 1 << "\n";
    pet_arr[i].print();
    // Print information about the `i`th pet object
  }
  return 0;
}
