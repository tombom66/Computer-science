#include "dsa.hpp"
#include <iostream>
int main() {
  Classroom cpsc121;
  cpsc121.populate("students.txt");
  cpsc121.list();

  return 0;
}
