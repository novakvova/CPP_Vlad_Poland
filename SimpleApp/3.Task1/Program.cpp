#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SObiektyw {
    string nazwa;  //Назва
    double przeslona; //кількість_об’єктивів
    int ogniskowa; //тип обєкта
};


struct SAparat {
    string nazwa; //Назва
    SObiektyw* obiektywy; //список обєктів
    int n; //кількість об'єктів
};

void usun(SAparat& aparat) {
    delete[] aparat.obiektywy;
    aparat.obiektywy = nullptr;
    aparat.n = 0;
}

void clearStream(ifstream& stream) {
    stream.ignore();
    stream.clear();
    stream.close();
}

bool wczytaj(const char* nazwaPlilku, SAparat& aparat) {
    ifstream plik(nazwaPlilku);
    if (!plik.is_open()) {
        cerr << "Blad przy otworzeniu pliku wejsciowego:";
        clearStream(plik);
        return false;
    }

    if (!(plik >> aparat.nazwa)) {
        cerr << "Blad przy zapisywaniu aparat.nazwa";
        clearStream(plik);
        aparat.nazwa = "";
        return false;
    }

    if (!(plik >> aparat.n)) {
        cerr << "Blad przy zapisywaniu aparat.n";
        clearStream(plik);
        aparat.n = 0;
        return false;
    }
    if (aparat.n <= 0) {
        cerr << "n musze byc wieksze" << endl;
        aparat.n = 0;
        return false;
    }

    aparat.obiektywy = new SObiektyw[aparat.n];

    for (int i = 0; i < aparat.n; i++) {
        if (!(plik >> aparat.obiektywy[i].nazwa)) {
            cerr << "Blad przy zapisywaniu nazwy obiektywu" << i;
            clearStream(plik);
            usun(aparat);
            return false;
        }

        if (!(plik >> aparat.obiektywy[i].przeslona)) {
            cerr << "Blad przy zapisywaniu przeslony obiektywu" << i;
            clearStream(plik);
            usun(aparat);
            return false;
        }

        if (!(plik >> aparat.obiektywy[i].ogniskowa)) {
            cerr << "Blad przy zapisywaniu ogniskowy obiektywu" << i;
            clearStream(plik);
            usun(aparat);
            return false;
        }

    }
    plik.close();
    return true;
}

void wypisz(ofstream& plik, SAparat& aparat) {
    if (!(plik << aparat.nazwa << endl)) {
        cerr << "Blad przy zapisywaniu nazwy aparatu";
        plik.clear();
        plik.close();
        exit(EXIT_FAILURE);
    }

    if (!(plik << aparat.n << endl)) {
        cerr << "Blad przy zapisywaniu n obiektywow aparatu";
        plik.clear();
        plik.close();
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < aparat.n; i++) {
        if (!(plik << aparat.obiektywy[i].nazwa << " ")) {
            cerr << "Blad przy zapisywaniu nazwy obiektywu" << i;
            plik.clear();
            plik.close();
            usun(aparat);
            exit(EXIT_FAILURE);
        }

        if (!(plik << aparat.obiektywy[i].przeslona << " ")) {
            cerr << "Blad przy zapisywaniu przeslony obiektywu" << i;
            plik.clear();
            plik.close();
            usun(aparat);
            exit(EXIT_FAILURE);
        }

        if (!(plik << aparat.obiektywy[i].ogniskowa << " " << endl)) {
            cerr << "Blad przy zapisywaniu ogniskowy obiektywu" << i;
            plik.clear();
            plik.close();
            usun(aparat);
            exit(EXIT_FAILURE);
        }

    }
}

void wypisz(ostream& plik, SAparat& aparat) {
    cout << aparat.nazwa << endl;
    cout << aparat.n << endl;
    for (int i = 0; i < aparat.n; i++) {
        cout << aparat.obiektywy[i].nazwa << " " << aparat.obiektywy[i].przeslona << " " << aparat.obiektywy[i].ogniskowa << endl;
    }
}


int zlicz(const SAparat& aparat) {
    int ile = 0;
    for (int i = 0; i < aparat.n; i++) {
        if (aparat.obiektywy[i].ogniskowa > 50) {
            ile++;
        }
    }
    return ile;
}




int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Musze byc 3 argumenty:";
        cerr << "/.nazwa in.txt out.txt";
        return -1;
    }

    SAparat aparat;
    if (wczytaj(argv[1], aparat)) {
        wypisz(cout, aparat);
        cout << zlicz(aparat) << endl;
        ofstream plik(argv[2]);
        if (!plik) {
            cerr << "Zapis zakonczony bledem";

        }
        else {
            wypisz(plik, aparat);
            usun(aparat);
            plik.close();
        }
    }
    return 0;
}
