/* Nama program : Stack_Array
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 10/05/2024
   Deskripsi    : stack (Array)
**********************************************************************/
#include <iostream>
#include <string>

using namespace std;

const int maxElement = 256;

struct pegawai
{
    string nama;
    string NIP;
    int golongan;
};

struct node
{
    pegawai data[maxElement];
    int Top;
};

typedef node *Pointer;
typedef Pointer Stack;

void createStack(Stack &S); 
void createElement(pegawai &data); 
int gajiGolongan(int golongan);
int average(Stack S);
int MAXGaji(Stack S);
int MINGaji(Stack S);
void push(Stack &S, pegawai data);
void pop(Stack &S, pegawai &deletePegawai);
void traversal(Stack &S);

int main()
{
    pegawai newPegawai, deletePegawai;
    Stack Top;

    createStack(Top);

    int choice;

    do
    {
        cout << "\n=================Main Menu=================\n";
        cout << "1. Tambah Pegawai\n";
        cout << "2. Tampilkan Data Pegawai dan Rata-rata Gaji\n";
        cout << "3. Hapus Data Pegawai\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createElement(newPegawai);
            push(Top, newPegawai);
            cout << "Pegawai berhasil ditambahkan!\n";
            break;
        case 2:
            traversal(Top);
            break;
        case 3:
            pop(Top, deletePegawai);
            cout << "Pegawai dengan NIP " << deletePegawai.NIP << " telah dihapus!\n";
            break;
        case 4:
            cout << "Program Keluar\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

void createStack(Stack &S)
{
    S = new node;
    S->Top = -1;
}

void createElement(pegawai &data)
{
    cout << "NIP          :    ";
    cin >> data.NIP;
    cout << "Nama         :    ";
    cin >> data.nama;
    cout << "Golongan     :    ";
    cin >> data.golongan;
}

int gajiGolongan(int golongan)
{
    int gaji = 0;
    switch (golongan)
    {
    case 1:
        gaji = 3000000;
        break;
    case 2:
        gaji = 4000000;
        break;
    case 3:
        gaji = 5000000;
        break;
    default:
        gaji = 0;
        break;
    }
    return gaji;
}

int average(Stack S)
{
    if (S->Top == -1)
    {
        return -1;
    }
    else
    {

        int banyakData = S->Top + 1;
        int totalGaji = 0;
        for (int i = 0; i < banyakData; i++)
        {
            totalGaji += gajiGolongan(S->data[i].golongan);
        }
        return totalGaji / banyakData;
    }
}

int MAXGaji(Stack S)
{
    if (S->Top == -1)
    {
        return -1;
    }
    else
    {
        int Max = 0;
        int gaji;
        int banyakData = S->Top + 1;
        for (int i = 0; i < banyakData; i++)
        {
            gaji = gajiGolongan(S->data[i].golongan);
            if (Max < gaji)
            {
                Max = gaji;
            }
        }

        return Max;
    }
}

int MINGaji(Stack S)
{
    if (S->Top == -1)
    {
        return -1;
    }
    else
    {
        int Min = INT32_MAX;
        int gaji;
        int banyakData = S->Top + 1;
        for (int i = 0; i < banyakData; i++)
        {
            gaji = gajiGolongan(S->data[i].golongan);
            if (Min > gaji)
            {
                Min = gaji;
            }
        }

        return Min;
    }
}

void push(Stack &S, pegawai data)
{
    if (S->Top == maxElement - 1)
    {
        cout << "Stack sudah penuh" << endl;
        return;
    }
    else
    {
        S->Top = S->Top + 1;
        S->data[S->Top] = data;
    }
}

void pop(Stack &S, pegawai &deletePegawai)
{
    if (S->Top == -1)
    {
        cout << "Tidak ada pegawai yang dapat dihapus" << endl;
    }
    else
    {
        deletePegawai = S->data[S->Top];
        S->Top = S->Top - 1;
    }
}

void traversal(Stack &S)
{
    int banyakElement = S->Top + 1;
    int n = 0;
    int gaji = 0;
    cout << "======================================================" << endl;
    cout << "NO\tNIP\tNama\tGolongan\tGaji" << endl;
    cout << "======================================================" << endl;
    for (int i = banyakElement - 1; i >= 0; i--)
    {
        n++;
        gaji = gajiGolongan(S->data[i].golongan);
        cout << n << "\t" << S->data[i].NIP << "\t" << S->data[i].nama << "\t" << S->data[i].golongan << "\t\t" << gaji << endl;
    }
    cout << "======================================================" << endl;
    cout << "Rata-rata Gaji  :  " << average(S) << endl;
    cout << "Gaji Tertinggi  :  " << MAXGaji(S) << endl;
    cout << "Gaji Terendah   :  " << MINGaji(S) << endl;
}
