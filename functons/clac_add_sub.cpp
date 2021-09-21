//Program : Kalkulator Sederhana : Penjumlahan dan Pengurangan
//Author : feri
// Date : 20 September 2021

#include<iostream>
#include <string>
using namespace std;

int a,b, hasil;		//variabel GLOBAL

void garis(int x)			//procedure garis : bertugas untuk mencetak garis = sebanyak x kali
{	
	int a;
	for(a=1;a<=x;a++)
		printf("=");

	printf("\n");
}

void header()				//procedure header :: menampilkan tampilan awal
{
	printf("         PROGRAM KALKULATOR SEDERHANA\n");
	printf("            Programmer by. Cah Gagah\n");
	printf("Teknik Informatika - Strata 1 Fasilkom UDINUS\n");
	garis(45);			//memanggil procedure garis : menampilkan = sebanyak 45 kali
	printf("\n\n");
}

int tambahkan(int x, int y)			//function tambahkan : x+y
{
	return x+y;	
}

int kurangkan(int x, int y)			//function krangkanon  : x-y
{
	return x-y;	
}


int main()
{
	
	char opr;
	header();		//memanggil procedure header : menampilkan tampilan awal
	cout<<"Inputkan Nilai A : "; cin>>a;
	cout<<"Inputkan Nilai B : "; cin>>b;

	cout<<"Inputkan Operator [+ atau -] : "; cin>>opr;
	if(opr=='+')
		hasil = tambahkan(a,b);				//memaninggil fungsi tambahkan : a+b
	if(opr=='-')
		hasil = kurangkan(a,b);				//memaninggil fungsi kurangkan : a-b
		
		
	cout<<"Hasilnya : "<<a<<opr<<b<<"="<<hasil<<endl;	
	cout<<"\n\nTambahkan Fungsi Untuk Operator x (kali), / (bagi) dan ^ (pangkat)";
	return 0;
}