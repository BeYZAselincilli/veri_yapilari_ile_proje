/** 

*/

#include "Organizma.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include<list>
#include<cmath>
#include <iomanip>

using namespace std;

int main()
{  
Ikiliarama *agac=new Ikiliarama();
Radixsortf* radix=new Radixsortf();
Kuyruk *kuyruk=new Kuyruk();
Organ *organ= new Organ[2600];
Organ *mutasyonluorgan=new Organ[2600];
Sistem *sistem=new Sistem[26];
Sistem *mutasyonlusistem=new Sistem[26];
Organizma *organizma =new Organizma[1];
Organizma *mutasyonluorganizma = new Organizma[1];
int sistemdizisi=0;
int OrganSayisi=0;
int DokuSayisi=0;
int organdizi=0;
int organizmadizisi=0;
ifstream file("gulenyuz.txt",ios::in);
	if (file.good())
{  
    string str;
    while(getline(file, str)) 
    {      
       Doku *doku4=new Doku();
        istringstream ss(str);
        int num;      
        Doku doku , arr[10];     
        int gecicihucre1;
     
        while(ss >> num)
        {
            doku4->HucreEkle(num); 
    	}
                 DokuSayisi++;  

    radix->radixsort(*doku4 , arr);  //radixsort fonksiyonunun cagirilmasi

        doku4->ortaelemanindisi=(doku4->Hucre_Sayisi+1)/2;
        Hucre* gecicihucre=doku4->ilk_hucre;

         for(int i=0;i<doku4->ortaelemanindisi-1;i++)
         {
            gecicihucre=gecicihucre->sonrakihucre;            
         }
          radix->dokuikilieleman=gecicihucre->veri;
 
            doku4->ortadokuadresi=gecicihucre;
 
            doku4->ortadokuadresi->veri=gecicihucre->veri;

           
 
           organ[organdizi].OrganaDokuEkle(doku4);
 
          organ[organdizi].agacaeklee->ekle(doku4->ortadokuadresi); 
      //    mutasyonluorgan[organdizi].agacaeklee->Postorderdizisi_Ekle(organ->agacaeklee->kok,doku4->ortadokuadresi->veri);
          if(DokuSayisi%52000==0 && DokuSayisi==0){
            organizmadizisi++;
          }

 if(DokuSayisi%20==0 && DokuSayisi!=0){  
    sistem[sistemdizisi].SistemeOrganEkle(&organ[organdizi]);

  //  mutasyonlusistem[sistemdizisi].SistemeOrganEkle(&mutasyonluorgan[organdizi]);
      organdizi++;
     }
         

  if(DokuSayisi%2000==0){
      sistemdizisi++;   
  }

 }	
}

for(int i=0;i<organdizi;i++)
{  cout<<endl;
  // cout<<i+1<<"organ yazdiriliyor..";
   delete &organ[i];
  // delete &mutasyonluorgan[i];
}

for(int i=0;i<sistemdizisi;i++){
 // sistem[i].SistemYazdir();

 organizma[organizmadizisi].OrganizmayaSistemEkle(&sistem[i]);
 //mutasyonluorganizma[organizmadizisi].OrganizmayaSistemEkle(&mutasyonlusistem[i]);
//delete &sistem[i];
 // cout<<endl;
   
}

 cout<<"                     ORGANIZMA"<<endl<<endl<<endl;
 organizma[organizmadizisi].OrganizmaYazdir();
cout<<endl<<endl;

  string input;
  getline(cin, input);
   system("cls");
  if (input.empty()){      cout<<"                       MUTASYONLU ORGANIZMA"<<endl<<endl<<endl;
 organizma->Hucre_Mutasyonu();
  organizma[organizmadizisi].MutasyonluOrganizmaYazdir();
 }

  
}
