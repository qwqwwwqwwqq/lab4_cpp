#include "time.h"

namespace {
int Normalize(int value, int limit) {
  return ((value % limit) + limit) % limit;
}
}

Time::Time() : hours_(0), minutes_(0) {}

Time::Time(int hours, int minutes) {
  hours_ = static_cast<short int>(Normalize(hours, 24));
  minutes_ = static_cast<short int>(Normalize(minutes, 60));
}

Time::Time(const Time& other) : hours_(other.hours_), minutes_(other.minutes_) {}

int Time::GetHours() const { return hours_; }

int Time::GetMinutes() const { return minutes_; }

bool Time::SetHours(int hours) {
  if (hours >= 0 && hours <= 23) {
    hours_ = static_cast<short int>(hours);
    return true;
  }
  return false;
}

bool Time::SetMinutes(int minutes) {
  if (minutes >= 0 && minutes <= 59) {
    minutes_ = static_cast<short int>(minutes);
    return true;
  }
  return false;
}

Time Time::Subtract(const Time& other) const {
  int total = (hours_ * 60 + minutes_) - (other.hours_ * 60 + other.minutes_);
  total = Normalize(total, 24 * 60);
  return Time(total / 60, total % 60);
}

Time& Time::operator--() {
  int total = hours_ * 60 + minutes_ - 1;
  total = Normalize(total, 24 * 60);
  hours_ = static_cast<short int>(total / 60);
  minutes_ = static_cast<short int>(total % 60);
  return *this;
}

Time Time::operator--(int) {
  Time old(*this);
  --(*this);
  return old;
}

Time::operator short int() const { return hours_; }

Time::operator bool() const { return hours_ != 0 || minutes_ != 0; }

Time Time::operator+(unsigned int minutes) const {
  int total = hours_ * 60 + minutes_ + static_cast<int>(minutes);
  total = Normalize(total, 24 * 60);
  return Time(total / 60, total % 60);
}

Time Time::operator+(const Time& other) const {
  int total = (hours_ * 60 + minutes_) + (other.hours_ * 60 + other.minutes_);
  total = Normalize(total, 24 * 60);
  return Time(total / 60, total % 60);
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
  if (t.hours_ < 10) os << "0";
  os << t.hours_ << ":";
  if (t.minutes_ < 10) os << "0";
  os << t.minutes_;
  return os;
}