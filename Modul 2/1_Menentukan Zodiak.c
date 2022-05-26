#include <stdio.h>
#include <string.h>

char nama[30];
char bulan[10];
int tanggal=0;
int tahun;
char *bintang;

void menuUtama();
void caribintang();
void hasil();
int keluar();
double check();

int main(){
	menuUtama ();
	keluar();
}


void menuUtama (){

	system("cls");
        printf("\t+==============================================================+\n");
        printf("\t|                 CARI TAU ZODIAK ANDA DISINI                  |\n");
        printf("\t+==============================================================+\n");
        printf("\t|                                                              |\n");
		printf("\t|\tMasukkan Nama Anda             : "); scanf(" %[^\n]s", &nama);
		printf("\t|\tTgl Lahir(ex: 01 Januari 2000 ): "); scanf(" %d %s", &tanggal, &bulan, &tahun);
		printf("\t|                                                              |\n");
		printf("\t+--------------------------------------------------------------+\n");
        tanggal, bulan, tahun = check();
		caribintang(tanggal, bulan, tahun);
		
}

double check(){
	double input;
	char checkinput;
	int cek;

	cek=scanf("%lf%c", &input,&checkinput);

	if(cek!=2 || checkinput!='\n'){
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t >>  input anda invalid!  << \n\n");
		system("pause");
		system("cls");
		cek=1;
		fflush(stdin);
		menuUtama();
	}
	else{
		cek=0;
		fflush(stdin);
		return input;
	}

}

void caribintang() {
    printf("\n\n");
    
	if ((strcmp(bulan, "Januari") == 0) || (strcmp(bulan, "januari") == 0)  || (strcmp(bulan, "JANUARI") == 0)) {
		if (tanggal >= 1 && tanggal <= 19) {
			bintang = "Capricorn";hasil();
		} else if (tanggal >= 20 && tanggal <= 31) {
			bintang = "Aquarius"; hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		}
	} else if ((strcmp(bulan, "Februari") == 0) || (strcmp(bulan, "februari") == 0) || (strcmp(bulan, "FEBRUARI") == 0)) {
	    if ((tahun % 400 ==0) ||(tahun%4==0)) { 
            if (tanggal > 0 && tanggal < 19) {
                bintang = "Aquarius";hasil();
            } else if (tanggal > 18 && tanggal <= 29) {
                bintang = "Pisces"; hasil();
            } else {
                printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
                bintang = "-";
            }
        } else if (tahun % 100 ==0) { 
            if (tanggal > 0 && tanggal < 19) {
                bintang = "Aquarius";hasil();
            } else if (tanggal > 18 && tanggal <= 28) {
                bintang = "Pisces"; hasil();
            } else {
                printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
                bintang = "-";
            }
        } else { 
            if (tanggal > 0 && tanggal < 19) {
                bintang = "Aquarius";hasil();
            } else if (tanggal > 18 && tanggal <= 28) {
                bintang = "Pisces"; hasil();
            } else {
                printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
                bintang = "-";
            }
        } 
	}
	else if ((strcmp(bulan, "Maret") == 0) || (strcmp(bulan, "maret") == 0) || (strcmp(bulan, "MARET") == 0))  {
		if (tanggal > 0 && tanggal < 21) {
			bintang = "Pisces";hasil();
		} else if (tanggal > 20 && tanggal < 32) {
			bintang = "Aries";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "April") == 0) || (strcmp(bulan, "april") == 0) || (strcmp(bulan, "APRIL") == 0)) {
		if (tanggal > 0 && tanggal < 20) {
			bintang = "Aries";hasil();
		} else if (tanggal > 19 && tanggal < 31) {
			bintang = "Taurus";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "Mei") == 0) || (strcmp(bulan, "mei") == 0) || (strcmp(bulan, "MEI") == 0)) {
		if (tanggal > 0 && tanggal < 21) {
			bintang = "Taurus";hasil();
		} else if (tanggal > 20 && tanggal < 31) {
			bintang = "Gemini";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "Juni") == 0) || (strcmp(bulan, "juni") == 0)  || (strcmp(bulan, "JUNI") == 0)) {
		if (tanggal > 0 && tanggal < 21) {
			bintang = "Gemini";hasil();
		} else if (tanggal > 20 && tanggal < 31) {
			bintang = "Cancer";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "Juli") == 0) || (strcmp(bulan, "juli") == 0) || (strcmp(bulan, "JULI") == 0))  {
		if (tanggal > 0 && tanggal < 23) {
			bintang = "Cancer";hasil();
		} else if (tanggal > 22 && tanggal < 32) {
			bintang = "Leo";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "Agustus") == 0) || (strcmp(bulan, "agustus") == 0) || (strcmp(bulan, "AGUSTUS") == 0))  {
		if (tanggal > 0 && tanggal < 23) {
			bintang = "Leo";hasil();
		} else if (tanggal > 22 && tanggal < 32) {
			bintang = "Virgo";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "September") == 0) || (strcmp(bulan, "september") == 0) || (strcmp(bulan, "SEPTEMBER") == 0)) {
		if (tanggal > 0 && tanggal < 23) {
			bintang = "Virgo"; hasil();
		} else if (tanggal > 22 && tanggal < 31) {
			bintang = "Libra";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		}
	} else if ((strcmp(bulan, "Oktober") == 0) || (strcmp(bulan, "oktober") == 0) || (strcmp(bulan, "OKTOBER") == 0))  {
		if (tanggal > 0 && tanggal < 23) {
			bintang = "Libra"; hasil();
		} else if (tanggal > 22 && tanggal < 32) {
			bintang = "Scorpio";hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		} 
	} else if ((strcmp(bulan, "November") == 0) || (strcmp(bulan, "november") == 0) || (strcmp(bulan, "NOVEMBER") == 0))  {
		if (tanggal > 0 && tanggal < 22) {
			bintang = "Scorpio"; hasil();
		} else if (tanggal > 22 && tanggal < 31) {
			bintang = "Sagitarius";
			hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		}
	} else if ((strcmp(bulan, "Desember") == 0) || (strcmp(bulan, "desember") == 0) || (strcmp(bulan, "DESEMBER") == 0))  {
		if (tanggal > 0 && tanggal < 22) {
			bintang = "Sagitarius"; hasil();
		} else if (tanggal > 21 && tanggal < 32) {
			bintang = "Carpicorn"; hasil();
		} else {
			printf("\n\n\t\t>>Masukkan Tanggal Yang Benar ! Tanggal tidak sampai %d\n", tanggal);
			bintang = "-";
		}
		
	} else {
		printf("\t\tFormat Bulan Salah\n");
		bintang = "-";
	}

}

void hasil(){
    printf("\t+==============================================================+\n");
    printf("\t|                                                              |\n");
	printf("\n\t|\tNama: %s\n", nama);
	printf("\t|\tTanggal Lahir: %d %s %d\n", tanggal, bulan, tahun);
	printf("\t|\tZodiak: %s\n", bintang);
	printf("\t|                                                              |\n");
	printf("\t+==============================================================+\n");
	keluar();
}




int keluar (){
	int pilih;
	printf("\n\n");
	printf("\t                     >> Opsi Kembali <<                \n");
	printf("\t ++--------------------------------------------------++\n");
	printf("\t ||             [1] | Kembali ke Halaman Utama       ||\n");
	printf("\t ||                                                  ||\n");
	printf("\t ||             [2] | Keluar dari program            ||\n");
	printf("\t ++--------------------------------------------------++\n");
	printf("\t || >> Silahkan pilih : ");
	pilih=check();

	if(pilih==1){
		menuUtama ();
	}
	else if(pilih==2){
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t >>  Terima kasih telah menggunakan program kami! << \n");
		printf("\t\t\t >>               ENTER 1X UNTUK KELUAR!          << ");
		return 0;
	
	}
	else{
		system("cls");
		printf("\t\t\t >>  Masukan inputan yang benar! << \n");
		getch();
	}
}

