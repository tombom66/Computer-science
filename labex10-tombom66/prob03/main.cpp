#include "list.hpp"
#include <iostream>
int main() {
  ShoppingList s(10);
  s.addItem("Milk");
  s.addItem("Eggs");
  s.addItem("Flour");
  s.addItem("Sugar");
  s.addItem("Cocoa Powder");
  s.addItem("Vanilla");
  s.printList();
  // Create an instance of the ShoppingList object

  // Call the addItem member function to add items into the shopping list

  // Call the printList member function to display the list

  return 0;
}
