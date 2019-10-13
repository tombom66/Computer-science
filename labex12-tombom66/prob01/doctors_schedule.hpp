#ifndef DOCTOR_SCHEDULE_HPP
#define DOCTOR_SCHEDULE_HPP
#include <iostream>
#include <string>

// Appointment Class
class Appointment {
private:
  std::string name_;
  std::string location_;
  std::string time_;

public:
  // Default Constructor
  Appointment() : Appointment("", "", "12:00pm") {}

  // Non-Default Constructor
  Appointment(const std::string &name, const std::string &location,
              const std::string &time)
      : name_(name), location_(location), time_(time) {}

  // Accessors and Mutators
  std::string getName() const { return name_; }
  void setName(const std::string &name) { name_ = name; }
  std::string getLocation() const { return location_; }
  void setLocation(const std::string &location) { location_ = location; }
  std::string getTime() const { return time_; }
  void setTime(const std::string &time) { time_ = time; }

  // The print member function that will return a `std::string` output
  std::string print() {
    std::string output = "You have an appointment with " + name_ + " at " +
                         time_ + ", " + location_ + "\n";
    return output;
  }
};

class DoctorSchedule : public Appointment {
private:
  Appointment *appointment_;
  int num_appointments_;
  int current_appointment_num_;
  // Create private member variables below...

public:
  int getNumAppointments() const { return num_appointments_; }
  int getCurrentAppointmentNum() const {
    return current_appointment_num_;
  }                  // still need to return the index
  bool isFinished(); //
  DoctorSchedule(int num_appointment);

  ~DoctorSchedule() { delete[] appointment_; }

  void moveToNextAppointment();
  std::string getCurrentAppointment();

  // Create all the member functions below...
};

#endif
