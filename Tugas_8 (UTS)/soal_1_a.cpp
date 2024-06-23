#include <iostream>
using namespace std;

void fungsi(int a, int &b, int &c)
{
    int y = 2;
    b = y + a; // b merupakan a dalam fungsi main sehingga b = 2 + 3;
    c += b; // c merupakan b dalam fungsi main maka c = c(3) + 5 (Melihat operasi sebelumnya)
    a--; // a merupakan c dalam fungsi main maka a = a(3) - 1;

    // setelah operasi di atas dijalankan maka outputnya akan menjadi 2, 5, 8, 3
    cout << a << ", " << b << ", " << c << ", " << y << endl;

}
main()
{
    int a = 3, c = 3, b = 3, y = 3;
    fungsi(c, a, b); // c = a, a = &b, dan b = &c;
    /*Fungsi di atas menghasilkan 2, 5, 8, 3. 
    Perlu di ingat bahwa a dan b menggunakan pass by referece 
    sehingga nilai a dan b dalam main akan berubah sesuai dengan apa yang terjadi di fugsi void.
    dalam hal ini a = 5 dan b = 8;
    */ 

    //Maka hasil output di bawah adalah 5, 8, 3, 3
    cout << a << ", " << b << ", " << c << ", " << y << endl;
}
