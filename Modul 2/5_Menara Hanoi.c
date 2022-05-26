#include <stdio.h>
#include <stdlib.h>


float tanpa_koma(){
    char masukan[100];
    while(1){
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int salah = 0;
    int minus = 0;
    float hasil;

        scanf("%[^\n]", &masukan);
        fflush(stdin);

         while(masukan[i] != '\0'){
            if(masukan[i] == '.'){
                salah = 1;
                masukan[i] = '\0';
            }else if(masukan[i] == ' '){
                salah = 1;
                masukan[i] = '\0';
            }else if(masukan[i]>='0' && masukan[i]<='9'){
                isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                i++;
            }else{
                salah = 1;
                masukan[i] = '\0';
            }
            // a1hj
        }//end while
            hasil = isi_depan;
        if(salah == 1){
            printf("--->Masukkan salah! Masukkan angka yang benar : ");
        }else{
            return hasil;
        }
    }
}

char exite (){
    char huruf;
    scanf("%c",&huruf);
            if(huruf=='y'  || huruf=='Y'){
                return huruf;
            }else if (huruf=='n'  || huruf=='N'){
                return huruf;
            }else if (huruf=='t' || huruf=='T'){
            	return huruf;
			}else{
                printf("--->inputan tidak valid ! coba lagi :");
                fflush (stdin);
            }
    return exite();
}

void pm(int start, int end){
	printf("Pindahkan cakram paling atas dari tiang %d ke tiang %d \n", start, end );
}

void hanoiR(int n, int start, int end){
	int other;
	if (n==1) {
		pm(start, end);
	}else {
		other = 6 - (start +end);
		hanoiR(n-1, start, other);
		pm(start,end);
		hanoiR(n-1, other, end);
	}
}

void hanoiI(int ckr){
   int a;
   for (a = 1; a < (1 << ckr); a++){
   	printf( "Pindahkan cakram paling atas dari tiang %i ke tiang %i \n",((a&a-1)%3)+1, (((a|a-1)+1)%3)+1 );
   }
}


int jumlahIteratif(int jml){
	int i;
	int j = 1;
	for (i = 1; i <= jml; i++){
		j = 2 * j;
	}
	return j - 1;
}

void hanoiRekursif(){
	int jumlah;
	char ulang;
	int mulai = 1;
	int akhir = 3;
	int masukan;
	
	system("cls");
	
	printf("   >>|PROGRAM MENARA HANOI REKURSIF|<<  \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah cakram : ");
	masukan = tanpa_koma(1);	
	
	printf("Jumlah langkah paling sedikit dari %d cakram menara hanoi =  %d \n", masukan, jumlahIteratif(masukan));
	printf("==============================================================\n");
	printf("Langkah : \n");
	hanoiR(masukan, mulai, akhir);
	printf("-----------------------------------\n\n");
	printf("Apakah Anda ingin mengulang langkah hanoi rekursif ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			hanoiRekursif();
			break;
		}
		else if (ulang == 'N' || ulang == 'n'){
			main();
			break;
		}
		else if (ulang == 'T' || ulang == 't'){
			exit(0);
			break;
		}
		else{
			printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
		}
   }
		
}

void hanoiIteratif(){
	int jumlah;
	char ulang;
	int mulai = 1;
	int akhir = 3;
	int masukan;
	
	system("cls");
	
	printf("   >>|PROGRAM MENARA HANOI ITERATIF|<<  \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah cakram: ");
    masukan = tanpa_koma(1);
    
	printf("Jumlah langkah paling sedikit dari %d cakram menara hanoi =  %d \n", masukan, jumlahIteratif(masukan));
	printf("==============================================================\n");
	printf("Langkah : \n");
	hanoiI(masukan);
	printf("-----------------------------------\n\n");
	printf("Apakah Anda ingin mengulang langkah hanoi iteratif ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");
	
   while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			hanoiIteratif();
			break;
		}
		else if (ulang == 'N' || ulang == 'n'){
			main();
			break;
		}
		else if (ulang == 'T' || ulang == 't'){
			exit(0);
			break;
		}
		else{
			printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
		}
   }
}



int main()
{
	int menu, pilih;
	char cekenter;
	char enter = '\n';
	char ent;
	
	system("cls");
	fflush (stdin);
	printf("\t\t\t\t==================================\n");
	printf("\t\t\t\t     PROGRAM MENARA HANOI         \n");
	printf("\t\t\t\t             OLEH:                \n");
	printf("\t\t\t\t          KELOMPOK 01             \n");
	printf("\t\t\t\t==================================\n");
	printf("\n\n\n\n\n\t\t\t\t*********************************	");
	printf("\n\t\t\t\t*** Tekan Enter untuk memulai ***			");
	printf("\n\t\t\t\t*********************************\n\n\n");
	system("pause");
	scanf("%c", &ent);
	
	if(ent = enter) {
	system("cls");
	printf("===================================================\n");
	printf("|               PROGRAM MENARA HANOI              |\n");
	printf("===================================================\n\n\n");

	printf("    +----------------------------------------+\n");
	printf("    |                  MENU                  |\n");
	printf("    +----------------------------------------+\n");
	printf("    |         1. Menara Hanoi Rekursif       |\n");
	printf("    |         2. Menara Hanoi Iteratif       |\n");
	printf("    |         3. Tutup Program               |\n");
	printf("    +----------------------------------------+\n\n\n");
	

   while (1){
   	    printf("Masukkan pilihan menu : ");
   		pilih = tanpa_koma(1);
   		
		if (pilih == 1){
			hanoiRekursif();
			break;
		}
	    else if (pilih == 2){
			hanoiIteratif();
			break;
		}
		else if (pilih == 3){
			exit(0);
			break;
		}
		else{
			printf("Inputan salah! (Mohon hanya memasukkan angka dari 1 hingga 3)\n\n");
		}
   }
   }
	return 0;

}


