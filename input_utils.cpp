#include "input_utils.h"

#include <iostream>
#include <limits>
#include <string>

int ReadInt(const std::string& prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    std::cout << "Ошибка: введите целое число.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int ReadIntInRange(const std::string& prompt, int min_val, int max_val) {
  while (true) {
    int value = ReadInt(prompt);
    if (value >= min_val && value <= max_val) {
      return value;
    }
    std::cout << "Ошибка: значение должно быть от " << min_val
              << " до " << max_val << ". Повторите ввод.\n";
  }
}

unsigned int ReadUnsignedInt(const std::string& prompt) {
  int value;
  while (true) {
    value = ReadInt(prompt);
    if (value >= 0) {
      return static_cast<unsigned int>(value);
    }
    std::cout << "Ошибка: введите неотрицательное число. Повторите ввод.\n";
  }
}

int ReadIntOr(const std::string& prompt, int default_value) {
  while (true) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);

    if (line.empty()) {
      return default_value;
    }

    try {
      size_t pos = 0;
      int value = std::stoi(line, &pos);
      if (pos != line.size()) {
        std::cout << "Ошибка: введите целое число или Enter.\n";
        continue;
      }
      return value;
    } catch (...) {
      std::cout << "Ошибка: введите целое число или Enter.\n";
    }
  }
}

int ReadIntInRangeOr(const std::string& prompt, int min_val, int max_val,
                     int default_value) {
  while (true) {
    int value = ReadIntOr(prompt, default_value);
    if (value >= min_val && value <= max_val) {
      return value;
    }
    std::cout << "Ошибка: значение должно быть от " << min_val
              << " до " << max_val << ". Повторите ввод.\n";
  }
}