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

//argc - к≥льк≥сть парметр≥в
//argv - сам≥ параметри
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); //≥н≥ц≥ал≥зац≥€ рандом - ходить по таблиц≥ рандома, дл€ правильноњ роботи
	//час запуска вашшого додатку - це Ї випадкове число
	//cout << "Random = " << getRandomValue(3.5, 4.5)<<"\n";

	cout << "¬каж≥ть розм≥р матриц≥: ";
	int n, m;
	cin >> n >> m;
	
	float** matrix = new float*[n]; //вид≥л€Їмо пам€ть п≥д р€дки - маЇмо n - р€дк≥в
	for (int i = 0; i < n; ++i) //п≥д кожен n - р€док вид≥л€Їмо m - стовпчик≥в
	{ 
		matrix[i] = new float[m];
	}
	int min, max;
	cout << "¬каж≥ть велички float (min та max) рандом: ";
	cin >> min >> max;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = getRandomValue(min, max);
		}
	}
	printMatrix(matrix, n, m);

	cout << "—ума не парних р€дк≥в = "<< sumMatrix(matrix,n, m)<<"\n";
	
	
	//cout << "------------" << n << "----" << m << "\n";
	
	
	/*
	//вказ≥ник, ми вид≥л€Їмо пам€ть на n - чисел
	int* mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = 0;
	}
	print(mas, n);

	int a; // = stoi(argv[2]);  //друге число - поч€ток д≥апазону
	int b; // = stoi(argv[3]);  //третЇ число - к≥нець д≥апазону
	cout << "¬каж≥ть початок д≥пазону ->_";
	cin >> a;
	cout << "¬каж≥ть к≥нець д≥пазону ->_";
	cin >> b;

	for (int i = 0; i < n; i++)
	{
		mas[i] = a + std::rand() % (b - a + 1);
	}
	print(mas, n);

	cout << "—умма чисел кратна 5 = " << summa(mas, n) << "\n";

	delete[] mas; //очисчаЇмо пам'€ть
	*/
	//затримка в робот≥ програми
	cin.get();
	return 0;
}