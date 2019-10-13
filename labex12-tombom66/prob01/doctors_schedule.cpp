#include "doctors_schedule.hpp"
#include <iostream>
DoctorSchedule::DoctorSchedule(int num_appointment) {
  // Make sure that the constructor initializes the following data members:
  // initialize `num_appointments_` to the variable passed in
  // initialize `appointment_` to a dynamically allocated array of `Appointment`
  // objects whose size is based on `num_appointment`

  num_appointments_ = num_appointment;
  appointment_ = new Appointment[num_appointments_];
  for (int i = 0; i < num_appointments_; i++) {
    std::string name, location, time;
    std::cout << "Who is this appointment with?: ";
    std::getline(std::cin, name);
    std::cout << "Where is this appointment?: ";
    std::getline(std::cin, location);
    std::cout << "What time is this appointment?: ";
    std::getline(std::cin, time);
    appointment_[i] = Appointment(name, location, time);

    // Create an `Appointment` object according to the user input

    // Set the appointment at this index of the array.

    std::cout << "\n\n";
  }
  current_appointment_num_ = 0;
  // Initiatlize `current_appointment_num_` to ensure it is the first
  // appointment.
}
bool DoctorSchedule::isFinished() {
  if (current_appointment_num_ >= num_appointments_) {
    return true;
  } else {
    return false;
  }
}
void DoctorSchedule::moveToNextAppointment() { current_appointment_num_++; }
std::string DoctorSchedule::getCurrentAppointment() {
  std::string currently;

  for (int i = 0; i < num_appointments_; i++) {
    if (i == current_appointment_num_) {
      currently = (appointment_ + i)->print();
    }
  }

  return currently;
}
