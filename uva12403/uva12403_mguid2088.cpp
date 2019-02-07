#include <iostream>

int total_amt = 0;

inline void report() {
  std::cout << total_amt << '\n';
}

inline void donate(int amt) {
  total_amt += amt;
}

int main () {
  std::ios_base::sync_with_stdio(false);

  int num_cmds;
  std::cin >> num_cmds;

  char c;
  while (num_cmds--) {
    std::cin >> c;
    std::cin.ignore(5, '\n');
    switch(c) {
      case 'r':
        report();
        break;
      case 'd':
        int amt;
        std::cin >> amt;
        donate(amt);
    }
  }
}



