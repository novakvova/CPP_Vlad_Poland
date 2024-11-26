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

//argc - кількість парметрів
//argv - самі параметри
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); //ініціалізація рандом - ходить по таблиці рандома, для правильної роботи
	//час запуска вашшого додатку - це є випадкове число
	//cout << "Random = " << getRandomValue(3.5, 4.5)<<"\n";

	cout << "Вкажіть розмір матриці: ";
	int n, m;
	cin >> n >> m;
	
	float** matrix = new float*[n]; //виділяємо память під рядки - маємо n - рядків
	for (int i = 0; i < n; ++i) //під кожен n - рядок виділяємо m - стовпчиків
	{ 
		matrix[i] = new float[m];
	}
	int min, max;
	cout << "Вкажіть велички float (min та max) рандом: ";
	cin >> min >> max;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = getRandomValue(min, max);
		}
	}
	printMatrix(matrix, n, m);

	cout << "Сума не парних рядків = "<< sumMatrix(matrix,n, m)<<"\n";
	
	// Step 5: Deallocate memory
	for (int i = 0; i < m; ++i) {
		delete[] matrix[i]; // Delete each row
	}
	delete[] matrix; // Delete the row pointers

	cin.get();
	return 0;
}