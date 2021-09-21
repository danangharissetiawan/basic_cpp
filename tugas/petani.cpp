#include <iostream>
#include <iomanip>

using namespace std;


struct petani_data
{
    char nama[30];
    int panen_hari_1;
    int n_hari;
    int total_panen;
    long pendapatan;

};


int main()
{

    int jumlah_petani;
    cout << "Jumlah petani yang akan didata: "; cin >> jumlah_petani;

    int harga_perkilo;
    cout << "Harga cabai perkilo: "; cin >> harga_perkilo;

    struct petani_data petani[jumlah_petani];

    // int total_panen[jumlah_petani];
    // long pendapatan[jumlah_petani];


    for(int x = 0; x < jumlah_petani; x++)
    {
        cout << "\n--- Data Petani ke - " << x + 1 << " ---" << endl;
        cout<<"Inputkan Nama Petani: "; cin>>petani[x].nama;
        cout<<"Inputkan lama panen berlangsung: "; cin>>petani[x].n_hari;
        cout<<"Inputkan panen di hari 1: "; cin>>petani[x].panen_hari_1;

        int sum = 0;
        for(int i=0; i < petani[x].n_hari; i++)
        {
            if (i > 0)
                sum += sum + petani[x].panen_hari_1;
            else
                sum += petani[x].panen_hari_1;
        }

        petani[x].total_panen = sum;
        petani[x].pendapatan = petani[x].total_panen * harga_perkilo;
    }

    // bubble_sort
    struct petani_data param;
    int length = sizeof(petani)/sizeof(petani[0]);
    for (int step = 0; step < (length - 1); ++step) {
        int swapped = 0;
        for (int i = 0; i < (length - step - 1); ++i) {
            if (petani[i].pendapatan > petani[i + 1].pendapatan) {
                param = petani[i];
                petani[i] = petani[i + 1];
                petani[i + 1] = param;

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }

    // int y=jumlah_petani-2;
	// while(y >= 0)
	// {
	// 	int index = 0;
	// 	while(index <= y)
	// 	{
	// 		if(petani[index].pendapatan > petani[index+1].pendapatan)
	// 		{
	// 			param = petani[index];
	// 			petani[index] = petani[index+1];
	// 			petani[index+1] = param;
						
	// 		} 
	// 		index++;
	// 	}
	// 	y--;
	// }

    cout
        << left << setw(10) << "Nama"
        << left << setw(30) << "Total Hari"
        << left << setw(30) << "Panen Hari 1"
        << left << setw(30) << "Total Panen"
        << left << setw(35) << "Pendapatan"
        << endl;

    for (int n = 0; n < jumlah_petani; n++) {
        cout
            << left << setw(10) << petani[n].nama
            << left << setw(30) << petani[n].n_hari
            << left << petani[n].panen_hari_1 << setw(30) << " kg"
            << left << petani[n].total_panen << setw(30)  << " kg"
            << left << "Rp." << setw(35) << petani[n].pendapatan
            << endl;
    }

    return 0;

}

