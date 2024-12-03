#include<iostream>
using namespace std;

bool isCheckEmail(const string& str) {
	char itemSearch = '@';
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == '@')
			return true;
		i++;
	}
	return false;
}
int main()
{
	string str;
	cout << "Enter email: ";
	cin >> str;
	cout << "Hello str = " << str << endl;
	cout << "Is Email = "<< isCheckEmail(str) << "\n";
	return 0;
}