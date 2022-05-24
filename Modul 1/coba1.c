#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

 
void Jumlah();
void Kurang();
void Kali();
void Bagi();
void Mod();
 
int main(){
	 int operasi;
    char u;
    mengulang : 
    printf( " ===== Kalkulator Sederhana =====\n \n");
	printf( " Pilih Operasi Aritmatika\n" );
    printf( " 1. Penjumlahan \n" );
    printf(" 2. Pengurangan \n" );
    printf( " 3. Perkalian \n" );
    printf( " 4. Pembagian \n" );
    printf( " 5. Modulus \n" );
    printf( " 0. Exit \n" );
    printf( "\n Pilihan Anda : ");
    scanf("%d", &operasi);
    printf( " ================================================== \n \n" );
    switch(operasi){
        case 1 :
            Jumlah();
            break;
        case 2 :
            Kurang();
            break;
        case 3 :
            Kali();
            break;
        case 4 :
            Bagi();
            break;
        case 5 :
            Mod();
            break;
        case 0 :
            exit(0);
            break;
        default :
            system("cls");
            printf( " Pilihan Anda Tidak Ada Dalam Menu. \n Silahkan Input Ulang \n" );
            goto mengulang;
            break;
    }
    printf("\n\n");
    printf( " ================================================== \n" );
    printf( " Tekan Y jika Ingin Menginput Ulang \n");
	printf( " Atau Tekan Huruf Lainnya Untuk Keluar \n " );
    scanf("%c", &u);
    if(u == 'Y' || u == 'y'){
        system("cls");
        goto mengulang;
    } else {
        exit(0);
    }
    return 0;
}

void Jumlah(){
    float a, b;
    float jumlah;
    printf( " Penjumlahan\n\n" );
    printf( " Masukkan Bilangan Pertama : ");
    scanf("%f", &a);
    printf( " Masukkan Bilangan Kedua : " );
    scanf("%f", &b);
    jumlah = a+b;
    printf( " Hasil Penghitungan : ", jumlah);
}
 
void Kurang(){
    float a, b;
    float kurang;
    printf( " Pengurangan\n\n" );
    printf(" Masukkan Bilangan Pertama : ");
    scanf("%f", &a);
    printf( " Masukkan Bilangan Kedua : ");
    scanf("%f", &b);
    kurang = a-b;
    printf( " Hasil Penghitungan : " , kurang );
}
 
void Kali(){
    float a, b;
    float kali;
    printf( " Perkalian\n\n" );
    printf( " Masukkan Bilangan Pertama : ");
    scanf("%f", &a);
    printf( " Masukkan Bilangan Kedua : ");
    scanf("%f", &b);
    kali = a*b;
    printf( " Hasil Penghitungan : ", kali );
}
 
void Bagi(){
    float a, b;
    float bagi;
    printf( " Pembagian\n\n" );
    printf( " Masukkan Bilangan Pertama : ");
    scanf("%f", &a);
    printf( " Masukkan Bilangan Kedua : ");
    scanf("%f", &b);
    bagi = a/b;
    printf( " Hasil Penghitungan : ", bagi );
}
 
void Mod(){
    int a, b;
    float modulus = 0;
    printf( " Modulus\n\n");
    printf( " Masukkan Bilangan : ");
    scanf("%f", &a);
    printf( " Masukkan Bilangan Pembagi : ");
    scanf("%f", &b);
    modulus = a%b;
    printf( " Hasil Penghitungan : ", modulus);
}


