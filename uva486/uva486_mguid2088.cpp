#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

class StreamingEnglishNumberParser {
public:
  StreamingEnglishNumberParser(std::istream& instream) : m_instream(instream) {}

  void run() {
    while (m_instream.good()) {
      std::getline(m_instream, m_current_line);
      if(m_current_line.empty()) break;
      std::istringstream ss(m_current_line);
      int num = 0;
      int sign = 1;
      while (ss >> m_data) {
        const int val = word_num_map[m_data];
        switch (val) {
          case -1:
            sign = -1;
            break;
          case 100:
            num *= 100;
            break;
          case 1000:
            m_current_num += num * 1000;
            num = 0;
            break;
          case 1000000:
            m_current_num += num * 1000000;
            num = 0;
            break;
          default:
            num += val;
        }
      }
      m_current_num += num;

      std::cout << sign * m_current_num << '\n';
      m_current_num = 0;
    }
  }

private:
  std::unordered_map<std::string, int> word_num_map{
      {"negative", -1},   {"zero", 0},         {"one", 1},      {"two", 2},        {"three", 3},
      {"four", 4},        {"five", 5},         {"six", 6},      {"seven", 7},      {"eight", 8},
      {"nine", 9},        {"ten", 10},         {"eleven", 11},  {"twelve", 12},    {"thirteen", 13},
      {"fourteen", 14},   {"fifteen", 15},     {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18},
      {"nineteen", 19},   {"twenty", 20},      {"thirty", 30},  {"forty", 40},     {"fifty", 50},
      {"sixty", 60},      {"seventy", 70},     {"eighty", 80},  {"ninety", 90},    {"hundred", 100},
      {"thousand", 1000}, {"million", 1000000}};
  std::string m_current_line;
  std::string m_data;
  int m_current_num;
  std::istream& m_instream;
};

static StreamingEnglishNumberParser english_num_parser(std::cin);

int main() {
  english_num_parser.run();
}
