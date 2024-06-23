/* Nama program : soal_3
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 14/03/2024
   Deskripsi    : program modular untuk melakukan penjumlahan dan perkalian 2 buah matriks.
**********************************************************************/

#include <iostream>

void inputArray(int arr_a[][3], int arr_b[][3]);
void perkalianMatriks(int arr_a[][3], int arr_b[][3]);
void penjumlahanMatriks(int arr_a[][3], int arr_b[][3]);
void cetakMatriks(int arr[][3]);

int main()
{
    int arr_a[3][3], arr_b[3][3];
    inputArray(arr_a, arr_b);
    perkalianMatriks(arr_a, arr_b);
    penjumlahanMatriks(arr_a, arr_b);

    return 0;
}

//Fungi input nilai matriks
void inputArray(int arr_a[][3], int arr_b[][3])
{
    std::cout << "Masukkan array_a (3x3): " << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> arr_a[i][j];
        }
    }
    std::cout << "Masukkan array_b (3x3): " << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> arr_b[i][j];
        }
    }
}

//Fungsi mencetak matriks
void cetakMatriks(int arr[][3], int operasi)
{
    if (operasi == 1)
    {
        std::cout << "Hasil Perkalian: " << '\n';
    }
    else if (operasi == 2)
    {
        std::cout << "Hasil penjumlahan: " << '\n';
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//Fungsi perkalian matriks
void perkalianMatriks(int arr_a[][3], int arr_b[][3])
{
    int result[3][3];
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum += arr_a[i][k] * arr_b[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
    cetakMatriks(result, 1);
}

//Fungsi penjumlahan matriks
void penjumlahanMatriks(int arr_a[][3], int arr_b[][3])
{
    int result[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = arr_a[i][j] + arr_b[i][j];
        }
    }
    cetakMatriks(result, 2);
}
