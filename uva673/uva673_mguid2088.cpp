#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
int main () {
  int n;
  scanf("%d", &n);
  std::string line;
  getc(stdin);
  while(n--) {
    std::getline(std::cin, line);
    par = brace = 0;
    std::stack<char> balance_stack;
    for(char &c: line) {
      if (c == '(' || c == '[') {
        balance_stack.push(c);
      } else if (c == ')') {
        if (balance_stack.empty() || balance_stack.top() != '('){
          balance_stack.push('a');
          break;
        }
        balance_stack.pop();
      } else if (c == ']') {
        if (balance_stack.empty() || balance_stack.top() != '['){
          balance_stack.push('a');
          break;
        }
        balance_stack.pop();
      }
    }
    printf(balance_stack.empty() ? "Yes\n" : "No\n");
  }
}
