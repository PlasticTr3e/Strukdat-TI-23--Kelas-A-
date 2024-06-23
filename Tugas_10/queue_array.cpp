/* Nama program : queue_array
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 13/05/2024
   Deskripsi    : queue (Array)
**********************************************************************/
#include <iostream>
#include <string>

using namespace std;

const int maxElement = 255;

struct pegawai
{
    string nama;
    string NIP;
    int golongan;
};

struct Queue
{
    pegawai data[maxElement];
    int head;
    int tail;
};

Queue Q;

void createQueue(Queue &Q);
void createElement(pegawai &data);
int gajiGolongan(int golongan);
int average(Queue Q);
int MAXGaji(Queue Q);
int MINGaji(Queue Q);
void inQueue(Queue &Q, pegawai data);
void deQueue(Queue &Q, pegawai &deletePegawai);
void traversal(Queue Q);

int main()
{
    pegawai newPegawai, deletePegawai;

    createQueue(Q);

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
            inQueue(Q, newPegawai);
            cout << "Pegawai berhasil ditambahkan!\n";
            break;
        case 2:
            traversal(Q);
            break;
        case 3:
            deQueue(Q, deletePegawai);
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

void createQueue(Queue &Q)
{
    Q.head = 0;
    Q.tail = -1;
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

int average(Queue Q)
{
    if (Q.tail == -1)
    {
        return -1;
    }
    else
    {

        int banyakData = Q.tail + 1;
        int totalGaji = 0;
        for (int i = 0; i < banyakData; i++)
        {
            totalGaji += gajiGolongan(Q.data[i].golongan);
        }
        return totalGaji / banyakData;
    }
}

int MAXGaji(Queue Q)
{
    if (Q.tail == -1)
    {
        return -1;
    }
    else
    {
        int Max = 0;
        int gaji;
        int banyakData = Q.tail + 1;
        for (int i = 0; i < banyakData; i++)
        {
            gaji = gajiGolongan(Q.data[i].golongan);
            if (Max < gaji)
            {
                Max = gaji;
            }
        }

        return Max;
    }
}

int MINGaji(Queue Q)
{
    if (Q.tail == -1)
    {
        return -1;
    }
    else
    {
        int Min = INT32_MAX;
        int gaji;
        int banyakData = Q.tail + 1;
        for (int i = 0; i < banyakData; i++)
        {
            gaji = gajiGolongan(Q.data[i].golongan);
            if (Min > gaji)
            {
                Min = gaji;
            }
        }

        return Min;
    }
}

void inQueue(Queue &Q, pegawai data)
{
    if (Q.tail == maxElement - 1)
    {
        cout << "List sudah penuh" << endl;
        return;
    }
    else
    {
        Q.tail = Q.tail + 1;
        Q.data[Q.tail] = data;
    }
}

void deQueue(Queue &Q, pegawai &deletePegawai)
{
    if (Q.tail == -1)
    {
        cout << "Tidak ada pegawai yang dapat dihapus" << endl;
    }
    else
    {
        deletePegawai = Q.data[Q.tail];
        for (int i = 0; i < Q.tail; i++)
        {
            Q.data[i] = Q.data[i + 1];
        }
        Q.tail--;
    }
}

void traversal(Queue Q)
{
    int banyakElement = Q.tail + 1;
    int n = 0;
    int gaji = 0;
    cout << "======================================================" << endl;
    cout << "NO\tNIP\tNama\tGolongan\tGaji" << endl;
    cout << "======================================================" << endl;
    for (int i = 0; i < banyakElement; i++)
    {
        n++;
        gaji = gajiGolongan(Q.data[i].golongan);
        cout << n << "\t" << Q.data[i].NIP << "\t" << Q.data[i].nama << "\t" << Q.data[i].golongan << "\t\t" << gaji << endl;
    }
    cout << "======================================================" << endl;
    cout << "Rata-rata Gaji  :  " << average(Q) << endl;
    cout << "Gaji Tertinggi  :  " << MAXGaji(Q) << endl;
    cout << "Gaji Terendah   :  " << MINGaji(Q) << endl;
}
