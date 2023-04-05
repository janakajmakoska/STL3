#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Mnozestvo {
private:
    T niza[100];
    static int brojElementi;
public:
    Mnozestvo() {}
    void dodadi(T x) {
        bool flag = true;
        for(int i=0; i<brojElementi; i++) {
            if(niza[i] == x) {
                flag = false;
                break;
            }
        }
        if(flag) {
            niza[brojElementi] = x;
            brojElementi++;
        } else {
            cout << "Elementot vekje postoi vo mnozestvoto." << endl;
        }
    }
    void prikazi() {
        for(int i=0; i<brojElementi; i++) {
            cout << niza[i] << " ";
        }
        cout << endl;
    }
    T najgolem() {
        T maxEl = niza[0];
        for(int i=1; i<brojElementi; i++) {
            if(niza[i] > maxEl) {
                maxEl = niza[i];
            }
        }
        return maxEl;
    }
    static int getBrojElementi() {
        return brojElementi;
    }
};

template <typename T>
int Mnozestvo<T>::brojElementi = 0;

template <>
char* Mnozestvo<char*>::najgolem() {
    char* maxEl = niza[0];
    for(int i=1; i<Mnozestvo<char*>::getBrojElementi(); i++) {
        if(strcmp(niza[i], maxEl) > 0) {
            maxEl = niza[i];
        }
    }
    return maxEl;
}

int main() {
    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<char*> C;
    int izbor;
    do {
        cout << "Izberi opcija: " << endl;
        cout << "1. Dodadi element vo A" << endl;
        cout << "2. Dodadi element vo B" << endl;
        cout << "3. Dodadi element vo C" << endl;
        cout << "4. Prikazi go A" << endl;
        cout << "5. Prikazi go B" << endl;
        cout << "6. Prikazi go C" << endl;
        cout << "7. Prikazi najgolem element" << endl;
        cout << "8. Prikazi broj na elementi vo mnozestvata" << endl;
        cout << "9. Kraj" << endl;
        cin >> izbor;
        switch (izbor) {
            case 1:
                int elA;
                cout << "Vnesi element: ";
                cin >> elA;
                A.dodadi(elA);
                break;
            case 2:
                double elB;
                cout << "Vnesi element: ";
                cin >> elB;
                B.dodadi(elB);
                break;
            case 3:
                char elC[50];
                cout << "Vnesi element: ";
                cin >> elC;
                C.dodadi(elC);
                break;
            case 4:
                A.prikazi();
                break;
            case 5:
                B.prikazi();
                break;
            case 6:
                C.prikazi();
                break;
            case 7:
                A.najgolem();
                B.najgolem();
                C.najgolem();
                break;
            case 8:
                A.getBrojElementi();
                B.getBrojElementi();
                C.getBrojElementi();
                break;
            case 9:
                break;
}
}
while (izbor !=9);
return 0;
}