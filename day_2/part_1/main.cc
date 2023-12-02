#include <iomanip>
#include <iostream>
#include <fstream>
#include <ranges>
#include <string>
#include <regex>
#include <string_view>
#include <vector>

std::vector<std::string> split(const std::string s, const std::string delim) {
  std::regex delim_r(delim);
  std::vector<std::string> list(std::sregex_token_iterator(s.begin(), s.end(), delim_r, -1), std::sregex_token_iterator());
  return list;
}

class Game {
  private:
    int _id;
    std::string _s;
    bool _is_valid = true;
  public:
    Game(std::string s) { _s = s; }
    bool IsValid() {
      return _is_valid;
    }
    int Id() { return _id; }
    void Parse() {
      auto game_data = split(_s, ": ");
      auto game_info = split(game_data[0], " ");
      _id = stoi(game_info[1]);
      auto rounds = split(game_data[1], "; ");
      for (auto round: rounds) {
        auto game = split(round, ", ");
        for (auto wtf: game) {
          auto wtf_split = split(wtf, " ");
          if (wtf_split[1] == "blue" && stoi(wtf_split[0]) > 14) _is_valid = false;
          if (wtf_split[1] == "green" && stoi(wtf_split[0]) > 13) _is_valid = false;
          if (wtf_split[1] == "red" && stoi(wtf_split[0]) > 12) _is_valid = false;
          if (!_is_valid) break;
        }
      }
    }
};

int main() {
  std::string line;
  std::ifstream file ("input.txt");
	if (file.is_open()) 
	{
    int total = 0;
		while (getline(file, line))
		{
      Game game(line);

      game.Parse();
      if (game.IsValid()) total += game.Id();
		}
		file.close();
    std::cout << total << "\n";
	}
	else std::cout << "Unable to open file";

	return 0;
}
