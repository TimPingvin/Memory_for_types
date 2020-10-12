#include <iostream>

void memory() 
{
	std::cout << "Объём памяти под int = " << sizeof(int) << " байта" << '\n';
	std::cout << "Объём памяти под short int = " << sizeof(short int) << " байта" << '\n';
	std::cout << "Объём памяти под long int = " << sizeof(long int) << " байта" << '\n';
	std::cout << "Объём памяти под float = " << sizeof(float) << " байта" << '\n';
	std::cout << "Объём памяти под double = " << sizeof(double) << " байт" << '\n';
	std::cout << "Объём памяти под long double = " << sizeof(long double) << " байт" << '\n';
	std::cout << "Объём памяти под char = " << sizeof(char) << " байт" << '\n';
	std::cout << "Объём памяти под bool = " << sizeof(bool) << " байт" << '\n' << '\n';
}

void code_int() 
{
	int num,mask;
	mask = INT_MIN;
	std::cout << "Число - ";
	std::cin >> num;
	putchar(num & mask ? '1' : '0');
	std::cout << " ";
	for (int i = 1; i < sizeof(int) * 8; i++) {
		putchar(num & mask ? '1' : '0');
		num <<= 1;
	}
	std::cout << " - код введённого числа" << '\n' << '\n';
}

void code_float()
{
	union {
		long int tool;
		float num;
	};
	int mask = INT_MIN;
	std::cout << "Число - ";
	std::cin >> num;
	putchar(tool & mask ? '1' : '0');
	tool <<= 1;
	std::cout << " ";
	for (int i = 1; i < 9; i++) {
		putchar(tool & mask ? '1' : '0');
		tool <<= 1;
	}
	std::cout << " ";
	for (int i = 9; i < 32; i++) {
		putchar(tool & mask ? '1' : '0');
		tool <<= 1;
	}
	std::cout << " - его код" << '\n' << '\n';
}

void code_double() 
{
	union {
		long int tool[2];
		double num;
	};
	std::cout << "Число - ";
	std::cin >> num;
	int mask = INT_MIN, a;
	a = mask & tool[1];
	if (a == mask) {
		std::cout << "1 ";
	}
	else {
		std::cout << "0 ";
	}
	tool[1] <<= 1;
	for (int i = 1; i != 12; i++) {
		a = tool[1] & mask;
		if (a == mask) {
			std::cout << '1';
		}
		else{
			std::cout << '0';
		}
		tool[1] <<= 1;
	}
	std::cout << " ";
	for (int i = 12; i != 32; i++) {
		a = tool[1] & mask;
		if (a == mask) {
			std::cout << '1';
		}
		else{
			std::cout << '0';
		}
		tool[1] <<= 1;
	}

	for (int i = 0; i != 32; i++) {
		a = tool[0] & mask;
		if (a == mask) {
			std::cout << '1';
		}
		else{
			std::cout << '0';
		}
		tool[0] <<= 1;
	}
	std::cout << " - его код" << '\n' << '\n';
}

int main() {
	setlocale(0, "");
	int nomer;
	start:
		std::cout << "Выберите номер раздела" << '\n' << '\n';
		std::cout << "1) Объём памяти под разные типы данных " << '\n';
		std::cout << "2) Код числа int" << '\n';
		std::cout << "3) Код числа float" << '\n';
		std::cout << "4) Код числа double" << '\n' << '\n';
		std::cin >> nomer;
		std::cout << '\n';

		switch (nomer) {
		case 1:
			memory();
			break;
		case 2:
			code_int();
			break;
		case 3:
			code_float();
			break;
		case 4:
			code_double();
			break;
		default:
			std::cout << "Это уже не к нам)";
			break;
		}
		std::cout << '\n' << "Если нужно что-то ещё - введите '1', если нет - что угодно, но не '1') " << '\n' << '\n';
		int replay;
		std::cin >> replay;
		switch (replay) {
		case 1:
			goto start;
			break;
		default:
			return 0;
			break;
		}
}
