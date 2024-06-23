/* Nama program : soal_3
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 01/03/2024
   Deskripsi    : Menentukan dan menjelaskan hasil dan langkah - langkah dari program di bawah ini
*********************************************/
#include <iostream>
using namespace std;

void fungsi(int a, int &b, int &c)
{
    b = ++a;
    c += --b;
    a--;
    cout << a << " " << b << " " << c << endl;
    /*  Pemanggilan pertama
    Diberikan a = c(2) sebagai value kemudian b = a(2), dan c = b(2) sebagai reference
    kemudian:
    b = ++a; artinya a mengalami penambahan 1 (pre increment) sehingga a = 3, kemudian b = a / b = 3;
    c += --b; artinya b mengalami pemgurangan 1 (pre decrement ) sehingga b = 2, kemudian ditambahkan dengan c; c = c + b / c = 2 + 2 = 4;
    a--; artinya a mengalami pengurangan 1 (post decrement) sehingga a = 2;
    variabel a, b, dan c kemudian di tampilkan dalam konsol [2 2 4]
        Pemanggilan kedua
    Diberikan a = a(2) + b(4) sebagai value, b = c(2), dan c = y(2) sebagai reference
    Kemudian:
    b = ++a; artinya a mengalami penambahan 1 (pre increment) sehingga a = 7, kemudian b = a / b = 7;
    c += --b; artinya b mengalami pemgurangan 1 (pre decrement ) sehingga b = 6, kemudian ditambahkan dengan c; c = c + b / c = 2 + 6 = 8;
    a--; artinya a mengalami pengurangan 1 (post decrement) sehingga a = 6;
    variabel a, b, dan c kemudian di tampilkan dalam konsol [6 6 8]
    */
}
main()
{
    int a = 2, c = 2, b = 2, y = 2;
    fungsi(c, a, b);//pemanggilan fungsi pertama, hasil [2 2 4]
    cout << a << " " << b << " " << c << endl;//hasil [2 4 2], variabel a dan b akan memiliki nilai yang sama dengan variabel yang diberikkan referencenya pada fungsi pemanggilan pertama, dalam hal ini a = b, dan b = c;
    fungsi(a + b, c, y);//pemanggilan fungsi kedua, hasil [6 6 8]
    cout << a << " " << b << " " << c << endl;//hasil [2 4 6], vvariabel c akan memiliki nilai yang sama dengan variabel yang diberikkan referencenya pada fungsi pemanggilan kedua, dalam hal ini c = b;
}