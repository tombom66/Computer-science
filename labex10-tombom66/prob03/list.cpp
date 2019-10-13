#include "list.hpp"
#include <iostream>
void ShoppingList::addItem(std::string add) {
  if (numItems_ < listSize_) {
    list_[numItems_++] = add;
  }
}
void ShoppingList::removeLast() {
  if (numItems_ > 0) {
    list_[--numItems_] = "";
  }
}
void ShoppingList::printList() {
  std::cout << "Shopping List:" << std::endl;
  for (int i = 0; i < numItems_; i++) {
    std::cout << i + 1 << ")" << list_[i] << std::endl;
  }
}
