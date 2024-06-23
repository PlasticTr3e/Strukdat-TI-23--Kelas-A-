/* Nama program : soal_1
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 01/03/2024
   Deskripsi    : Program modular untuk mencari luas persegi panjang
*********************************************/
#include <iostream>

using namespace std;

//Fungsi menghitung luas persegi panjang
int luas(int sisi){
    return sisi * sisi;
}

//Fungsi input panjang sisi
void input(int& input_sisi){
    cin >> input_sisi;
}

//Fungsi cetak hasil
void cetak(int luas){
    cout << luas;
}

int main(){
    int sisi;
    input(sisi);
    cetak(luas(sisi));


    return 0;
}