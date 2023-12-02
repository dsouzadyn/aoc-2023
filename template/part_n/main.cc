#include <iostream>
#include <fstream>
#include <string>


int main() {
  std::string line;
  std::ifstream file ("input.txt");
	if (file.is_open()) 
	{
		while (getline(file, line))
		{
      std::cout << line << "\n";
		}
		file.close();
	}
	else std::cout << "Unable to open file";

	return 0;
}
