#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <conio.h>

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

float mean(int *data, int jumlah_data){
	int i;
	float sum=0;
	for(i=1 ; i<=jumlah_data ; i++){
		sum = sum + data[i];
	}
	float avg = sum/(float)jumlah_data;
	return (avg);
}

float median(float *data, int jumlah_data){
	float hasil;
	if(jumlah_data%2==0){
		hasil = (data[(jumlah_data/2)] + data[(jumlah_data/2)+1]) /2;
	}else{
		hasil = data[(jumlah_data/2)+1];
	}
	return hasil;
}


void modus(int n, int *data){
	int z=0, x=0, k=1, i, j; 
	int total[n];
	float mod[n];
	float temp;


//menghitung berapa kali muncul tiap angka 
	for(i=0;i<n;i++){
		total[i]=0;
		for(j=0;j<n;j++){
			if(data[i]==data[j]){
				total[i]++;
			}
		}
	}
	
	//menentukan nilai yang paling sering muncul 
	for(i=0;i<n;i++){
		if(total[i]>k){
			k=total[i];
		}
	}
	
	//jika modus lebih dari satu 
	for(i=0;i<n;i++){
		if(x==0){
			mod[x]=0;
		}else{
			mod[x]=mod[x-1];
		}
		if(total[i]==k){
			if(data[i]!=mod[x]){
				mod[x]=data[i]; 
				x++;
			}
		}
	}
	
	//Jika Semua angka muncul sama banyak 
	for(i=0;i<n;i++){
		if(total[i]==k){
		z++;
		}
	}
	if(z==n){ 
		x=0;
	}
	
	if (x==0){
		printf("\nTidak ada modus dari data tersebut!\n");
	}else{
		printf("\nHasil Dari Modus Adalah: "); 
		for(i=0;i<x;i++){
			printf(" %.0f", mod[i]);
			
			if(i<x-1){
				printf(",");
			}
		}
		printf("\n");
	}
}

void menu_mean(){
	int masukan;
	int data[100];
	int i;
	float hasil_mean;
	char ulang;
	
	system("cls");
	printf("           >>|MENGHITUNG MEAN|<<             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = tanpa_koma(1);	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = tanpa_koma(1);
    }
    
    hasil_mean = mean(data,masukan);
    printf("\n-----------------------------------\n");
 	printf("Nilai Mean\t: %.2f" ,hasil_mean);
	printf("\n\nApakah Anda ingin mengulang untuk menghitung mean ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			menu_mean();
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

void menu_median(){
	int masukan;
	float data[100];
	int i;
	float hasil_median;
	char ulang;
	
	system("cls");
	printf("           >>|MENGHITUNG MEDIAN|<<             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = tanpa_koma(1);	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = tanpa_koma(1);
    }
    
    hasil_median = median(data,masukan);
    printf("\n-----------------------------------\n");
 	printf("Nilai Median\t: %.2f" ,hasil_median);
	printf("\n\nApakah Anda ingin mengulang untuk menghitung median ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			menu_median();
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

void menu_modus(){
	int masukan;
	int data[100];
	int i;
	char ulang;
	
	system("cls");
	printf("           >>|MENGHITUNG MODUS|<<             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = tanpa_koma(1);	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = tanpa_koma(1);
    }
    
    printf("\n-----------------------------------\n");
 	printf("Nilai Modus\t:");
 	modus(masukan, data);
	printf("\n\nApakah Anda ingin mengulang untuk menghitung modus ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			menu_modus();
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

int main(){
    int menu, pilih;
	char cekenter;
	char enter = '\n';
	char ent;
	
	
	system("cls");
	printf("\t\t\t\t==================================\n");
	printf("\t\t\t\t     PROGRAM MENARA HANOI         \n");
	printf("\t\t\t\t             OLEH:                \n");
	printf("\t\t\t\t          KELOMPOK 01             \n");
	printf("\t\t\t\t==================================\n");
	printf("\n\n\n\n\n\t\t\t\t*********************************	");
	printf("\n\t\t\t\t*** Tekan Enter untuk memulai ***			");
	printf("\n\t\t\t\t*********************************\n\n\n");
	system("pause");
	system("cls");
	scanf("%c", &ent);
	
	if(ent = enter) {
	system("cls");
	printf("===================================================\n");
	printf("|                PROGRAM STATISTIKA               |\n");
	printf("===================================================\n\n\n");

	printf("    +----------------------------------------+\n");
	printf("    |                  MENU                  |\n");
	printf("    +----------------------------------------+\n");
	printf("    |         1. Menghitung Mean             |\n");
	printf("    |         2. Menghitung Median           |\n");
	printf("    |         3. Menghitung Modus            |\n");
	printf("    |         4. Tutup Program               |\n");
	printf("    +----------------------------------------+\n\n\n");
	

   while (1){
   	    printf("Masukkan pilihan menu : ");
   		pilih = tanpa_koma(1);
   		
		if (pilih == 1){
			menu_mean();
			break;
		}
	    else if (pilih == 2){
			menu_median();
			break;
		}
		else if (pilih == 3){
			menu_modus();
			break;
		}
		else if (pilih == 4){
			exit(0);
			break;
		}
		else{
			printf("Inputan salah! (Mohon hanya memasukkan angka dari 1 hingga 4)\n\n");
		}
   }
   }
	return 0;	
}

