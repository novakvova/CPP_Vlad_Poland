/*
�������� 3:

ֳ�� �������� � ������������ ������� ������ � �������� �����.

��������:
�������� �� ���������:

	������� pomoc, ��� ������� ���������� ��� ��, �� � ��������� �������� (����� �������) 
		������� ���������� ����� (�� ����� �������� ������� @).
	������� selektor, ��� ������� ������ �������� � ������� ��� ���������� �������� 
		����� ��� ������ �� ������ � �������� ���� ��� ����� ���������� �����, 
		��������� ������� � ����� �� ������ ������ �����. 
		�������������� ������� pomoc, � �� �������� � ������� ��������� �� ��������� ���� string.

����� �����:

	������� ����: in.txt
	�������� ����: out.txt (����������� �� ��������� ���������� ����� �� ��� ������� ��������).
�������� ������:
	�������, �� ������� � ������ ����� �������, ��������� ��������, ����������, 
		������ ���� ����� ��� ����� �����.

�������� �� ��������� ������� main, ��� ����������� �������� ������ ��������.

*/


#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
using namespace std;

//��������� �� ����� ������ @
bool pomoc(const string& str) 
{
	return str.find('@') != string::npos;
}

void selektor(const string& input, const string& output) {
	ifstream input_f(input);
	ofstream out_f(output);

	if (!input_f) {
		std::cerr << "�� ������� ������� ������� ����: " << input << std::endl;
		return;
	}

	if (!out_f) {
		std::cerr << "�� ������� �������� �������� ����: " << output << std::endl;
		return;
	}

	string line;
	while (getline(input_f, line)) {
		stringstream ss(line);
		string word;
		while (ss >> word) {
			// ���� ����� � ������� ���������� �����, ������ ���� � �������� ����
			//cout << word << endl;
			if (pomoc(word)) {
				out_f << word << ";\n";
			}
		}
	}
}

int main(const int argc, const char* argv[])
{
	if (argc < 3)
	{
		cout << "Enter input and output file name argv!!!\n";
		return -1;
	}

	selektor(argv[1], argv[2]);

	return 0;
}