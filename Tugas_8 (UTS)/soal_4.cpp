/* Nama program : Soal_4
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 05/05/2024
   Deskripsi    : Data pegawai UTS
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

// Membuat head
void createHead(Pointer &head)
{
    head = nullptr;
}

// Membuat element baru
void createElement(List &newNode)
{
    newNode = new node;
    cout << "NIP          :    ";
    cin >> newNode->data.NIP;
    cout << "Nama         :    ";
    cin >> newNode->data.nama;
    cout << "Golongan     :    ";
    cin >> newNode->data.golongan;
}

// Fungsi pencarian dengan kata kunci NIP
void searching(Pointer head, Pointer &pCari, Pointer &prev, string key)
{
    pCari = head;
    prev = nullptr;

    while (pCari != nullptr)
    {
        if (pCari->data.NIP == key)
        {
            return; // Key ditemukan
        }
        prev = pCari;
        pCari = pCari->next;
    }

    pCari = nullptr; // Kunci tidak ditemukan
}

// Fungsi untuk meninsert list ke data sebelum, berdasarkan kata kunci
void insertBefore(Pointer &head, Pointer pCari, Pointer prev, List newNode)
{
    if (head == nullptr) //jika list kosong
    {
        head = newNode;
    }
    else if (head == pCari || pCari == nullptr) // jiga pcari sama dengan head atau pcari tidak ditemukkan
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = pCari->next;
    }
}

// Fungsi menghitung gaji berdasarkan golongan
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

// Menampilkan list beserta rata rata gaji pegawai
void traversal(Pointer head)
{
    Pointer pHelp = head;
    int gaji, totalGaji = 0, average;
    int n = 0;
    cout << "======================================================" << endl;
    cout << "NO\tNIP\tNama\tGolongan\tGaji" << endl;
    cout << "======================================================" << endl;

    while (pHelp != nullptr)
    {
        n++;
        gaji = gajiGolongan(pHelp->data.golongan);
        totalGaji += gaji;
        cout << n << "\t" << pHelp->data.NIP << "\t" << pHelp->data.nama << "\t" << pHelp->data.golongan << "\t\t" << gaji << endl;
        pHelp = pHelp->next;
    }
    cout << "======================================================" << endl;
    average = (totalGaji > 0) ? totalGaji / n : 0; // fungsi menghitung rata rata gaji
    cout << "Rata-rata Gaji : " << average << endl;
}

int main()
{
    Pointer head, pCari, prev;
    List newNode;
    string key;

    createHead(head);

    for (int i = 0; i < 4; i++)
    {
        createElement(newNode);
        cout << "Masukkan Sebelum NIP   :   ";
        cin >> key;
        searching(head, pCari, prev, key);
        insertBefore(head, pCari, prev, newNode);
    }

    traversal(head);

    return 0;
}