#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <regex>

using namespace std;
string name_to_number_start(string ts) {
	string_view s{ts};
	if (s.starts_with("one")) return "1";
	if (s.starts_with("two")) return "2";
	if (s.starts_with("three")) return "3";
	if (s.starts_with("four")) return "4";
	if (s.starts_with("five")) return "5";
	if (s.starts_with("six")) return "6";
	if (s.starts_with("seven")) return "7";
	if (s.starts_with("eight")) return "8";
	if (s.starts_with("nine")) return "9";
	return "a";
}
string name_to_number_end(string ts) {
	string_view s{ts};
	if (s.starts_with("one")) return "1";
	if (s.starts_with("two")) return "2";
	if (s.starts_with("three")) return "3";
	if (s.starts_with("four")) return "4";
	if (s.starts_with("five")) return "5";
	if (s.starts_with("six")) return "6";
	if (s.starts_with("seven")) return "7";
	if (s.starts_with("eight")) return "8";
	if (s.starts_with("nine")) return "9";
	return "a";
}
int process_string(string s) {
	int t;
	int s_size = s.length();
	for (int i = 0; i < s_size; i++) {
		string number = name_to_number_start(s.substr(i, s_size - i));
		if (isdigit(number[0])) {
			t = (number[0] - '0') * 10;
			break;
		}
		if (isdigit(s[i])) {
			t = (s[i] - '0') * 10;
			break;
		}
	}
	for (int i = s_size - 1; i >= 0; i--) {
		string number = name_to_number_end(s.substr(i, i - s_size));
		if (isdigit(number[0])) {
			t += (number[0] - '0');
			break;
		}
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
