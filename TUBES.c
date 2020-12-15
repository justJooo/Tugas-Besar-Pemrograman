#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int poin, barang, harga, total, diskon, pembayaran, kembalian;

void TotalBelanja()
{
	printf("Masukan Jumlah Barang	=\n");
	scanf("%d", &barang);
	printf("Masukan Harga Barang	=\n");
	scanf("%d", &harga);
	total=barang*harga;
	printf("Masukkan uang yang diberikan    = \n");
	scanf("%d", &pembayaran);
}
void Diskon()
{
	if (total >= 75000 && total < 900000){
		diskon = 10/100;
		total=total-(total*10/100);
		printf("\nSelamat Anda Mendapat Diskon sebesar 10 persen!\n");
	
	}
	else if (total >= 900000){
		diskon = 20/100;
		total=total-(total*20/100);
		printf("\nSelamat Anda Mendapat Diskon sebesar 20 persen!\n");
	}
	else 
	printf("\nMaaf, Anda tidak mendapat Diskon. Silakan Berbelanja dengan minimal pembelian total 75000.\n");
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

    printf("Point total Anda : %d\n",poin);
    printf("Tukar point? (Ketik 1 untuk Ya dan 2 untuk Tidak)");
    scanf("%d",&pilihan);
    while(pilihan == 1 && poin > 0){
        printf("Ingin tukar point dengan apa?\n");
        printf("1.Gantungan kunci\n");
        printf("2.Payung\n");
        printf("3.Boneka\n");
        printf("Silakan masukkan angka dari pilihan :");
        scanf("%d",&pilih);

        if (pilih == 1){
            if( poin < gantungan_kunci.point){
                printf("Point Anda tidak mencukupi\n");
                exit(1);
            }
            poin -= gantungan_kunci.point;
            printf("Anda mendapatkan gantungan kunci!\n");
            printf("Sisa point anda : %d\n",poin);
            printf("Tukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 2){
            if(poin < payung.point){
                printf("Point Anda tidak mencukupi.");
                exit(1);
            }
            printf("Silakan pilih warna merchandise anda:\n");
            printf("1.Merah\n");
            printf("2.Biru\n");
            printf("3.Hitam\n");
            printf("Silakan masukkan angka dari pilihan :");
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
                printf("Pilih warna berdasarkan list yang ada (Masukkan Angka saja) : \n");
            }
            poin -= payung.point;
            printf("Anda mendapatkan Payung Berwarna : %s!\n",payung.pilihan_warna);
            printf("Sisa point anda : %d\n",poin);
            printf("Tukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 3){
            if(poin <boneka.point){
                printf("Point Anda tidak mencukupi");
                exit(1);
            }
            poin -= boneka.point;
            printf("Anda mendapatkan Boneka Mascot!\n");
            printf("Sisa point Anda : %d\n",poin);
            printf("Tukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
    }
        }
	 if(poin == 0){
            printf("Point Anda sudah habis. Silakan lakukan transaksi lain untuk menambah point.\n");
        }
}
typedef struct{//Perlu dirubah bila ingin di update
	char Nama[50];
	char Member[20];
	char Telp[13];
	long ID;
}Nota;
FILE*PENJUALAN;
char txt[20] = "Nota Penjualan.txt";

void Create(){
	Nota Penjualan;
	PENJUALAN=fopen(txt,"a");
	printf("Masukkan Nama Customer \t: ");scanf("%[^\n]",&Penjualan.Nama);fflush(stdin);
	printf("Masukkan ID Customer \t: ");scanf("%i",&Penjualan.ID);fflush(stdin);
	printf("Masukkan Member Customer \t: ");scanf("%s",&Penjualan.Member);fflush(stdin);
	printf("Masukkan No Telepon Customer \t: ");scanf("%[^\n]",&Penjualan.Telp);fflush(stdin);
	fprintf(PENJUALAN,"%s_%i_%s_%s\n",Penjualan.Nama,Penjualan.ID,Penjualan.Member,Penjualan.Telp);
	fclose(PENJUALAN);
}

void Delete(){
	Nota Penjualan[50];
	int id,index,i;
	printf("Masukan ID Customer yang ingin dihapus \t: ");scanf("%i",&id);fflush(stdin);
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	index=0;
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%s_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp);
		fflush(stdin);
		if(id!=Penjualan[index].ID){
			index++;
		}
	}
	fclose(PENJUALAN);
	PENJUALAN=fopen("Nota Penjualan.txt","w");
	fclose(PENJUALAN);
	PENJUALAN=fopen("Nota Penjualan.txt","a");
	for(i=0;i<index;i++){
		fprintf(PENJUALAN,"%s_%i_%s_%s\n",Penjualan[i].Nama,Penjualan[i].ID,Penjualan[i].Member,Penjualan[i].Telp);
	}
	fclose(PENJUALAN);
}

void Update(){
	Nota Penjualan[50];
	int id,index,i;
	printf("Masukan ID yang ingin diubah \t: ");scanf("%i",&id);fflush(stdin);
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	index=0;
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%s_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp);
		fflush(stdin);
		if(id==Penjualan[index].ID){
			printf("Masukkan Nama Customer \t: ");scanf("%[^\n]",&Penjualan[index].Nama);fflush(stdin);
			printf("Masukkan ID Customer \t: ");scanf("%i",&Penjualan[index].ID);fflush(stdin);
			printf("Masukkan Member Customer :\t");scanf("%s",&Penjualan[index].Member);fflush(stdin);
			printf("Masukkan Telp Customer\t: ");scanf("%[^\n]",&Penjualan[index].Telp);fflush(stdin);
		}
		index++;
	}
	fclose(PENJUALAN);
	PENJUALAN=fopen("Nota Penjualan.txt","w");
	fclose(PENJUALAN);
	PENJUALAN=fopen("Nota Penjualan.txt","a");
	for(i=0;i<index;i++){
		fprintf(PENJUALAN,"%s_%i_%s_%s\n",Penjualan[i].Nama,Penjualan[i].ID,Penjualan[i].Member,Penjualan[i].Telp);
	}
	fclose(PENJUALAN);
}

void Read(){
	Nota Penjualan;
	int id;
	printf("Masukan ID yang ingin ditampilkan \t: ");scanf("%i",&id);fflush(stdin);
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%s_%s_%[^\n]\n",&Penjualan.Nama,&Penjualan.ID,&Penjualan.Member,&Penjualan.Telp);
		fflush(stdin);
		if(id==Penjualan.ID){
			printf("Nama Customer \t : %s\n",Penjualan.Nama);
			printf("ID Customer \t : %i\n",Penjualan.ID);
			printf("Member Customer \t : %s\n",Penjualan.Member);
			printf("No Telepon Customer \t : %s\n\n",Penjualan.Telp);
		}
	}
}
int Pembayaran_Kembalian ()
{
    if (total != 0){
	printf("Total pembelanjaan Anda : %d\n", total);
	printf("Jumlah barang yang Anda bayar : %d\n", barang);
    
if (pembayaran < total){
	printf("Uang anda tidak mencukupi. Mohon membayar sesuai dengan total pembelian Anda.");
    exit(1);
}
else if (pembayaran > total){
    kembalian=pembayaran-total;
	return kembalian;
}}}
int main(){
	
	int pilihan1,point,menu;
	char Lanjut[2];
	TotalBelanja();
    point = hitung_poin(total);
	Diskon();
	printf("Total Pembelanjaan Anda adalah  = %d\n", total);
	printf("Uang Pembayaran Anda adalah     = %d\n", pembayaran);
	printf("Uang Kembalian Anda adalah      = %d\n", Pembayaran_Kembalian());
	printf("Ingin tukar point? (Ketik 1 untuk Ya):\n");
	scanf("%d",&pilihan1);

    if(pilihan1 == 1){
        
        tukar_poin(point);
    }
	do{
		printf("====================Menu====================\n");
		printf("1. Create\n2. Read\n3. Update\n4. Delete\n===========================================\nPilihan >> ");
		scanf("%i",&menu);fflush(stdin);
		switch(menu){
			case 1:
				Create();
			break;
			case 2:
				Read();
			break;
			case 3:
				Update();
			break;
			case 4:
				Delete();
			break;
		}
		printf("Apakah anda ingin melanjutkan? (y/t): "); scanf("%[^\n]",&Lanjut);fflush(stdin);
	}while(strcmp(Lanjut,"y")==0);
}
