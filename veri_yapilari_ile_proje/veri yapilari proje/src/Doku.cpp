#include<Doku.hpp>
#include <iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;

Doku::Doku(){
    ilk_hucre=0;
    sonrakidoku=0;
    Hucre_Sayisi=0;
    ortaelemanindisi;
    int DokuSayisi=0;
    ortadokuadresi=0;
}

Doku::~Doku(){
    Hucre *gecicihucre=ilk_hucre;
    
    while(gecicihucre!=0){
        
        Hucre *silinecekhucre=gecicihucre;
        gecicihucre=gecicihucre->sonrakihucre;
        delete silinecekhucre;
        silinecekhucre=0;
    }
}
void Doku::HucreEkle(int veri){
     Hucre *yenihucre=new Hucre(veri);
    if(ilk_hucre!=0){
    Hucre *gecicihucre=ilk_hucre;
     while(gecicihucre->sonrakihucre!=0){
        gecicihucre=gecicihucre->sonrakihucre;
     }
     gecicihucre->sonrakihucre=yenihucre;
        Hucre_Sayisi++;  
  
    }
    else if(ilk_hucre==0){
        ilk_hucre=yenihucre;
   
        Hucre_Sayisi++;
    }
}

void Doku::HucreYazdir(){
    Hucre *gecicihucre=ilk_hucre;
    while(gecicihucre!=0){
          cout<<gecicihucre->veri<<"  ";
         
        gecicihucre=gecicihucre->sonrakihucre;

    }
  
}

void Doku::HucreCikar(){
    if(ilk_hucre!=0){
     Hucre *gecicihucre=ilk_hucre;
    while (gecicihucre->sonrakihucre->sonrakihucre!=0){
        gecicihucre=gecicihucre->sonrakihucre;
    }
    delete gecicihucre->sonrakihucre;
    gecicihucre->sonrakihucre=0;
    }

    else if(ilk_hucre->sonrakihucre==0)
    {
        delete ilk_hucre;
        ilk_hucre=0;
    }

    else if(ilk_hucre==0){
        cout<<"hucre elemani yok!!";
    }

}

    Hucre* Doku::Listebasi(){
        return ilk_hucre;
    }

    int Doku::HucreBosMu(){
        if (ilk_hucre==0){
            return 1;
        }
        else 
        return 0;
    }

    int Doku::HucreSil(){
        Hucre *gecicihucre=ilk_hucre;
        int gecicihucre1=gecicihucre->veri;
        ilk_hucre=gecicihucre->sonrakihucre;
        delete gecicihucre;
        return gecicihucre1;
    }

