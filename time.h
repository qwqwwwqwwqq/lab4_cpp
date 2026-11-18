#ifndef LAB4_TIME_H_
#define LAB4_TIME_H_

#include <iostream>

class Time {
 public:
  Time();
  Time(int hours, int minutes);
  Time(const Time& other);

  int GetHours() const;
  int GetMinutes() const;
  bool SetHours(int hours);
  bool SetMinutes(int minutes);

  Time Subtract(const Time& other) const;

  Time& operator--();
  Time operator--(int);

  explicit operator short int() const;
  operator bool() const;

  Time operator+(unsigned int minutes) const;
  Time operator+(const Time& other) const;

  friend std::ostream& operator<<(std::ostream& os, const Time& t);

 private:
  short int hours_;
  short int minutes_;
};

#endif