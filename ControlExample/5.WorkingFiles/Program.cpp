#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//���� � ���� - ios_base::out - ����� ����, ���� ������ ���, �� �� ���������
	//ofstream outFileBober("vlad.txt", ios_base::out);
	//app -- ����� �������� � ����
	//ofstream outFileBober("vlad.txt", ios_base::app);
	//outFileBober << "123\n";
	//outFileBober.close();
	
	//������� ����
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