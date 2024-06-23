/* Nama program : soal_5
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 14/03/2024
   Deskripsi    : Buatlah program untuk mengelola selisih waktu
**********************************************************************/
#include <iostream>
using namespace std;

// Struktur untuk merepresentasikan waktu
struct Waktu {
    int jam, menit, detik;
};

// Prototipe fungsi
void masukkanWaktu(Waktu &waktu);
void hitungSelisih(Waktu awal, Waktu akhir, Waktu &selisih);
void cetakWaktu(Waktu waktu);

int main() {
    Waktu waktuA, waktuB, selisih;

    cout << "Masukkan Waktu A: " << endl;
    masukkanWaktu(waktuA);

    cout << "Masukkan Waktu B: " << endl;
    masukkanWaktu(waktuB);

    hitungSelisih(waktuA, waktuB, selisih);

    cout << "Selisih Waktu: ";
    cetakWaktu(selisih);

    return 0;
}

// Fungsi untuk mendapatkan input waktu dari pengguna
void masukkanWaktu(Waktu &waktu) {
    cout << "Jam: ";
    cin >> waktu.jam;
    cout << "Menit: ";
    cin >> waktu.menit;
    cout << "Detik: ";
    cin >> waktu.detik;
}

// Fungsi untuk menghitung selisih antara dua waktu
void hitungSelisih(Waktu awal, Waktu akhir, Waktu &selisih) {
    int detikAwal = awal.jam * 3600 + awal.menit * 60 + awal.detik;
    int detikAkhir = akhir.jam * 3600 + akhir.menit * 60 + akhir.detik;
    int selisihDetik = detikAkhir - detikAwal;

    // Mengatasi selisih negatif
    if (selisihDetik < 0) {
        selisihDetik += 24 * 3600; // Dalam sehari
    }

    // Mengonversi selisih kembali ke jam, menit, dan detik
    selisih.jam = selisihDetik / 3600;
    selisih.menit = (selisihDetik % 3600) / 60;
    selisih.detik = (selisihDetik % 3600) % 60;
}

// Fungsi untuk mencetak waktu
void cetakWaktu(Waktu waktu) {
    cout << waktu.jam << " jam, " << waktu.menit << " menit, " << waktu.detik << " detik" << endl;
}
