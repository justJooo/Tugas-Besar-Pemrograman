#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int point, barang, harga, total, diskon, pembayaran, kembalian,a;
char nama[50];
char path[100];

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

void tukar_poin (){
    int pilih,pil2,pilihan;
    struct merchandise gantungan_kunci,payung,boneka;
    gantungan_kunci.point = 2;
    payung.point=5;
    boneka.point=7;

    printf("Point total Anda : %d\n",point);
    printf("Tukar point? (Ketik 1 untuk Ya dan 2 untuk Tidak)");
    scanf("%d",&pilihan);
    while(pilihan == 1 && point > 0){
        printf("Ingin tukar point dengan apa?\n");
        printf("1.Gantungan kunci\n");
        printf("2.Payung\n");
        printf("3.Boneka\n");
        printf("Silakan masukkan angka dari pilihan :");
        scanf("%d",&pilih);

        if (pilih == 1){
            if( point < gantungan_kunci.point){
                printf("Point Anda tidak mencukupi\n");
                exit(1);
            }
            point -= gantungan_kunci.point;
            printf("Anda mendapatkan gantungan kunci!\n");
            printf("Sisa point anda : %d\n",point);
            printf("Tukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 2){
            if(point < payung.point){
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
            point -= payung.point;
            printf("Anda mendapatkan Payung Berwarna : %s!\n",payung.pilihan_warna);
            printf("Sisa point anda : %d\n",point);
            printf("Tukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 3){
            if(point <boneka.point){
                printf("Point Anda tidak mencukupi");
                exit(1);
            }
            point -= boneka.point;
            printf("Anda mendapatkan Boneka Mascot!\n");
            printf("Sisa point Anda : %d\n",point);
            printf("Tukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
    }
        }
	 if(point == 0){
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
else if (pembayaran >= total){
    kembalian=pembayaran-total;
	return kembalian;
}}}
void judul(){
    printf("===========================================\n");
    printf("**  **    ***     *****   *****  *****  \n");
    printf("** **    ** **   ***       ***   **  ** \n");
    printf("*****   *******   *****    ***   *****  \n");
    printf("**  **  **   **      ***   ***   **  **\n");
    printf("**  **  **   **  *****    *****  **  **\n");
    printf("===========================================\n");
}
void cek_member(){
    char str[1000];
    char *pos;

     FILE *fpointer;
    

    printf("Masukan nama : ");
    scanf("%s", nama);

    fpointer = fopen("Daftar_Member.txt", "r");

    if (fpointer == NULL)
    {
        fclose(fpointer);
        printf("File tidak ditemukan!\n");
        fpointer = fopen("Daftar_Member.txt","a");
        fclose(fpointer);
        fpointer = fopen("Daftar_Member.txt","r");
    }
    while ((fgets(str,1000, fpointer)) != NULL){
         pos = strstr(str, nama);
         
         if (pos != NULL)
        {
            a = 1;
            break;
        }
    }
    fclose(fpointer);
    if(a == 1){
        printf("nama ditemukan\n");
        a = 1;
    }
    else
    {
        printf("nama tidak ditemukan\n");
        a = 0;
    }
    fclose(fpointer);
}
void jadi_member(){

FILE *fpointer;

strcpy(path,nama);
strcat(path,".txt");

fpointer = fopen(path,"w");
fprintf(fpointer,"0");
fclose(fpointer);
fpointer = fopen("Daftar_Member.txt","a");
fprintf(fpointer,"%s\n",nama);
fclose(fpointer);
}
void update_point(int point){
    FILE *fpointer;
    fpointer = fopen(path,"w");
    fprintf(fpointer,"%d",point);
    fclose(fpointer);
}
int get_point(){
    int temp;
    FILE *fpointer;
    fpointer = fopen(path,"r");
    fscanf(fpointer,"%d",&temp);
    fclose(fpointer);
    return temp;
}
int main(){
	
	int pilihan1,menu,pil2,pil3;
	char Lanjut[2];
    judul();
	TotalBelanja();
    point = hitung_poin(total);
	Diskon();
	printf("Total Pembelanjaan Anda adalah  = %d\n", total);
	printf("Uang Pembayaran Anda adalah     = %d\n", pembayaran);
	printf("Uang Kembalian Anda adalah      = %d\n", Pembayaran_Kembalian());
	 printf("Member ?\n");
    printf("1.YES\n");
    printf("2.NO\n");
    scanf("%d",&pil2);
    if(pil2 == 1)
        cek_member();
    
    if (a == 0 || pil2 != 1){
    printf("\nIngin menjadi member?\n");
    printf("1.YES\n");
    printf("2.NO\n");
    scanf("%d",&pil3);
    if (pil3 == 1)
    {
     jadi_member();  
    }
    else {
        printf("Terima kasih telah berbelanja\n");
        return(0);
    }
    }else if (a == 1){
        strcpy(path,nama);
        strcat(path,".txt");
    }
    printf("Anda mendapatkan %d point\n",point);
    point += get_point();
    
	printf("ingin tukar point?\n");
    printf("1.YES\n");
    printf("2.NO\n");
	scanf("%d",&pilihan1);

    if(pilihan1 == 1){
        tukar_poin();
    }
    update_point(point);
    printf("Terima kasih sudah berbelanja\n");
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
