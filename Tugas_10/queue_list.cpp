/* Nama program : queue_list
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 13/05/2024
   Deskripsi    : queue (Linked List)
**********************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct pegawai
{
    string NIP;
    string nama;
    int golongan;
};

struct node
{
    pegawai data;
    node *next;
};

typedef node *Pointer;
typedef Pointer List;

struct Queue
{
    List Head;
    List Tail;
};

Queue Q;

void createList(Queue &Q);
void createElement(List &newNode);
void inQueue(Queue &Q, Pointer newNode);
void deQueue(Queue &Q, Pointer &pHapus);
int gajiGolongan(int golongan);
int average(Queue Q);
int MAXGaji(Queue Q);
int MINGaji(Queue Q);
void traversal(Queue Q);

int main()
{
    Pointer pHapus;
    List newNode;

    createList(Q);

    int choice;

    do
    {
        cout << "\n==============Main Menu==============\n";
        cout << "1. Tambah Pegawai\n";
        cout << "2. Tampilkan Data Pegawai dan Rata-rata Gaji\n";
        cout << "3. Hapus Data Pegawai\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createElement(newNode);
            inQueue(Q, newNode);
            cout << "Pegawai berhasil ditambahkan!\n";
            break;
        case 2:
            traversal(Q);
            break;
        case 3:
            deQueue(Q, pHapus);
            cout << "Pegawai dengan NIP " << pHapus->data.NIP << " telah dihapus!\n";
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

void createList(Queue &Q)
{
    Q.Head = nullptr;
    Q.Tail = nullptr;
}

void createElement(List &newNode)
{
    newNode = new node;
    cout << "NIP          :    ";
    cin >> newNode->data.NIP;
    cout << "Nama         :    ";
    cin >> newNode->data.nama;
    cout << "Golongan     :    ";
    cin >> newNode->data.golongan;
    newNode->next = nullptr;
}

void inQueue(Queue &Q, Pointer newNode)
{
    if (Q.Head == nullptr)
    {
        Q.Head = newNode;
        Q.Tail = newNode;
    }
    else
    {
        Q.Tail->next = newNode;
        Q.Tail = newNode;
    }
}

void deQueue(Queue &Q, Pointer &pHapus)
{
    if (Q.Head == nullptr)
    {
        cout << "List kosong! Tidak ada data yang bisa dihapus.\n";
        pHapus = nullptr;
        return;
    }
    else if (Q.Head == Q.Tail)
    {
        pHapus = Q.Head;
        Q.Head = nullptr;
        Q.Tail = nullptr;
    }
    else
    {
        pHapus = Q.Head;
        Q.Head = Q.Head->next;
    }
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
    if (Q.Head == nullptr)
    {
        return 0;
    }
    else
    {
        int banyakData = 0;
        int totalGaji = 0;
        Pointer temp = Q.Head;
        do
        {
            banyakData++;
            totalGaji += gajiGolongan(temp->data.golongan);
            temp = temp->next;
        } while (temp != nullptr);
        return totalGaji / banyakData;
    }
}

int MAXGaji(Queue Q)
{
    int Max = 0;
    if (Q.Head == nullptr)
    {
        return 0;
    }
    else
    {
        Pointer temp = Q.Head;
        do
        {
            if (Max < gajiGolongan(Q.Head->data.golongan))
            {
                Max = gajiGolongan(Q.Head->data.golongan);
            }
            // Q.Head = Q.Head->next;
            temp = temp->next;

        } while (temp != nullptr);
    }
    return Max;
}

int MINGaji(Queue Q)
{
    int Min = INT32_MAX;
    if (Q.Head == nullptr)
    {
        return 0;
    }
    else
    {
        Pointer temp = Q.Head;
        do
        {
            if (Min > gajiGolongan(Q.Head->data.golongan))
            {
                Min = gajiGolongan(Q.Head->data.golongan);
            }
            // Q.Head = Q.Head->next;
            temp = temp->next;

        } while (temp != nullptr);
    }
    return Min;
}

void traversal(Queue Q)
{
    Pointer pHelp = Q.Head;
    int gaji;
    int n = 0;
    cout << "======================================================" << endl;
    cout << "NO\tNIP\tNama\tGolongan\tGaji" << endl;
    cout << "======================================================" << endl;

    do
    {
        n++;
        gaji = gajiGolongan(pHelp->data.golongan);
        cout << n << "\t" << pHelp->data.NIP << "\t" << pHelp->data.nama << "\t" << pHelp->data.golongan << "\t\t" << gaji << endl;
        pHelp = pHelp->next;
    } while (pHelp != nullptr);

    cout << "======================================================" << endl;
    cout << "Rata-rata Gaji  :  " << average(Q) << endl;
    cout << "Gaji Tertinggi  :  " << MAXGaji(Q) << endl;
    cout << "Gaji Terendah   :  " << MINGaji(Q) << endl;
}