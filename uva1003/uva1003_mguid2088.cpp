#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

//error value
const double EPSILON = 1e-9;
const double PI = 3.14159265358;
const double HALF_PI = 0.5 * PI;
const double TAO = 2.0 * PI;

//a tree
class tree {
public:
  tree() { tree(0,0,0,0); }
  tree(const int &x, const int &y, const int &d, const int &h) : x(x), y(y), d(d), h(h) {}
  int x, y, d, h;
};

//generate the forest relative to a single tree and determine its obstacles
class tree_relative_forest {
public:
  tree_relative_forest(const double &r1, const double &h1) : r1(r1), h1(h1), max_reach(sqrt((r1*r1)+(h1*h1))) {}

  //add the angles for a fence only if it falls within the fall range of this tree
  void add_fence(double distance, double offset) {
    if(max_reach >= distance + EPSILON) {
      double angle = acos(distance / max_reach) + atan(r1 / h1);
      angles.emplace_back(-angle+offset, angle+offset);
    }
  }
  //add the angles for a tree only if it falls within the fall range of this tree
  void add_tree(double distance, double r2, double offset) {
    if(max_reach >= distance - r2 + EPSILON) {
      double angle = asin((r1 + r2) / distance);
      angles.emplace_back(-angle+offset, angle+offset);
    }
  }
  bool find_gap() {
    for(int i = 0; i < angles.size(); i++) {
      auto angle_pair = angles[i];

      double left = angle_pair.first;
      double right = angle_pair.second;

      //try to wrap the angle to positive if negative
      left = fmod(left, TAO);
      if ( left < 0.0 ) {
        left += TAO;
      }
      right = fmod(right, TAO);
      if ( right < 0.0 ) {
        right += TAO;
      }

      //regular case, just add left and right angles
      if ( left <= right) {
        angles[i] = std::make_pair(left, right);
      } else { //right is greater than left
        angles[i] = std::make_pair(left, TAO);
        //alot of time is being spent in this emplace_back call
        angles.emplace_back(0.0, right);
      }
    }
    std::sort(angles.begin(), angles.end());

    double limit = 0.0;
    for(auto &angle_pair: angles) {
      if(angle_pair.first > (limit + EPSILON)) {
        return true;
      }
      if (angle_pair.second > limit) {
        limit = angle_pair.second;
      }
    }
    return limit + EPSILON < TAO;
  }
private:
  double r1, h1;
  double max_reach;
  std::vector< std::pair<double, double> > angles;
};

//this function refuses to inline
//ignore this awful specialized function 1
void get_five_ints(int& a, int& b, int& c, int& d, int& e) {
  char ch;
  while((ch = getchar_unlocked()) >= '0') a = (a * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') b = (b * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') c = (c * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') d = (d * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') e = (e * 10) + (ch & 0xF);
}

//this function inlines
//ignore this awful specialized function 2
inline void get_four_ints(int& a, int& b, int& c, int& d) {
  char ch;
  while((ch = getchar_unlocked()) >= '0') a = (a * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') b = (b * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') c = (c * 10) + (ch & 0xF);
  while((ch = getchar_unlocked()) >= '0') d = (d * 10) + (ch & 0xF);
}


//determine the fallable trees for a given forest
void process_forest(int case_num, int x_min, int y_min, int x_max, int y_max, const std::vector<tree> &trees) {
  std::vector<int> remaining_trees(trees.size(), 1);
  std::iota(remaining_trees.begin(), remaining_trees.end(), 0);
  while(remaining_trees.size()) {
    bool progress = false;
    for(int i = 0; i < trees.size(); i++) {
      if(std::find(remaining_trees.begin(), remaining_trees.end(), i) == remaining_trees.end()) continue;
      auto &t = trees[i];

      tree_relative_forest f(0.5 * t.d, t.h);
      f.add_fence(x_max - t.x, 0.0);
      f.add_fence(y_max - t.y, HALF_PI);
      f.add_fence(t.x - x_min, PI);
      f.add_fence(t.y - y_min, 1.5 * PI);

      for(int j = 0; j < trees.size(); j++) {
        if( j == i || std::find(remaining_trees.begin(), remaining_trees.end(), j) == remaining_trees.end()) continue;
        auto &t2 = trees[j];

        double dx = t2.x - t.x;
        double dy = t2.y - t.y;
        double angle;

        if( dy ) {
          if( dx ) {
            angle = atan2(dy, dx);
          } else {
            angle = atan2(-dx, dy) + HALF_PI;
          }
        } else {
          if ( dx < 0 ) {
            angle = atan2(-dy, -dx) + PI;
          } else {
            angle = atan2(dx, -dy) + 1.5 * PI;
          }
        }
        f.add_tree(sqrt((dx * dx) + (dy * dy)), 0.5 * t2.d, angle);
      }
      if(f.find_gap()) {
        remaining_trees.erase(std::find(remaining_trees.begin(), remaining_trees.end(), i));
        //remaining_trees[i] = 0;
        progress = true;
      }
    }
    if(!progress) break;
  }
  printf("Forest %d\n%lu tree(s) can be cut\n\n", case_num, trees.size() - remaining_trees.size());
}

int main() {
  int x_min = 0, y_min = 0, x_max = 0, y_max = 0, num_trees = 0, tree_x, tree_y, tree_d, tree_h;
  get_five_ints(x_min, y_min, x_max, y_max, num_trees);
  //scanf(" %d %d %d %d %d ", &x_min, &y_min, &x_max, &y_max, &num_trees);
  int case_num = 1;
  while(num_trees != 0) {
    std::vector<tree> trees;
    while(num_trees--) {
      tree_x = tree_y = tree_d = tree_h = 0;
      get_four_ints(tree_x, tree_y, tree_d, tree_h);
      //scanf(" %d %d %d %d ", &tree_x, &tree_y, &tree_d, &tree_h);
      trees.emplace_back(tree_x, tree_y, tree_d, tree_h);
    }
    process_forest(case_num, x_min, y_min, x_max, y_max, trees);
    case_num++;
    x_min = y_min = x_max = y_max = num_trees = 0;
    get_five_ints(x_min, y_min, x_max, y_max, num_trees);
    //scanf(" %d %d %d %d %d ", &x_min, &y_min, &x_max, &y_max, &num_trees);
  }
}

