#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <utility>

std::vector<std::string> split(const std::string s, const std::string delim)
{
	std::regex delim_r(delim);
	std::vector<std::string> list(
			std::sregex_token_iterator(s.begin(), s.end(), delim_r, -1),
			std::sregex_token_iterator());
	return list;
}

void solve(std::vector<std::pair<long long, long long>> time_distance)
{
	long long total = 1;
	for (auto td : time_distance)
	{
		long long time = td.first;
		long long distance = td.second;
		long long min_time = time;
		long long max_time = time;
		for (long long i = 1; i <= time; i++)
		{
			if ((i * (time - i)) > distance)
			{
				min_time = i;
				break;
			}
		}
		for (long long i = time; i >= 1; i--)
		{
			if ((i * (time - i)) > distance)
			{
				max_time = i;
				break;
			}
		}
		total *= std::max((max_time - min_time + 1), 1LL);
	}
	std::cout << total << '\n';
}

int main()
{
	std::string line;
	std::ifstream file("input.txt");
	if (file.is_open())
	{
		std::vector<std::string> lines;
		std::vector<long long> times;
		std::vector<long long> distances;
		while (getline(file, line))
		{
			lines.push_back(line);
		}
		auto times_split = split(lines[0], "(\\s+)");
		auto distance_split = split(lines[1], "(\\s+)");
		std::vector<std::pair<long long, long long>> time_distance;
		std::string time;
		std::string distance;
		for (long long i = 1; i < times_split.size(); i++)
		{
			time += times_split[i];
			distance += distance_split[i];
		}
		time_distance.push_back(std::make_pair(stoll(time), stoll(distance)));
		solve(time_distance);
		file.close();
	}
	else
		std::cout << "Unable to open file";

	return 0;
}
