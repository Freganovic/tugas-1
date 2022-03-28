#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include <fstream>
#include <conio.h>
#define  n 1000

using namespace std;




struct mahasiswa{
	
	
    string type;
    string kerusakan;
    string modal;
    string harga;
    
   
    int num;
}Mhs[n];

struct queue{
    int awal, akhir;
}Queue;

void deQueue();
void menu();
void inQueue();
void tampil();

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil di reset" << endl;
    menu();
}

bool isFull(){
    if(Queue.akhir == n - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
    if(Queue.akhir == -1){
        return true;
    }else {
        return false;
    }
}

void inQueue(){
    if(!isFull()){
	
    string type;
	string kerusakan;
	string modal;
	string harga;
	
   	
        cout << "Masukkan type handphone: ";
        cin >> type;
        cout << "Masukkan kerusakan:";
        cin >> kerusakan;
        cout << "Masukan modal:";
        cin >> modal;
        cout << "Masukan harga user:";
        cin >> harga;
        
    
	 	

	 
	 
        Mhs[Queue.akhir].type = type;
        Mhs[Queue.akhir].kerusakan = kerusakan;
        Mhs[Queue.akhir].modal = modal;
        Mhs[Queue.akhir].harga = harga;
        
        
        ++Queue.akhir;
        cout <<"Data Tersimpan";
        cout << endl;
        cout <<endl;
        menu();
    }else {
        cout << "Data penuh";
        menu();
    }
}

void menu(){
    int pilih;
    cout << "1. masukkan data\n";
    cout << "2. Hapus satu data\n";
    cout << "3. Reset data\n";
    cout << "4. tampil data\n";
    cout << "Masukkan pilihan anda:";
    cin >> pilih;
    cout << endl;
    if(pilih == 1){
        inQueue();
    }else if(pilih == 2){
        deQueue();
    } else if(pilih == 3){
        init();
    }else if(pilih == 4){
        tampil();
    }else {
        menu();
    }
}

void deQueue(){
    if(!isEmpty()){
        for(int i = Queue.awal; i < Queue.akhir; i++){
            Mhs[i].type = Mhs[i+1].type;
            Mhs[i].kerusakan = Mhs[i+1].kerusakan;
            Mhs[i].modal = Mhs[i+1].modal;
        }Queue.akhir--;
        cout << "Data berhasil dihapus" << endl;
        cout << endl;
        menu();
    }else{
        cout << "antrian kosong" << endl;
    }
}

void tampil(){
	
	ofstream MyFile("Data Pembukuan bulan february.txt");
	
    if(!isEmpty()){
        for(int i = 0; i < Queue.akhir; i++){
       
	    cout << " Data " <<endl;	
	cout <<" " <<Mhs[i].type << " "<<Mhs[i].kerusakan<<" "<<Mhs[i].modal <<" "<<Mhs[i].harga << endl;
	MyFile<<" " <<Mhs[i].type <<" " <<Mhs[i].kerusakan<<" " <<Mhs[i].modal<<endl;
	cout << endl;
	
        }
    }else {
        cout << "data kosong";
        cout << endl << endl;
    }
    menu();
}

int main(){
    menu();

    return 0;
}


