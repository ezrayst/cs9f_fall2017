#include <iostream>
#include <fstream>

int main () {
  int number, number_prev, subtotal, total;
  subtotal = 0;
  total = 0;
  number = 1;
  number_prev = 1;
    while (number != 0 || number_prev != 0) {
      number_prev = number;    
      std::cout << "Enter integer: ";
      std::cin >> number;
      total += number;
      subtotal += number;
      if (number == 0 && number_prev != 0) {
        std::cout << "Current subtotal: " << subtotal << "\n";
        subtotal = 0;
      }
    }
    std::cout << "Total: " << total << "\n" << "Program terminated.\n"; 
  return 0;
}