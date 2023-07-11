#include "Sistem.hpp"
#include <iostream>
using namespace std;

Sistem ::Sistem(){
    SistemSayisi=0;
    sonrakisistem=0;
    ilkorgan=0;
    OrganSayisi=0;
}

Sistem::~Sistem(){
    
}

void Sistem ::SistemeOrganEkle(Organ *eklenecekorgan){
        Organ *yeniorgan=new Organ();
    yeniorgan=eklenecekorgan;

    if(ilkorgan!=0){
    Organ *geciciorgan=ilkorgan;
    while(geciciorgan->sonrakiorgan!=0){      
        geciciorgan=geciciorgan->sonrakiorgan;
    }
    geciciorgan->sonrakiorgan=yeniorgan;
    OrganSayisi++;
}
else if(ilkorgan==0){
    ilkorgan=yeniorgan;
    OrganSayisi++;
}
}

void Sistem::SistemYazdir(){
    Organ *geciciorgan=ilkorgan;
    int sayac=0;
    while(geciciorgan!=0){
        
        if(geciciorgan->Yukseklik_far()==1)
        {
                cout<<"#";
        }
        else if(geciciorgan->Yukseklik_far()==0)
        {
            cout<<" ";
        }
        geciciorgan=geciciorgan->sonrakiorgan;
}
}



void Sistem::MutasyonluSistemYazdir(){
    Organ *geciciorgan=ilkorgan;
    int sayac=0;
    while(geciciorgan!=0){
        
        if(geciciorgan->Yukseklik_far_mutasyon()==1)
        {
                cout<<"#";
        }
        else if(geciciorgan->Yukseklik_far_mutasyon()==0)
        {
            cout<<" ";
        }
        geciciorgan=geciciorgan->sonrakiorgan;
}
}


