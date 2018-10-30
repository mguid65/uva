#include <string>
#include <unordered_map>
#include <iostream>

static std::unordered_map<char, char> char_mapping {
	{ 'A' , 'A' },
	{ 'E' , '3' },
	{ 'H' , 'H' },
	{ 'I' , 'I' },
	{ 'J' , 'L' },
	{ 'L' , 'J' },
	{ 'M' , 'M' },
	{ 'O' , 'O' },
	{ 'S' , '2' },
	{ 'T' , 'T' },
	{ 'U' , 'U' },
        { 'V' , 'V' },
        { 'W' , 'W' },
        { 'X' , 'X' },
        { 'Y' , 'Y' },
        { 'Z' , '5' },
        { '1' , '1' },
        { '2' , 'S' },
        { '3' , 'E' },
        { '5' , 'Z' },
        { '8' , '8' } };

int main () {
  std::ios_base::sync_with_stdio(false);
  std::string s, a, b;
  while(std::cin >> s) {
    a = b = "";

    int len = s.size();\
    for(int i = len - 1; i >= 0 ; i--) {
      a += s[i];
      b += char_mapping[s[i]];
    }

    if (s == a && s == b) std::cout << s << " -- is a mirrored palindrome.\n\n";
    else if (s == a && s != b) std::cout << s << " -- is a regular palindrome.\n\n";
    else if (s != a && s == b) std::cout << s << " -- is a mirrored string.\n\n";
    else std::cout << s << " -- is not a palindrome.\n\n";

  }
}
