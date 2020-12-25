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
        printf("Silakan masukkan nomor pilihan Anda: ");
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
	long ID;
    char Tanggal [10];
}Nota;
FILE*PENJUALAN;
char txt[20] = "Nota Penjualan.txt";

void Create(){
	Nota Penjualan;
	PENJUALAN=fopen(txt,"a");
	printf("=========================================================================\n");
	printf("====================== LIST PENJUALAN MINIMARKET X ======================\n");
	printf("\nNama Customer \t\t\t: ");scanf("%[^\n]",&Penjualan.Nama);fflush(stdin);
	printf("ID Customer \t\t\t: ");scanf("%i",&Penjualan.ID);fflush(stdin);
	printf("Nomor Member Customer \t\t: ");scanf("%s",&Penjualan.Member);fflush(stdin);
	printf("No Telepon Customer \t\t: ");scanf("%[^\n]",&Penjualan.Telp);fflush(stdin);
	printf("Tanggal Pembelian Customer \t: ");scanf("%s", &Penjualan.Tanggal);fflush (stdin);
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
		fscanf(PENJUALAN,"%[^]%i_%s_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp);
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
		fscanf(PENJUALAN,"%[^]%i_%s_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp);
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
		fscanf(PENJUALAN,"%[^]%i_%s_%s_%[^\n]\n",&Penjualan.Nama,&Penjualan.ID,&Penjualan.Member,&Penjualan.Telp);
		fflush(stdin);
		if(id==Penjualan.ID){
			printf("Nama Customer \t : %s\n",Penjualan.Nama);
			printf("ID Customer \t : %i\n",Penjualan.ID);
			printf("Member Customer \t : %s\n",Penjualan.Member);
			printf("No Telepon Customer \t : %s\n\n",Penjualan.Telp);
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
    

    printf("Masukan nama : ");
    scanf("%s",nama);

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
struct list
{
    char *nama;
    int harga;
};
void menu_barang(struct list *barang){
    

    printf("+------------------------------------+\n");
    printf("|1.%s     2.%s   3.%s      |\n",barang[0].nama,barang[1].nama,barang[2].nama);
    printf("|4.%s  5.%s 6.%s     |\n",barang[3].nama,barang[4].nama,barang[5].nama);
    printf("|7.%s 8.%s   9.%s|\n",barang[6].nama,barang[7].nama,barang[8].nama);
    printf("+------------------------------------+\n");
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
    struct list barang[9];
    barang[0].nama = "Mie";
    barang[0].harga = 2500;
    barang[1].nama = "Gas (3kg)";
    barang[1].harga = 25000;
    barang[2].nama = "Odol";
    barang[2].harga = 1200;
    barang[3].nama = "Permen";
    barang[3].harga = 500;
    barang[4].nama = "Gas (5,5kg)";
    barang[4].harga = 67500;
    barang[5].nama = "Sabun";
    barang[5].harga = 3000;
    barang[6].nama = "Biskuit";
    barang[6].harga = 10000;
    barang[7].nama = "Teh celup";
    barang[7].harga = 13500;
    barang[8].nama = "Gula (1kg)";
    barang[8].harga = 13000;
    printf("\n|==================== KASIR MINIMARKET X ====================|\n");
	printf("|                                                            |\n");
     menu_barang(barang);
    do{
    printf("Pilih barang yang dibeli : ");
    scanf("%d",&pil4);
    if(pil4 > 9){
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
        fprintf(fpointer,"____________________________________________________\n");
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
    printf("Ada lagi ?\n");
    printf("1.YES\n");
    printf("2.NO\n");
    scanf("%d",&pil5);
    }
    while (pil5 == 1);
    point = hitung_poin(total);
    diskonpersen = persentase_diskon(total);
	total = Diskon(total);
    printf("Total : %d\n",total);
	printf ("Masukan uang pembayaran :");
    scanf("%d",&pembayaran);
	printf("|---------------------- NOTA PEMBELIAN ----------------------|\n");
	printf("|>>                Data Pembelanjaan Customer              <<|\n");
	printf("|| Pembelanjaan Anda adalah        = %d                  ||\n", total);
	printf("|| Uang Pembayaran Anda adalah     = %d                 ||\n", pembayaran);
	printf("\n|| Uang Kembalian Anda adalah      = %d                  ||\n", Pembayaran_Kembalian(total,pembayaran));
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
    fprintf(fpointer," total :       %d\n",total);
    fprintf(fpointer,"====================================================\n");
    fclose(fpointer);
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
    if(pil2 != 1 && pil3 == 1){
        printf("Masukan nama :");
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
        point = tukar_poin(point);
    }
    update_point(point);
    printf("Terima kasih sudah berbelanja\n");
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
