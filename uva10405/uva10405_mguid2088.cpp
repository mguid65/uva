#include <algorithm>
#include <string>
#include <iostream>

using std::max;
using std::string;
using std::cin;
using std::cout;

int table[1001][1001];

int lcs( const string& s1, const string& s2, int m, int n ) {
   int i, j;
   for (int i = n; i >= 0; i--) {
     for (int j = m; j >= 0; j--) {
       if (i == n || j == m) {
         table[i][j] = 0;
         continue;
       }
       if (s1[i] == s2[j])
         table[i][j] = table[i+1][j+1] + 1;
       else
         table[i][j] = max(table[i+1][j], table[i][j+1]);
     }
   }
   return table[0][0];
}


int main () {
  std::ios_base::sync_with_stdio(false);
  string s1, s2;

  while(getline(cin, s1)) {
    getline(cin, s2);
    int n = s1.size();
    int m = s2.size();

    //printf("%s, %s\n", s1, s2);

    cout << lcs(s1, s2, m, n) << '\n';
  }
}
