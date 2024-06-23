/* Nama program : soal_2
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 14/03/2024
   Deskripsi    : program modular untuk mencari jumlah dari setiap baris dan kolom suatu matriks. 
**********************************************************************/

#include <iostream>

using namespace std;

void inputMatriks(int arr[][3]);
void sumMatriks_baris(int arr[][3]);
void sumMatriks_kolom(int arr[][3]);

int main()
{
    int matriks[3][3];
    inputMatriks(matriks);
    cout << endl;
    sumMatriks_baris(matriks);
    cout << endl;
    sumMatriks_kolom(matriks);

    return 0;
}

//Fungsi input matriks
void inputMatriks(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
}

//Fungsi untuk menjumlahkan setiap baris matriks
void sumMatriks_baris(int arr[][3])
{
    int sumBaris[]{0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumBaris[i] += arr[i][j];
        }
    }
    for (int n : sumBaris)
    {
        cout << n << endl;
    }
}

//Fungsi untuk menjumlahkan setiap kolom matriks
void sumMatriks_kolom(int arr[][3])
{
    int sumBaris[]{0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumBaris[i] += arr[j][i];
        }
    }
    for (int n : sumBaris)
    {
        cout << n << endl;
    }
}