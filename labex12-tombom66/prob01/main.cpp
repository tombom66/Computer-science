#include "doctors_schedule.hpp"
#include <iostream>
int main() {
  int num;
  Appointment obj;
  std::cout << "How many appointments does the doctor have?: ";
  std::cin >> num;
  std::cin.ignore();
  DoctorSchedule schedule = DoctorSchedule(num);
  // contruct the `DoctorSchedule` here using the input we just got
  // and store it in a variable called `schedule`

  // The following loop should:
  // 1. output the doctor's current appointment
  // 2. wait until the user hits enter to move on to the next appointment
  char j;
  while (schedule.isFinished() == false) {
    // output the current appointment
    std::cout << schedule.getCurrentAppointment();

    // This block pauses the loop until the user hits enter.
    std::cout << "Press enter to move on to the next appointment";
    std::cin.get();
    schedule.moveToNextAppointment();
    // use `schedule` to move to the next appointment
  }
  std::cout << "Good work today, doctor!\n";

  return 0;
}
