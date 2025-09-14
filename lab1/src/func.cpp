#include "func.hpp"
#include <string>

std::string func(std::string text, int n, char old_value, char new_value) {
  if (n <= 0)
    return text;

  std::string ans = text;
  int i{0}, count{0};

  while (text[i] != '\0') {
    if (text[i] == old_value)
      count = (++count) % n;
    if (text[i] == old_value && count == 0)
      ans[i] = new_value;
    i++;
  }
  return ans;
}