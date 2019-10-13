#include <iostream>
#include "power.hpp"
int power(int base_input, int power_input)
{
    int result = 1;
    for(int i = 0; i < power_input; ++i){
        result *= base_input;
    }

    std::cout << base_input<< " ^ "<<  power_input << " = "<<result << std::endl;
}
