#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int point, barang, harga, total, diskon,a;
char nama[50];
char path[100];

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

void tukar_poin (){
    int pilih,pil2,pilihan;
    struct merchandise gantungan_kunci,payung,boneka;
    gantungan_kunci.point = 2;
    payung.point=5;
    boneka.point=7;

    printf("point anda ada : %d\n",point);
    printf("Tukar poin?(ketik 1 untuk ya dan 2 untuk tidak)");
    scanf("%d",&pilihan);
    while(pilihan == 1 && point > 0){
        printf("ingin tukar poin dengan apa?\n");
        printf("1.Gantungan kunci\n");
        printf("2.Payung\n");
        printf("3.Boneka\n");
        printf("Masukan angka dari pilihan : ");
        scanf("%d",&pilih);

        if (pilih == 1){
            if( point < gantungan_kunci.point){
                printf("Point tidak mencukupi\n");
                exit(1);
            }
            point -= gantungan_kunci.point;
            printf("Anda mendapatkan gantungan kunci\n");
            printf("sisa poin anda : %d\n",point);
            printf("Tukar poin lagi?(ketik 1 untuk ya dan 2 untuk tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 2){
            if(point < payung.point){
                printf("Point tidak mencukupi");
                exit(1);
            }
            printf("Pilih warna\n");
            printf("1.Merah\n");
            printf("2.Biru\n");
            printf("3.Hitam\n");
            printf("Masukan angka sesuai pilihan : ");
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
            point -= payung.point;
            printf("anda mendapatkan payung berwarna : %s\n",payung.pilihan_warna);
            printf("sisa poin anda : %d\n",point);
            printf("Tukar poin lagi?(ketik 1 untuk ya dan 2 untuk tidak)\n");
            scanf("%d",&pilihan);
        }
        else if(pilih == 3){
            if(point <boneka.point){
                printf("Point tidak mencukupi");
                exit(1);
            }
            point -= boneka.point;
            printf("Anda mendapatkan boneka mascot\n");
            printf("sisa poin anda : %d\n",point);
            printf("Tukar poin lagi?(ketik 1 untuk ya dan 2 untuk tidak)\n");
            scanf("%d",&pilihan);
    }
        }
	 if(point == 0){
            printf("Point anda sudah habis\n");
        }
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
void judul(){
    printf("===========================================\n");
    printf("**  **    ***     *****   *****  *****  \n");
    printf("** **    ** **   ***       ***   **  ** \n");
    printf("*****   *******   *****    ***   *****  \n");
    printf("**  **  **   **      ***   ***   **  **\n");
    printf("**  **  **   **  *****    *****  **  **\n");
    printf("===========================================\n");
}
int main(){
	int pilihan1,pil2,pil3;
    judul();
	TotalBelanja();
	point = hitung_poin(total);
	Diskon();
	printf("Total Pembelanjaan anda adalah  = %d\n", total);
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
    return 0;
}
