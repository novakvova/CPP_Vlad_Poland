#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Структура для студента
struct SStudent {
    string imie;  // Ім'я студента
    string nazwisko;  // Прізвище студента
    int indeks;  // Номер індексу (унікальний ідентифікатор студента)
    int grupaD;  // Номер денної групи студента
    int grupaL;  // Номер лабораторної групи студента
    int liczbaNiezaliczonych;  // Кількість незарахованих курсів
    string* niezaliczoneKursy;  // Динамічний масив назв незарахованих курсів

    // Конструктор для ініціалізації масиву
    SStudent() : niezaliczoneKursy(nullptr) {}

    // Деструктор для звільнення пам'яті
    ~SStudent() {
        delete[] niezaliczoneKursy;
    }
};

void clearStream(ifstream& stream) {
    stream.ignore();
    stream.clear();
    stream.close();
}

// Структура для списку студентів
struct SLista {
    std::string nazwa;
    SStudent* studenci;
    int liczbaStudentow;

    SLista() : studenci(nullptr), liczbaStudentow(0) {}

    ~SLista() {
        delete[] studenci;
    }

    // Функція для зчитування студентів із файлу
    bool wczytaj(const string& nazwaPliku) {
        ifstream plik(nazwaPliku);
        if (!plik.is_open()) {
            cerr << "Не вдалося відкрити файл." << endl;
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

    // Функція для виведення інформації про одного студента
    void wypisz(const SStudent& student, std::ostream& out) const {
        out << student.imie << " " << student.nazwisko << " " << student.indeks << " "
            << student.grupaD << " " << student.grupaL << " " << student.liczbaNiezaliczonych << "\n";

        for (int j = 0; j < student.liczbaNiezaliczonych; ++j) {
            out << student.niezaliczoneKursy[j] << " ";
        }
        out << "\n";
    }

    // Функція для виведення всіх студентів
    void wypisz(ostream& out) const {
        out << "Список: " << nazwa << "\n";
        for (int i = 0; i < liczbaStudentow; ++i) {
            wypisz(studenci[i], out);
        }
    }

    // Фільтр: вивести студентів, які здали "Podstawy_Programowania"
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

    // Обчислення середньої кількості незарахованих курсів
    double srednia() const {
        if (liczbaStudentow == 0) return 0.0;

        int suma = 0;
        for (int i = 0; i < liczbaStudentow; ++i) {
            suma += studenci[i].liczbaNiezaliczonych;
        }

        return suma / (double)liczbaStudentow;
    }

    // Виведення студента з найбільшою кількістю незарахованих курсів
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

    // Сортування студентів за критерієм
       // Сортування студентів методом бульбашки
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

    // Функція для обміну двох студентів
    void myswap(SStudent& a, SStudent& b) {
        SStudent temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    SLista lista;
    lista.wczytaj("studenci.txt");

    std::cout << "Весь список студентів:" << endl;
    lista.wypisz(cout);

    std::cout << "Середня кількість незарахованих курсів: " << lista.srednia() << "\n";

    std::cout << "Студент із найбільшою кількістю незарахованих курсів:" << std::endl;
    lista.wypiszNajgorszego(cout);

    std::cout << "Список студентів після сортування за іменем:" << std::endl;
    lista.sortuj(cout);

    lista.filtr("zaliczeni.txt");
    return 0;
}
