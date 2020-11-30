#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int poin, barang, harga, total, diskon;

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

int hitung_poin (int total_belanja){
    int poin = total_belanja / 50000;
    return poin;
}
struct merchandise
{
    int point;
    char pilihan_warna[20];
};

void tukar_poin (int poin){
    int pilih,pil2,pilihan;
    struct merchandise gantungan_kunci,payung,boneka;
    gantungan_kunci.point = 2;
    payung.point=5;
    boneka.point=7;

    printf("point anda ada : %d\n",poin);
    printf("Tukar poin?(ketik 1 untuk ya dan 2 untuk tidak)");
    scanf("%d",&pilihan);
    while(pilihan == 1 && poin > 0){
        printf("ingin tukar poin dengan apa?\n");
        printf("1.Gantungan kunci\n");
        printf("2.Payung\n");
        printf("3.Boneka\n");
        printf("Masukan angka dari pilihan :");
        scanf("%d",&pilih);

        if (pilih == 1){
            if( poin < gantungan_kunci.point){
                printf("Point tidak mencukupi\n");
                exit(1);
            }
            poin -= gantungan_kunci.point;
            printf("Anda mendapatkan gantungan kunci\n");
            printf("sisa poin anda : %d\n",poin);
            printf("Tukar poin lagi?(ketik 1 untuk ya dan 2 untuk tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 2){
            if(poin < payung.point){
                printf("Point tidak mencukupi");
                exit(1);
            }
            printf("Pilih warna\n");
            printf("1.Merah\n");
            printf("2.Biru\n");
            printf("3.Hitam\n");
            printf("Masukan angka sesuai pilihan");
            scanf("%d",&pil2);
            if(pil2 == 1){
                strcpy (payung.pilihan_warna,"Merah");
            }
            else if(pil2==2){
                strcpy (payung.pilihan_warna,"Biru");
            }
            else if(pil2==3){
                strcpy (payung.pilihan_warna,"Hitam");
            }
            else {
                printf("Pilih warna berdasarkan list yang ada (cukup masukan angka sebelum warna pada list)");
            }
            poin -= payung.point;
            printf("anda mendapatkan payung berwarna : %s\n",payung.pilihan_warna);
            printf("sisa poin anda : %d\n",poin);
            printf("Tukar poin lagi?(ketik 1 untuk ya dan 2 untuk tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 3){
            if(poin <boneka.point){
                printf("Point tidak mencukupi");
                exit(1);
            }
            poin -= boneka.point;
            printf("Anda mendapatkan boneka mascot\n");
            printf("sisa poin anda : %d\n",poin);
            printf("Tukar poin lagi?(ketik 1 untuk ya dan 2 untuk tidak)\n");
            scanf("%d",&pilihan);
    }
        }
}

int main(){
	
	int pilihan1,point;
	TotalBelanja();
	Diskon();
	printf("Total Pembelanjaan anda adalah  = %d\n", total);
	printf("ingin tukar point?(ketik 1 untuk ya)\n");
	scanf("%d",&pilihan1);

    if(pilihan1 == 1){
        point = hitung_poin(total);
        tukar_poin(point);
    }
}


