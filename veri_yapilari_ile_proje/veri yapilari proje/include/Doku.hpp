#include "Hucre.hpp"
#ifndef Doku_hpp
#define Doku_hpp

#include <iostream>
class Doku{
    public:
    Doku *sonrakidoku;
    Hucre* ilk_hucre;
    int Hucre_Sayisi;
    int ortaelemanindisi;
    Doku();
    ~Doku();
    void HucreEkle(int veri);
    void HucreCikar();
    void HucreYazdir();
    Hucre* Listebasi();
    int HucreBosMu();
    int HucreSil();
   Hucre *ortadokuadresi;
  
};


#endif