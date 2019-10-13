#ifndef DSA_HPP
#define DSA_HPP
#include <iostream>
class Student {
private:
  std::string name_;
  int id_;

public:
  Student() : name_("Stu Dent"), id_(123456789) {}
  void setName(std::string name) { name_ = name; } // mutators
  void setId(int id) { id_ = id; }
  std::string getName() { return name_; }
  int getId() { return id_; } // accessors
};
class Classroom {
private:
  Student *student_;
  int numStudents_;

public:
  Classroom() {
    numStudents_ = 0;
    student_ = nullptr;
  }
  int getNumStudents() { return numStudents_; }
  ~Classroom() { delete[] student_; }
  void populate(std::string filename);
  void list();
};

// Create the `Student` class  below...

// Create the `Classroom` class below...

#endif
