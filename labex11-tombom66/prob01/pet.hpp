#include <iostream>
class Breed {
private:
  std::string species_, name_, color_;
public:
  std::string getSpecies() {return species_;}//Create accessors called getSpecies, getName, and getColor.
  std::string getName() {return name_;}
  std::string getColor(){return color_;}
  void setSpecies(std::string species){species_ = species;}//mutators
  void setName(std::string name){name_ = name;}
  void setColor(std::string color){color_ = color;}
Breed():species_("Dog"), name_("Pug"),color_("Fawn"){}//default constructor//name_ to "Pug", and color_ to "Fawn".
Breed(std::string species1, std::string name1, std::string color1): species_(species1),name_(name1),color_(color1){}
};
class  Pet {
private://std::string name_, Breed breed_ , and double weight_.
std::string name_;
Breed breed_;
double weight_;
public:
Pet(): name_("Doug"), weight_(15.6){}
Pet(std::string name1, Breed breed1, double weight1):name_(name1),breed_(breed1),weight_(weight1){} // std::string for name_, Breed for breed_, and a double for weight_ in
std::string getName(){return name_;}//Create accessors called getName, getBreed, and getWeight.
Breed getBreed(){return breed_;}
double getWeight(){return weight_;}
void setName(std::string name) {name_ = name;}
void setBreed(Breed breed) {breed_ = breed;}
void setWeight(double weight){weight_ = weight;}//Create mutators called setName, setBreed, and setWeight.
void print();

};
