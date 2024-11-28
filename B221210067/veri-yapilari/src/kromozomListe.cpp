/**
* @file kromozomListe.cpp
* @description kromozom listeesini içerir kromozomlarla ilgili fonksiyonları içerir.
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#include "kromozomListe.hpp"
#include<iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>

kromozomListe::kromozomListe()
{
    ilk = 0;
}
kromozomListe::~kromozomListe()
{
    kromozomDugum* gec = ilk;
    while (gec != 0)
    {
        kromozomDugum* silinecek = gec;
        gec = gec->sonraki;

        delete silinecek;
    }
}
void kromozomListe::ekle(genListe* veri)
{
    kromozomDugum* yeniDugum = new kromozomDugum(veri);
    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        kromozomDugum* gec = ilk;

        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }
}
genListe* kromozomListe::ilkGetir()
{
    if (ilk != 0)
        return ilk->genListesi;
    throw out_of_range("kromozomDugum::ilkGetir(): kromozomDugum bos Hatasi");
}
void kromozomListe::cikar()
{
    if (ilk == 0)      return;

    if (ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        kromozomDugum* gec = ilk;

        while (gec->sonraki->sonraki != 0)
            gec = gec->sonraki;

        delete gec->sonraki;
        gec->sonraki = 0;
    }


}
void kromozomListe::onuneEkle(int sira, genListe* veri)
{
    kromozomDugum* aktifDugum = dugumGetir(sira);

    if (aktifDugum)
    {
        kromozomDugum* aktifOnceki = aktifDugum->onceki;

        kromozomDugum* yeniDugum = new kromozomDugum(veri);

        aktifDugum->onceki = yeniDugum;

        yeniDugum->sonraki = aktifDugum;
        yeniDugum->onceki = aktifOnceki;

        if (aktifOnceki)
            aktifOnceki->sonraki = yeniDugum;
        else
            ilk = yeniDugum;

    }
}
void kromozomListe::cikar(int sira)
{
    kromozomDugum* silinecek = dugumGetir(sira);

    if (silinecek)
    {

        kromozomDugum* silinecekOnceki = silinecek->onceki;
        kromozomDugum* silinecekSonraki = silinecek->sonraki;

        if (silinecekSonraki)
            silinecekSonraki->onceki = silinecekOnceki;

        if (silinecekOnceki)
            silinecekOnceki->sonraki = silinecekSonraki;
        else
            ilk = silinecekSonraki;
        delete silinecek;
    }
}
kromozomDugum* kromozomListe::dugumGetir(int sira)
{
    kromozomDugum* gec = ilk;

    while (sira >= 0 && gec != 0)
    {

        if (sira == 0)
            return gec;
        gec = gec->sonraki;

        sira--;
    }

    return 0;
}
ostream& operator<<(ostream& os, kromozomListe& liste)
{

    kromozomDugum* gec = liste.ilk;

    while (gec != nullptr)
    {

        if (gec->genListesi != nullptr) {
            gec->genListesi->birSatirYazdir();
        }
        else {
            os << "Boş gen listesi" << endl;
        }
        gec = gec->sonraki;
    }

    return os;
}

void kromozomListe::caprazlama(int sira1, int sira2) {
    kromozomDugum* kromozom1 = dugumGetir(sira1);
    kromozomDugum* kromozom2 = dugumGetir(sira2);

    if (kromozom1 == nullptr || kromozom2 == nullptr) {
        throw out_of_range("Geçersiz kromozom satır numarası");
    }

    genListe* genListesi1 = kromozom1->genListesi;
    genListe* genListesi2 = kromozom2->genListesi;

    int boyut1 = genListesi1->boyut();
    int boyut2 = genListesi2->boyut();

    int orta1 = boyut1 / 2;
    int orta2 = boyut2 / 2;

    genListe* yeniGenListesi1 = new genListe();
    genListe* yeniGenListesi2 = new genListe();

    for (int i = 0; i < orta1; i++) {
        yeniGenListesi1->ekle(genListesi1->dugumGetir(i)->veri);
    }
    for (int i = orta2; i < boyut2; i++) {
        yeniGenListesi1->ekle(genListesi2->dugumGetir(i)->veri);
    }

    for (int i = orta1; i < boyut1; i++) {
        yeniGenListesi2->ekle(genListesi1->dugumGetir(i)->veri);
    }
    for (int i = 0; i < orta2; i++) {
        yeniGenListesi2->ekle(genListesi2->dugumGetir(i)->veri);
    }

    ekle(yeniGenListesi1);
    ekle(yeniGenListesi2);
}

void kromozomListe::mutasyon(int kromozomSira, int genSutun) {
    kromozomDugum* kromozom = dugumGetir(kromozomSira);

    if (kromozom == nullptr) {
        throw out_of_range("Geçersiz kromozom satır numarası");
    }

    genListe* genListesi = kromozom->genListesi;
    genDugum* gen = genListesi->dugumGetir(genSutun);

    if (gen == nullptr) {
        throw out_of_range("Geçersiz gen sütun numarası");
    }

    gen->veri = 'X';

}

void kromozomListe::otomatikIslemler(const string& dosyaIsmi) {
    ifstream dosya(dosyaIsmi);
    if (!dosya.is_open()) {
        throw runtime_error("Islemler dosyasi acilamadi");
    }

    std::string satir;
    while (getline(dosya, satir)) {
        istringstream iss(satir);
        char islemTuru;
        int sira1, sira2;

        iss >> islemTuru >> sira1 >> sira2;

        try {
            if (islemTuru == 'C') {
                caprazlama(sira1, sira2);
            }
            else if (islemTuru == 'M') {
                mutasyon(sira1, sira2);
            }
            else {
                cerr << "Gecersiz islem turu: " << islemTuru << endl;
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }

    dosya.close();
}

void kromozomListe::ekranaYaz() {
    kromozomDugum* gec = ilk;
    while (gec != nullptr) {
        try {
            char yazilacakGen = gec->genListesi->kucukGenBul();
            cout << yazilacakGen << " ";
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
        gec = gec->sonraki;
    }
    cout << endl;
}

kromozomListe* dosyadanListeOlustur(string dosyaIsmi)
{
    ifstream dosya(dosyaIsmi);

    kromozomListe* kromozomlar = new kromozomListe();
    if (dosya.is_open())
    {
        string satir;
        while (getline(dosya, satir)) {
            char siradakiGen;
            stringstream satirOku(satir);
            genListe* siradakiListe = new genListe;
            while (satirOku >> siradakiGen) {
                siradakiListe->ekle(siradakiGen);
            }

            kromozomlar->ekle(siradakiListe);
        }

        dosya.close();
    }
    return kromozomlar;
}