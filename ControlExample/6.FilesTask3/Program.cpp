#include<iostream>
#include<fstream>
using namespace std;

bool isParamsArgv(string str) {
	//argv[1] - tt@tt.tt
	int pos = str.find('@');
	return pos<str.length();
}
int main(const int argc, const char* argv[])
{
	if (argc < 3)
	{
		cout << "Enter input.txt and output.txt argv!!!\n";
	}
	ifstream reader(argv[1]);
	if (!reader) {
		cout << "Problem out file!\n";
		return -1;
	}
	char word[100];
	char ch;
	int i = 0;
	bool isEnd = false;
	while (reader.get(ch)) {
		//cout << ch;
		if (ch == ' ')
			isEnd = true;
		if (ch == '\t')
			isEnd = true;
		if (ch == '\n')
			isEnd = true;
		if (isEnd) {
			if (i == 0)
				isEnd = false;
			else {
				//Перевірити чи word містить собаку @, якщо містить @, то записуємо у out.txt
				word[i] = '\0';
				cout << word << endl;
				isEnd = false;
				i = 0;
			}
		}
		else {
			word[i] = ch;
			i++;
		}
	}
	if (i != 0)
	{
		word[i] = '\0';
		cout << word << "\n";
	}
	reader.close();
	return 0;
}