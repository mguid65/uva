#include <iostream>
#include <unordered_map>
#include <string>

int main () {
  std::string line;
  int count = 1;
  while(std::getline(std::cin, line)) {
    if (line == "#") break;
    std::cout << "Case " << count << ": ";
    if (line == "HELLO")
	std::cout << "ENGLISH\n";
    else if (line == "HOLA")
	std::cout << "SPANISH\n";
    else if (line == "HALLO")
	std::cout << "GERMAN\n";
    else if (line == "BONJOUR")
	std::cout << "FRENCH\n";
    else if (line == "CIAO")
	std::cout << "ITALIAN\n";
    else if (line == "ZDRAVSTVUJTE")
	std::cout << "RUSSIAN\n";
    else
	std::cout << "UNKNOWN\n";
    count++;
  }
}
