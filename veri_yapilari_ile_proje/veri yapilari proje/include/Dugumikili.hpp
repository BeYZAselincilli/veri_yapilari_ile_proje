#ifndef Dugumikili_hpp
#define Dugumikili_hpp
#include "Kuyruk.hpp"

class Dugumikili{
    public:
    Dugumikili(Hucre *dugum);
    ~Dugumikili();
    int veri;
    Dugumikili *soldugum;
    Dugumikili *sagdugum;
};
#endif
