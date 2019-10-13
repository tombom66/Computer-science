#include "../doctors_schedule.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

const std::string RANDOM_TIMES[10] = {
    "5:40p.m.", "4:15p.m",   "3:10p.m", "8:00a.m.", "10:45a.m.",
    "2:10p.m.", "11:20a.m.", "9:25a.m", "6:50p.m.", "7:00p.m."};
void generate_inputset(std::string &output, std::string &input,
                       std::string name[], std::string location[],
                       std::string times[], int num) {
  std::ostringstream test_output;
  std::ostringstream test_input;
  for (int i = 0; i < num; i++) {
    test_output << "Who is this appointment with?: ";
    name[i] = generate_string(30);
    test_input << name[i] << "\n";
    test_output << "Where is this appointment?: ";
    location[i] = generate_string(30);
    test_input << location[i] << "\n";
    test_output << "What time is this appointment?: ";
    times[i] = RANDOM_TIMES[rand() % 10];
    test_input << times[i] << "\n";
    test_output << "\n\n";
  }
  input = test_input.str();
  output = test_output.str();
}

TEST(DoctorSchedule, OutputFormat) {
  std::ostringstream test_output;
  std::ostringstream test_input;

  srand(time(NULL));
  int num = rand() % 10;
  std::string name[num];
  std::string location[num];
  std::string times[num];
  test_output << "How many appointments does the doctor have?: ";
  test_input << num << "\n";
  for (int i = 0; i < num; i++) {
    test_output << "Who is this appointment with?: ";
    name[i] = generate_string(30);
    test_input << name[i] << "\n";
    test_output << "Where is this appointment?: ";
    location[i] = generate_string(30);
    test_input << location[i] << "\n";
    test_output << "What time is this appointment?: ";
    times[i] = RANDOM_TIMES[rand() % 10];
    test_input << times[i] << "\n";
    test_output << "\n\n";
  }
  for (int i = 0; i < num; i++) {
    test_output << "You have an appointment with " << name[i] << " at "
                << times[i] << ", " << location[i] << "\n";
    test_output << "Press enter to move on to the next appointment";
    test_input << "\n";
  }
  test_output << "Good work today, doctor!\n";

  std::string unittest_output = test_output.str();
  std::string unittest_input = test_input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(DoctorSchedule, Constructor) {
  std::string unittest_input;
  std::string unittest_output;
  std::string name[5];
  std::string location[5];
  std::string times[5];
  generate_inputset(unittest_output, unittest_input, name, location, times, 5);

  ASSERT_SIO_EQ(unittest_input, unittest_output, {
    DoctorSchedule your_doctor_schedule(5);
    ASSERT_EQ(your_doctor_schedule.currentAppointmentNum(), 0);
    ASSERT_EQ(your_doctor_schedule.getNumAppointments(), 5);
  });
}

TEST(DoctorSchedule, CurrentAppointment) {
  std::string unittest_input;
  std::string unittest_output;
  std::string name[5];
  std::string location[5];
  std::string times[5];
  generate_inputset(unittest_output, unittest_input, name, location, times, 5);
  std::ostringstream curr1;
  curr1 << "You have an appointment with " << name[0] << " at " << times[0]
        << ", " << location[0] << "\n";
  ASSERT_SIO_EQ(unittest_input, unittest_output, {
    DoctorSchedule your_doctor_schedule(5);
    std::string unittest_output2 = curr1.str();
    ASSERT_EQ(your_doctor_schedule.getCurrentAppointment(), unittest_output2);
  });
}

TEST(DoctorSchedule, NextAppointment) {
  std::string unittest_input;
  std::string unittest_output;
  std::string name[2];
  std::string location[2];
  std::string times[2];
  generate_inputset(unittest_output, unittest_input, name, location, times, 2);
  std::ostringstream curr1;
  curr1 << "You have an appointment with " << name[0] << " at " << times[0]
        << ", " << location[0] << "\n";
  std::ostringstream curr2;
  curr2 << "You have an appointment with " << name[1] << " at " << times[1]
        << ", " << location[1] << "\n";
  ASSERT_SIO_EQ(unittest_input, unittest_output, {
    DoctorSchedule your_doctor_schedule(2);
    std::string unittest_output2 = curr1.str();
    ASSERT_EQ(your_doctor_schedule.getCurrentAppointment(), unittest_output2);
    your_doctor_schedule.moveToNextAppointment();
    std::string unittest_output3 = curr2.str();
    ASSERT_EQ(your_doctor_schedule.getCurrentAppointment(), unittest_output3);
  });
}

TEST(DoctorSchedule, FinishedAppointment) {
  std::string unittest_input;
  std::string unittest_output;
  std::string name[5];
  std::string location[5];
  std::string times[5];
  generate_inputset(unittest_output, unittest_input, name, location, times, 5);
  std::ostringstream curr1;
  curr1 << "You have an appointment with " << name[0] << " at " << times[0]
        << ", " << location[0] << "\n";
  std::ostringstream curr2;
  curr2 << "You have an appointment with " << name[1] << " at " << times[1]
        << ", " << location[1] << "\n";
  ASSERT_SIO_EQ(unittest_input, unittest_output, {
    DoctorSchedule your_doctor_schedule(5);
    your_doctor_schedule.moveToNextAppointment();
    your_doctor_schedule.moveToNextAppointment();
    your_doctor_schedule.moveToNextAppointment();
    your_doctor_schedule.moveToNextAppointment();
    your_doctor_schedule.moveToNextAppointment();
    ASSERT_EQ(your_doctor_schedule.isFinished(), true);
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
