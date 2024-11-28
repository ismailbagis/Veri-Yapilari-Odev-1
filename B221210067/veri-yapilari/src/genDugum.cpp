/**
* @file genDugum.cpp
* @description gen düğümünün yapısını içerir.
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/


#include "genDugum.hpp"

genDugum::genDugum(char veri)
{
    this->veri = veri;

    onceki = sonraki = 0;
}
genDugum::~genDugum()
{
}