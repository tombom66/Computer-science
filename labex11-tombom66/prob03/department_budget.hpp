#include <fstream>
#include <iostream>
class DepartmentBudget {
private:
  std::string name_;
  double budget_, current_balance_;

public:
  std::string getName() { return name_; } // Create accessors
  double getBudget() { return budget_; }
  double getCurrentBalance() { return current_balance_; }

  void setName(std::string name) { name_ = name; } // mutators
  void setBudget(double budget) {
    budget_ = budget;
    current_balance_ = budget;
  } // still need to work on how to use
    // the 2 data members
  void setCurrentBalance(double balance) { current_balance_ = balance; }
  void recordSpending(double record) {
    current_balance_ += record;
  } // recorddpending need to work on
  DepartmentBudget() : name_("NULL"), budget_(100.0), current_balance_(100.0) {}
  // default constructor

  DepartmentBudget(std::string filename); // non default constructor
};
