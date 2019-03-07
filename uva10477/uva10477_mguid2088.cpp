#include <iostream>
#include <array>

std::array<std::array<int, 20>, 20> board{0};

class hybrid_knight {
public:
  static enum state{knight, mutant_knight, mutant_pawn};
  hybrid_knight(const state&& st,const pair<int, int>&& start) : m_state(st), m_pos(start) {}

  
private:
  state m_state;
  pair<int, int> m_pos;
};
