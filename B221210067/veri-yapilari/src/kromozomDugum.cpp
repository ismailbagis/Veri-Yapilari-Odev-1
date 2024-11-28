/**
* @file kromozomDugum.cpp
* @description kromozom düğümünün yapısını içerir.
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#include "kromozomDugum.hpp"

kromozomDugum::kromozomDugum(genListe* genListesi)
{
    this->genListesi = genListesi;

    onceki = sonraki = 0;
}
kromozomDugum::~kromozomDugum()
{
}