#include "player.hpp"
void Player::displayStat(){
  std::cout <<"Player: " << pname <<std::endl;
  std::cout <<"Health: " << health <<std::endl;
  std::cout <<"Strength: " << strength <<std::endl;
  std::cout <<"Defense: " <<defense << std::endl;
  std::cout <<"At position: " << "(" <<x <<", " << y << ")" << std::endl;
}
void Player::playerMove(){
x+=1;
y+=1;

}
bool Player::isPlayerDead(){
if(health==0){
return true;
}
else {
return false; // Otherwise, they aren't.
  }
}
void Player::takeDamage(int damage)
{
  health -=damage;
  if(health <0)
  health =0;
  std::cout <<pname << " took " <<damage << " damage." <<std::endl;
if (isPlayerDead()){
std::cout <<pname << " is dead" <<std::endl;
}
}
