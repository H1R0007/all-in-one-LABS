#include "utils.cpp"
#include <iostream>

int main() {
	std::cout << "program is alrready started!!!" << std::endl;

	int a = 0;
	int b = 0;
	std::cout << "Please, Enter a numbers to calculate: ";
	std::cin >> a >> b;
	int g1 = plus(a, b);
	int g2 = ymnozh(a, b);
	int g3 = vych(a, b);
	bool g4 = ravenstvo(a, b);

  std::cout << "g1 = " << g1 << std::endl;
  std::cout << "g2 = " << g2 << std::endl;
  std::cout << "g3 = " << g3 << std::endl;
  std::cout << "g4 = " << g4 << std::endl;

  std::cout << "program already done!" << std::endl;
  
  return 0;
}
