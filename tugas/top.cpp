#include <iostream>
using namespace std;

struct petani {
	char nama[30];
	int N;
	int M;
	int totuang;
	int totcabai;
};


int main() {
	int hargaCabai, jumlahPetani;
	int xx,y,index;
	cout<<"Berapa jumlah petani dalam perkebunan cabai : "; cin>>jumlahPetani;
	struct petani petanicabai[jumlahPetani];
	struct petani param;
	
	cout<<"Harga Cabai Perkilogram : "; cin>>hargaCabai; cout<<"\n";
		
	for(int i=0; i<jumlahPetani; i++) {
		cout<<"Nama Petani ke-"<<i+1<<" : "; cin>>petanicabai[i].nama;
		cout<<"Lama hari Panen : " ; cin>>petanicabai[i].N;
		cout<<"Hasil Panen Hari Pertama (kg) : "; cin>>petanicabai[i].M; 
		
		xx= petanicabai[i].M;
		for(int k=1; k<petanicabai[i].N; k++) 
		{
			xx= xx+(2*xx);
		}
		petanicabai[i].totcabai = xx;
		petanicabai[i].totuang  = xx * hargaCabai;
	}
	
	//bubblesortdisini
	y=jumlahPetani-2;
	while(y >= 0)
	{
		index = 0;
		while(index <= y)
		{
			if(petanicabai[index].totuang > petanicabai[index+1].totuang)
			{
				param = petanicabai[index];
				petanicabai[index] = petanicabai[index+1];
				petanicabai[index+1] = param;
						
			} 
			index++;
		}
		y--;
	}
	//processing end
	
	
	cout<<"Perkebunan Cabai TOP MARKOTOP\n";
	cout<<"============================================================================\n";
	cout<<"No   Nama Petani          Total Hari   Panen hari   Total Hasil    Total Uang\n";
	cout<<"                          Panen        Pertama      Panen          didapat   \n";
	cout<<"----------------------------------------------------------------------------\n";
	for(int j=0; j<jumlahPetani; j++) 
	{		
		printf("%d   %s   %d  %d   %d   %d \n",j+1,petanicabai[j].nama, petanicabai[j].N, petanicabai[j].M, petanicabai[j].totcabai, petanicabai[j].totuang);
	}
	cout<<"----------------------------------------------------------------------------\n";
	
	return 0;
}
