#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// ��������� ��� ��������
struct SStudent {
    string imie;  // ��'� ��������
    string nazwisko;  // ������� ��������
    int indeks;  // ����� ������� (��������� ������������� ��������)
    int grupaD;  // ����� ����� ����� ��������
    int grupaL;  // ����� ����������� ����� ��������
    int liczbaNiezaliczonych;  // ʳ������ ������������� �����
    string* niezaliczoneKursy;  // ��������� ����� ���� ������������� �����

    // ����������� ��� ����������� ������
    SStudent() : niezaliczoneKursy(nullptr) {}

    // ���������� ��� ��������� ���'��
    ~SStudent() {
        delete[] niezaliczoneKursy;
    }
};

void clearStream(ifstream& stream) {
    stream.ignore();
    stream.clear();
    stream.close();
}

// ��������� ��� ������ ��������
struct SLista {
    std::string nazwa;
    SStudent* studenci;
    int liczbaStudentow;

    SLista() : studenci(nullptr), liczbaStudentow(0) {}

    ~SLista() {
        delete[] studenci;
    }

    // ������� ��� ���������� �������� �� �����
    bool wczytaj(const string& nazwaPliku) {
        ifstream plik(nazwaPliku);
        if (!plik.is_open()) {
            cerr << "�� ������� ������� ����." << endl;
            return false;
        }
        if (!(plik >> nazwa)) {
            cerr << "--Blad przy zapisywaniu nazwa--";
            clearStream(plik);
            nazwa = "";
            return false;
        }
        if (!(plik >> liczbaStudentow)) {
            cerr << "Blad przy zapisywaniu liczbaStudentow";
            clearStream(plik);
            liczbaStudentow = 0;
            return false;
        }

        if (liczbaStudentow <= 0) {
            cerr << "liczbaStudentow musze byc wieksze" << endl;
            liczbaStudentow = 0;
            return false;
        }

        studenci = new SStudent[liczbaStudentow];

        for (int i = 0; i < liczbaStudentow; i++) {
            SStudent& student = studenci[i];
            if (!(plik >> student.imie)) {
                cerr << "Blad przy zapisywaniu student.imie obiektywu" << i;
                clearStream(plik);
                return false;
            }


            if (!(plik >> student.nazwisko)) {
                cerr << "Blad przy zapisywaniu nazwisko obiektywu" << i;
                clearStream(plik);
                return false;
            }

            if (!(plik >> student.indeks)) {
                cerr << "Blad przy zapisywaniu indeks obiektywu" << i;
                clearStream(plik);
                return false;
            }

            if (!(plik >> student.grupaD)) {
                cerr << "Blad przy zapisywaniu grupaD obiektywu" << i;
                clearStream(plik);
                return false;
            }

            if (!(plik >> student.grupaL)) {
                cerr << "Blad przy zapisywaniu grupaL obiektywu" << i;
                clearStream(plik);
                return false;
            }

            if (!(plik >> student.liczbaNiezaliczonych)) {
                cerr << "Blad przy zapisywaniu liczbaNiezaliczonych obiektywu" << i;
                clearStream(plik);
                return false;
            }

            //if (student.liczbaNiezaliczonych <= 0) {
            //    cerr << "student.liczbaNiezaliczonych musze byc wieksze" << endl;
            //    student.liczbaNiezaliczonych = 0;
            //    //continue;
            //    //return false;
            //}

            student.niezaliczoneKursy = new std::string[student.liczbaNiezaliczonych];
            for (int j = 0; j < student.liczbaNiezaliczonych; j++) {
                if (!(plik >> student.niezaliczoneKursy[j])) {
                    cerr << "Blad przy zapisywaniu student.niezaliczoneKursy[j] obiektywu" << j;
                    clearStream(plik);
                    return false;
                }
            }
        }
    }

    // ������� ��� ��������� ���������� ��� ������ ��������
    void wypisz(const SStudent& student, std::ostream& out) const {
        out << student.imie << " " << student.nazwisko << " " << student.indeks << " "
            << student.grupaD << " " << student.grupaL << " " << student.liczbaNiezaliczonych << "\n";

        for (int j = 0; j < student.liczbaNiezaliczonych; ++j) {
            out << student.niezaliczoneKursy[j] << " ";
        }
        out << "\n";
    }

    // ������� ��� ��������� ��� ��������
    void wypisz(ostream& out) const {
        out << "������: " << nazwa << "\n";
        for (int i = 0; i < liczbaStudentow; ++i) {
            wypisz(studenci[i], out);
        }
    }

    // Գ����: ������� ��������, �� ����� "Podstawy_Programowania"
    void filtr(const string& nazwaPlikuWyj) const {
        std::ofstream out(nazwaPlikuWyj);
        for (int i = 0; i < liczbaStudentow; ++i) {
            const SStudent& student = studenci[i];
            bool zdane = true;
            for (int j = 0; j < student.liczbaNiezaliczonych; ++j) {
                if (student.niezaliczoneKursy[j] == "Podstawy_Programowania") {
                    zdane = false;
                    break;
                }
            }
            if (zdane) {
                wypisz(student, out);
            }
        }
    }

    // ���������� �������� ������� ������������� �����
    double srednia() const {
        if (liczbaStudentow == 0) return 0.0;

        int suma = 0;
        for (int i = 0; i < liczbaStudentow; ++i) {
            suma += studenci[i].liczbaNiezaliczonych;
        }

        return suma / (double)liczbaStudentow;
    }

    // ��������� �������� � ��������� ������� ������������� �����
    void wypiszNajgorszego(ostream& out) const {
        if (liczbaStudentow == 0) return;

        const SStudent* najgorszy = &studenci[0];
        for (int i = 1; i < liczbaStudentow; i++) {
            if (studenci[i].liczbaNiezaliczonych > najgorszy->liczbaNiezaliczonych) {
                najgorszy = &studenci[i];
            }
        }

        wypisz(*najgorszy, out);
    }

    // ���������� �������� �� �������
       // ���������� �������� ������� ���������
    void sortuj(std::ostream& out) {
        for (int i = 0; i < liczbaStudentow - 1; ++i) {
            for (int j = 0; j < liczbaStudentow - i - 1; ++j) {
                bool swapNeeded = false;

                if (studenci[j].imie > studenci[j + 1].imie) 
                {
                    swapNeeded = true;
                }

                if (swapNeeded) {

                    myswap(studenci[j], studenci[j + 1]);
                }
            }
        }

        wypisz(out);
    }

    // ������� ��� ����� ���� ��������
    void myswap(SStudent& a, SStudent& b) {
        SStudent temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    SLista lista;
    lista.wczytaj("studenci.txt");

    std::cout << "���� ������ ��������:" << endl;
    lista.wypisz(cout);

    std::cout << "������� ������� ������������� �����: " << lista.srednia() << "\n";

    std::cout << "������� �� ��������� ������� ������������� �����:" << std::endl;
    lista.wypiszNajgorszego(cout);

    std::cout << "������ �������� ���� ���������� �� ������:" << std::endl;
    lista.sortuj(cout);

    lista.filtr("zaliczeni.txt");
    return 0;
}
