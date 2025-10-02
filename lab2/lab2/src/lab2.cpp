#include "func.hpp"

void print_separator() {
  std::cout << "\n------------------------------------------------\n";
}

int main() {

  print_separator();
  std::cout << "1. Демонстрация Конструкторов\n";
  
  Four zero;
  std::cout << "1a) Four(): ";
  zero.print(std::cout) << " (Размер: 0)\n";

  try {
      Four from_dec_1(21);
      std::cout << "1b) Four(21): ";
      from_dec_1.print(std::cout) << "21\n";
      
      Four from_dec_2(16);
      std::cout << "    Four(16): ";
      from_dec_2.print(std::cout) << std::endl;
  } catch (const std::exception& e) {
      std::cerr << "!!! ОШИБКА Конструктора Four(unsigned int): " << e.what() << "\n";
  }
  
  Four from_list_1{2, 0, 1}; 
  std::cout << "1c) Four{2, 0, 1}: ";
  from_list_1.print(std::cout) << std::endl;

  Four from_str_1("312"); 
  std::cout << "1d) Four(\"312\"): ";
  from_str_1.print(std::cout) << std::endl;

  Four copy_of_str = from_str_1;
  std::cout << "1e) Four copy_of_str = Four(\"312\"): ";
  copy_of_str.print(std::cout) << std::endl;
  
  try {
      Four invalid_str("1243");
  } catch (const std::invalid_argument& e) {
      std::cout << "1f) Проверка исключения ('1243'): Успешно. " << e.what() << "\n";
  }
  
  print_separator();
  std::cout << "2. Демонстрация Арифметических Операций\n";

  Four A("33"); 
  Four B("1"); 
  Four C("102");
  
  std::cout << "   A = 33, B = 1, C = 102\n";

  Four sum_AB = A.add(B); 
  std::cout << "2a) A.add(B) (33 + 1): ";
  sum_AB.print(std::cout) << std::endl;

  Four sum_AC = A.add(C);
  std::cout << "    A.add(C) (33 + 102): ";
  sum_AC.print(std::cout) << std::endl;

  Four sub_1 = C.sub(B); 
  std::cout << "2b) C.sub(B) (102 - 1): ";
  sub_1.print(std::cout) << std::endl;
  Four sub_2 = C.sub(A); 
  std::cout << "    C.sub(A) (102 - 33): ";
  sub_2.print(std::cout) << std::endl;

  Four sub_3 = A.sub(C); 
  std::cout << "    A.sub(C) (33 - 102): ";
  sub_3.print(std::cout) << std::endl;
  
  Four sub_4 = C.sub(C); 
  std::cout << "    C.sub(C) (102 - 102): ";
  sub_4.print(std::cout) << std::endl;

  print_separator();
  std::cout << "3. Демонстрация Операций Сравнения\n";

  Four D("100");
  Four E("100"); 
  Four F("33");
  
  std::cout << "   D = 100, E = 100, F = 33\n";
  
  std::cout << "3a) D.eq(E) (100 == 100): " << (D.eq(E) ? "TRUE" : "FALSE") << "\n";
  std::cout << "    D.eq(F) (100 == 33): " << (D.eq(F) ? "TRUE" : "FALSE") << "\n";
  
  std::cout << "3b) D.gt(F) (100 > 33): " << (D.gt(F) ? "TRUE" : "FALSE") << "\n";
  std::cout << "    F.gt(D) (33 > 100): " << (F.gt(D) ? "TRUE" : "FALSE") << "\n";
  std::cout << "    D.ge(E) (100 >= 100): " << (D.ge(E) ? "TRUE" : "FALSE") << "\n"; 
  
  std::cout << "3c) F.lt(D) (33 < 100): " << (F.lt(D) ? "TRUE" : "FALSE") << "\n";
  std::cout << "    D.lt(F) (100 < 33): " << (D.lt(F) ? "TRUE" : "FALSE") << "\n";
  std::cout << "    D.le(E) (100 <= 100): " << (D.le(E) ? "TRUE" : "FALSE") << "\n";
  
  print_separator();
  std::cout << "4. Демонстрация Конструктора Перемещения (Move)\n";
  
  Four original_move("23");
  std::cout << "   Original Four(\"23\") \n";

  Four moved = std::move(original_move);
  
  std::cout << "   moved: ";
  moved.print(std::cout) << "\n";

  std::cout << "   original_move (после перемещения): ";
  original_move.print(std::cout) << "\n";
  
  return 0;
}