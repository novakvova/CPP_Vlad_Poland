#include <iostream>
#include <string>

using namespace std;

// ��������� SSok
struct SSok { 
    double wyskosc;           // ������
    double promien_podstawy;  // ����� ������
    string marka;             // �����
};

// ��������� SKarton
struct SKarton {
    SSok* soki;               // ����� ��'���� ���� SSok
    int ile_sokow;            // ʳ������ ����
    int kod;                  // ��� (���� �����)
};

// ������� ��� ����� ���������� ��� ��
void printSok(const SSok& sok) {
    cout << "Sok - Marka: " << sok.marka
        << ", Wysokosc: " << sok.wyskosc
        << ", Promien podstawy: " << sok.promien_podstawy << endl;
}

// ������� �������
int main() {

    //���� ���� ����.
    // ���� ���� ��������.
    // ������ �������� ��� � ��������
    // ʳ������ ����
    int ile_sokow = 3;

    // ��������� ����� ����
    SSok* soki = new SSok[ile_sokow];

    // ����������� ����
    soki[0] = { 15.5, 3.65, "Dawtona" };
    soki[1] = { 16.5, 3.0, "Hortex" };
    soki[2] = { 16.0, 3.5, "Tymbark" };

    // ���� ���������� ��� ����
    for (int i = 0; i < ile_sokow; i++) {
        printSok(soki[i]);
    }

    // ��������� ���������� ������
    delete[] soki;

    return 0;
}
