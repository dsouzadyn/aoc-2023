#include <iomanip>
#include <iostream>
#include <fstream>
#include <ranges>
#include <string>
#include <regex>
#include <string_view>
#include <vector>
#include <algorithm>

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
    int max_red = 1;
    int max_blue = 1;
    int max_green = 1;
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
          if (wtf_split[1] == "red") max_red = std::max(max_red, stoi(wtf_split[0]));
          if (wtf_split[1] == "green") max_green = std::max(max_green, stoi(wtf_split[0]));
          if (wtf_split[1] == "blue") max_blue = std::max(max_blue, stoi(wtf_split[0]));
        }
      }
    }
    int Power() {
      return max_red * max_blue * max_green;
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
      total += game.Power();
		}
		file.close();
    std::cout << total << "\n";
	}
	else std::cout << "Unable to open file";

	return 0;
}
