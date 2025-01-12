#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Структура SSok
struct SSok {
    double wyskosc;           // Висота
    double promien_podstawy;  // Радіус основи
    string marka;             // Марка
};

// Функція wczytaj
SSok* wczytaj(istream& in, int& rozmiar) {
    // Зчитуємо кількість соків
    in >> rozmiar;

    // Створюємо динамічний масив об'єктів SSok
    SSok* soki = new SSok[rozmiar];

    // Зчитуємо дані про кожен сік
    for (int i = 0; i < rozmiar; i++) {
        in >> soki[i].wyskosc >> soki[i].promien_podstawy >> soki[i].marka;
    }

    // Повертаємо покажчик на динамічний масив
    return soki;
}

// Функція для виводу даних про соки
void drukujSoki(const SSok* soki, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << "Sok " << i + 1 << " - Marka: " << soki[i].marka
            << ", Wysokosc: " << soki[i].wyskosc
            << ", Promien podstawy: " << soki[i].promien_podstawy << endl;
    }
}

// Головна функція
int main() {
    // Файл з вхідними даними
    ifstream inputFile("soki.txt");

    // Перевірка, чи файл відкрився
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    // Змінні
    int rozmiar;
    SSok* soki = wczytaj(inputFile, rozmiar); // Викликаємо функцію wczytaj

    // Закриваємо файл
    inputFile.close();

    // Вивід соків
    cout << "Прочитані соки:" << endl;
    drukujSoki(soki, rozmiar);

    // Звільнення пам'яті
    delete[] soki;

    return 0;
}
