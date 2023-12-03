#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> find_adjacent_numbers(std::vector<std::string> grid, int i, int j)
{
	std::vector<int> numbers;
	// Easy cases
	// 1. Left of symbol
	if (grid[i][j - 1] != '.')
	{
		int r = j - 1;
		int l = r;
		for (int q = j - 1; q >= 0 && grid[i][q] != '.'; q--)
			l = q;
		int number = stoi(grid[i].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	// 2. Right of symbol
	if (grid[i][j + 1] != '.')
	{
		int r = j + 1;
		int l = r;
		for (int q = j + 1; q < grid[i].size() && grid[i][q] != '.'; q++)
			r = q;
		int number = stoi(grid[i].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	// The tedious cases
	// 1. Top of symbol
	if (grid[i - 1][j] != '.')
	{
		int l = j;
		int r = l;
		for (int q = j - 1; q >= 0 && grid[i - 1][q] != '.'; q--)
			l = q;
		for (int q = j + 1; q < grid[i - 1].size() && grid[i - 1][q] != '.'; q++)
			r = q;
		int number = stoi(grid[i - 1].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	else
	{
		// 1a. Top left of symbol
		if (grid[i - 1][j - 1] != '.')
		{
			int l = j - 1;
			int r = l;
			for (int q = j - 1; q >= 0 && grid[i - 1][q] != '.'; q--)
				l = q;
			int number = stoi(grid[i - 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
		// 1b. Top right of symbol
		if (grid[i - 1][j + 1] != '.')
		{
			int r = j + 1;
			int l = r;
			for (int q = j + 1; q < grid[i - 1].size() && grid[i - 1][q] != '.'; q++)
				r = q;
			int number = stoi(grid[i - 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
	}
	// 2. Bottom of symbol
	if (grid[i + 1][j] != '.')
	{
		int l = j;
		int r = l;
		for (int q = j - 1; q >= 0 && grid[i + 1][q] != '.'; q--)
			l = q;
		for (int q = j + 1; q < grid[i + 1].size() && grid[i + 1][q] != '.'; q++)
			r = q;
		int number = stoi(grid[i + 1].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	else
	{
		// 2a. Bottom left of symbol
		if (grid[i + 1][j - 1] != '.')
		{
			int l = j - 1;
			int r = l;
			for (int q = j - 1; q >= 0 && grid[i + 1][q] != '.'; q--)
				l = q;
			int number = stoi(grid[i + 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
		// 2b. Bottom right of symbol
		if (grid[i + 1][j + 1] != '.')
		{
			int r = j + 1;
			int l = r;
			for (int q = j + 1; q < grid[i + 1].size() && grid[i + 1][q] != '.'; q++)
				r = q;
			int number = stoi(grid[i + 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
	}
	return numbers;
}

void solve(std::vector<std::string> grid)
{
	int total = 0;
	for (int i = 1; i < grid.size() - 1; i++)
	{
		for (int j = 1; j < grid[i].size() - 1; j++)
		{
			char el = grid[i][j];
			if (!isdigit(el) && el != '.')
			{
				for (auto i : find_adjacent_numbers(grid, i, j))
					total += i;
			}
		}
	}
	std::cout << total << '\n';
}

int main()
{
	std::string line;
	std::ifstream file("input.txt");
	std::vector<std::string> grid;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			grid.push_back(line);
		}
		solve(grid);
		file.close();
	}
	else
		std::cout << "Unable to open file";

	return 0;
}
