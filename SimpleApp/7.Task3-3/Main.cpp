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

// Структура SKarton
struct SKarton {
    SSok* soki;           // Масив соків
    int ile_soków;        // Кількість соків
    string kod;           // Код коробки
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

// Функція pakuj_karton
void pakuj_karton(SKarton& karton, SSok* soki, int rozmiar) {
    karton.soki = soki;           // Ініціалізуємо масив соків
    karton.ile_soków = rozmiar;   // Ініціалізуємо кількість соків
    karton.kod = "ABC123";        // Призначаємо код коробки
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

    // Створення коробки
    SKarton karton;

    // Виклик функції pakuj_karton для ініціалізації коробки
    pakuj_karton(karton, soki, rozmiar);

    // Вивід соків
    cout << "Прочитані соки:" << endl;
    //drukujSoki(soki, rozmiar);
    drukujSoki(karton.soki, rozmiar);

    // Виведення даних про коробку
    cout << "\nКартон з соками:" << endl;
    cout << "Код коробки: " << karton.kod << endl;
    cout << "Кількість соків: " << karton.ile_soków << endl;

    // Звільнення пам'яті
    delete[] soki;

    return 0;
}
