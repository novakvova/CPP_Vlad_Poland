#include<iostream>
using namespace std;

int main()
{
	char ch[80];
	cout << "Enter full name: ";
	cin.getline(ch, 80, '\n');
	//cout << "Hello " << ch << "\n";
	char item;
	cout << "Enter char item: ";
	cin >> item;
	//cout << "View item " << item << endl;
	int len = 0;
	int i = 0;
	while (ch[i] != '\0') {
		len++;
		i++;
	}
	//cout << "Len str = " << len << "\n";
	int n=len+2; //Для двох символів 1 - з початку інший у кінці'
	char* newStr = new char[n+1]; //n+1 у кінці має бути '\0'
	i = 0; 
	for (int i = 0; i < n; i++)
	{
		if (i == 0) 
		{
			newStr[0] = item;
			continue;
		}
			
		if (i == n - 1) 
		{
			newStr[i] = item;
			break;
		}
		newStr[i] = ch[i - 1];
	}
	newStr[n] = '\0';
	cout << "new str = " << newStr << "\n";
	return 0;
}