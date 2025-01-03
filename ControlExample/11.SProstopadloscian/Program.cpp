#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Структура для представлення паралелепіпеда
struct SProstopadloscian {
    double length;   // Довжина основи
    double width;    // Ширина основи
    double height;   // Висота
};

// Функція для зчитування даних із файлу
SProstopadloscian* wczytaj(const char* plick_wej, int& n) {
    ifstream file(plick_wej);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл: " << plick_wej << endl;
        return nullptr;
    }

    // Підрахунок кількості записів
    n = 0;
    double length, width, height;
    while (file >> length >> width >> height) {
        n++;
    }

    // Повертаємося на початок файлу
    file.clear();
    file.seekg(0);

    // Створення динамічного масиву
    SProstopadloscian* parallelepipeds = new SProstopadloscian[n];
    for (int i = 0; i < n; i++) {
        file >> parallelepipeds[i].length >> parallelepipeds[i].width >> parallelepipeds[i].height;
    }

    file.close();
    return parallelepipeds;
}

// Функція для обчислення площі поверхні
double pole(const SProstopadloscian& p) {
    return 2 * (p.length * p.width + p.length * p.height + p.width * p.height);
}

// Функція для знаходження індекса паралелепіпеда з найбільшою площею
int znajdz_pole(const SProstopadloscian* p, int n) {
    int maxIndex = 0;
    double maxPole = pole(p[0]);
    for (int i = 1; i < n; i++) {
        double currentPole = pole(p[i]);
        if (currentPole > maxPole) {
            maxPole = currentPole;
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функція для обчислення об'єму
double objetosc(const SProstopadloscian& p) {
    return p.length * p.width * p.height;
}

// Функція для знаходження найбільшого об'єму
int znajdz_objetosc(const SProstopadloscian* p, int n) {
    int maxIndex = 0;
    double maxVolume = objetosc(p[0]);
    for (int i = 1; i < n; i++) {
        double currentVolume = objetosc(p[i]);
        if (currentVolume > maxVolume) {
            maxVolume = currentVolume;
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Критерій сортування за висотою
bool wysokosc(const SProstopadloscian& p1, const SProstopadloscian& p2) {
    return p1.height < p2.height;
}

// Функція для сортування масиву паралелепіпедів
void sortuj(SProstopadloscian* p, int n) {
    sort(p, p + n, [](const SProstopadloscian& a, const SProstopadloscian& b) {
        return a.height < b.height;
        });
}

// Функція для виводу інформації про паралелепіпед
void wypisz(const SProstopadloscian& p) {
    cout << "Довжина: " << p.length
        << ", Ширина: " << p.width
        << ", Висота: " << p.height << endl;
}

// Функція для виводу всіх паралелепіпедів
void wypisz(const SProstopadloscian* p, int n) {
    for (int i = 0; i < n; i++) {
        wypisz(p[i]);
    }
}

// Функція для запису даних до файлу
bool wypisz(const SProstopadloscian* p, int n, const string& filename) {
    ofstream file(filename, ios::app); // Відкриття у режимі дописування
    if (!file.is_open()) return false;

    for (int i = 0; i < n; i++) {
        file << p[i].length << "\t" << p[i].width << "\t" << p[i].height << endl;
    }
    file.close();
    return true;
}

// Головна функція
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Вкажіть вхідний та вихідний файли як аргументи командного рядка!" << endl;
        return 1;
    }

    int n = 0;
    SProstopadloscian* parallelepipeds = wczytaj(argv[1], n);

    cout << "Count paralelepiped " << n << endl;

    cout << parallelepipeds[0].length << " "<< parallelepipeds[0].width<<" "<<parallelepipeds[0].height << endl;
    cout << parallelepipeds[1].length << " " << parallelepipeds[1].width << " " << parallelepipeds[1].height << endl;;
    if (parallelepipeds) {
        wypisz(parallelepipeds, n);

        if (wypisz(parallelepipeds, n, argv[2])) {
            cout << "Дані успішно записано у файл." << endl;
        }
        else {
            cerr << "Помилка запису до файлу!" << endl;
        }

        int maxPoleIndex = znajdz_pole(parallelepipeds, n);
        cout << "Паралелепіпед з найбільшою площею поверхні знаходиться на позиції: "
            << maxPoleIndex << endl;

        int maxVolumeIndex = znajdz_objetosc(parallelepipeds, n);
        cout << "Найбільший об'єм паралелепіпеда: "
            << objetosc(parallelepipeds[maxVolumeIndex]) << endl;

        sortuj(parallelepipeds, n);
        wypisz(parallelepipeds, n);

        if (wypisz(parallelepipeds, n, argv[2])) {
            cout << "Дані успішно записано у файл після сортування." << endl;
        }
        else {
            cerr << "Помилка запису до файлу!" << endl;
        }

        delete[] parallelepipeds; // Звільняємо пам'ять
    }
    else {
        cerr << "Не вдалося зчитати дані з файлу!" << endl;
    }

    return 0;
}