#include <iostream>
class D2 {
int w, h;
public:
D2() { w=h= 1; }
D2(int w, int h) { this->w=w; this->h=h; }
int getArea() { return w*h; }
};
class D3: public D2 {
    int l;
public:
    D3(int w, int h, int l): D2(w, h), l(l) { } 
    int getVolume() {
    return getArea() * l;
}
};



int main() {
D3 box(2, 3, 4);
std::cout << box.getVolume()<< std::endl;
return 0;
}