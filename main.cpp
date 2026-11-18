#include <clocale>
#include <iostream>

#include "input_utils.h"
#include "time.h"

namespace {

Time ReadTime(const std::string& label) {
  std::cout << "\n" << label << "\n";
  int h = ReadIntInRange("Введите часы (0-23): ", 0, 23);
  int m = ReadIntInRange("Введите минуты (0-59): ", 0, 59);
  return Time(h, m);
}

void DemoConstructors() {
  std::cout << "\nДемонстрация конструкторов\n";

  int h1 = ReadIntInRangeOr(
      "Введите часы для конструктора по умолчанию (Enter -> 0): ", 0, 23, 0);
  int m1 = ReadIntInRangeOr(
      "Введите минуты для конструктора по умолчанию (Enter -> 0): ", 0, 59, 0);
  Time t1(h1, m1);
  std::cout << "1. По умолчанию: " << t1 << "\n";

  int h2 = ReadIntInRangeOr(
      "Введите часы для Time(h, m) (Enter -> 0): ", 0, 23, 0);
  int m2 = ReadIntInRangeOr(
      "Введите минуты для Time(h, m) (Enter -> 0): ", 0, 59, 0);
  Time t2(h2, m2);
  std::cout << "2. С параметрами: " << t2 << "\n";

  Time t3(t2);
  std::cout << "3. Копирования (копия t2): " << t3 << "\n";
}

void DemoProperties() {
  std::cout << "\nДемонстрация свойств\n";
  Time t = ReadTime("Исходное время:");
  std::cout << "Текущее: " << t << "\n";

  while (true) {
    int new_h = ReadInt("Введите новые часы (0-23): ");
    if (t.SetHours(new_h)) {
      std::cout << "SetHours применён. Время: " << t << "\n";
      break;
    }
    std::cout << "Ошибка: часы должны быть 0-23. Повторите.\n";
  }

  while (true) {
    int new_m = ReadInt("Введите новые минуты (0-59): ");
    if (t.SetMinutes(new_m)) {
      std::cout << "SetMinutes применён. Время: " << t << "\n";
      break;
    }
    std::cout << "Ошибка: минуты должны быть 0-59. Повторите.\n";
  }

  std::cout << "GetHours = " << t.GetHours()
            << ", GetMinutes = " << t.GetMinutes() << "\n";
}

void DemoSubtract() {
  std::cout << "\nЗадание 1: Subtract (вычитание времени)\n";
  Time a = ReadTime("Время A:");
  Time b = ReadTime("Время B:");
  Time c = a.Subtract(b);
  std::cout << a << " - " << b << " = " << c
            << "  (переход в предыдущие сутки, если A < B)\n";
}

void DemoUnary() {
  std::cout << "\nЗадание 2: унарный --\n";
  Time t = ReadTime("Исходное время:");
  std::cout << "Исходное: " << t << "\n";

  Time prefix = t;
  --prefix;
  std::cout << "После --t (префиксный): " << prefix << "\n";

  Time post = t;
  Time old = post--;
  std::cout << "После t-- (постфиксный): объект = " << post
            << ", вернулось = " << old << "\n";
}

void DemoCast() {
  std::cout << "\nЗадание 2: приведение типа\n";
  Time t = ReadTime("Время:");
  short int h = static_cast<short int>(t);
  std::cout << "static_cast<short int>(t) = " << h << " (только часы)\n";
  std::cout << "if (t) -> " << (t ? "true" : "false")
            << " (true, если не 00:00)\n";
}

void DemoBinary() {
  std::cout << "\nЗадание 2: бинарные +\n";
  Time t = ReadTime("Время:");

  unsigned int mins = ReadUnsignedInt("Сколько минут добавить (>= 0): ");
  std::cout << t << " + " << mins << " мин = " << (t + mins) << "\n";

  Time other = ReadTime("Второе время для сложения:");
  std::cout << t << " + " << other << " = " << (t + other)
            << "  (переход в следующие сутки)\n";
}

}

int main() {
  setlocale(LC_ALL, "Russian");

  std::cout << "Лабораторная работа №4. Вариант 14\n";
  std::cout << "Класс Time: вычитание, --, приведение, сложение\n";

  DemoConstructors();
  DemoProperties();
  DemoSubtract();
  DemoUnary();
  DemoCast();
  DemoBinary();

  return 0;
}