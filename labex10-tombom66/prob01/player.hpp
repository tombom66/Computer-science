#include <iostream>
class Player{
private:
  int x, y, health, strength, defense;
  std::string pname;

public://setXpos, setYpos, setName, setHealth, setStrength, and setDefense.
  int getXpos() {return x;}
  int getYpos() {return y;}
  std::string getName() {return pname;}
  int getHealth() {return health;}
  int getStrength() {return strength;}
  int getDefense() {return defense;}
  void setXpos(int x_) {x = x_;}
  void setYpos(int y_){y=y_;}
  void setName(std::string pname_) {pname=pname_;}
  void setHealth(int health_){health=health_;}
  void setStrength(int strength_){strength=strength_;}
  void setDefense(int defense_) {defense=defense_;}
  void displayStat();
  void playerMove();
  bool isPlayerDead();
  void takeDamage(int damage);
  Player(){ //default constructor
    x=0;
    y=0;
    pname="bob";
    health=10;
    strength=5;
    defense=2;
  }
  Player(std::string pname1,int health1,int strength1,int defense1,int x1, int y1){//non default constructor1
    x=x1;
    y=y1;
    health=health1;
    strength=strength1;
    defense=defense1;
    pname= pname1;
  }
};
