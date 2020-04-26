#include "interpreter.h"

#define dataSize 30000

BYTE data[dataSize];

void initData() {
	for (size_t i = 0; i < dataSize; ++i)data[i] = 0;
}

void run(std::vector<BYTE>& code) {
	initData();

	size_t codeIndex = 0;
	size_t dataIndex = 0;
	while (codeIndex < code.size()) {
		BYTE codePiece = code[codeIndex];
		switch (codePiece)
		{
		case '.':
			std::cout << data[dataIndex];
			codeIndex++;
			break;
		case ',':
			std::cin >> data[dataIndex];
			codeIndex++;
			break;
		case '+':
			data[dataIndex]++;
			codeIndex++;
			break;
		case '-':
			data[dataIndex]--;
			codeIndex++;
			break;
		case '>':
			dataIndex++;
			codeIndex++;
			break;
		case '<':
			dataIndex--;
			codeIndex++;
			break;
		case '[':
			if (data[dataIndex]) {
				codeIndex++;
			}
			else {
				size_t count = 1;
				if (codeIndex == code.size()) {
					std::cout << "\n\nError missing ] in code\n";
					return;
				}
				while (count) {
					codeIndex++;
					if (codeIndex >= code.size()) {
						std::cout << "\n\nError missing ] in code\n";
						return;
					}
					if (code[codeIndex] == '[')count++;
					else if (code[codeIndex] == ']')count--;
				}
				codeIndex++;
			}
			break;

		case ']':
			if (data[dataIndex]) {
				size_t count = 1;
				if (codeIndex == 0) {
					std::cout << "\n\nError missing [ in code\n";
					return;
				}
				codeIndex--;
				while (count) {
					if (code[codeIndex] == ']')count++;
					else if (code[codeIndex] == '[')count--;
					if (codeIndex == 0) {
						std::cout << "\n\nError missing ] in code\n";
						return;
					}
					codeIndex--;
				}
				codeIndex++;
			}
			else {
				codeIndex++;
			}
			break;

		default:
			codeIndex++;
			break;
		}

	}

}