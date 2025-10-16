#include <iostream>
#include <cctype>
#include <string>

int main() {
	std::string s;
	std::getline(std::cin, s);

	for (char &c : s) {
		if (isalpha(c)) {
			c = std::toupper(c);
		} else if (isdigit(c)) {
			c = '*';
		} else if (c == ' ' || c == '\t') {
			c = '_';
		}
	}
	std::cout << s;
	return 0;
}