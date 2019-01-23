#include <cstdio>
#include <vector>
#include <algorithm>

template<class InputIt, class OutputIt, class BinaryOperation>
OutputIt adjacent_difference(InputIt first, InputIt last,
                             OutputIt d_first, BinaryOperation op)
{
    if (first == last) return d_first;

    typedef typename std::iterator_traits<InputIt>::value_type value_t;
    value_t acc = *first;
    *d_first = acc;
    while (++first != last) {
        value_t val = *first;
        *++d_first = op(val, std::move(acc)); // std::move since C++20
        acc = std::move(val);
    }
    return ++d_first;
}

class gear_set {
public:
  gear_set(std::vector<int> &front, std::vector<int> &rear) {
    for(auto& f_teeth: front) {
      for(auto& r_teeth: rear) {
        spread.emplace_back((double)r_teeth/(double)f_teeth);
      }
    }
    std::sort(spread.begin(), spread.end());

    adjacent_difference(spread.begin(), spread.end(), spread.begin(), [](const double &a, const double &b) {
      return a / b;
    });
  }
  double get_max_spread() {
    return *std::max_element(spread.begin()+1, spread.end());
  }
private:
  std::vector<double> spread;
};

int main () {
  int f_num, r_num;
  int in;
  while(scanf(" %d %d ", &f_num, &r_num) && f_num != 0) {
    std::vector<int> front;
    std::vector<int> rear;
    while(f_num--) {
      scanf(" %d ", &in);
      front.push_back(in);
    }
    while(r_num--) {
      scanf(" %d ", &in);
      rear.push_back(in);
    }
    gear_set gs(front, rear);
    printf("%.2lf\n", gs.get_max_spread());
  }
}
