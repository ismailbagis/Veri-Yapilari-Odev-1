/**
* @file main.cpp
* @description istenilen işlemleri seçtiğimiz ve dosya okuduğumuz kısımı içerir
* @course 1.Öğretim A grubu
* @assignment 1.Ödev
* @date 25/11/2024
* @author İsmail Bağış - ismail.bagis@ogr.sakarya.edu.tr
*/



#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include"kromozomListe.hpp"

using namespace std;

int main() {
    kromozomListe* kromozomlar = dosyadanListeOlustur("Dna.txt");

    // Kullanıcıdan işlem seçimi al
    int secim;
    while (true) {
        cout << "\n1- Caprazlama\n2- Mutasyon\n3- Otomatik Islemler\n4- Ekrana Yaz\n5- Cikis\nSeciminizi yapin: ";
        cin >> secim;

        switch (secim) {
        case 1: {
            int sira1, sira2;
            cout << "Birinci kromozom satir numarasini girin: ";
            cin >> sira1;
            cout << "Ikinci kromozom satir numarasini girin: ";
            cin >> sira2;
            try {
                kromozomlar->caprazlama(sira1, sira2);
            }
            catch (const exception& e) {
                cerr << e.what() <<endl;
            }

            cout << *kromozomlar;
            break;
        }
        case 2: {
            int kromozomSira, genSutun;
            cout << "Kromozom satir numarasini girin: ";
            cin >> kromozomSira;
            cout << "Gen sutun numarasini girin: ";
            cin >> genSutun;
            try {
                kromozomlar->mutasyon(kromozomSira, genSutun);
            }
            catch (const exception& e) {
                cerr << e.what() <<endl;
            }
            cout << *kromozomlar;
            break;
        }
        case 3: {
            try {
                kromozomlar->otomatikIslemler("Islemler.txt");
            }
            catch (const exception& e) {
                cerr << e.what() <<endl;
            }
            cout << *kromozomlar;
            break;
        }
        case 4: {
            kromozomlar->ekranaYaz();
            break;
        }
        case 5: {
            cout << "cikiliyor..." <<endl;
            delete kromozomlar;
            return 0;
        }
        default:
            cout << "Gecersiz secim, tekrar deneyin." <<endl;
        }
    }
    
}
