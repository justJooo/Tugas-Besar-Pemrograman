//Bug Fixing menambahkan seleksi kondisi Pembayaran

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
else if (pembayaran = total){
	kembalian=0;
	return kembalian;
}
}
}
