#include <iostream>
#include "identifychar.hpp"
void identifyChar(char input)
{

      if ((input >= 'A' && input <='Z') || (input >= 'a' && input <= 'z'))
      {
            std::cout << input << " is a letter" << std::endl;
      }
      else if (input <= 57 && input >= 48) // this is the numbers between 0 and 9 for ascii menu
      {
            std::cout << input  <<  " is a number" << std::endl;
      }
      else 
      {
            std::cout << input << " is a special character"<< std::endl;
      }
}
