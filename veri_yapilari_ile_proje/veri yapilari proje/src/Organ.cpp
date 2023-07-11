#include "Organ.hpp"
#include <iostream>
using namespace std;

Organ :: Organ (){
    DokuSayisi=0;
    ilkdoku=0;
   sonrakiorgan=0;
  
}
Organ :: ~Organ (){
  //  cout<<"Organ silindi";
}

void Organ::OrganaDokuEkle(Doku *eklenecekdoku)
{    
  
    Doku *yenidoku=new Doku();
    yenidoku=eklenecekdoku;

    if(ilkdoku!=0){
    Doku *gecicidoku=ilkdoku;
    while(gecicidoku->sonrakidoku!=0){      
        gecicidoku=gecicidoku->sonrakidoku;
    }
    gecicidoku->sonrakidoku=yenidoku;
    DokuSayisi++;
}
else if(ilkdoku==0){
    ilkdoku=yenidoku;
    DokuSayisi++;
}
}


bool Organ::Yukseklik_far()
{
    int fark= abs(agacaeklee->yukseklikbulma(agacaeklee->kok->soldugum)- agacaeklee->yukseklikbulma(agacaeklee->kok->sagdugum));
    if(fark>1)
    {
        return 1;
    }

    else {
        return 0;
    
    }
}


bool Organ::Yukseklik_far_mutasyon()
{
    int fark= abs(mutasyonlu_Agaclar->yukseklikbulma(mutasyonlu_Agaclar->kok->soldugum)- mutasyonlu_Agaclar->yukseklikbulma(mutasyonlu_Agaclar->kok->sagdugum));
    if(fark>1)
    {
        return 1;
    }

    else {
        return 0;
    
    }
}


void Organ::OrganYazdir(){
    Doku *gecicidoku=ilkdoku;
    while(gecicidoku!=0){
      cout<<"doku adresleri "<<gecicidoku;
      cout<<" doku verileri ";
        gecicidoku->HucreYazdir();
   //     cout<<endl;
        gecicidoku=gecicidoku->sonrakidoku;
    }
    
}

