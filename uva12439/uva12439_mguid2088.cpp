#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::string;

inline bool is_leap(int year) {
   return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

inline int leap_years_in_range(int y1, int y2) {
  int four = (y2/4) - ((y1-1)/4);
  int hundred = (y2/100) - ((y1-1)/100);
  int fourhundred = (y2/400) - ((y1-1)/400);
  return four - hundred + fourhundred;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int cases, y1, d1, y2, d2;
  cin >> cases;

  for(int i = 1; i <= cases; i++) {
    string m1;

    cin >> m1;
    cin >> d1;
    cin.ignore(1, ' ');
    cin >> y1;
    if((m1 != "January") && (m1 != "February")) y1++;

    cin >> m1;
    cin >> d2;
    cin.ignore(1, ' ');
    cin >> y2;
    if((m1 == "January") || (m1 == "February" && d2 < 29)) y2--;

    cout << "Case: " << i << ' ' << leap_years_in_range(y1, y2) << '\n';
  }
}

