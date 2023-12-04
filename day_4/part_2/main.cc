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

void solve(std::vector<std::string> lines) {
  std::vector<int> answer(lines.size(), 1);
  for (int i = 0; i < lines.size(); i++) {

    auto line_split = split(lines[i], "([:]\\s+)");
    auto card_split = split(line_split[1], "(\\s[|]\\s+)");

    std::set<std::string> winning_set;

    for (auto winning_card : split(card_split[0], "(\\s+)")) {
      winning_set.insert(winning_card);
    }
    int total = 0;
    for (auto card : split(card_split[1], "(\\s+)")) {
      if (winning_set.count(card) > 0) {
        total++;
      }
    }
    for (int j = i + 1; j <= i + total; j++)
      answer[j] += answer[i];
  }
  int final_answer = 0;
  for (auto a : answer)
    final_answer += a;
  std::cout << final_answer << '\n';
}

int main() {
  std::string line;
  std::ifstream file("input.txt");
  if (file.is_open()) {
    std::vector<std::string> lines;
    while (getline(file, line)) {
      lines.push_back(line);
    }
    file.close();
    solve(lines);
  } else
    std::cout << "Unable to open file";
  return 0;
}
