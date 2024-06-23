/* Nama program : Stack_LinkedList
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 10/05/2024
   Deskripsi    : stack (Linked List)
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
typedef Pointer Stack;

void createStack(Stack &Top);
void createElement(Stack &newNode);
void push(Stack &Top, Pointer newNode);
void pop(Stack &Top, Pointer &pHapus);
int gajiGolongan(int golongan);
int average(Stack Top);
int MAXGaji(Stack Top);
int MINGaji(Stack Top);
void traversal(Pointer Top);

int main()
{
   Pointer Top, pHapus;
   Stack newNode;

   createStack(Top);

   int choice;

   do
   {
      cout << "\n**Main Menu**\n";
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
         push(Top, newNode);
         cout << "Pegawai berhasil ditambahkan!\n";
         break;
      case 2:
         traversal(Top);
         break;
      case 3:
         pop(Top, pHapus);
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

void createStack(Stack &Top)
{
   Top = nullptr;
}

void createElement(Stack &newNode)
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

void push(Stack &Top, Pointer newNode)
{
   if (Top == nullptr)
   {
      Top = newNode;
   }
   else
   {
      newNode->next = Top;
      Top = newNode;
   }
}

void pop(Stack &Top, Pointer &pHapus)
{
   if (Top == nullptr)
   {
      cout << "Stack kosong! Tidak ada data yang bisa dihapus.\n";
      pHapus = nullptr;
      return;
   }
   else
   {
      pHapus = Top;
      Top = Top->next;
      pHapus->next = nullptr;
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

int average(Stack Top)
{
   if (Top == nullptr)
   {
      return 0;
   }
   else
   {
      int banyakData = 0;
      int totalGaji = 0;
      Pointer temp = Top;
      do
      {
         banyakData++;
         totalGaji += gajiGolongan(temp->data.golongan);
         temp = temp->next;
      } while (temp != nullptr);
      return totalGaji / banyakData;
   }
}

int MAXGaji(Stack Top)
{
   int Max = 0;
   if (Top == nullptr)
   {
      return 0;
   }
   else
   {
      Pointer temp = Top;
      do
      {
         if (Max < gajiGolongan(Top->data.golongan))
         {
            Max = gajiGolongan(Top->data.golongan);
         }
         Top = Top->next;
         temp = temp->next;

      } while (temp != nullptr);
   }
   return Max;
}

int MINGaji(Stack Top)
{
   int Min = INT32_MAX;
   if (Top == nullptr)
   {
      return 0;
   }
   else
   {
      Pointer temp = Top;
      do
      {
         if (Min > gajiGolongan(Top->data.golongan))
         {
            Min = gajiGolongan(Top->data.golongan);
         }
         Top = Top->next;
         temp = temp->next;

      } while (temp != nullptr);
   }
   return Min;
}

void traversal(Pointer Top)
{
   Pointer pHelp = Top;
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
   cout << "Rata-rata Gaji  :  " << average(Top) << endl;
   cout << "Gaji Tertinggi  :  " << MAXGaji(Top) << endl;
   cout << "Gaji Terendah   :  " << MINGaji(Top) << endl;
}