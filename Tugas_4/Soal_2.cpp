/* Nama program : soal_2
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 30/03/2024
   Deskripsi    : Kerjakan soal diatas, buatlah gambaran keadaan memori (address dan content). 
Beri penjelasan dari setiap perintah.
**********************************************************************/
#include <iostream>
using namespace std;

main()
{
    int n = 1;      //Deklarasi variabel betipe int n = 1
    int *p = &n;    //Deklarasi variabel bertipe int* p yang menunjuk alamat n
    int *q;         //Deklarasi variabel bertipe int* q
    int *r;         //Deklarasi variabel bertipe int* r
    int *s;         //Deklarasi variabel bertipe int* s
    cout << " n = " << n << " &n = " << &n << endl; //n = enampilkan value dari n, &n = menampilkan alamat n
    cout << " p = " << p << " *p = " << *p << endl; //p = menampilkan alamat yang ditunjuk pointer p, *p = menampilkan value dari alamat yang ditunjuk pointer p yaitu n
    cout << "&p = " << &p << " &(*p)= " << &(*p) << endl; //&p = menampilkan alamat pointer p, &(*p) = menampilkan alamat dari value yang ditunjuk pointer p (&n)
    q = new int; //alokasi memori bertipe int yang ditunjuk pointer p
    *q = 2;      //alamat yang dialokasikan akan menyimpan value 2
    cout << " q = " << q << " *q = " << *q << endl; //q = menampilkan alamat yang ditunjuk pointer q, *q = menampilkan value dari alamat yang ditunjuk pointer q yaitu 2
    cout << " &q = " << &q << " &(*q)= " << &(*q) << endl; //&q = menampilkan alamat memori pointer q, &(*q) = menampilkan alamat dari value yang ditunjuk pointer q (new int)
    // delete(q) // apa yg terjadi ?? alokasi memori dengan kata kunci "new" akan dihapus
    r = new int; //alokasi memori bertipe int yang ditunjuk pointer r
    *r = 3;      //alamat yang dialokasikan akan menyimpan value 3
    cout << " r = " << r << " *r = " << *r << endl; //r = menampilkan alamat yang ditunjuk pointer r, *r = menampilkan value dari alamat yang ditunjuk pointer r yaitu 3
    cout << " &r = " << &r << " &(*r) = " << &(*r) << endl; //&r = menampilkan alamat memori pointer q, &(*r) = menampilkan alamat dari value yang ditunjuk pointer r (new int)
    s = q;  //pointer s menunjuk pointer value dari pointer q yang merupkan alokasi memori bertipe int (new int)
    *s = 4; //menyimpan value 4 kedalam memori yang ditunjuk pointer s (q)
    cout << " q = " << q << " *q = " << *q << endl; //q = menampilkan alamat yang ditunjuk pointer q, *q = menampilkan value dari alamat yang ditunjuk pointer q yaitu 4
    cout << " s = " << s << " *s = " << *s << endl; //s = menampilkan alamat yang ditunjuk pointer s, *s = menampilkan value dari alamat yang ditunjuk pointer s yaitu 4    
    cout << " &q = " << &q << " &s = " << &s << endl; //&q = menampilkan alamat dari pointer q, &s = menampilkan alamat dari pointer s
}
