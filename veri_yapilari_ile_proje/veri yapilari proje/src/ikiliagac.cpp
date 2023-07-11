#include "Ikiliagac.hpp"
#include <iostream>

using namespace std;

Ikiliarama::Ikiliarama(){
    kok=0;
    aktifDugum=0;
}

Ikiliarama::~Ikiliarama(){

}

bool Ikiliarama::varmi(int veri){
    return varmi( veri,kok);
}

bool Ikiliarama::varmi(int aranan, Dugumikili*aktif){
    if(aranan>aktif->veri){
        if(aktif->sagdugum){
            return varmi(aranan,aktif->sagdugum);
        }
        return false;
    }

    else if(aranan<aktif->veri){
        if(aktif->soldugum){
            return varmi(aranan,aktif->soldugum);
        }
        return false;
    }
    else return true;
}
void Ikiliarama::ekle(Hucre *eklecenekdugum)
{
    
    if(kok==0)
    {     
        kok=new Dugumikili(dugum); 
        kok->veri=eklecenekdugum->veri;
       // cout<<"ortanca eleman eklendi" <<"    "<<"aktif dugum verisi.";
    }
    else{  
        ekle(eklecenekdugum,kok);
    }
}
void Ikiliarama::ekle(Hucre *eklenecekdugum, Dugumikili *aktifDugum){

  if(eklenecekdugum->veri < aktifDugum->veri ||eklenecekdugum->veri==aktifDugum->veri){

        // cout<<"eklenilecek veri "<<eklenecekdugum->veri<<"        "<<"aktif dugum verisi...."<< aktifDugum->veri<<endl;
        if(aktifDugum->soldugum){
          //  cout<<"sol var o yuzden bi daha cagirdik"<<endl;


            ekle(eklenecekdugum,aktifDugum->soldugum);
            if(yukseklikbulma(aktifDugum->soldugum)-yukseklikbulma(aktifDugum->sagdugum)>1){
              //  cout<<"agac dengesiz"<<endl;
            }
         //   cout<<"sol dugume eklendi "<<endl;
        }
     else{
            aktifDugum->soldugum=new Dugumikili(dugum);
           
            // cout<<eklenecekdugum->veri<<endl;
        aktifDugum->soldugum->veri=eklenecekdugum->veri;

         //   cout<<"sol dugume eklendi "<<endl;
        }
    }
     if(eklenecekdugum->veri > aktifDugum->veri){
    if(yukseklikbulma(aktifDugum->sagdugum)-yukseklikbulma(aktifDugum->soldugum)>1){
    //    cout<<"agac dengesiz"<<endl;
    }
          //  cout<<eklenecekdugum->veri<<"       aktif dugum verisi"<<aktifDugum->veri;
      //  cout<<endl <<endl<<endl<<"sag tarafa girdi ......"<<endl;
        if(aktifDugum->sagdugum){

            ekle(eklenecekdugum,aktifDugum->sagdugum);
         //   cout<<"sag dugume eklendi "<<endl;
        }
        else{
            aktifDugum->sagdugum=new Dugumikili(dugum);
         //    cout<<eklenecekdugum->veri<<endl;

         aktifDugum->sagdugum->veri=  eklenecekdugum->veri;
         
            //cout<<"sag dugume eklendi "<<endl;
        }     
    }
    
}

/*void Ikiliarama::Postorderdizisi_Ekle(Dugumikili *kok, aktifDugum){
    if(kok==0){
        kok=new Dugumikili(dugum);
    }

    /*    else {
        Postorderdizisi_Ekle(kok->soldugum,veri);
         Postorderdizisi_Ekle(kok->sagdugum, veri);
    }
*//*
else if(veri<kok->veri){

  //Postorderdizisi_Ekle(kok->soldugum,veri);
}
else {
   // Postorderdizisi_Ekle(kok->sagdugum,veri);
}
*/







int Ikiliarama::yukseklikbulma(Dugumikili *aktifDugum){
    if(aktifDugum) {
        return 1+max(yukseklikbulma(aktifDugum->soldugum),yukseklikbulma(aktifDugum->sagdugum));
    }
    return -1;
}
