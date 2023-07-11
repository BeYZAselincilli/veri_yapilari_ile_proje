#include <Radixsortf.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include<list>
#include<cmath>
using namespace std;

int Radixsortf:: maximumdigit(Doku &doku){
    int gecicihucre1, digit=0 ,i;
    Hucre *birincihucre=doku.Listebasi();
    gecicihucre1=birincihucre->veri;

    while(birincihucre!=0){
        if(gecicihucre1<birincihucre->veri){
            gecicihucre1=birincihucre->veri;
        }
        birincihucre=birincihucre->sonrakihucre;
    }

    while(gecicihucre1>0){
        gecicihucre1=gecicihucre1/10;
        digit++;
    }
    return digit;
}

int  Radixsortf::  pow(int gecicihucre1, int b){
    int esitlik=1;
    while(b--){
        esitlik=esitlik*gecicihucre1;
    }
    return esitlik;
}

void  Radixsortf::  radixsort(Doku &doku ,Doku arr[]){
    int i=1, j, gecicihucre1, indis;
    int num=maximumdigit(doku);

while (i<=num){
    while (!doku.HucreBosMu()){
        gecicihucre1=doku.HucreSil();
        indis=gecicihucre1%pow(10,i);
        indis=indis/pow(10,i-1);
        arr[indis].HucreEkle(gecicihucre1);
            
    }

    for(j=0;j<10;j++){
        while(!arr[j].HucreBosMu()){
            gecicihucre1=arr[j].HucreSil();
            doku.HucreEkle(gecicihucre1);
            doku.Hucre_Sayisi--;
        }
    }
    i++;
}
}

