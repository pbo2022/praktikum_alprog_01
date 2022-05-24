#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void home();
float validasi();
void ulang();
void output();
struct kubus1 k1;
union kubus2 k2;

struct kubus1{
    float sisi;
    float luas;
    float volume;
};

union kubus2{
    float sisi;
    float luas;
    float volume;
};

int main(){
    system("cls");
	printf("\t\t\t\t==================================\n");
	printf("\t\t\t\t     PROGRAM MENARA HANOI         \n");
	printf("\t\t\t\t             OLEH:                \n");
	printf("\t\t\t\t          KELOMPOK 01             \n");
	printf("\t\t\t\t==================================\n");
	printf("\n\n\n\n\n\t\t\t\t*********************************	");
	printf("\n\t\t\t\t*** Tekan Enter untuk memulai ***			");
	printf("\n\t\t\t\t*********************************\n\n\n");
	getch();
	home();
    system("cls");
    return 0;
}

void home(){
    
    system("cls");
    printf("       ===================================== \n");
    printf("  =============  PROGRAM MENGHITUNG  =============\n");
    printf(" ============  LUAS PERMUKAAN & VOLUME  ===========\n");
    printf("  =============        KUBUS         =============\n");
    printf("       ===================================== \n");
    printf("================================================\n");
    printf("==> MASUKKAN PANJANG SISI KUBUS 1 [cm] : ");
    k1.sisi=validasi();
    printf("==> MASUKKAN PANJANG SISI KUBUS 2 [cm] : ");
    k2.sisi=validasi();
        if(k1.sisi<=0 || k2.sisi<=0){
           printf("\n------------------------------------------------\n");
            printf("|               INPUT ANDA ERROR               |\n");
            printf("|         SILAHKAN MENGULANGI INPUTAN          |\n");
            printf("------------------------------------------------\n");
            printf("==> Silahkan Masukan Angka Yang Baru : ");
        }
    system("cls");
    output();
}

void output(){
 
 
    printf("       ===================================== \n");
    printf("  =============  PROGRAM MENGHITUNG  =============\n");
    printf(" ============  LUAS PERMUKAAN & VOLUME  ===========\n");
    printf("  =============        KUBUS         =============\n");
    printf("       ===================================== \n");
    printf("+---------------------------------------------------+\n");
    printf("|               KUBUS DENGAN STRUCT                 |\n");
    printf("+---------------------------------------------------+\n");
    printf("==> SISI           : %.2f cm                         \n", k1.sisi);
            k1.luas=(k1.sisi*k1.sisi)*6;
    printf("==> LUAS PERMUKAAN : %.2f cm2                        \n",k1.luas);
            k1.volume=k1.sisi*k1.sisi*k1.sisi;
    printf("==> VOLUME         : %.2f cm3                        \n",k1.volume);
    printf("+===================================================+\n");
    printf("| Ukuran Memory Pada Kubus Struct : %d Byte         |\n", sizeof(k1));
    printf("+===================================================+\n");
    printf("+---------------------------------------------------+\n");
    printf("|               KUBUS DENGAN UNION                  |\n");
    printf("+---------------------------------------------------+\n");
    printf("==> SISI           : %.2f cm                         \n", k2.sisi);
            k2.luas=(k2.sisi*k2.sisi)*6;
    printf("==> LUAS PERMUKAAN : %.2f cm2                        \n",k2.luas);
            k2.volume=k1.sisi*k1.sisi*k1.sisi;
    printf("==> VOLUME         : %.2f cm3                        \n",k2.volume);
    printf("+===================================================+\n");
    printf("| Ukuran Memory Pada Kubus Onion : %d Byte           |\n", sizeof(k2));
    printf("+===================================================+\n");
    printf("Tekan apa saja untuk melanjutkan...");
	getch();
    ulang();
}

float validasi(){

    char input[100];
    int a, i;
    int negatif=0;
    int salah=0;
    int koma=0;
    int belakang=0;
    int deret=0;
    int depan=0;
    float nolKoma=1;
    float hasil;

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(input[a]=='.'){
            koma++;
            if(input[0]=='.' || input[a+1]=='\0' || koma>1 ){
                salah=1;
                input[a]='\0';
            }
            a++;
        }else if(input[a]>='0' && input[a]<='9'){
            if(koma==1){
                belakang=(belakang*10)+(input[a]-48);
                deret++;
                a++;
            }else{
                depan=(depan*10)+(input[a]-48);
                a++;
            }
        }else{
            salah=1;
            input[a]='\0';
        }
    }

    if(koma==1){
        for(i=0;i<deret;i++){
            nolKoma=nolKoma/10;
        }
        hasil=belakang*nolKoma+depan;

    }else{
        hasil=depan;
    }

    if(salah==1){
        printf("================================================\n");
        printf("|                 INPUT ERROR                  |\n");
        printf("|         SILAHKAN ULANGI INPUT ANDA           |\n");
        printf("================================================\n");

        printf("| SILAHKAN MASUKKAN ANGKA YANG BARU : ");
        return validasi();
    }else{
        return hasil;
    }

}

void ulang(){
    float a;
    int b;

    system("cls");
    printf("+-------------------------------------------------------+\n");
    printf("|  APAKAH ANDA INGIN MENGULANG PERHITUNGAN NILAI AKHIR? |\n");
    printf("+-------------------------------------------------------+\n");
    printf("| PILIHAN :                                             |\n");
    printf("| --> YA    = 1                                         |\n");
    printf("| --> TIDAK = 2                                         |\n");
    printf("+-------------------------------------------------------+\n");
    printf("==> Masukkan Pilihan : ");
    a=validasi();
    b=(int)a;
    
    while(a!=b || a<1 || a>2){
      printf("\n+----------------------------------------------+\n");
        printf("|               INPUT ANDA ERROR               |\n");
        printf("|         SILAHKAN MENGULANGI INPUTAN          |\n");
        printf("+----------------------------------------------+\n");
        printf("==> Silahkan Masukan Angka Yang Baru : ");
        a=validasi();
        b=(int)a;
    }

    system("cls");

    if(a==1){
        home();
    }else if(a==2){
        printf("\n  Terima Kasih");
				sleep(1);
				printf(".");
				sleep(1);
				printf(".");
				sleep(1);
				printf(".");
				sleep(1);
				printf(" :)");
				sleep(1);
    }
    exit(0);
}

