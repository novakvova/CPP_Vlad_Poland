/*
Завдання 3:

Ціль завдання — відпрацювання навичок роботи з потоками файлів.

Завдання:
Розробіть та реалізуйте:

	Функцію pomoc, яка повертає інформацію про те, чи є переданий аргумент (рядок символів) 
		адресою електронної пошти (на основі наявності символу @).
	Функцію selektor, яка повертає логічне значення і служить для фільтрації вхідного 
		файлу для пошуку та запису у вихідний файл усіх адрес електронної пошти, 
		розділених крапкою з комою та знаком нового рядка. 
		Використовуйте функцію pomoc, а всі операції з текстом виконуйте за допомогою типу string.

Імена файлів:

	Вхідний файл: in.txt
	Вихідний файл: out.txt (передаються як параметри командного рядка під час запуску програми).
Додаткові вимоги:
	Прийміть, що виразом є кожний рядок символів, розділений пробілами, табуляцією, 
		знаком кінця рядка або кінцем файлу.

Розробіть та реалізуйте функцію main, яка забезпечить коректну роботу програми.

*/


#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
using namespace std;

//Перевірямо чи рядок містить @
bool pomoc(const string& str) 
{
	return str.find('@') != string::npos;
}

void selektor(const string& input, const string& output) {
	ifstream input_f(input);
	ofstream out_f(output);

	if (!input_f) {
		std::cerr << "Не вдалося відкрити вхідний файл: " << input << std::endl;
		return;
	}

	if (!out_f) {
		std::cerr << "Не вдалося створити вихідний файл: " << output << std::endl;
		return;
	}

	string line;
	while (getline(input_f, line)) {
		stringstream ss(line);
		string word;
		while (ss >> word) {
			// Якщо слово є адресою електронної пошти, додаємо його у вихідний файл
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