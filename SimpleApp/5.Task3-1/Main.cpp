#include <iostream>
#include <string>

using namespace std;

// Структура SSok
struct SSok { 
    double wyskosc;           // Висота
    double promien_podstawy;  // Радіус основи
    string marka;             // Марка
};

// Структура SKarton
struct SKarton {
    SSok* soki;               // Масив об'єктів типу SSok
    int ile_sokow;            // Кількість соків
    int kod;                  // Код (ціле число)
};

// Функція для друку інформації про сік
void printSok(const SSok& sok) {
    cout << "Sok - Marka: " << sok.marka
        << ", Wysokosc: " << sok.wyskosc
        << ", Promien podstawy: " << sok.promien_podstawy << endl;
}

// Головна функція
int main() {

    //Маємо певні соки.
    // Маємо певні бляшанки.
    // Можеом наливати сок у бляшанки
    // Кількість соків
    int ile_sokow = 3;

    // Динамічний масив соків
    SSok* soki = new SSok[ile_sokow];

    // Ініціалізація соків
    soki[0] = { 15.5, 3.65, "Dawtona" };
    soki[1] = { 16.5, 3.0, "Hortex" };
    soki[2] = { 16.0, 3.5, "Tymbark" };

    // Вивід інформації про соки
    for (int i = 0; i < ile_sokow; i++) {
        printSok(soki[i]);
    }

    // Видалення динамічного масиву
    delete[] soki;

    return 0;
}
