/* Nama program : soal_1
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 14/03/2024
   Deskripsi    : Salin dan buat program diatas (lengkapi tampilan untuk input 
dan output)
•Ubah berbentuk fungsi dan void (untuk input) serta void (untuk 
output). Perhatikan passing by value atau by reference nya
**********************************************************************/
#include <iostream>

using namespace std;

struct Mahasiswa
{
    char NPM[8];
    char nama[20];
    int nilai;
};

typedef Mahasiswa *PointerToMhs; // pointer menunjuk address record Mahasiswa

//Fungsi input data
void newMahasiswa(PointerToMhs &mhs)
{
    mhs = new Mahasiswa; //Alokasi memori baru untuk struct
    cout << "Masukkan Nama  :   ";
    cin >> mhs->nama;
    cout << "Masukkan Nilai :   ";
    cin >> mhs->nilai;
    cout << "Masukkan NPM   :   ";
    cin >> mhs->NPM;
    cout << endl;
}

//Fungsi output data 
void output_dataMhs(PointerToMhs mhs)
{
    cout << endl;
    cout << "NPM : " << mhs->NPM << endl;
    cout << "Nama : " << mhs->nama << endl;
    cout << "Nilai : " << mhs->nilai << endl << endl;
}


main()
{
    PointerToMhs p, q;
    newMahasiswa(p);
    newMahasiswa(q);
    output_dataMhs(p);
    output_dataMhs(q);
    delete (p); // menghapus alokasi memori
    delete (q); // menghapus alokasi memori
}
