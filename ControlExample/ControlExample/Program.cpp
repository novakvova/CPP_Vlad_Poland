#include<iostream>
//#include <cstdlib> 
#include <string>
#include <ctime>
using namespace std;
#include<Windows.h>

void print(int *mas, int n) 
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << "\n";
}

int summa(int* mas, int n)
{
	int summa = 0;
	for (int i = 0; i < n; i++)
	{
		if ((mas[i] % 5) == 0)
			summa += mas[i];
	}
	return summa;
}
//argc - ������� ��������
//argv - ��� ���������
int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); //����������� ������ - ������ �� ������� �������, ��� ��������� ������
	//��� ������� ������� ������� - �� � ��������� �����
	/*
	cout << "ʳ������ ��������� "<<argc<<" \n";
	for (int i = 0; i < argc; i++)
	{
		cout << "����� ��������� " << i+1<< " -- " << argv[i] << " \n";
	}
	*/
	if (argc == 1) {
		cout << "������ ����� ������ ����� ��������� ���������� �����!";
		return 1;
	}
	//����� ������
	int n = stoi(argv[1]);  //����� ����� - �� ����� ������

	
	//�������, �� �������� ������ �� n - �����
	int *mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = 0;
	}
	print(mas, n);

	int a; // = stoi(argv[2]);  //����� ����� - ������� ��������
	int b; // = stoi(argv[3]);  //���� ����� - ����� ��������
	cout << "������ ������� ������� ->_";
	cin >> a;
	cout << "������ ����� ������� ->_";
	cin >> b;

	for (int i = 0; i < n; i++)
	{
		mas[i] = a + std::rand() % (b - a + 1);
	}
	print(mas, n);

	cout << "����� ����� ������ 5 = " << summa(mas, n) << "\n";
	//�������� � ����� ��������
	cin.get();
	return 0;
}