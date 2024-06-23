/* Nama program : Soal_2
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 05/05/2024
   Deskripsi    : Hapus array UTS
**********************************************************************/
#include <iostream>

using namespace std;

struct arr
{
    int data[20];
    int n;
};

typedef arr LarikInt;

int deleteData(LarikInt &A, int &n, int x);
void inputData(LarikInt &A, int n);
void cetakData(LarikInt A, int n);

int main()
{
    int n, x;
    cout << "Masukkan Banyak Data   :   ";
    cin >> n;
    LarikInt array;
    inputData(array, n);
    cetakData(array, n);
    cout << "Input Data Yang Akan Dihapus   :   ";
    cin >> x;
    deleteData(array, n, x);
    cetakData(array, n);

    return 0;
}

void inputData(LarikInt &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Input Data ke-" << i + 1 << "  :   ";
        cin >> A.data[i];
    }
}
void cetakData(LarikInt A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A.data[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
int deleteData(LarikInt &A, int &n, int x)
{
    int index = 0;
    while (index < n && A.data[index] != x)
    {
        index++;
    }

    if (index == n)
    {
        return 0;
    }

    for (int i = index; i < n; i++)
    {
        A.data[i] = A.data[i + 1];
    }

    n--;

    return 1;
}