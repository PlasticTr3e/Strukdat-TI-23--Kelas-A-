/* Nama program : soal_2
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 01/04/2024
   Deskripsi    : List
**********************************************************************/

#include <iostream>
using namespace std;

struct Mahasiswa
{
    char NPM[8];
    char nama[20];
    int nilai;
    Mahasiswa* next;
};

typedef Mahasiswa* pointerToList;
typedef pointerToList list;

void createFirst(list &first){
    first = NULL;
}

void createList(list &node){
    node = new Mahasiswa;
    cout << "Masukkan Nama: "; cin >> node->nama;
    cout << "Masukkan NPM:  "; cin >> node->NPM;
    cout << "Masukkan nilai:"; cin >> node->nilai;
    node->next=NULL;
    cout << endl;
}

void trafersal(list first){
    pointerToList ptrBantu = first;
    while (ptrBantu != NULL)
    {
        cout << ptrBantu->nama << " " << ptrBantu->nilai << " " << ptrBantu ->NPM << endl;
        ptrBantu = ptrBantu->next;
    }
    cout << endl;
}

float average(list first){
    float jumlah, rata_rata;
    int n = 0;
    pointerToList ptrBantu = first;
    do
    {
        jumlah += ptrBantu->nilai;
        ptrBantu = ptrBantu->next;
        n++;
    } while (ptrBantu != NULL);
    rata_rata = jumlah / n;
    return rata_rata;
}

int main(){

    //Membentuk list
    list first, p1, p2, p3;
    createFirst(first);
    createList(p1);
    createList(p2);
    createList(p3);
    first = p1;
    p1->next = p2;
    p2->next = p3;

    trafersal(first);
    cout << "Nilai rata - rata: " << average(first) << endl;

    //Mencetak B dengan 2 cara
    cout << "Cara B 1:    " << p2->nama << " " << p2->nilai << " " << p2->NPM << endl;
    cout << "Cara B 2:    " << p1->next->nama << " " << p1->next->nilai << " " << p1->next->NPM << endl;

    //Mencetak C melalui p1
    cout << "Cetak C:     " <<p1->next->next->nama << " " << p1->next->next->nilai << " " << p1->next->next->NPM << endl;


    return 0;
}