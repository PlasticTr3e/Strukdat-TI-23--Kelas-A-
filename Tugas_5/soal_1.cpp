/* Nama program : soal_1
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 01/04/2024
   Deskripsi    : Revisi kuis
**********************************************************************/

#include <iostream>
using namespace std;

//menyimpan informasi mahasiswa (NPM, nama, nilai)
struct Mahasiswa
{
    char NPM[8];
    char nama[20];
    int nilai;
};

//struktur data untuk node dalam linked list
struct node
{
    Mahasiswa dataMahasiswa;
    node *nextNode;
};

/*pointerToList: pointer yang menunjuk ke struktur node
list: alias untuk pointerToList, digunakan untuk menunjuk ke head dari linked list*/
typedef node* pointerToList;
typedef pointerToList list;

//menginisialisasi head dari linked list menjadi NULL
void createHead(list &head){
    head = new node;
    head->nextNode = nullptr;
}

/*membuat elemen baru (node) dan meminta input data mahasiswa (nama, NPM, nilai), 
lalu mengembalikan pointer ke elemen baru tersebut*/
void createList(list &newNode){
    newNode = new node;
    cout << "Masukkan Nama  :   "; cin >> newNode->dataMahasiswa.nama;
    cout << "Masukkan NPM   :   "; cin >> newNode->dataMahasiswa.NPM;
    cout << "Masukkan nilai :   "; cin >> newNode->dataMahasiswa.nilai;
    newNode->nextNode=nullptr;
    cout << endl;
}

//menampilkan seluruh elemen dalam linked list (head) dengan format tabel
void trafersal(pointerToList head){
    pointerToList ptrBantu = head;
    do
    {
        cout << "Nama   :   " << ptrBantu->dataMahasiswa.nama << endl;
        cout << "NPM    :   " << ptrBantu->dataMahasiswa.NPM << endl;
        cout << "NILAI  :   " << ptrBantu->dataMahasiswa.nilai << endl;
        cout << endl;
        ptrBantu = ptrBantu->nextNode;
    } while (ptrBantu != nullptr);
    
    cout << endl;
}

//menghitung dan mengembalikan nilai rata-rata nilai mahasiswa dalam linked list (head)
float average(pointerToList head){
    float jumlah, rata_rata;
    int n = 0;
    pointerToList ptrBantu = head;
    do
    {
        jumlah += ptrBantu->dataMahasiswa.nilai;
        ptrBantu = ptrBantu->nextNode;
        n++;
    } while (ptrBantu != nullptr);
    rata_rata = jumlah / n;
    return rata_rata;
}

int main(){

    //Membentuk list
    list head, p1, p2, p3; //Inisialisasi head, p1, p2, p3 sebagai pointer ke node
    createHead(head); //Memanggil createHead(head) untuk menginisialisasi head
    createList(p1);
    createList(p2); //Memanggil createList(p1), createList(p2), createList(p3) untuk membuat elemen baru dan menyimpannya di p1, p2, p3
    createList(p3);
    head = p1;
    p1->nextNode = p2;
    p2->nextNode = p3;

    trafersal(head);
    cout << "Nilai rata - rata  :   " << average(head) << endl;

    //Mencetak B dengan 2 cara
    cout << "Cara 1 cetak B (Lewat p2)   :   " << p2->dataMahasiswa.nama << " " << p2->dataMahasiswa.nilai << " " << p2->dataMahasiswa.NPM << endl;
    cout << "Cara 2 cetak B (Lewat p1)   :   " << p1->nextNode->dataMahasiswa.nama << " " << p1->nextNode->dataMahasiswa.nilai << " " << p1->nextNode->dataMahasiswa.NPM << endl;

    //Mencetak C melalui p1
    cout << "Cetak C    :   " <<p1->nextNode->nextNode->dataMahasiswa.nama << " " << p1->nextNode->nextNode->dataMahasiswa.nilai << " " << p1->nextNode->nextNode->dataMahasiswa.NPM << endl;


    return 0;
}