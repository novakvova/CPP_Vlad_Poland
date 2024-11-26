#include<iostream>
//#include <cstdlib> 
#include <string>
#include <ctime>
using namespace std;
#include<Windows.h>

float getRandomValue(float min, float max) 
{
	return min + (float)(rand()) / RAND_MAX * (max - min);
}

void printMatrix(float** matrix, int n, int m) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

float sumMatrix(float** matrix, int n, int m)
{
	float summ=0.0;
	for (int i = 0; i < n; i+=2)
	{
		for (int j = 0; j < m; j++)
		{
			summ+= matrix[i][j];
		}
	}

	return summ;
}

//argc - ������� ��������
//argv - ��� ���������
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); //����������� ������ - ������ �� ������� �������, ��� ��������� ������
	//��� ������� ������� ������� - �� � ��������� �����
	//cout << "Random = " << getRandomValue(3.5, 4.5)<<"\n";

	cout << "������ ����� �������: ";
	int n, m;
	cin >> n >> m;
	
	float** matrix = new float*[n]; //�������� ������ �� ����� - ���� n - �����
	for (int i = 0; i < n; ++i) //�� ����� n - ����� �������� m - ���������
	{ 
		matrix[i] = new float[m];
	}
	int min, max;
	cout << "������ ������� float (min �� max) ������: ";
	cin >> min >> max;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = getRandomValue(min, max);
		}
	}
	printMatrix(matrix, n, m);

	cout << "���� �� ������ ����� = "<< sumMatrix(matrix,n, m)<<"\n";
	
	
	//cout << "------------" << n << "----" << m << "\n";
	
	
	/*
	//�������, �� �������� ������ �� n - �����
	int* mas = new int[n];

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

	delete[] mas; //�������� ���'���
	*/
	//�������� � ����� ��������
	cin.get();
	return 0;
}