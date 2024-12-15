#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string nazwa, model;
int rok;
char skrzynia;
float pojemnosc;
int moc;

struct sAuto {
    string nazwa;
    string model;
    int rok;
    char skrzynia;
    float pojemnosc;
    int moc;
};

sAuto inicjuj(const string& nazwa, const string& model, const int rok, const char skrzynia, const float pojemnosc, const int moc) {
    return { nazwa, model, rok, skrzynia, pojemnosc, moc };
}

void inicjuj1(sAuto& Auto, const string& nazwa, const string& model, const int rok, const char skrzynia, const float pojemnosc, const int moc) {
    Auto.nazwa = nazwa;
    Auto.model = model;
    Auto.rok = rok;
    Auto.skrzynia = skrzynia;
    Auto.pojemnosc = pojemnosc;
    Auto.moc = moc;
}

void inicjuj(sAuto* Auto, const string& nazwa, const string& model, const int rok, const char skrzynia, const float pojemnosc, const int moc) {
    Auto->nazwa = nazwa;
    Auto->model = model;
    Auto->rok = rok;
    Auto->skrzynia = skrzynia;
    Auto->pojemnosc = pojemnosc;
    Auto->moc = moc;
}

sAuto wczytaj(sAuto(*wfun)(const string&, const string&, const int, const char, const float, const int)) {

    //cout << "Podaj nazwe: ";
    //cin >> nazwa;

    //cout << "Podaj model: ";
    //cin >> model;

    ////cout << "Podaj rok: ";
    ////cin >> rok;

    //while (true) { // Нескінченний цикл, доки не отримаємо правильне число
    //    cout << "Podaj rok: ";
    //    cin >> rok;

    //    // Перевірка, чи введено число
    //    if (cin.fail()) {
    //        cin.clear(); // Скидаємо стан помилки потоку
    //        cin.ignore(1000, '\n'); // Очищаємо буфер вводу до нового рядка
    //        cout << "Blad! Prosze podac liczbe calkowita.\n";
    //    }
    //    else {
    //        if (rok < 1769 || rok > 2024)
    //        {
    //            cout << "rok < 1769 || rok > 2024. Try again\n";
    //            continue;
    //        }
    //        break; // Якщо ввід правильний, виходимо з циклу
    //    }
    //}

    //while (true) {
    //    cout << "Podaj skrzynie (A, a, M, m): ";
    //    cin >> skrzynia;
    //    if (skrzynia == 'A' || skrzynia == 'a' || skrzynia == 'M' || skrzynia == 'm')
    //        break;
    //}

    //cout << "Podaj pojemnosc: ";
    //cin >> pojemnosc;

    //cout << "Podaj moc: ";
    //cin >> moc;

    return wfun(nazwa, model, rok, skrzynia, pojemnosc, moc);
}

void wczytaj1(sAuto& Auto, void (*wfun)(sAuto&, const string&, const string&, const int, const char, const float, const int)) {


    //cout << "Podaj nazwe: ";
    //cin >> nazwa;

    //cout << "Podaj model: ";
    //cin >> model;

    //cout << "Podaj rok: ";
    //cin >> rok;

    //cout << "Podaj skrzynie: ";
    //cin >> skrzynia;

    //cout << "Podaj pojemnosc: ";
    //cin >> pojemnosc;

    //cout << "Podaj moc: ";
    //cin >> moc;

    wfun(Auto, nazwa, model, rok, skrzynia, pojemnosc, moc);
}

void wczytaj(sAuto* Auto, void (*wfun)(sAuto*, const string&, const string&, const int, const char, const float, const int)) {

    //cout << "Podaj nazwe: ";
    //cin >> nazwa;

    //cout << "Podaj model: ";
    //cin >> model;

    //cout << "Podaj rok: ";
    //cin >> rok;

    //cout << "Podaj skrzynie: ";
    //cin >> skrzynia;

    //cout << "Podaj pojemnosc: ";
    //cin >> pojemnosc;

    //cout << "Podaj moc: ";
    //cin >> moc;

    wfun(Auto, nazwa, model, rok, skrzynia, pojemnosc, moc);
}

void wypisz(const sAuto& Auto) {
    cout << "Nazwa: " << Auto.nazwa << " Model: " << Auto.model << " Rok: " << Auto.rok << " Skrzynia: " << Auto.skrzynia << " Pojemnosc: " << Auto.pojemnosc << " Moc: " << Auto.moc << endl;
}

void wypisz(const sAuto* Auto) {
    cout << "Nazwa: " << Auto->nazwa << " Model: " << Auto->model << " Rok: " << Auto->rok << " Skrzynia: " << Auto->skrzynia << " Pojemnosc: " << Auto->pojemnosc << " Moc: " << Auto->moc << endl;
}

void selector(const sAuto& Auto) {
    int current_year = 2024;
    if (current_year - Auto.rok <= 5) {
        wypisz(Auto);
    }
    else {
        cout << "Samochod ma wiecej niz 5 lat" << endl;
    }
}

int main() {

    // Перевірка кількості аргументів
    if (argc != 7) {
        cout << "Blad! Podaj dane samochodu w nastepujacy sposob:" << endl;
        cout << "Program marka model rok skrzynia pojemnosc moc" << endl;
        return 1;
    }

    cout << "****Lista inicjalizacyjna: *****" << endl;
    sAuto sam1 = { nazwa, model, rok, skrzynia, pojemnosc, moc };
    wypisz(sam1);

    cout << "****Lista zmienna: *****" << endl;
    //під набір змінних, викликаємо - wczytaj - вводимо усі поля і після цього викликаємо inicjuj - де повертаємо об'єкт, який ввели з клавіатури.
    sAuto sam2 = wczytaj(inicjuj);
    wypisz(sam2); //Виводимо усю інформацію
    selector(sam2); //Перевірка чи є 5 років, якщо старше 5 - то виводимо лише текст і попередженням

    cout << "****Lista referencyjna: *****" << endl;
    sAuto sam3;  // створили змінну
    sAuto& z_sam = sam3; // змінна z_sam - посилається - на sam3
    wczytaj1(z_sam, inicjuj1); //Вводимо z_sam через вказівник на метод
    wypisz(z_sam); //виводимо
    selector(sam3); //перевріяємо вік машини

    cout << "****Lista wskaznikowa: *****" << endl;
    sAuto sam4;
    sAuto* w_sam = &sam4; // Вказівник на адресу памятті
    wczytaj(w_sam, inicjuj); //Вводимо дані
    wypisz(w_sam); //виводимо інформацію
    selector(sam4); //Перевіряємо чи вірно вказував вказівник. Інформація про роки авто

    return 0;
}