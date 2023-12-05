#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <vector>
#include <string_view>
#include <regex>
#include <limits>

class Seed
{
private:
	long long _seed;
	long long _soil;
	long long _fertilizer;
	long long _water;
	long long _light;
	long long _temperature;
	long long _humidity;
	long long _location;

public:
	Seed(long long seed) { _seed = seed; }
	void FindSoil(std::vector<std::vector<long long>> soilmap)
	{
		bool found_destination = false;
		for (auto row : soilmap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_seed >= dest && (_seed - dest) <= range)
			{
				_soil = source + (_seed - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_soil = _seed;
		}
	}
	void FindFertilizer(std::vector<std::vector<long long>> fertilizermap)
	{
		bool found_destination = false;
		for (auto row : fertilizermap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_soil >= dest && (_soil - dest) <= range)
			{
				_fertilizer = source + (_soil - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_fertilizer = _soil;
		}
	}
	void FindWater(std::vector<std::vector<long long>> watermap)
	{
		bool found_destination = false;
		for (auto row : watermap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_fertilizer >= dest && (_fertilizer - dest) <= range)
			{
				_water = source + (_fertilizer - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_water = _fertilizer;
		}
	}
	void FindLight(std::vector<std::vector<long long>> lightmap)
	{
		bool found_destination = false;
		for (auto row : lightmap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_water >= dest && (_water - dest) <= range)
			{
				_light = source + (_water - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_light = _water;
		}
	}
	void FindTemperature(std::vector<std::vector<long long>> temperaturemap)
	{
		bool found_destination = false;
		for (auto row : temperaturemap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_light >= dest && (_light - dest) <= range)
			{
				_temperature = source + (_light - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_temperature = _light;
		}
	}
	void FindHumidity(std::vector<std::vector<long long>> humiditymap)
	{
		bool found_destination = false;
		for (auto row : humiditymap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_temperature >= dest && (_temperature - dest) <= range)
			{
				_humidity = source + (_temperature - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_humidity = _temperature;
		}
	}
	void FindLocation(std::vector<std::vector<long long>> locationmap)
	{
		bool found_destination = false;
		for (auto row : locationmap)
		{
			long long source = row[0];
			long long dest = row[1];
			long long range = row[2];
			if (_humidity >= dest && (_humidity - dest) <= range)
			{
				_location = source + (_humidity - dest);
				found_destination = true;
				break;
			}
		}
		if (!found_destination)
		{
			_location = _humidity;
		}
	}
	long long Location() { return _location; }
};

std::vector<std::string> split(const std::string s, const std::string delim)
{
	std::regex delim_r(delim);
	std::vector<std::string> list(
			std::sregex_token_iterator(s.begin(), s.end(), delim_r, -1),
			std::sregex_token_iterator());
	return list;
}

int main()
{
	std::string line;
	std::ifstream file("input.txt");
	if (file.is_open())
	{
		std::vector<Seed> seeds;
		std::map<std::string, std::vector<std::vector<long long>>> maps;
		std::string type = "";
		while (getline(file, line))
		{
			std::string_view l{line};
			if (l.starts_with("seeds:"))
			{
				auto seed_split = split(line, "(\\s+)");
				for (long long i = 1; i < seed_split.size(); i++)
					seeds.push_back(Seed(stoll(seed_split[i])));
			}
			else if (!isdigit(line[0]))
			{
				if (l.starts_with("seed-to-soil"))
					type = "soil";
				if (l.starts_with("soil-to-fertilizer"))
					type = "fertilizer";
				if (l.starts_with("fertilizer-to-water"))
					type = "water";
				if (l.starts_with("water-to-light"))
					type = "light";
				if (l.starts_with("light-to-temperature"))
					type = "temperature";
				if (l.starts_with("temperature-to-humidity"))
					type = "humidity";
				if (l.starts_with("humidity-to-location"))
					type = "location";
			}
			else
			{
				auto map_row = split(line, "(\\s+)");
				std::vector<long long> row;
				for (auto mr : map_row)
					row.push_back(stoll(mr));
				maps[type].push_back(row);
			}
		}

		file.close();
		long long min_location = std::numeric_limits<long long>::max();
		for (auto seed : seeds)
		{
			seed.FindSoil(maps["soil"]);
			seed.FindFertilizer(maps["fertilizer"]);
			seed.FindWater(maps["water"]);
			seed.FindLight(maps["light"]);
			seed.FindTemperature(maps["temperature"]);
			seed.FindHumidity(maps["humidity"]);
			seed.FindLocation(maps["location"]);
			min_location = std::min(min_location, seed.Location());
		}
		std::cout << min_location << "\n";
	}
	else
		std::cout << "Unable to open file";

	return 0;
}
