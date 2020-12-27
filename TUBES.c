#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a;
char nama[50];
char path[100];

int Diskon(int total)
{
    int diskon;
	if (total >= 75000 && total < 900000){
		diskon = 10/100;
		total=total-(total*10/100);
		printf("\nSelamat Anda Mendapat Diskon sebesar 10 persen! Silakan Cek Total Belanja Anda.\n");
        return total;

	}
	else if (total >= 900000){
		diskon = 20/100;
		total=total-(total*20/100);
		printf("\nSelamat Anda Mendapat Diskon sebesar 20 persen! Silakan Cek Total Belanja Anda.\n");
        return total;
	}
	else
	printf("\nMaaf, Anda tidak mendapat Diskon. Silakan Berbelanja dengan minimal pembelian total 75000.\n");
    return total;
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

int tukar_poin (int point){
    int pilih,pil2,pilihan;
    struct merchandise gantungan_kunci,payung,boneka;
    gantungan_kunci.point = 2;
    payung.point=5;
    boneka.point=7;

    printf("\n** Point total Anda : %d **\n",point);
    do{
        printf("Ingin tukar point dengan apa?\n");
        printf("1.Gantungan kunci (2 Point)\n");
        printf("2.Payung          (5 Point)\n");
        printf("3.Boneka          (7 Point)\n");
        printf("Silakan masukkan nomor pilihan Anda : ");
        scanf("%d",&pilih);

        if (pilih == 1){
            if( point < gantungan_kunci.point){
                printf("Maaf, Point Anda tidak mencukupi.\n");
                break;
            }
            point -= gantungan_kunci.point;
            printf("==================================================\n");
            printf("|~ Selamat! Anda mendapatkan gantungan kunci! ~|\n");
            printf("|> Sisa point anda : %d                           |\n",point);
            printf("==================================================\n");
            printf("\nTukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 2){
            if(point < payung.point){
               printf("Maaf, Point Anda tidak mencukupi.\n");
                break;
            }
            printf("Silakan pilih warna merchandise anda:\n");
            printf("1.Merah\n");
            printf("2.Biru\n");
            printf("3.Hitam\n");
            printf("Silakan masukkan angka dari pilihan:");
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
            printf("=======================================================\n");
            printf("|~ Selamat! Anda mendapatkan Payung Berwarna : %s! ~|\n",payung.pilihan_warna);
            printf("|> Sisa point anda : %d                               |\n",point);
            printf("=======================================================\n");
            printf("\nTukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 3){
            if(point <boneka.point){
               printf("Maaf, Point Anda tidak mencukupi.\n");
                break;
            }
            point -= boneka.point;
            printf("==================================================\n");
            printf("|~ Selamat! Anda mendapatkan Boneka Mascot! ~|\n");
            printf("|> Sisa point Anda : %d                         |\n",point);
            printf("==================================================\n");
            printf("\nTukar point lagi? (Ketik 1 untuk Ya dan 2 untuk Tidak)\n");
            scanf("%d",&pilihan);
    }
        }
        while(pilihan == 1 && point > 0);
	 if(point == 0){
            printf("Point Anda sudah habis. Silakan lakukan transaksi lain untuk menambah point.\n");
        }
        return point;
}
typedef struct{//Perlu dirubah bila ingin di update
		char Nama[50];
	char Member[20];
	char Telp[13];
	char Tanggal[10];
	long ID;
}Nota;
FILE*PENJUALAN;
char txt[20] = "Nota Penjualan.txt";

void Create(){
	Nota Penjualan;
	PENJUALAN=fopen(txt,"a");
	printf("=========================================================================\n");
	printf("====================== LIST PENJUALAN MINIMARKET X ======================\n");
	printf("\nMasukkan Nama Customer \t\t\t: ");scanf("%[^\n]",&Penjualan.Nama);fflush(stdin);
	printf("Masukkan ID Customer \t\t\t: ");scanf("%i",&Penjualan.ID);fflush(stdin);
	printf("Masukkan Member Customer \t\t: ");scanf("%s",&Penjualan.Member);fflush(stdin);
	printf("Masukkan No Telepon Customer \t\t: ");scanf("%s",&Penjualan.Telp);fflush(stdin);
	printf("Masukkan Tanggal Transaksi \t\t: ");scanf("%s",&Penjualan.Tanggal);fflush(stdin);
	printf("\n=========================================================================");
	fprintf(PENJUALAN,"%s_%i_%s_%s_%s\n",Penjualan.Nama,Penjualan.ID,Penjualan.Member,Penjualan.Telp,Penjualan.Tanggal);
	fclose(PENJUALAN);
}

void Delete(){
	Nota Penjualan[50];
	int id,index,i;
	printf("Masukan ID Customer yang ingin dihapus \t: ");scanf("%i",&id);fflush(stdin);
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	index=0;
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^]%i_%s_%s_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp,&Penjualan[index].Tanggal);
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
		fprintf(PENJUALAN,"%s_%i_%s_%s\n",Penjualan[i].Nama,Penjualan[i].ID,Penjualan[i].Member,Penjualan[i].Telp),Penjualan[i].Tanggal;
	}
	fclose(PENJUALAN);
}

void Update(){
	Nota Penjualan[50];
	int id,index,i;
	printf("Masukan ID yang ingin diubah \t: ");scanf("%i",&id);fflush(stdin);
	printf("\n");
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	index=0;
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^]%i_%[^]%[^]%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp),&Penjualan[index].Tanggal;
		fflush(stdin);
		if(id==Penjualan[index].ID){
			printf("Masukkan Nama Customer \t\t\t: ");scanf("%[^\n]",&Penjualan[index].Nama);fflush(stdin);
			printf("Masukkan ID Customer \t\t\t: ");scanf("%i",&Penjualan[index].ID);fflush(stdin);
			printf("Masukkan Member Customer \t\t: ");scanf("%s",&Penjualan[index].Member);fflush(stdin);
			printf("Masukkan No Telepon Customer \t\t:  ");scanf("%s",&Penjualan[index].Telp);fflush(stdin);
			printf("Masukkan Tanggal Transaksi \t\t:  ");scanf("%[^\n]",&Penjualan[index].Tanggal);fflush(stdin);
		}
		index++;
	}
	fclose(PENJUALAN);
	PENJUALAN=fopen("Nota Penjualan.txt","w");
	fclose(PENJUALAN);
	PENJUALAN=fopen("Nota Penjualan.txt","a");
	for(i=0;i<index;i++){
		fprintf(PENJUALAN,"%s_%i_%s_%s_%s\n",Penjualan[i].Nama,Penjualan[i].ID,Penjualan[i].Member,Penjualan[i].Telp,Penjualan[i].Tanggal);
	}
	fclose(PENJUALAN);
}

void Read(){
	Nota Penjualan;
	int id;
	printf("Masukan ID yang ingin ditampilkan \t: ");scanf("%i",&id);fflush(stdin);
	printf("\n");
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^]%i_%[^]%[^]%[^\n]\n",&Penjualan.Nama,&Penjualan.ID,&Penjualan.Member,&Penjualan.Telp,&Penjualan.Tanggal);
		fflush(stdin);
		if(id==Penjualan.ID){
			printf("Nama Customer \t\t\t\t : %s\n",Penjualan.Nama);
			printf("ID Customer \t\t\t\t : %i\n",Penjualan.ID);
			printf("Member Customer \t\t\t : %s\n",Penjualan.Member);
			printf("No Telepon Customer \t\t\t : %s\n",Penjualan.Telp);
			printf("Tanggal Transaksi \t\t\t : %s\n",Penjualan.Tanggal);
		}
	}
}


int Pembayaran_Kembalian (int total, int pembayaran){
    int kembalian;
    if (total != 0){

if (pembayaran < total){
	printf("Uang anda tidak mencukupi. Mohon membayar sesuai dengan total pembelian Anda.");
    exit(1);
}
else if (pembayaran > total){
    kembalian=pembayaran-total;
	return kembalian;
}
}
}
void cek_member(){
    char str[1000];
    char *pos;

     FILE *fpointer;


    printf("Masukan nama Member : ");
    scanf("%s",nama);

    fpointer = fopen("Daftar_Member.txt", "r");

    if (fpointer == NULL)
    {
        fclose(fpointer);
        printf("Member tidak ditemukan!\n");
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
        printf("Nama Ditemukan.\n");
        a = 1;
    }
    else
    {
        printf("Nama Tidak Ditemukan.\n");
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
struct list
{
    char *nama;
    int harga;
};
void menu_barang(struct list *barang){

    printf("+------------------------------------------------------------+\n");
    printf("|\t1.%s \t 2.%s \t  3.%s\t     |\n",barang[0].nama,barang[1].nama,barang[2].nama);
    printf("|\t4.%s \t 5.%s \t  6.%s\t     |\n",barang[3].nama,barang[4].nama,barang[5].nama);
    printf("|\t7.%s \t 8.%s \t  9.%s\t     |\n",barang[6].nama,barang[7].nama,barang[8].nama);
    printf("|\t10.%s \t 11.%s \t  12.%s\t     |\n",barang[9].nama,barang[10].nama,barang[11].nama);
    printf("|\t13.%s \t 14.%s \t  15.%s\t     |\n",barang[12].nama,barang[13].nama,barang[14].nama);
    printf("+------------------------------------------------------------+\n");
}
int hitung_belanja (int banyak, int indeks, struct list *barang){
    int subtotal = barang[indeks-1].harga * banyak;
    return subtotal;
}
void update_to_file(char *nama_barang,int qty,int subtotal){
FILE *fpointer;
fpointer = fopen("struk_belanja.txt","a");
fprintf(fpointer,"  %s           ",nama_barang);
fprintf(fpointer,"%d              ",qty);
fprintf(fpointer,"%d\n",subtotal);
fclose(fpointer);
}
int persentase_diskon (int total){
    int diskon;
    if(total >= 75000 && total < 900000){
        diskon = 10;
        return diskon;
    }
    else if (total >= 900000){
        diskon =20;
        return diskon;
    }
    else diskon = 0;
    return diskon;
}
int main(){

	int pilihan1,menu,pil2,pil3,pil4,pil5,kuantitas,subtotal,pembayaran,point,diskonpersen;
    int total = 0;
    int flag = 0;
	char Lanjut[2];
    FILE *fpointer;
    struct list barang[15];
    barang[0].nama = "Mie Instan";
    barang[0].harga = 2500;
    barang[1].nama = "Gas (3kg)";
    barang[1].harga = 25000;
    barang[2].nama = "Pasta Gigi";
    barang[2].harga = 1200;
    barang[3].nama = "Permen";
    barang[3].harga = 500;
    barang[4].nama = "Gas (5,5kg)";
    barang[4].harga = 67500;
    barang[5].nama = "Sabun Mandi";
    barang[5].harga = 3000;
    barang[6].nama = "Biskuit";
    barang[6].harga = 10000;
    barang[7].nama = "Teh Celup";
    barang[7].harga = 13500;
    barang[8].nama = "Gula (1kg)";
    barang[8].harga = 13000;
    barang[9].nama = "Beras (4kg)";
    barang[9].harga = 48500;
    barang[10].nama = "Tissue";
    barang[10].harga = 9000;
    barang[11].nama = "Kotak P3K";
    barang[11].harga = 95000;
    barang[12].nama = "Susu";
    barang[12].harga = 5000;
    barang[13].nama = "Shampoo";
    barang[13].harga = 4000;
    barang[14].nama = "Parfum";
    barang[14].harga = 37500;
    printf("\n|==================== KASIR MINIMARKET X ====================|");
	printf("\n|                                                            |\n");
     menu_barang(barang);
    do{
    printf("Masukkan nomor barang yang dibeli : ");
    scanf("%d",&pil4);
    if(pil4 > 15){
        break;
    }
    barang->nama=barang[pil4-1].nama;
    printf ("Kuantitas : ");
    scanf("%d",&kuantitas);
    subtotal = hitung_belanja(kuantitas,pil4,barang);
    printf("Subtotal : %d\n",subtotal);
    total += subtotal;
    if(flag == 0){
        fpointer = fopen("struk_belanja.txt","w");
        fprintf(fpointer,"====================================================\n");
        fprintf(fpointer,"====================MINIMARKET X====================\n");
        fprintf(fpointer,"__________________\n");
        fprintf(fpointer,"||   barang   ||   Jumlah   ||      Subtotal      ||\n");
        fprintf(fpointer,"----------------------------------------------------\n");
        fprintf(fpointer,"  %s           ",barang->nama);
        fprintf(fpointer,"%d               ",kuantitas);
        fprintf(fpointer,"%d\n",subtotal);
        fclose(fpointer);
        flag++;
        fclose(fpointer);
    }
    else {
        update_to_file(barang[pil4-1].nama,kuantitas,subtotal);
    }
    printf("Ada tambahan lagi ?\n");
    printf("1.Ya\n");
    printf("2.Tidak\n");
    scanf("%d",&pil5);
    }
    while (pil5 == 1);
    point = hitung_poin(total);
    diskonpersen = persentase_diskon(total);
	total = Diskon(total);
    printf("Total : %d\n",total);
	printf ("Masukan jumlah uang pembayaran :");
    scanf("%d",&pembayaran);
	printf("|---------------------- NOTA PEMBELIAN ----------------------|\n");
	printf("|>>                Data Pembelanjaan Customer              <<|\n");
	printf("|| Pembelanjaan Anda adalah        = %d                  ||\n", total);
	printf("|| Uang Pembayaran Anda adalah     = %d                  ||\n", pembayaran);
	printf("\n|| Uang Kembalian Anda adalah      = %d                   ||\n", Pembayaran_Kembalian(total,pembayaran));
	printf("|=================Terima Kasih telah berbelanja==============|\n");
	printf("|                                                            |\n");
    fpointer = fopen("struk_belanja.txt","a");
    fprintf(fpointer,"====================================================\n");
    if(diskonpersen == 0){
        fprintf(fpointer,"Diskon :     --\n");
    }
    else{
    fprintf(fpointer," Diskon :      %d%%\n",diskonpersen);
    }
    fprintf(fpointer," Total :       %d\n",total);
    fprintf(fpointer,"====================================================\n");
    fclose(fpointer);
	printf("Member?\n");
    printf("1.Ya\n");
    printf("2.Tidak\n");
    scanf("%d",&pil2);
    if(pil2 == 1)
        cek_member();
    if (a == 0 || pil2 != 1){
    printf("\nApakah Anda ingin menjadi Member?\n");
    printf("1.Ya\n");
    printf("2.Tidak\n");
    scanf("%d",&pil3);
    if(pil2 != 1 && pil3 == 1){
        printf("Masukan Nama : ");
        scanf("%s",nama);
        strcpy(path,nama);
        strcat(path,".txt");
        jadi_member();
        a=0;
    }
    else if (pil3 == 1 && pil2 == 1)
    {
     jadi_member();
    }
    else {
        printf("Terima Kasih telah berbelanja. Silakan datang kembali!\n");
        return(0);
    }
    }else if (a == 1){
        strcpy(path,nama);
        strcat(path,".txt");
    }
    printf("Anda mendapatkan %d point.\n",point);
    point += get_point();

	printf("Apakah anda ingin menukar point?\n");
    printf("1.Ya\n");
    printf("2.Tidak\n");
	scanf("%d",&pilihan1);

    if(pilihan1 == 1){
        point = tukar_poin(point);
    }
    update_point(point);
    printf("Terima kasih sudah berbelanja. Silakan datang kembali!\n");
	do{
		printf("==================== Menu =================\n");
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
		printf("\nApakah anda ingin melanjutkan? (y/t): "); scanf("%[^\n]",&Lanjut);fflush(stdin);
	}while(strcmp(Lanjut,"y")==0);
}
