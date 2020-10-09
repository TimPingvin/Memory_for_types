#include <iostream>

void memory() 
{
	std::cout << "����� ������ ��� int = " << sizeof(int) << " �����" << '\n';
	std::cout << "����� ������ ��� short int = " << sizeof(short int) << " �����" << '\n';
	std::cout << "����� ������ ��� long int = " << sizeof(long int) << " �����" << '\n';
	std::cout << "����� ������ ��� float = " << sizeof(float) << " �����" << '\n';
	std::cout << "����� ������ ��� double = " << sizeof(double) << " ����" << '\n';
	std::cout << "����� ������ ��� long double = " << sizeof(long double) << " ����" << '\n';
	std::cout << "����� ������ ��� char = " << sizeof(char) << " ����" << '\n';
	std::cout << "����� ������ ��� bool = " << sizeof(bool) << " ����" << '\n' << '\n';
}

void code_int() 
{
	int num,mask;
	mask = INT_MIN;
	std::cout << "����� - ";
	std::cin >> num;
	putchar(num & mask ? '1' : '0');
	std::cout << " ";
	for (int i = 1; i < sizeof(int) * 8; i++) {
		putchar(num & mask ? '1' : '0');
		num <<= 1;
	}
	std::cout << " - ��� ��������� �����" << '\n' << '\n';
}

void code_float()
{
	union {
		long int tool;
		float num;
	};
	int mask = INT_MIN;
	std::cout << "����� - ";
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
	std::cout << " - ��� ���" << '\n' << '\n';
}

void code_double() 
{
	union {
		long int tool[2];
		double num;
	};
	std::cout << "����� - ";
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
	for (int i = 1; i != 13; i++) {
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
	for (int i = 13; i != 32; i++) {
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
	std::cout << " - ��� ���" << '\n' << '\n';
}

int main() {
	setlocale(0, "");
	int nomer;
	start:
		std::cout << "�������� ����� �������" << '\n' << '\n';
		std::cout << "1) ����� ������ ��� ������ ���� ������" << '\n';
		std::cout << "2) ��� ����� int" << '\n';
		std::cout << "3) ��� ����� float" << '\n';
		std::cout << "4) ��� ����� double" << '\n' << '\n';
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
			std::cout << "��� ��� �� � ���)";
			break;
		}
		std::cout << '\n' << "���� ����� ���-�� ��� - ������� '1', ���� ��� - '0' " << '\n' << '\n';
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