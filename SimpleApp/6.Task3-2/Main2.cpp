#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ��������� SSok
struct SSok {
    double wyskosc;           // ������
    double promien_podstawy;  // ����� ������
    string marka;             // �����
};

// ������� wczytaj
SSok* wczytaj(istream& in, int& rozmiar) {
    // ������� ������� ����
    in >> rozmiar;

    // ��������� ��������� ����� ��'���� SSok
    SSok* soki = new SSok[rozmiar];

    // ������� ��� ��� ����� ��
    for (int i = 0; i < rozmiar; i++) {
        in >> soki[i].wyskosc >> soki[i].promien_podstawy >> soki[i].marka;
    }

    // ��������� �������� �� ��������� �����
    return soki;
}

// ������� ��� ������ ����� ��� ����
void drukujSoki(const SSok* soki, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << "Sok " << i + 1 << " - Marka: " << soki[i].marka
            << ", Wysokosc: " << soki[i].wyskosc
            << ", Promien podstawy: " << soki[i].promien_podstawy << endl;
    }
}

// ������� �������
int main() {
    // ���� � �������� ������
    ifstream inputFile("soki.txt");

    // ��������, �� ���� ��������
    if (!inputFile) {
        cerr << "�� ������� ������� ����!" << endl;
        return 1;
    }

    // ����
    int rozmiar;
    SSok* soki = wczytaj(inputFile, rozmiar); // ��������� ������� wczytaj

    // ��������� ����
    inputFile.close();

    // ���� ����
    cout << "�������� ����:" << endl;
    drukujSoki(soki, rozmiar);

    // ��������� ���'��
    delete[] soki;

    return 0;
}
