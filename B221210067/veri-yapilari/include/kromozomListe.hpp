/**
* @file kromozomListe.hpp
* @description kromozom listesinin üye fonskiyonlarını içerir.
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#ifndef kromozomListe_hpp
#define kromozomListe_hpp
#include<exception>
#include<iostream>
#include "kromozomDugum.hpp"
class kromozomListe
{
public:
    kromozomListe();
    ~kromozomListe();
    void ekle(genListe* veri);
    void cikar();
    void cikar(int sira);
    void onuneEkle(int sira, genListe* veri);
    genListe* ilkGetir();
    friend ostream& operator<<(ostream& os, kromozomListe& liste);
    kromozomDugum* dugumGetir(int sira);
    void caprazlama(int sira1, int sira2);
    void mutasyon(int kromozomSira, int genSutun);
    void otomatikIslemler(const std::string& dosyaIsmi);
    void ekranaYaz();

private:


    kromozomDugum* ilk;

};
    kromozomListe* dosyadanListeOlustur(string dosyaIsmi);

#endif