#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct SStudent {
    string imie;
    string nazwisko;
    int numer_indeksu;
    int grupe_dziek;
    int grupe_lab;
    int liczba_niezal;
    string* wykaz_niezal;
};

struct SLista {
    string nazwa_listy;      //Назва групи SDP_211
    int liczba_studentow;    //Кількість студентів у групі
    SStudent* studenty;      //Список усіх студентіву групі
};

void usun(SLista& lista) {
    if (lista.studenty) {
        for (int i = 0; i < lista.liczba_studentow; i++) {
            if (lista.studenty[i].wykaz_niezal) {
                delete[] lista.studenty[i].wykaz_niezal;
                lista.studenty[i].wykaz_niezal = nullptr;
            }
        }
        delete[] lista.studenty;
        lista.studenty = nullptr;
    }
}

//istream - це базовий клас для потоків - тобто у фунцію можна пердавати як cin так і ifstream reader;


SLista wczytaj(istream& plik_wej, SLista& lista) {
    if (!(plik_wej >> lista.nazwa_listy)) {
        cerr << "Blad przy zapisywaniu nazwy listy!" << endl;
        plik_wej.clear();  //Для того, щоб можна було коректно завершити роботу з файлом і очистити зяднання.
        lista.nazwa_listy = "";
        lista.liczba_studentow = 0;
        lista.studenty = nullptr;
        return lista;
    }

    if (!(plik_wej >> lista.liczba_studentow)) {
        cerr << "Blad przy zapisywaniu liczby studentow!" << endl;
        plik_wej.clear();
        lista.nazwa_listy = ""; //видаляємо назву групи, що було прочитана вище
        lista.liczba_studentow = 0;
        lista.studenty = nullptr;
        return lista;
    }
    
    lista.studenty = new SStudent[lista.liczba_studentow];


    for (int i = 0; i < lista.liczba_studentow; i++) {
        if (!(plik_wej >> lista.studenty[i].imie)) {
            cerr << "Blad przy zapisywaniu imienia studenta N " << i + 1 << endl;
            plik_wej.clear();
            usun(lista);
            return lista;
        }
        /*
        if (!(plik_wej >> lista.studenty[i].nazwisko)) {
            cerr << "Blad przy zapisywaniu nazwiska studenta N " << i + 1 << endl;
            plik_wej.clear();
            usun(lista);
            return lista;
        }

        if (!(plik_wej >> lista.studenty[i].numer_indeksu)) {
            cerr << "Blad przy zapisywaniu numera indeksu studenta N " << i + 1 << endl;
            plik_wej.clear();
            usun(lista);
            return lista;
        }

        if (!(plik_wej >> lista.studenty[i].grupe_dziek)) {
            cerr << "Blad przy zapisywaniu grupy dziekanska studenta N " << i + 1 << endl;
            plik_wej.clear();
            usun(lista);
            return lista;
        }

        if (!(plik_wej >> lista.studenty[i].grupe_lab)) {
            cerr << "Blad przy zapisywaniu grupy laboratornej studenta N " << i + 1 << endl;
            plik_wej.clear();
            usun(lista);
            return lista;
        }

        if (!(plik_wej >> lista.studenty[i].liczba_niezal)) {
            cerr << "Blad przy zapisywaniu liczby niezaliczonych przedmiotow studenta N " << i + 1 << endl;
            plik_wej.clear();
            usun(lista);
            return lista;
        }
        lista.studenty[i].wykaz_niezal = new string[lista.studenty[i].liczba_niezal];
        if (lista.studenty[i].liczba_niezal != 0) {
            for (int j = 0; j < lista.studenty[i].liczba_niezal; j++) {
                if (!(plik_wej >> lista.studenty[i].wykaz_niezal[j])) {
                    cerr << "Blad przy zapisywaniu niezaliczonego przedmiota numer " << i << endl;
                    plik_wej.clear();
                    usun(lista);
                    return lista;
                }
            }
        }
        */
    }
    return lista;
}

void wypisz(ostream& dzhul, const SStudent& lista) {
    dzhul << "\nImie: " << lista.imie << "\nNazwisko: " << lista.nazwisko << "\nNumer indeksu: " << lista.numer_indeksu << "\nGrupa dziekanska: " << lista.grupe_dziek << "\nGrupa laboratorna: " << lista.grupe_lab;

    if (lista.liczba_niezal == 0) {
        dzhul << "\nWszystkie przedmioty sa zaliczone!" << endl;
    }
    else {
        dzhul << "\nLiczba niezaliczonych przedmiotow: " << lista.liczba_niezal << endl;
        for (int i = 0; i < lista.liczba_niezal; i++) {
            dzhul << lista.wykaz_niezal[i] << " ";
        }
        cout << endl;
    }

}

void wypisz(ostream& dzhul, const SLista& lista) {
    for (int i = 0; i < lista.liczba_studentow; i++) {
        dzhul << "\n\nStudent N" << i + 1 << ":";
        wypisz(dzhul, lista.studenty[i]);
    }
}


void filtr(ostream& plik_out, const SLista& lista) {
    for (int i = 0; i < lista.liczba_studentow; i++) {
        bool znaleziono = false;
        for (int j = 0; j < lista.studenty[i].liczba_niezal; j++) {
            if (lista.studenty[i].wykaz_niezal[j] == "Podstawy_Programowania") {
                znaleziono = true;
                break;
            }
        }
        if (!znaleziono) {
            wypisz(plik_out, lista.studenty[i]);
        }
    }
}

double srednia(SLista& lista) {
    double avg = 0;
    for (int i = 0; i < lista.liczba_studentow; i++) {
        avg += lista.studenty[i].liczba_niezal;
    }
    return avg / lista.liczba_studentow;
}

void wyszukaj(ostream& dzhul, const SLista& lista) {
    int max = lista.studenty[0].liczba_niezal;
    int indeks;
    for (int i = 1; i < lista.liczba_studentow; i++) {
        if (max < lista.studenty[i].liczba_niezal) {
            max = lista.studenty[i].liczba_niezal;
            indeks = i;
        }
    }
    cout << "\n\nStudent z najwieksza liczba niezaliczonych przedmiotow: " << endl;
    wypisz(dzhul, lista.studenty[indeks]);
}

bool wg_nazwiska(const SStudent& a, const SStudent& b) {
    return a.nazwisko < b.nazwisko;
}

bool wg_imienia(const SStudent& a, const SStudent& b) {
    return a.imie < b.imie;
}

bool wg_indeksu(const SStudent& a, const SStudent& b) {
    return a.numer_indeksu < b.numer_indeksu;
}

bool wg_grupyL(const SStudent& a, const SStudent& b) {
    return a.grupe_dziek < b.grupe_dziek;
}

bool wg_grupyDz(const SStudent& a, const SStudent& b) {
    return a.grupe_lab < b.grupe_lab;
}

bool wg_liczbyK(const SStudent& a, const SStudent& b) {
    return a.liczba_niezal < b.liczba_niezal;
}

void sortuj(SLista& lista, bool (*kryterium)(const SStudent&, const SStudent&)) {
    sort(lista.studenty, lista.studenty + lista.liczba_studentow, kryterium);
}


int main(int argc, char* argv[])
{
    if (argc != 3) {
        cerr << "Musze byc 3 parametry!" << endl;
        cerr << "./nazwa in.txt out.txt" << endl;
        return -1;
    }
    //Це значить із файлу ми маємо отримати інформаці в змінні, для цього використовуємо 
    // назва_потоку >> назва_змінно
    //змінна може бути будь-яка - рядок, або число

    ifstream plik_in(argv[1]);   //якщо ми на початку ifstream - це значить читання файлу
    if (!plik_in.good()) { //перевіряємо чи існує взагалі файл
        cerr << "Blad przy otwarciu pliku wejsciowego w maine!" << endl;
        plik_in.clear(); //обиває зядання з файлом, тобто, що файл не буде занятий даною прогамою.
        plik_in.close(); //Закриває зяднання з файлом
        return -1;
    }
    //Відкриває зяднання з файлом для запису даного файлу
    //Якщо файл відкритий для запису під час роботи програми він буде заблований,
    //туди інша програма не повинна запсувати дані, бо буде до жорстка посилка
    //Якщо ми записуємо у файл, то у нас запису буде такий
    //// назва_потоку << назва_змінно;
    //Ця схеме працює так само, як cout<<назва_змінної; - різниця лиш у тому, що ми запис ведемо на екран ПК.

    ofstream plik_out(argv[2]); //Якщо ofstream - це значить записування файлу. 
    if (!plik_out.good()) {  //Перевіряє чи існує файл, сам його створює, як є можливість.
        cerr << "Blad przy otwarciu pliku wyjsciowego w maine!" << endl;
        plik_out.clear();
        plik_out.close();
        return -1;
    }
    
    SLista lista = { "", 0, nullptr };
    //Прочитам дані із файлу argv[1] у змінну lista - типу SLista
    //lista = wczytaj(cin, lista);
    lista = wczytaj(plik_in, lista); //Фукнція читання із файлу
    cout << "Name group " << lista.nazwa_listy << "\n";
    cout << "Count group student " << lista.liczba_studentow << "\n";
    //wypisz(cout, lista);
    /*
    filtr(plik_out, lista);

    cout << "\nSrednia: " << srednia(lista) << endl;

    wyszukaj(cout, lista);

    cout << "\nPosortowane: " << endl;
    sortuj(lista, wg_nazwiska);
    wypisz(cout, lista);

    usun(lista);

    plik_out.close();
    plik_in.close();*/
    return 0;
}
