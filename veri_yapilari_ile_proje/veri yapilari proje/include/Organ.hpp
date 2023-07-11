#ifndef Organ_hpp
#define Organ_hpp
#include "ikiliagac.hpp"
    class Organ {
        public:
        Organ();
        ~Organ();
        void OrganaDokuEkle(Doku *eklenecekdoku);
        int DokuSayisi;
        Doku *ilkdoku;
        Organ *sonrakiorgan;
        void OrganYazdir();

        bool Yukseklik_far();


        Ikiliarama *agacaeklee=new Ikiliarama();
        bool Yukseklik_far_mutasyon();

        Ikiliarama *mutasyonlu_Agaclar=new Ikiliarama();

       Organ *ilkorgan;
    };

#endif