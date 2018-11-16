#include <cstdio>
#include <vector>
#include <iostream>

class tree {
public:
  tree() { tree(0,0,0,0); }
  tree(int x, int y, int d, int h) : x(x), y(y), d(d), h(h) {}
  int x, y, d, h;
  friend std::ostream& operator<<(std::ostream& os, const tree& t);
};

std::ostream& operator<<(std::ostream& os, const tree& t)
{
    os << t.x << ' ' << t.y << ' ' << t.d << ' ' << t.h << '\n';
    return os;
}

std::vector<tree> forest;

//this function refuses to inline
void get_five_ints(int& a, int& b, int& c, int& d, int& e) {
  char ch;
  while((ch = getchar_unlocked()) >= '0') a = (a * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') b = (b * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') c = (c * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') d = (d * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') e = (e * 10) + (ch & 0xF);
}

inline void get_four_ints(int& a, int& b, int& c, int& d) {
  char ch;
  while((ch = getchar_unlocked()) >= '0') a = (a * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') b = (b * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') c = (c * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') d = (d * 10) + (ch & 0xF);
}

int main() {
  int xmin = 0, ymin = 0, xmax = 0, ymax = 0, numtrees = 0, tree_x, tree_y, tree_d, tree_h, cuttable = 0;
  get_five_ints(xmin, ymin, xmax, ymax, numtrees);

  while(numtrees != 0) {
    while(numtrees--) {
      tree_x = tree_y = tree_d = tree_h = 0;
      get_four_ints(tree_x, tree_y, tree_d, tree_h);
      forest.push_back(tree{tree_x, tree_y, tree_d, tree_h});
    }
    //DO CALCULATIONS HERE



    //DO CALCULATIONS HERE
    xmin = ymin = xmax = ymax = numtrees = 0;
    get_five_ints(xmin, ymin, xmax, ymax, numtrees);
  }

  printf("%d tree(s) can be cut\n", cuttable);
}
