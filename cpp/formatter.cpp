#include <string>
#include <sstream>
#include <iostream>

class Formatter : public std::ostringstream {
};

int main() {
	std::string s = (std::ostringstream() << "hello" << " world"

	return 0;
}

