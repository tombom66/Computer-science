#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <fstream>
#include "gtest_ext.h"
#include "../dsa.hpp"

TEST(DSA, OutputFormat)
{
  std::string unittest_output = "Student list\n1. 505895605 Lonnie Hansen\n"
                         "2. 265588505 Sunny To\n3. 161732427 Leah Smith\n"
                         "4. 877254949 San Tran\n5. 644480729 Andrew Gomez\n";
  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(Student, PublicMethodsPresent) {
  Student your_student;
  your_student.getName();
  your_student.getId();
  your_student.setName(generate_string(10));
  your_student.setId(rand());
}

TEST(Student, DefaultConstructor) {
  Student your_student;
  ASSERT_EQ(your_student.getName(), "Stu Dent");
  ASSERT_EQ(your_student.getId(), 123456789);
}

TEST(Student, NonDefaultConstructor) {
  std::string unittest_random_name = generate_string(10);
  int unittest_random_id = rand() % 1000;
  Student your_student(unittest_random_name, unittest_random_id);
  ASSERT_EQ(your_student.getName(), unittest_random_name);
  ASSERT_EQ(your_student.getId(), unittest_random_id);
}

TEST(Classroom, PublicMethodsPresentAndPopulate) {
  Classroom your_classroom;
  your_classroom.getNumStudents();
  your_classroom.populate("students.txt");
  std::string unittest_output = "Student list\n1. 505895605 Lonnie Hansen\n"
                         "2. 265588505 Sunny To\n3. 161732427 Leah Smith\n"
                         "4. 877254949 San Tran\n5. 644480729 Andrew Gomez\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_classroom.list();
  });
}

TEST(Classroom, DefaultConstructor) {
  Classroom your_classroom;
  ASSERT_EQ(your_classroom.getNumStudents(), 0);
}

TEST(Classroom, NonDefaultConstructor) {
  std::string unittest_random_name = generate_string(10);
  int unittest_random_id = rand() % 1000;
  Student your_student(unittest_random_name, unittest_random_id);
  ASSERT_EQ(your_student.getName(), unittest_random_name);
  ASSERT_EQ(your_student.getId(), unittest_random_id);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
