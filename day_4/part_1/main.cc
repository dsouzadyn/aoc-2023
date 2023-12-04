#include <fstream>
#include <iostream>
#include <regex>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string s, const std::string delim) {
  std::regex delim_r(delim);
  std::vector<std::string> list(
      std::sregex_token_iterator(s.begin(), s.end(), delim_r, -1),
      std::sregex_token_iterator());
  return list;
}

int main() {
  std::string line;
  std::ifstream file("input.txt");
  if (file.is_open()) {
    int grand_total = 0;
    while (getline(file, line)) {
      auto line_split = split(line, "([:]\\s+)");
      auto card_split = split(line_split[1], "(\\s[|]\\s+)");

      std::set<std::string> winning_set;

      for (auto winning_card : split(card_split[0], "(\\s+)")) {
        winning_set.insert(winning_card);
      }
      int total = 0;
      for (auto card : split(card_split[1], "(\\s+)")) {
        if (winning_set.count(card) > 0) {
          if (total == 0)
            total = 1;
          else
            total += total;
        }
      }
      grand_total += total;
    }
    file.close();
    std::cout << grand_total << '\n';
  } else
    std::cout << "Unable to open file";
  return 0;
}
