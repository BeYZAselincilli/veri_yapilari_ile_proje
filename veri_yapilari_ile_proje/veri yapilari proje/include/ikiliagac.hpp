#ifndef ikiliagac_hpp
#define ikiliagac_hpp
#include "Dugumikili.hpp"



class Ikiliarama{
    public:
    Ikiliarama();
    ~Ikiliarama();
    bool varmi(int veri);
    bool varmi(int aranan, Dugumikili *kok);
    void ekle(Hucre *eklenecekdugum, Dugumikili *aktifDugum);
    void ekle(Hucre *eklenecekdugum) ;
    Dugumikili *aktifDugum;
    Hucre *dugum;
    Dugumikili *kok;
    int yukseklikbulma(Dugumikili *aktifDugum);
    void Postorderdizisi_Ekle(Dugumikili *kok, int veri);
    };

#endif
