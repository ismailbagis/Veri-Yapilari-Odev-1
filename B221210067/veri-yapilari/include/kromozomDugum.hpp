/**
* @file kromozomDugum.hpp
* @description kromozom düğümlerinin üye fonskiyonlarını içerir.
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#ifndef kromozomDugum_hpp
#define kromozomDugum_hpp
#include<iostream>
#include "genListe.hpp"

class kromozomDugum
{
public:
    kromozomDugum(genListe* genListesi);
    ~kromozomDugum();
    genListe* genListesi;
    kromozomDugum* sonraki;
    kromozomDugum* onceki;
};


#endif