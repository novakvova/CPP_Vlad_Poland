#include <iostream>
#include <cmath>  // Для функцій sqrt та fabs
using namespace std;

// Структура для точки
struct SPunkt {
    double x;
    double y;
};

// Структура для прямої: y = ax + b
struct SProsta {
    double a; // Кутовий коефіцієнт
    double b; // Зсув
};

// Структура для кола: (x - a)^2 + (y - b)^2 = r^2
struct SOkrag {
    double a; // Центр кола (x)
    double b; // Центр кола (y)
    double r; // Радіус
};

// Структура для квадратного рівняння: ax^2 + bx + c = 0
struct SRownanie {
    double a;
    double b;
    double c;
};
//Пошук дискримінанту  - розвязок квадратного рівняння
int roz_row(const SRownanie& r, SPunkt& p1, SPunkt& p2);
//Обчислює точки перетину прямої та кола.
int pkt_przec(const SProsta& p, const SOkrag& o, SPunkt& p1, SPunkt& p2);

bool czy_prostopadle(const SProsta& p1, const SProsta& p2);

// Головна функція для тестування
int main() {
    SPunkt p1 = { 0, 0 }, p2 = { 0, 0 };
    SProsta prosta1 = { -1.0, 3.0 };
    SProsta prosta2 = { 1.0, -3.0 };
    SOkrag okrag = { 0.0, 1.0, 2.0 };

    int pier1 = pkt_przec(prosta1, okrag, p1, p2);
    if (pier1 == 2) {
        cout << "Peretyn Prymoi d tockkax: " << endl;
        cout << "(" << p1.x << ", " << p1.y << ")" << endl;
        cout << "(" << p2.x << ", " << p2.y << ")" << endl;
    }
    else if (pier1 == 1) {
        cout << "Пряма є дотичною до кола в точці: " << endl;
        cout << "(" << p1.x << ", " << p1.y << ")" << endl;
    }
    else if (pier1 == 0)
        cout << "Пряма не перетинає коло" << endl;
    else
        cout << "Немає розв'язків – це не квадратне рівняння";

    cout << "Чи є прямі перпендикулярними? " << boolalpha
        << czy_prostopadle(prosta1, prosta2) << endl;


    return 0;
}

// Функція для розв'язання квадратного рівняння
int roz_row(const SRownanie& r, SPunkt& p1, SPunkt& p2) {
    double D = r.b * r.b - 4 * r.a * r.c; // Дискримінант
    //abs - модуль цілого числа - fabs - модуль дробового числа

    if (r.a <= 0) { // Перевірка на нульовий коефіцієнт a
        return -1; // Це не квадратне рівняння
    }
    if (D > 0) { // Два розв'язки
        p1.x = (-r.b + sqrt(D)) / (2 * r.a);
        p2.x = (-r.b - sqrt(D)) / (2 * r.a);
        return 2;
    }
    else if (D < 0) { // Один розв'язок
        p1.x = -r.b / (2 * r.a);
        return 1;
    }
    return 0; // Немає розв'язків
}

// Функція для обчислення точок перетину прямої та кола
int pkt_przec(const SProsta& p, const SOkrag& o, SPunkt& p1, SPunkt& p2) {
    // Підставимо рівняння прямої y = ax + b у рівняння кола
    // маємо пряму -  SProsta& p, 
    // маємо коло - SOkrag& o
    // маємо точку - SPunkt& p2
    // 1+p.a^2
    double A = 1 + p.a * p.a;     //Шукаємо коефіцієнти A
    double B = 2 * (p.a * (p.b - o.b) - o.a); // B
    double C = o.a * o.a + (p.b - o.b) * (p.b - o.b) - o.r * o.r; //B

    SRownanie r = { A, B, C };
    //Пошук дискримінанту
    int roots = roz_row(r, p1, p2); //Тепер шукаємо дикримінант, тобто розвязки рівняння

    if (roots == 2) { // Два розв'язки - якщо дискримінант 2, то маємо 2розязки
        p1.y = p.a * p1.x + p.b;
        p2.y = p.a * p2.x + p.b;
    }
    else if (roots == 1) { // Один розв'язок (дотична)
        p1.y = p.a * p1.x + p.b;
    }
    return roots;
}
// Функція для перевірки, чи прямі перпендикулярні
bool czy_prostopadle(const SProsta& p1, const SProsta& p2) {
    return fabs(p1.a * p2.a + 1) < 1e-9; // Перевірка умови a1 * a2 = -1
}




/*
SPunkt p1 = { 0, 0 }, p2 = { 0, 0 };
SProsta prosta1 = { -1.0, 3.0 };
SProsta prosta2 = { 1.0, -3.0 };
SOkrag okrag = { 0.0, 1.0, 2.0 };

int pier1 = pkt_przec(prosta1, okrag, p1, p2);
if (pier1 == 2) {
    cout << "Пряма перетинає коло в точках: " << endl;
    cout << "(" << p1.x << ", " << p1.y << ")" << endl;
    cout << "(" << p2.x << ", " << p2.y << ")" << endl;
}
else if (pier1 == 1) {
    cout << "Пряма є дотичною до кола в точці: " << endl;
    cout << "(" << p1.x << ", " << p1.y << ")" << endl;
}
else if (pier1 == 0)
cout << "Пряма не перетинає коло" << endl;
else
cout << "Немає розв'язків – це не квадратне рівняння";

cout << "Чи є прямі перпендикулярними? " << boolalpha
<< czy_prostopadle(prosta1, prosta2) << endl;
*/