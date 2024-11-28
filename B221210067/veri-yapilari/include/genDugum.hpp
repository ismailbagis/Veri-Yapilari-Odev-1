/**
* @file genDugum.hpp
* @description gen düğümlerinin üye fonskiyonlarını içerir..
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/



#ifndef genDugum_hpp
#define genDugum_hpp
#include<iostream>
using namespace std;

class genDugum
{
public:
    genDugum(char veri);
    ~genDugum();
    char veri;
    genDugum* sonraki;
    genDugum* onceki;
};


#endif