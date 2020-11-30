#include <stdio.h>

int poin, barang, harga, total, diskon, poin;

void TotalBelanja()
{
	printf("Masukan Jumlah Barang	=\n");
	scanf("%d", &barang);
	printf("Masukan Harga Barang	=\n");
	scanf("%d", &harga);
	total=barang*harga;
}
void Diskon()
{
	if (total >= 75000 && total < 900000){
		diskon = 10/100;
		total=total-(total*10/100);
		printf("\nSelamat Anda Mendapat Diskon sebesar 10 persen\n");
	
	}
	else if (total >= 900000){
		diskon = 20/100;
		total=total-(total*20/100);
		printf("\nSelamat Anda Mendapat Diskon sebesar 20 persen\n");
	}
	else 
	printf("\nAnda Tidak Mendapat Diskon \n");
}

void main(){
	
	TotalBelanja();
	Diskon();
	printf("Total Pembelanjaan anda adalah  = %d", total);
}



