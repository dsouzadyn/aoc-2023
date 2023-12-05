#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> find_adjacent_numbers(std::vector<std::string> &grid, int &i, int &j)
{
	std::vector<int> numbers;
	int r, l;
	int number;
	// Easy cases
	// 1. Left of symbol
	if (grid[i][j - 1] != '.')
	{
		r = j - 1;
		l = r;
		for (int q = j - 1; q >= 0 && grid[i][q] != '.'; q--)
			l = q;
		number = stoi(grid[i].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	// 2. Right of symbol
	if (grid[i][j + 1] != '.')
	{
		r = j + 1;
		l = r;
		for (int q = j + 1; q < grid[i].size() && grid[i][q] != '.'; q++)
			r = q;
		number = stoi(grid[i].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	// The tedious cases
	// 1. Top of symbol
	if (grid[i - 1][j] != '.')
	{
		l = j;
		r = l;
		for (int q = j - 1; q >= 0 && grid[i - 1][q] != '.'; q--)
			l = q;
		for (int q = j + 1; q < grid[i - 1].size() && grid[i - 1][q] != '.'; q++)
			r = q;
		number = stoi(grid[i - 1].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	else
	{
		// 1a. Top left of symbol
		if (grid[i - 1][j - 1] != '.')
		{
			l = j - 1;
			r = l;
			for (int q = j - 1; q >= 0 && grid[i - 1][q] != '.'; q--)
				l = q;
			number = stoi(grid[i - 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
		// 1b. Top right of symbol
		if (grid[i - 1][j + 1] != '.')
		{
			r = j + 1;
			l = r;
			for (int q = j + 1; q < grid[i - 1].size() && grid[i - 1][q] != '.'; q++)
				r = q;
			number = stoi(grid[i - 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
	}
	// 2. Bottom of symbol
	if (grid[i + 1][j] != '.')
	{
		l = j;
		r = l;
		for (int q = j - 1; q >= 0 && grid[i + 1][q] != '.'; q--)
			l = q;
		for (int q = j + 1; q < grid[i + 1].size() && grid[i + 1][q] != '.'; q++)
			r = q;
		number = stoi(grid[i + 1].substr(l, r - l + 1));
		numbers.push_back(number);
	}
	else
	{
		// 2a. Bottom left of symbol
		if (grid[i + 1][j - 1] != '.')
		{
			l = j - 1;
			r = l;
			for (int q = j - 1; q >= 0 && grid[i + 1][q] != '.'; q--)
				l = q;
			number = stoi(grid[i + 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
		// 2b. Bottom right of symbol
		if (grid[i + 1][j + 1] != '.')
		{
			r = j + 1;
			l = r;
			for (int q = j + 1; q < grid[i + 1].size() && grid[i + 1][q] != '.'; q++)
				r = q;
			number = stoi(grid[i + 1].substr(l, r - l + 1));
			numbers.push_back(number);
		}
	}
	return numbers;
}

int find_gear_ratio(std::vector<int> numbers)
{
	if (numbers.size() != 2)
		return 0;
	else
	{
		return numbers[0] * numbers[1];
	}
}

void solve(std::vector<std::string> &grid)
{
	int total = 0;
	char el;
	for (int i = 1; i < grid.size() - 1; i++)
	{
		for (int j = 1; j < grid[i].size() - 1; j++)
		{
			el = grid[i][j];
			if (!isdigit(el) && el == '*')
			{
				total += find_gear_ratio(find_adjacent_numbers(grid, i, j));
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
