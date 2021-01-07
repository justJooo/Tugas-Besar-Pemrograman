typedef struct{//Perlu dirubah bila ingin di update
	char Nama[50];
	char Member[20];
	char Telp[13];
	char Tanggal[10];
	long ID;
}Nota;
FILE*PENJUALAN;
char txt[20] = "Nota Penjualan.txt";

//Melakukan Record Data untuk Member
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

//Menghapus Record Data Member
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
		fprintf(PENJUALAN,"%s_%i_%s_%s_%s\n",Penjualan[i].Nama,Penjualan[i].ID,Penjualan[i].Member,Penjualan[i].Telp),Penjualan[i].Tanggal;
	}
	fclose(PENJUALAN);
}

//Melakukan Updating pada Record Data
void Update(){
	Nota Penjualan[50];
	int id,index,i;
	printf("Masukan ID yang ingin diubah \t: ");scanf("%i",&id);fflush(stdin);
	printf("\n");
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	index=0;
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Penjualan[index].Nama,&Penjualan[index].ID,&Penjualan[index].Member,&Penjualan[index].Telp,&Penjualan[index].Tanggal);
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

//Memungkinkan User untuk melakukan pembacaan pada Record Data
void Read(){
	Nota Penjualan;
	int id;
	printf("Masukan ID yang ingin ditampilkan \t: ");scanf("%i",&id);fflush(stdin);
	printf("\n");
	PENJUALAN=fopen("Nota Penjualan.txt","r");
	while (!feof(PENJUALAN)){
		fscanf(PENJUALAN,"%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Penjualan.Nama,&Penjualan.ID,&Penjualan.Member,&Penjualan.Telp,&Penjualan.Tanggal);
		fflush(stdin);
		if(id==Penjualan.ID){
			printf("Nama Customer \t\t\t\t : %s\n",Penjualan.Nama);
			printf("ID Customer \t\t\t\t : %i\n",Penjualan.ID);
			printf("Member Customer \t\t\t : %s\n",Penjualan.Member);
			printf("No Telepon Customer \t\t\t : %s\n",Penjualan.Telp);
			printf("Tanggal Transaksi \t\t\t : %s\n",Penjualan.Tanggal);
		}
	}
    fclose(PENJUALAN);
}
