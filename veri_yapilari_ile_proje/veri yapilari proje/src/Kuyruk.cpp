#include "Kuyruk.hpp"
#include <iostream>

int Kuyruk:: maksimumdizielemansayisi(Doku &doku){
    int kuyrukhucresi, dizi=0 ,i;
    Hucre *birincikuyrukhucre=doku.Listebasi();
    kuyrukhucresi=birincikuyrukhucre->veri;

    while(birincikuyrukhucre!=0){
        if(kuyrukhucresi<birincikuyrukhucre->veri){
            kuyrukhucresi=birincikuyrukhucre->veri;
        }
        birincikuyrukhucre=birincikuyrukhucre->sonrakihucre;
    }

    while(kuyrukhucresi>0){
        kuyrukhucresi=kuyrukhucresi/10;
        dizi++;
    }
    return dizi;
}

int  Kuyruk::  entepedekieleman(int kuyrukhucresi, int kuyrukdegersayi){
    int deger=1;
    while(kuyrukdegersayi--){
        deger=deger*kuyrukhucresi;
    }
    return deger;
}

void  Kuyruk::  kuyruk(Doku &doku ,Doku kuyrukdizi[]){
    int i=1, j, kuyrukhucresi, kuyruk_indisi;
    int kuyruk_eleman_no=maksimumdizielemansayisi(doku);

while (i<=kuyruk_eleman_no){
    while (!doku.HucreBosMu()){
        kuyrukhucresi=doku.HucreSil();
        kuyruk_indisi=kuyrukhucresi%entepedekieleman(10,i);
        kuyruk_indisi=kuyruk_indisi/entepedekieleman(10,i-1);
        kuyrukdizi[kuyruk_indisi].HucreEkle(kuyrukhucresi);
            
    }

    for(j=0;j<10;j++){
        while(!kuyrukdizi[j].HucreBosMu()){
            kuyrukhucresi=kuyrukdizi[j].HucreSil();
            doku.HucreEkle(kuyrukhucresi);
            doku.Hucre_Sayisi--;
        }
    }
    i++;
}
}

