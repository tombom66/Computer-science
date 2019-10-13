#include <iostream>
class ShoppingList {
private:
  std::string *list_;
  int numItems_, listSize_;

public:
  int getNumItems() { return numItems_; }
  int getListSize() { return listSize_; }
  ShoppingList() : listSize_(10), numItems_(0) { list_ = new std::string[10]; }
  // default constructor

  ShoppingList(int size) : listSize_(size), numItems_(0) {
    list_ = new std::string[size];
  }
  // non default constructor

  ~ShoppingList() {
    delete[] list_;
    list_ = nullptr;
  }
  void addItem(std::string add);
  void removeLast();
  void printList();
};
