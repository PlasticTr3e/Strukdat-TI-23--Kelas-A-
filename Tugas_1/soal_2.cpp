/* Nama program : soal_2
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 01/03/2024
   Deskripsi    : Memecahkan masalah menjadi beberapa fungsi antara lain : fungsi input, fungsi faktorial, fungsi 
                  permutasi / kombinasi, fungsi output, dan fungsi utama (main).
*********************************************/
#include <iostream>

using namespace std;

//Input kombinasi dan permutasi
void input_nr(int &n, int &r)
{
    cout << "Masukkan N: ";
    cin >> n;
    cout << "Masukkan R: ";
    cin >> r;
}

//Input faktorial
void input_factorial(int &n){
    cout << "Faktorial: ";
    cin >> n;
}

//Fungsi faktorial
int factorial(int n)
{
    int factorial_n = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial_n *= i;
    }
    return factorial_n;
}

//Fungsi permutasi
int permutasi(int n, int r)
{
    // n! ?
    int factorial_n = factorial(n);

    //(n - r)! ?
    int factorial_nr = factorial(n - r);

    // n!/(n - r)! ?
    return (factorial_n / factorial_nr);
}

//Fungsi kombinasi
int kombinasi(int n, int r)
{
    // n! ?
    int factorial_n = factorial(n);

    // r! ?
    int factorial_r = factorial(r);

    //(n - r)! ?
    int factorial_nr = factorial(n - r);

    // n!/r!(n - r)! ?
    return (factorial_n / (factorial_r * factorial_nr));
}

//Fungsi cektas hasil
void cetakHasil(int input)
{
    cout << input << endl;
}

//Menu
void menu()
{
    int n, r;
    int input_user;
    cout << "1. Permutasi" << endl;
    cout << "2. Kombinasi" << endl;
    cout << "3. Faktorial" << endl;
    cout << "User input: ";
    cin >> input_user;
    switch (input_user)
    {
    case 1:
        input_nr(n, r);
        cetakHasil(permutasi(n, r));
        break;
    case 2:
        input_nr(n, r);
        cetakHasil(kombinasi(n, r));
        break;
    case 3:
        input_factorial(n);
        cetakHasil(factorial(n));

    default:
        menu();
        break;
    }
}

int main()
{
    menu();

    return 0;
}