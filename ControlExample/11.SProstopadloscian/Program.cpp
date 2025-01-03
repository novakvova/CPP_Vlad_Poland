#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ��������� ��� ������������� �������������
struct SProstopadloscian {
    double length;   // ������� ������
    double width;    // ������ ������
    double height;   // ������
};

// ������� ��� ���������� ����� �� �����
SProstopadloscian* wczytaj(const char* plick_wej, int& n) {
    ifstream file(plick_wej);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����: " << plick_wej << endl;
        return nullptr;
    }

    // ϳ�������� ������� ������
    n = 0;
    double length, width, height;
    while (file >> length >> width >> height) {
        n++;
    }

    // ����������� �� ������� �����
    file.clear();
    file.seekg(0);

    // ��������� ���������� ������
    SProstopadloscian* parallelepipeds = new SProstopadloscian[n];
    for (int i = 0; i < n; i++) {
        file >> parallelepipeds[i].length >> parallelepipeds[i].width >> parallelepipeds[i].height;
    }

    file.close();
    return parallelepipeds;
}

// ������� ��� ���������� ����� �������
double pole(const SProstopadloscian& p) {
    return 2 * (p.length * p.width + p.length * p.height + p.width * p.height);
}

// ������� ��� ����������� ������� ������������� � ��������� ������
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

// ������� ��� ���������� ��'���
double objetosc(const SProstopadloscian& p) {
    return p.length * p.width * p.height;
}

// ������� ��� ����������� ���������� ��'���
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

// ������� ���������� �� �������
bool wysokosc(const SProstopadloscian& p1, const SProstopadloscian& p2) {
    return p1.height < p2.height;
}

// ������� ��� ���������� ������ �������������
void sortuj(SProstopadloscian* p, int n) {
    sort(p, p + n, [](const SProstopadloscian& a, const SProstopadloscian& b) {
        return a.height < b.height;
        });
}

// ������� ��� ������ ���������� ��� ������������
void wypisz(const SProstopadloscian& p) {
    cout << "�������: " << p.length
        << ", ������: " << p.width
        << ", ������: " << p.height << endl;
}

// ������� ��� ������ ��� �������������
void wypisz(const SProstopadloscian* p, int n) {
    for (int i = 0; i < n; i++) {
        wypisz(p[i]);
    }
}

// ������� ��� ������ ����� �� �����
bool wypisz(const SProstopadloscian* p, int n, const string& filename) {
    ofstream file(filename, ios::app); // ³������� � ����� �����������
    if (!file.is_open()) return false;

    for (int i = 0; i < n; i++) {
        file << p[i].length << "\t" << p[i].width << "\t" << p[i].height << endl;
    }
    file.close();
    return true;
}

// ������� �������
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "������ ������� �� �������� ����� �� ��������� ���������� �����!" << endl;
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
            cout << "��� ������ �������� � ����." << endl;
        }
        else {
            cerr << "������� ������ �� �����!" << endl;
        }

        int maxPoleIndex = znajdz_pole(parallelepipeds, n);
        cout << "������������ � ��������� ������ ������� ����������� �� �������: "
            << maxPoleIndex << endl;

        int maxVolumeIndex = znajdz_objetosc(parallelepipeds, n);
        cout << "��������� ��'�� �������������: "
            << objetosc(parallelepipeds[maxVolumeIndex]) << endl;

        sortuj(parallelepipeds, n);
        wypisz(parallelepipeds, n);

        if (wypisz(parallelepipeds, n, argv[2])) {
            cout << "��� ������ �������� � ���� ���� ����������." << endl;
        }
        else {
            cerr << "������� ������ �� �����!" << endl;
        }

        delete[] parallelepipeds; // ��������� ���'���
    }
    else {
        cerr << "�� ������� ������� ��� � �����!" << endl;
    }

    return 0;
}