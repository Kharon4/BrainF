#include <fstream>
#include "interpreter.h"
#include "loader.h"

typedef unsigned char BYTE;

using namespace std;


int main() {
	vector<BYTE> code;
	string fileName;

	cout << "Enter File name : ";
	cin>>fileName;
	code = load(fileName);

	run(code);
	cout <<"\n\nExecution Finished\n";
	system("pause");
	return 0;
}