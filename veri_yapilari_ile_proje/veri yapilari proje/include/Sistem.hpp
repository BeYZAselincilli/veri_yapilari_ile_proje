#ifndef Sistem_hpp
#define Sistem_hpp
#include "Organ.hpp"

class Sistem{
    public:
    Sistem();
    ~Sistem();
    int SistemSayisi;
    Sistem *sonrakisistem;
    Organ *ilkorgan;
    void SistemeOrganEkle(Organ *eklenecekorgan);
    void SistemYazdir();
    void MutasyonluSistemYazdir();
    int OrganSayisi;
};


#endif