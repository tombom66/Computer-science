#include "dsa.hpp"
#include <fstream>
#include <iostream>
#include <string>
void Classroom::populate(std::string filename) {
  std::string temp_stu_;
  int temp_id_;
  std::ifstream inputFile;
  inputFile.open(filename);
  if (inputFile.fail() == true) {
    std::cout << "Error!\n";
  } else {
    inputFile >> numStudents_;
    inputFile.ignore();
    if (student_ == nullptr) {
      delete[] student_;
    }
    student_ = new Student[numStudents_];
    for (int i = 0; i < numStudents_; i++) {
      std::getline(inputFile, temp_stu_);
      student_[i].setName(temp_stu_);
      inputFile.ignore(1, '\n');
      inputFile >> temp_id_;
      student_[i].setId(temp_id_);
      inputFile.ignore(1, '\n');
    }
  }
  inputFile.close();
}
void Classroom::list() {
  std::cout << "Student List \n";
  for (int i = 0; i < numStudents_; i++) {
    std::cout << (i + 1) << ". " << student_[i].getId() << " "
              << student_[i].getName() << std::endl;
  }
}
