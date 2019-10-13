#ifndef FIND_NUMBER_HPP
#define FIND_NUMBER_HPP

class Numbers {
private:
  // Use these member variables
  int size_;
  int *values_;

public:
  int getSize_() { return size_; }
  int getValue_() { return *values_; }
  void setSize_(int size) { size_ = size; }

  void setValue_(int *values) {
    delete[] values_;
    values_ = values;
  }
  Numbers() {

    size_ = 10;
    values_ = new int[size_];
    for (int i = 0; i < size_; i++) {
      values_[i] = 0; // Initialize all elements to zero.
    }
  } // closes nubers
  void addIntoArray();
  void displayArray();
  void findNumber(int number);
  ~Numbers() {

    delete[] values_;
    values_ = nullptr;
  } // continue on from here
};

#endif
