/* Nama program : soal2.cpp
   Nama         : Fakhri Syawaludin
   NPM          : 140810230033
   Tanggal buat : 25/04/2024
   Deskripsi    : Tugas semua primitif list
**********************************************************************/


#include <iostream>
#include <string>
using namespace std;

struct Dosen
{
    string NIP;
    string nama;
    int golongan;
};

struct Node
{
    Dosen dataDosen;
    Node* next;
};

typedef Node* PointerToNode;
typedef PointerToNode List;

void CreateHead(List& head)
{
    head = nullptr;
}

void CreateNode(PointerToNode& newNode)
{
    newNode = new Node;
    cout << "Masukkan NIP       :  ";
    cin >> newNode->dataDosen.NIP;
    cout << "Masukkan Nama      :  ";
    cin.ignore();
    getline(cin, newNode->dataDosen.nama);
    cout << "Masukkan Golongan  :  ";
    cin >> newNode->dataDosen.golongan;
    newNode->next = nullptr;
}

void InsertFirst(List& head, PointerToNode newNode)
{
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void InsertBefore(List& head, PointerToNode newNode, string key)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->dataDosen.NIP == key)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    PointerToNode pHelp = head;
    while (pHelp->next != nullptr && pHelp->next->dataDosen.NIP != key)
    {
        pHelp = pHelp->next;
    }
    if (pHelp->next != nullptr)
    {
        newNode->next = pHelp->next;
        pHelp->next = newNode;
    }
}

void DeleteAndSearch(List& head, string value)
{
    PointerToNode prev = nullptr;
    PointerToNode pHelp = head;
    while (pHelp != nullptr && pHelp->dataDosen.NIP != value)
    {
        prev = pHelp;
        pHelp = pHelp->next;
    }
    if (pHelp == nullptr)
    {
        cout << "Elemen dengan nilai " << value << " tidak ditemukan." << endl;
        return;
    }
    if (prev != nullptr)
    {
        prev->next = pHelp->next;
    }
    else
    {
        head = pHelp->next;
    }
    cout << "Elemen dengan nilai " << value << " ditemukan dan dihapus." << endl;
    delete pHelp;
}

void DeleteFirst(List& head)
{
    PointerToNode ptrHelp;
    ptrHelp = head;
    if (head == nullptr)
    {
        return;
    }
    else
    {
        head = ptrHelp->next;
        ptrHelp = nullptr;
        delete ptrHelp;
    }
}

string GolonganGaji(int gol)
{
    string gaji;
    if (gol == 1)
    {
        gaji = "2.5 juta";
    }
    else if (gol == 2)
    {
        gaji = "3.5 juta";
    }
    else if (gol == 3)
    {
        gaji = "5 juta";
    }
    else if (gol == 4)
    {
        gaji = "7.5 juta";
    }
    return gaji;
}

void Traversal(List head)
{
    PointerToNode pHelp;
    int no = 1;
    string gaji;
    if (head == nullptr)
    {
        return;
    }
    else
    {
        pHelp = head;
        cout << "NO\tNIP\tNama\t\t\tGol\tGaji\n";
        cout << "-------------------------------------------------------------\n";
        do
        {
            gaji = GolonganGaji(pHelp->dataDosen.golongan);
            cout << no << "\t" << pHelp->dataDosen.NIP << "\t" << pHelp->dataDosen.nama << "\t\t" << pHelp->dataDosen.golongan << "\t" << gaji << "\n";
            no++;
            pHelp = pHelp->next;
        } while (pHelp != nullptr);
        cout << "-------------------------------------------------------------\n";
    }
}

int main()
{
    string key;
    PointerToNode head = nullptr;
    List newNode;

    int choice;
    bool menu = true;

    while (menu)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Create List" << endl;
        cout << "2. Create Element" << endl;
        cout << "3. Insert First" << endl;
        cout << "4. Insert Before" << endl;
        cout << "5. Delete First" << endl;
        cout << "6. Delete and Search" << endl;
        cout << "7. Traversal" << endl;
        cout << "0. Exit" << endl;

        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            CreateHead(head);
            cout << "List berhasil dibuat" << endl;
            break;
        case 2:
            CreateNode(newNode);
            cout << "Elemen berhasil dibuat" << endl;
            break;
        case 3:
            InsertFirst(head, newNode);
            cout << "Elemen berhasil disisipkan di depan" << endl;
            break;
        case 4:
            cout << "Akan dimasukkan ke sebelum NIP ke: ";
            cin >> key;
            InsertBefore(head, newNode, key);
            break;
        case 5:
            DeleteFirst(head);
            cout << "Elemen pertama berhasil dihapus" << endl;
            break;
        case 6:
            cout << "Masukkan kunci yang akan dicari: ";
            cin >> key;
            DeleteAndSearch(head, key);
            break;
        case 7:
            Traversal(head);
            break;
        default:
            menu = false;
        }
    }
    return 0;
}
