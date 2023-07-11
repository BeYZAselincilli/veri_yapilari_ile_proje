#ifndef Organizma_hpp
#define Organizma_hpp
#include "Sistem.hpp"
#include<iostream>
class Organizma{
    public:
    Organizma();
   ~Organizma();
   void OrganizmayaSistemEkle(Sistem *ekleneceksistem);
   void OrganizmaYazdir();
   int OrganizmaSayisi;
   Organizma* sonrakiorganizma;
   Sistem *ilksistem;
   int SistemSayisi;
   void PostOrder_DiziAtama(Dugumikili *kok, int *arr, int &i);
   void Hucre_Mutasyonu();
   void MutasyonluOrganizmaYazdir();
};
#endif 