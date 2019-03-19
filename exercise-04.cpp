/*
Nama program			: Exercise
Nama					: Fadlan Mulya Priatna
NPM						: 140810180041
Tanggal pembuatan		: 19 Maret 2019
Deskripsi progrram		: program ini berisikan kodingan exercise strukdat praktikum 4
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct  pegawai{
    char nama[20];
    char divisi[10];
    int gaji;
    pegawai* next;
};

typedef pegawai* pointer;
typedef pointer List;

void createList (List& First){
	First = NULL;
}

void createElmt (pointer& pBaru){
	pBaru = new pegawai;
	cout<<"masukkan data pegawai"<<endl;
	cout<<"Nama lengkap\t: ";cin.ignore();cin.getline(pBaru->nama,20);
    cout<<"Divisi\t: ";cin>>pBaru->divisi;
    cout<<"Gaji\t: ";cin>>pBaru->gaji;
	pBaru->next = NULL;
}

void insertFirst (List& First, pointer pBaru){
	// I.S List First mungkin kosong dan pBaru sudah terdefinisi
	// F.S List bertambah satu elemn di depan dengan pBaru
	
	if (First == NULL){			//kasus kosong
		First=pBaru;
	}
	else {							//kasus ada isi
		pBaru->next=First;			//1
		First=pBaru;				//2
	}
}

void traversal(List First){
	//I.S List mungkin kosong
	//F.S Semua elemn list didatangi dan ditampilkan mulai dari elemen pertama
	pointer pBantu;
    pBantu=First;										//catat elemen pertama
    while(pBantu != NULL){								//proses cetak
		cout<<"Nama lengkap\t: "<<pBantu->nama<<endl;
        cout<<"Divisi\t: "<<pBantu->divisi<<endl;
        cout<<"Gaji\t: "<<pBantu->gaji<<endl;
		cout<<endl;
        pBantu=pBantu->next;					//berpindah ke berikutnya
    }
}

void deleteFirst (List& First, pointer& pHapus){
	// I.S List Fisrt mungkin kosong
	// F.S List berkurang satu di depan, yang dihapus dikembalikan
	
	if (First == NULL){					//kosong
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){		//isi 1 elemen
		pHapus=First;
		First=NULL;
	}
	else{								//isi > 1 elemen
		pHapus=First;					//1
		First=First->next;				//2
		pHapus->next=NULL;				//3
	}
}

void insertLast(List& First, pointer pBaru){
	// I.S List First mungkin kosong dan pBaru sudah terdefinisi
	// F.S List bertambah satu elemen di belakang (sesudah last)
	
	pointer last;						//last utk mencatat elemen terakhir
	
	if (First==NULL){					//kosong
		First=pBaru;
	}
	else {								//ada isi
		last=First;						//menemukan elemen terakhir
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;				//sambungkan
	}
}

void deleteLast(List& First, pointer& pHapus){
	// I.S List First mungkin kosong
	// F.S List berkurang satu dibelakang, yang dihapus dikembalikan
	
	pointer last, precLast;
	if (First==NULL){					//kosong
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){		//isi 1 elemen
		pHapus=First;
		First=NULL;						//list jadi kosong
	}
	else{								//list > 1 elemen
		last=First;						//menemukan elemen terakhir
		precLast=NULL;
		while (last->next!=NULL){
			precLast=last;				//preclast mencatat yang akan ditinggalkan last
			last=last->next;			//last berpindah
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

int main(){
	pointer p;
	List Ma08;
	int pilihan;
	
	createList(Ma08);					// list kosong
	while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukkan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(p);
            insertFirst(Ma08,p);
        break;
        case 2:
            createElmt(p);
            insertLast(Ma08,p);
        break;	
        case 3:
            deleteFirst(Ma08,p);
        break;
        case 4:
            deleteLast(Ma08,p);
        break;
        case 5:
            traversal(Ma08);
        break;
        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}
