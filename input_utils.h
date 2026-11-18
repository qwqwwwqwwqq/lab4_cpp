#ifndef LAB4_INPUT_UTILS_H_
#define LAB4_INPUT_UTILS_H_

#include <string>

int ReadInt(const std::string& prompt);
int ReadIntInRange(const std::string& prompt, int min_val, int max_val);
unsigned int ReadUnsignedInt(const std::string& prompt);

int ReadIntOr(const std::string& prompt, int default_value);
int ReadIntInRangeOr(const std::string& prompt, int min_val, int max_val,
                     int default_value);

#endif