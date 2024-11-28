/**
* @file genListe.hpp
* @description gen listesinin üye fonskiyonlarını içerir.
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#ifndef genListe_hpp
#define genListe_hpp
#include<exception>
#include<iostream>
#include "genDugum.hpp"
class genListe
{
public:
    genListe();
    ~genListe();
    void ekle(char veri);
    void cikar();
    void cikar(int sira);
    void onuneEkle(int sira, char veri);
    int ilkGetir();
    void birSatirYazdir();
    int boyut();
    friend ostream& operator<<(ostream& os, genListe& liste);
    genDugum* dugumGetir(int sira);
    char kucukGenBul();
private:


    genDugum* ilk;

};

#endif