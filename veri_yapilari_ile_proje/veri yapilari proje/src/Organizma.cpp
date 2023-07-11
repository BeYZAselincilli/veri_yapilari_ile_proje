#include "Organizma.hpp"
#include <iostream>
using namespace std;

Organizma::Organizma(){
    OrganizmaSayisi=0;
    sonrakiorganizma=0;
    ilksistem=0;
    SistemSayisi=0;
    
}

Organizma::~Organizma(){

}

void Organizma::OrganizmayaSistemEkle(Sistem *ekleneceksistem){
    Sistem *yenisistem=new Sistem();
    yenisistem=ekleneceksistem;

    if(ilksistem!=0){
        Sistem *gecicisistem=ilksistem;
        while(gecicisistem->sonrakisistem!=0){
            gecicisistem=gecicisistem->sonrakisistem;
        }
        gecicisistem->sonrakisistem=yenisistem;
        SistemSayisi++;
    }
    else if(ilksistem==0){
        ilksistem=yenisistem;
        SistemSayisi++;
    }
}

void Organizma::OrganizmaYazdir(){
    Sistem *gecicisistem=ilksistem;
    while(gecicisistem!=0){
      //  cout<<"Sistem Adresleri"<<gecicisistem;
      //  cout<<"sistem verileri";
        gecicisistem->SistemYazdir();
      cout<<endl;
        gecicisistem=gecicisistem->sonrakisistem;
    }
}
void Organizma::MutasyonluOrganizmaYazdir(){
        Sistem *gecicisistem=ilksistem;
    while(gecicisistem!=0){
      //  cout<<"Sistem Adresleri"<<gecicisistem;
      //  cout<<"sistem verileri";
        gecicisistem->MutasyonluSistemYazdir();
        cout<<endl;
        gecicisistem=gecicisistem->sonrakisistem;
    }
}



void Organizma::Hucre_Mutasyonu(){
        Sistem *gecicisistem=new Sistem();
        Organ* Mutasyon_organlar=new Organ[2600];
        Sistem* yeni_Sistemler=new Sistem[26];
        int organ_Sayac=0;

      int satir_Sayisi=0;
      int sistem_Sayisi=0;
        gecicisistem=ilksistem;
        while(gecicisistem!=0){
       //   cout<<"gezdigi sistem adresi   "<<gecicisistem<<endl;
            Organ *geiciciorgan=gecicisistem->ilkorgan;         
            while(geiciciorgan!=0){ 
              
              //  cout<< "gezdigi organ adresi   "<<geiciciorgan<<endl;    
                if((geiciciorgan->agacaeklee->kok->veri)%50==0){

                int arr[20];
               int i=0;
                PostOrder_DiziAtama(geiciciorgan->agacaeklee->kok, arr, i);
              
                  for(int j=0; j<i;j++){
        // cout<<arr[j]<<endl;
         Doku* gec=new Doku();
         for(int i=0;i<20;i++)
         {
            if(arr[i]%2==0)
            {
               gec->HucreEkle(arr[i]/2);
            }

            else 
            {
                gec->HucreEkle(arr[i]);
            }
         }
        
        Hucre* gec2=gec->ilk_hucre;
        int sayac=0;
        while(gec2->sonrakihucre!=0 && sayac!=20)
        {
            geiciciorgan->mutasyonlu_Agaclar->ekle(gec2);
            sayac++;
      
        }

        }  

                 Doku *gecicidoku=new Doku();
                gecicidoku=geiciciorgan->ilkdoku;
                
                while(gecicidoku!=0){

                       Doku* mutasyonlu_doku=new Doku();

                    Hucre *gecicihucre=gecicidoku->ilk_hucre;
                    while(gecicihucre!=0){
                        if(gecicihucre->veri%2==0){
                       //     cout<<"eski hucre degeri   "<<gecicihucre->veri<<endl;
                            gecicihucre->veri=(gecicihucre->veri)/2;

                        }

                          gecicihucre=gecicihucre->sonrakihucre;
                    }

                    gecicidoku=gecicidoku->sonrakidoku;
                }     
                
               
                }  
                else 
                {
                    geiciciorgan->mutasyonlu_Agaclar=geiciciorgan->agacaeklee;
                }
               
               
                geiciciorgan=geiciciorgan->sonrakiorgan;
            
        }
    
      //  gecicisistem->MutasyonluSistemYazdir();
     //   cout<<endl;
        gecicisistem=gecicisistem->sonrakisistem;
}
}


void Organizma::PostOrder_DiziAtama(Dugumikili *kok, int *arr, int &i ){
    if(kok!=0){
        PostOrder_DiziAtama(kok->soldugum, arr, i);
        PostOrder_DiziAtama(kok->sagdugum,arr,i);
        arr[i++] = kok->veri;
    
}
}