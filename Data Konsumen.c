#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

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
	printf("Masukkan Nama Customer \t: ");scanf("%[^\n]",&Penjualan.Nama);fflush(stdin);
	printf("Masukkan ID Customer \t: ");scanf("%i",&Penjualan.ID);fflush(stdin);
	printf("Masukkan Member Customer \t: ");scanf("%s",&Penjualan.Member);fflush(stdin);
	printf("Masukkan No Telepon Customer \t: ");scanf("%s",&Penjualan.Telp);fflush(stdin);
	printf("Masukkan Tanggal Transaksi \t: ");scanf("%s",&Penjualan.Tanggal);fflush(stdin);
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
		fscanf(PENJUALAN,"%[^_]_%i_%s_%s_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp,&Penjualan[index].Tanggal);
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
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	index=0;
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp),&Penjualan[index].Tanggal;
		fflush(stdin);
		if(id==Penjualan[index].ID){
			printf("Masukkan Nama Customer \t: ");scanf("%[^\n]",&Penjualan[index].Nama);fflush(stdin);
			printf("Masukkan ID Customer \t: ");scanf("%i",&Penjualan[index].ID);fflush(stdin);
			printf("Masukkan Member Customer :\t");scanf("%s",&Penjualan[index].Member);fflush(stdin);
			printf("Masukkan Telp Customer \t: ");scanf("%s",&Penjualan[index].Telp);fflush(stdin);
			printf("Masukkan Tanggal Transaksi \t: ");scanf("%[^\n]",&Penjualan[index].Tanggal);fflush(stdin);
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
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Penjualan.Nama,&Penjualan.ID,&Penjualan.Member,&Penjualan.Telp,&Penjualan.Tanggal);
		fflush(stdin);
		if(id==Penjualan.ID){
			printf("Nama Customer \t : %s\n",Penjualan.Nama);
			printf("ID Customer \t : %i\n",Penjualan.ID);
			printf("Member Customer \t : %s\n",Penjualan.Member);
			printf("No Telepon Customer \t : %s\n",Penjualan.Telp);
			printf("Tanggal Transaksi \t : %s\n",Penjualan.Tanggal);
		}
	}
}

int main(){
	char Lanjut[2];
	int menu;
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
