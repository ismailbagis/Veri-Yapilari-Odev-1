/**
* @file genListe.cpp
* @description gen listeesini içerir genlerle ilgili fonksiyonları içerir.
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#include "genListe.hpp"
#include<iomanip>

genListe::genListe()
{
    ilk = 0;
}
genListe::~genListe()
{
    genDugum* gec = ilk;
    while (gec != 0)
    {
        genDugum* silinecek = gec;
        gec = gec->sonraki;

        delete silinecek;
    }
}
void genListe::ekle(char veri)
{
    genDugum* yeniDugum = new genDugum(veri);
    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        genDugum* gec = ilk;

        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }
}
int genListe::ilkGetir()
{
    if (ilk != 0)
        return ilk->veri;
    throw out_of_range("Liste::ilkGetir(): Liste bos Hatasi");
}
void genListe::cikar()
{
    if (ilk == 0)      return;

    if (ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        genDugum* gec = ilk;

        while (gec->sonraki->sonraki != 0)
            gec = gec->sonraki;

        delete gec->sonraki;
        gec->sonraki = 0;
    }


}
void genListe::onuneEkle(int sira, char veri)
{
    genDugum* aktifDugum = dugumGetir(sira);

    if (aktifDugum)
    {
        genDugum* aktifOnceki = aktifDugum->onceki;

        genDugum* yeniDugum = new genDugum(veri);

        aktifDugum->onceki = yeniDugum;

        yeniDugum->sonraki = aktifDugum;
        yeniDugum->onceki = aktifOnceki;

        if (aktifOnceki)
            aktifOnceki->sonraki = yeniDugum;
        else
            ilk = yeniDugum;

    }
}
void genListe::cikar(int sira)
{
    genDugum* silinecek = dugumGetir(sira);

    if (silinecek)
    {

        genDugum* silinecekOnceki = silinecek->onceki;
        genDugum* silinecekSonraki = silinecek->sonraki;

        if (silinecekSonraki)
            silinecekSonraki->onceki = silinecekOnceki;

        if (silinecekOnceki)
            silinecekOnceki->sonraki = silinecekSonraki;
        else
            ilk = silinecekSonraki;
        delete silinecek;
    }
}
genDugum* genListe::dugumGetir(int sira)
{
    genDugum* gec = ilk;

    while (sira >= 0 && gec != 0)
    {

        if (sira == 0)
            return gec;
        gec = gec->sonraki;

        sira--;
    }

    return 0;
}

int genListe::boyut() {
    int count = 0;
    genDugum* gec = ilk;
    while (gec != nullptr) {
        count++;
        gec = gec->sonraki;
    }
    return count;
}

ostream& operator<<(ostream& os, genListe& liste)
{

    genDugum* gec = liste.ilk;

    while (gec != 0)
    {
        gec = gec->sonraki;
    }

    return os;
}

void genListe::birSatirYazdir()
{
    genDugum* gec = ilk;

    while (gec != 0)
    {
        cout<< " " << gec->veri;
        gec = gec->sonraki;
    }
    cout << endl;

}

char genListe::kucukGenBul() {
    if (ilk == nullptr) {
        throw out_of_range("Liste bos");
    }

    genDugum* gec = ilk;
    while (gec->sonraki != nullptr) {
        gec = gec->sonraki;
    }

    char ilkGen = ilk->veri;
    char kucukGen = ilkGen;

    while (gec != nullptr) {
        if (gec->veri < ilkGen) {
            kucukGen = gec->veri;
            break;
        }
        gec = gec->onceki;
    }

    return kucukGen;
}