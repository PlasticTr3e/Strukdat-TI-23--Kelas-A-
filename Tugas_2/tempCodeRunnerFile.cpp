/* Nama program : soal_6
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 14/03/2024
   Deskripsi    :  program untuk mengelola selisih Tanggal.
**********************************************************************/
#include <iostream>
using namespace std;

// Struktur untuk merepresentasikan tanggal
struct Tanggal {
    int hari, bulan, tahun;
};

// Fungsi-fungsi
void inputTanggal(Tanggal &tgl);
void selisihTanggal(Tanggal tglAwal, Tanggal tglAkhir, Tanggal &selisih);
void cetakTanggal(Tanggal tgl);

int main() {
    Tanggal tglAwal, tglAkhir, selisih;

    cout << "Masukkan Tanggal Awal:" << endl;
    inputTanggal(tglAwal);

    cout << "Masukkan Tanggal Akhir:" << endl;
    inputTanggal(tglAkhir);

    selisihTanggal(tglAwal, tglAkhir, selisih);

    cout << "Selisih Tanggal: ";
    cetakTanggal(selisih);

    return 0;
}

// Fungsi untuk memasukkan tanggal
void inputTanggal(Tanggal &tgl) {
    cout << "Hari: ";
    cin >> tgl.hari;
    cout << "Bulan: ";
    cin >> tgl.bulan;
    cout << "Tahun: ";
    cin >> tgl.tahun;
}

// Fungsi untuk menghitung selisih antara dua tanggal
void selisihTanggal(Tanggal tglAwal, Tanggal tglAkhir, Tanggal &selisih) {
    // Menghitung selisih hari, bulan, dan tahun
    selisih.tahun = tglAkhir.tahun - tglAwal.tahun;
    selisih.bulan = tglAkhir.bulan - tglAwal.bulan;
    selisih.hari = tglAkhir.hari - tglAwal.hari;

    // Mengatasi hasil yang negatif
    if (selisih.hari < 0) {
        selisih.hari += 30; // Anggap setiap bulan adalah 30 hari
        selisih.bulan--;
    }
    if (selisih.bulan < 0) {
        selisih.bulan += 12; // 12 bulan dalam setahun
        selisih.tahun--;
    }
}

// Fungsi untuk menampilkan tanggal
void cetakTanggal(Tanggal tgl) {
    cout << tgl.hari << " Hari " << tgl.bulan << " Bulan " << tgl.tahun << " Tahun" << endl;
}
