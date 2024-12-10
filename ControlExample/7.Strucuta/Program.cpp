#include<iostream>
using namespace std;

struct student {
	string name; //���� ��������� 
	int age;	 //���� ���������
};

struct sAuto {
	string nazwa; //�����
	string model; //������
	int rok;	//�� ������������
	string skrzynia;	//��� ������� �������
	float pojemnosc;	//��'�� �������
	int moc;	//��������� �������
};

// ������� 1: ������� ��'��� sAuto �� �������� �����������
sAuto inicjuj(const string& nazwa, const string& model, int rok,
	const string& skrzynia, float pojemnosc, int moc)
{
	sAuto temp;
	temp.nazwa = nazwa;
	temp.model = model;
	temp.rok = rok;
	temp.skrzynia = skrzynia;
	temp.pojemnosc = pojemnosc;
	temp.moc = moc;
	return temp;
}

void inicjuj(sAuto& Auto, const string& nazwa, const string& model, int rok,
	const string& skrzynia, float pojemnosc, int moc) 
{
	Auto.nazwa = nazwa;
	Auto.model = model;
	Auto.rok = rok;
	Auto.skrzynia = skrzynia;
	Auto.pojemnosc = pojemnosc;
	Auto.moc = moc;
}

void inicjuj(sAuto* Auto, const string& nazwa, const string& model, int rok, 
	const string& skrzynia, float pojemnosc, int moc) 
{
	if (Auto) {
		Auto->nazwa = nazwa;
		Auto->model = model;
		Auto->rok = rok;
		Auto->skrzynia = skrzynia;
		Auto->pojemnosc = pojemnosc;
		Auto->moc = moc;
	}
}

// ������� ��� ������ ���������� ��� ���������
void printAuto(const sAuto& Auto) {
	cout << "Nazwa: " << Auto.nazwa << ", Model: " << Auto.model
		<< ", Rok: " << Auto.rok << ", Skrzynia: " << Auto.skrzynia
		<< ", Pojemnosc: " << Auto.pojemnosc << "L, Moc: " << Auto.moc << " KM" << endl;
}

int main() {

	student ivan;
	ivan.name = "Ivan Petrovych";
	ivan.age = 23;

	cout << ivan.name << "\t" << ivan.age << endl;

	student* ilona = new student;
	ilona->name = "Ilona Melnyk";
	ilona->age = 18;

	cout << ilona->name << "\t" << ilona->age << endl;

	//sAuto list[10];
	//sAuto* autoCar = new sAuto[15];
	//list[0].model = "asdfasf";
	//autoCar[0].rok = 2.7;

	sAuto bmw = inicjuj("bmw", "x5", 2006, "auto", 3.0, 230);

	printAuto(bmw);

	return 0;
}