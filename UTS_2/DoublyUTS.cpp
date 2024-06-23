#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string NPM, nama;
    int nilai;
};

struct NodeMhs {
    Mahasiswa info;
    NodeMhs* next;
    NodeMhs* prev;
};

typedef NodeMhs* Pointer;

void createHead(Pointer& head) {
    head = nullptr;
}

void createElement(Pointer& newElement) {
    newElement = new NodeMhs;
    cout << "Masukkan NPM   :   "; cin >> newElement->info.NPM;
    cout << "Masukkan nama  :   "; cin >> newElement->info.nama;
    cout << "Masukkan nilai :   "; cin >> newElement->info.nilai;
    newElement->next = nullptr;
    newElement->prev = nullptr;
    cout << endl;
}

void insertLast(Pointer newNode, Pointer &Head) {
    if (Head == nullptr) {
        Head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Pointer Last = Head->prev;
        Last->next = newNode;
        newNode->prev = Last;
        newNode->next = Head;
        Head->prev = newNode;
    }
}

void deleteFirst(Pointer &Head, Pointer &pHapus) {
    if (Head == nullptr) {
        cout << "Tidak ada data untuk dihapus" << endl;
    } else if (Head->next == Head) {
        pHapus = Head;
        Head = nullptr;
    } else {
        Pointer Last = Head->prev;
        pHapus = Head;
        Head = Head->next;
        Head->prev = Last;
        Last->next = Head;
    }
    pHapus->next = nullptr;
    pHapus->prev = nullptr;
}

void rataRata(Pointer Head) {
    if (Head == nullptr) {
        cout << "Tidak ada data" << endl;
        return;
    }
    Pointer Help = Head;
    float sum = 0;
    int count = 0;
    do {
        sum += Help->info.nilai;
        count++;
        Help = Help->next;
    } while (Help != Head);
    float average = sum / count;
    cout << "Rata-rata nilai mahasiswa adalah :" << average << endl;
}

void HM_Status(int nilai) {
    if (nilai >= 80 && nilai <= 100) {
        cout << "A\tLulus" << endl;
    } else if (nilai >= 68 && nilai < 80) {
        cout << "B\tLulus" << endl;
    } else if (nilai >= 55 && nilai < 68) {
        cout << "C\tLulus" << endl;
    } else if (nilai >= 45 && nilai < 55) {
        cout << "D\tTidak Lulus" << endl;
    } else {
        cout << "E\tTidak Lulus" << endl;
    }
}

void traversal(Pointer Head) {
    if (Head == nullptr) {
        cout << "Tidak ada data" << endl;
        return;
    }
    Pointer Help = Head;
    cout << "NPM\tNama\tNilai\tHM\tStatus" << endl;
    cout << "==================================================" << endl;
    do {
        cout << Help->info.NPM << "\t" << Help->info.nama << "\t" << Help->info.nilai << "\t"; HM_Status(Help->info.nilai);
        Help = Help->next;
    } while (Help != Head);
    cout << "==================================================" << endl;
    rataRata(Head);
}

int main() {
    Pointer Head, pHapus, newNode;
    createHead(Head);
    int n;
    cout << "Masukkan jumlah mahasiswa yang akan diinput : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        createElement(newNode);
        insertLast(newNode, Head);
    }
    traversal(Head);
    return 0;
}
