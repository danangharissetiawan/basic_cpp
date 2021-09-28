#include<iostream>
using namespace std;

struct stack
{
	char nama[30];
	int isi;
};

struct stack gudang[5];
int maks=5;
int top=1;

int full(int x) {
	if(x>maks)					//jika top diatas maks
		cout<<"Stack is Full...";
		return 1;
    // return maks;
}

int empty(int x) {
	if(x==1)
		cout<<"stack is Empty...";
		return 1;
	
    // return 0;
}

void push(int x)
{
	if(full(x)!=1)			// jika tumpukan belum penuh
	{
		cout<<"Masukan Nama Barang : ";cin>>gudang[x].nama;
		cout<<"Masukan Isi Barang  : ";cin>>gudang[x].isi;
		top++;
	}
}

void pop(int x)
{
	if(empty(x)!=0)
	{
		cout<<"Hasil POP adalah : "<<gudang[x-1].nama<<" - "<<gudang[x-1].isi<<endl;
		top--;
	}
}

void lihat(int x)
{
	int a;
	for(a=1;a<x;a++)
		cout<<a<<". "<<gudang[a].nama<<" - "<<gudang[a].isi<<endl;
	
	cout<<endl<<endl<<endl;	
}

int main()
{
	int pilih;
	do 
    {
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Lihat Data"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Pilihan anda : ";
		cin>>pilih;
		if(pilih==1) push(top);
		if(pilih==2) pop(top);
		if(pilih==3) lihat(top);
	}
	while(pilih!=4);
	return 0;
}