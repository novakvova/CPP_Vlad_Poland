#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//Вивід у файл - ios_base::out - Новий файл, якщо старий був, то він стирається
	//ofstream outFileBober("vlad.txt", ios_base::out);
	//app -- резим дозапису у файл
	//ofstream outFileBober("vlad.txt", ios_base::app);
	//outFileBober << "123\n";
	//outFileBober.close();
	
	//Читання фалу
	ifstream in("vlad.txt");
	//char line[100];
	char ch;
	while (in.get(ch))
		cout << ch;
	//in.get(line, '\n', 100);
	//cout << line<<endl;
	in.close();
	return 0;
}