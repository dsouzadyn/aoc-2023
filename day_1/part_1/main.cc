#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int process_string(string s) {
	int t;
	int s_size = s.length();
	for (int i = 0; i < s_size; i++) {
		if (isdigit(s[i])) {
			t = (s[i] - '0') * 10;
			break;
		}
	}
	for (int i = s_size - 1; i >= 0; i--) {
		if (isdigit(s[i])) {
			t += (s[i] - '0');
			break;
		}
	}
	return t;
}

int main() {
	string line;
	ifstream file ("input.txt");
	if (file.is_open()) 
	{
		int total = 0;
		while (getline(file, line))
		{
			total += process_string(line);
		}
		file.close();
		cout << total << "\n";
	}
	else cout << "Unable to open file";

	return 0;
}
