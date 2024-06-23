/* Nama program : soal_1
   Nama         : Bagas Diatama Wardoyo
   NPM          : 140810230061
   Tanggal buat : 14/03/2024
   Deskripsi    : program modular untuk mengolah suatu kumpulan data bertipe Array of Integer
**********************************************************************/

#include <iostream>

using namespace std;

void inputData(int arr[], int n);
int nilaiTertinggi(int arr[], int n);
int nilaiTerendah(int arr[], int n);
void sorting(int arr[], int n);
void swap(int& a, int& b);
void searching(int arr[], int n, int key);
void outputData(int arr[], int n);


int main(){
    int n, key;
    cout << "Banyak data: "; cin >> n;
    int arr [n];
    inputData(arr, n);
    cout << "Nilai tertinggi: " << nilaiTertinggi(arr, n) << endl;
    cout << "Nilai terendah: " << nilaiTerendah(arr, n) << endl;
    cout << "Nilai disorting: "; 
    sorting(arr, n);
    outputData(arr, n);
    cin >> key;
    searching(arr, n, key);

    return 0;
}

//Fungsi input data
void inputData(int arr[], int n){
    cout << "Masukkan Data: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

//Fungsi mencari nilai tertinggi
int nilaiTertinggi(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

//Fungsi mencari nilai terendah
int nilaiTerendah(int arr[], int n){
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

//Fungis untuk melakukan swap dalam sorting
void swap(int&a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

//Fungsi sorting
void sorting(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + i < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
            }
            
        }
        
    }
    
}

//Fungsi untuk menampilkan data
void outputData(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Fungsi unutk mencari data
void searching(int arr[], int n, int key){
    string found;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = "ditemukan";
            break;
        }else{

            found = "tidak ditemukan";
        }
    }
    cout << found;
}