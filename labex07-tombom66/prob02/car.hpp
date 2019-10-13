
#include <string>
class Car {
private:
  std::string name_;
  double price_;
  int mileage_;

public:
  std::string name() { return name_; }
  void set_name(std::string name) { name_ = name; }
  double price() { return price_; }
  void set_price(double price) { price_ = price; }
  int mileage() { return mileage_; }
  void set_mileage(int mileage) { mileage_ = mileage; }
};
int lowerst_price(Car objects[], int number);
