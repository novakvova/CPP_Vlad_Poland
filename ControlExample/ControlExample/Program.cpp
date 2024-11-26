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
//argc - кількість парметрів
//argv - самі параметри
int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); //ініціалізація рандом - ходить по таблиці рандома, для правильної роботи
	//час запуска вашшого додатку - це є випадкове число
	/*
	cout << "Кількість параметрів "<<argc<<" \n";
	for (int i = 0; i < argc; i++)
	{
		cout << "Номер параметру " << i+1<< " -- " << argv[i] << " \n";
	}
	*/
	if (argc == 1) {
		cout << "Вкажіть розмір масиву через параметер командного рядка!";
		return 1;
	}
	//розмір масиву
	int n = stoi(argv[1]);  //перше число - це розмір масиву

	
	//вказіник, ми виділяємо память на n - чисел
	int *mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = 0;
	}
	print(mas, n);

	int a; // = stoi(argv[2]);  //друге число - почяток діапазону
	int b; // = stoi(argv[3]);  //третє число - кінець діапазону
	cout << "Вкажіть початок діпазону ->_";
	cin >> a;
	cout << "Вкажіть кінець діпазону ->_";
	cin >> b;

	for (int i = 0; i < n; i++)
	{
		mas[i] = a + std::rand() % (b - a + 1);
	}
	print(mas, n);

	cout << "Сумма чисел кратна 5 = " << summa(mas, n) << "\n";
	//затримка в роботі програми
	cin.get();
	return 0;
}