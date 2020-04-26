#include "loader.h"
#include <iostream>

using namespace std;
std::vector<BYTE> load(std::string fileName) {
	vector<BYTE> rVal;
	ifstream file;
	file.open(fileName.c_str(), ios::in);
	if (file.fail()) {
		std::cout << "could not load given file" << std::endl;
		return rVal;
	}
	while (!file.eof()) {
		BYTE val;
		file >> val;
		rVal.push_back(val);
	}
	file.close();
	return rVal;
}