#include <iostream>

template<typename T>
class Zapis {
private:
    T x, y, z;
public:
    Zapis(T x, T y, T z) : x(x), y(y), z(z) {}
    
    template<typename U>
    friend bool kontrolor(const Zapis<U>& zapis);
};

template<typename U>
bool kontrolor(const Zapis<U>& zapis) {
    return (zapis.x + zapis.y + zapis.z) > 10000;
}

int main() {
    Zapis<int> z1(500, 300, 200);
    Zapis<double> z2(3000.5, 56800.7, 5000.8);
    
    std::cout << "Zapis 1: " << (kontrolor(z1) ? "Nadminuva" : "Ne nadminuva") << " 10000\n";
    std::cout << "Zapis 2: " << (kontrolor(z2) ? "Nadminuva" : "Ne nadminuva") << " 10000\n";
    
    return 0;
}
