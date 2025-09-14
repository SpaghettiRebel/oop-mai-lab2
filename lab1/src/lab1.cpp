#include <iostream>
#include <string>
#include "func.hpp"

int main() {
  std::string text;
  int n;
  char old_value, new_value;

  std::cout << "text: ";
  std::getline(std::cin, text);
  std::cout << "n: ";
  std::cin >> n;
  std::cout << "old_value: ";
  std::cin >> old_value;
  std::cout << "new_value: ";
  std::cin >> new_value;

  std::cout << func(text, n, old_value, new_value) << std::endl;

  return 0;
}