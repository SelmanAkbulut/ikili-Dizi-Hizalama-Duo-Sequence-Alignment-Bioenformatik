#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void doldur(int a,string *dizi);
int main()
{
    int i,j;
    string veri1,veri2,takas;
    string *vp1 = &veri1;
    string *vp2 = &veri2;
    doldur(1,vp1);
    doldur(2,vp2);
    cout<<veri1<<endl;
    cout<<veri2<<endl;
    int vertical=0,horizantel=0,diagonal=0;
    int buyuk=0,kucuk=0,azami=0;
    string dikey,yatay;
    ofstream dosya;
    system("del output.txt");
    dosya.open("output.txt");
    if(veri1.length()>=veri2.length())
    {
        buyuk=veri1.length() +1 ;
        kucuk=veri2.length() +1 ;
        yatay = veri2;
        dikey = veri1;
    }
    else
    {
        buyuk=veri2.length() + 1;
        kucuk=veri1.length() + 1;
        yatay = veri1;
        dikey = veri2;
    }
    cout<<"Buyuk olan : "<<buyuk<<" Kucuk Olan : " <<kucuk<<endl;
    cout<<"Buyuk olan : "<<dikey<<" Kucuk Olan : " <<yatay<<endl;
    int hizalama[kucuk][buyuk];
    for(i = 0 ; i < kucuk  ; i++) //Matrisin Bütün Elemanlarýný 0 ile doldurur.
    {
        for(j = 0 ; j < buyuk  ; j++)
        {
            hizalama[i][j] = 0;
        }
    }
    for(i = 1 ; i < kucuk ; i++) //Ýlk sutunu gap cezalarý ile doldurur.
    {
        hizalama[i][0] = i * -2;
    }
    for(i = 1 ; i < buyuk ; i++) //Ýlk satýrý gap cezalarý ile doldurur.
    {

        hizalama[0][i] = i * -2;
    }
    int data1[kucuk][buyuk];
    int eslesmedurumu = -1000;
    int sayac = 0;
    for(sayac=0 ; sayac < 2 ; sayac++)
    {
        cout<<"\n";
    if(sayac==0){
    for(i = 1 ; i < kucuk  ;i++) // Hizalama Matrisinin Eleman Deðerlerini Bulur.
    {
        for(j = 1 ; j < buyuk  ; j++)
        {

            if(yatay[i-1]==dikey[j-1])
            {
                data1[i-1][j-1] = 2;
                eslesmedurumu = hizalama[i-1][j-1] + 2;
            }
            vertical = hizalama[i-1][j] + -2;
            horizantel = hizalama[i][j-1] + -2;
            diagonal = hizalama[i-1][j-1] + -1;
            azami=vertical;
            if(diagonal>azami)
                azami=diagonal;
            if(horizantel>azami)
                azami=horizantel;
            if(eslesmedurumu >=azami)
                azami=eslesmedurumu;
            hizalama[i][j] = azami;

            if(azami == vertical)
                data1[i-1][j-1]  = 3;
            else if(azami == diagonal)
                data1[i-1][j-1]  = 2;
            else if(azami == eslesmedurumu)
                data1[i-1][j-1]  = 2;
            else if(azami == horizantel)
                data1[i-1][j-1]  = 1;
            eslesmedurumu = -1000;
        }
    }}
    else{
        for(i = 1 ; i < kucuk  ;i++) // Hizalama Matrisinin Eleman Deðerlerini Bulur.
    {
        for(j = 1 ; j < buyuk  ; j++)
        {
            if(yatay[i-1]==dikey[j-1])
            {
                data1[i-1][j-1] = 2;
                eslesmedurumu = hizalama[i-1][j-1] + 2;
            }
            vertical = hizalama[i-1][j] + -2;
            horizantel = hizalama[i][j-1] + -2;
            diagonal = hizalama[i-1][j-1] + -1;
            azami=horizantel;
            if(diagonal>azami)
                azami=diagonal;
            if(horizantel>azami)
                azami=horizantel;
            if(eslesmedurumu >= azami)
                azami=eslesmedurumu;
            hizalama[i][j] = azami;
            if(azami == horizantel)
                data1[i-1][j-1]  = 1;
            else if(azami == diagonal)
                data1[i-1][j-1]  = 2;
            else if(azami == vertical)
                data1[i-1][j-1]  = 3;
            else if(azami == eslesmedurumu)
                data1[i-1][j-1]  = 2;
            eslesmedurumu = -1000;
        }
    }
    }
    if(sayac == 0)
        dosya<<"----------High Road---------\n\n";
    if(sayac == 1 )
        dosya<<"\n\n----------Low Road---------\n\n";
    for(i = 0 ; i < kucuk ; i++)
    {
        for(j = 0 ; j < buyuk  ; j++)
        {
        dosya<<hizalama[i][j]<<"  ";
        }
        dosya<<"\n";
    }
    cout<<yatay<<" "<<dikey;
    cout<<"\n\n";
    cout<<"Gonderilen Sayi : "<<hizalama[kucuk-1][buyuk-1]<<"\n";

    for(i = 0 ;i < kucuk-1 ;i++ )
    {
        for(j = 0 ; j < buyuk-1 ;j++)
        {
            cout<<data1[i][j]<<" ";
        }
        cout<<"\n";
    }
    string cevap1,cevap2;
    i=kucuk-2;j=buyuk-2;
    while(1)
    {
        if(i<0 || j<0)
            break;
        if(data1[i][j]==2)
        {
            cevap1 += dikey[j];
            cevap2 += yatay[i];
            i--;
            j--;
        }
        else if(data1[i][j]==3)
        {
            cevap1 += "-";
            cevap2 += yatay[i];
            i--;
        }
        else if(data1[i][j]==1)
        {
            cevap1 += dikey[j];
            cevap2 += "-";
            j--;
        }
    }
    cout<<"Artan i deger : "<<i<<endl;
    cout<<"Artan j deger : "<<j<<endl;
    int k=0;
    cout<<cevap1.length()<<endl;
    cout<<cevap2.length()<<endl;
    if(j>i)
    {
        cout    <<"burada";
        for(k = 0 ; k < j ;k++){
            cevap1 += dikey[j-1-k];
            cevap2 += "-";
        }
    }
    if(i>j)
    {
        for(k = 0 ; k < i ;k++){
            cevap2 += yatay[j-1-k];
            cevap1 += "-";
        }
    }


    dosya<<"\n";
    for(i = cevap1.length() ; i >=0 ; i--)
    {
        dosya<<cevap1[i]<<" ";
    }
    dosya<<"\n";
    for(i = cevap2.length() ; i >=0 ; i--)
    {
        dosya<<cevap2[i]<<" ";
    }
    }
    dosya<<"\nMatch = 2\nMissmatch = -1\nGap = -2";
    return 0;
}

void doldur(int a,string *dizi)
{
    ifstream dosya ;
    if(a==1)
    {
        dosya.open("data1.txt");
    }
    else
        dosya.open("data2.txt");
    getline(dosya,*dizi);
    dosya.close();
}
