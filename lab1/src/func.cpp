#include "func.hpp"
#include <string>

std::string func(std::string text, int n, char old_value, char new_value) {
  if (n <= 0)
    return text;

  int count{0};

  for (size_t i = 0; i < text.size(); ++i) {
    if (text[i] == old_value) {
      if ((++count) % n == 0)
        text[i] = new_value;
    }
  }
  return text;
}