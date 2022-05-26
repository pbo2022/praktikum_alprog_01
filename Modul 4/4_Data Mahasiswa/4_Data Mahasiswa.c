#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef char biodata[300];
typedef struct{
    biodata nama;
    biodata NIM;
}mahasiswa;

void input_data_mhs(mahasiswa mhs);
void tampilkan_data_mhs(mahasiswa mhs);
void *input_desimal();
int input_pilihan();
void header();
void waiting();

int main(){
    system ("cls");
    mahasiswa mhs;
    char update;
    int op;
    header();
    printf("\n\tMasukkan pilihan");
    printf("\n\t1. Menginput data");
    printf("\n\t2. Mencari data");
    printf("\n\t3. Exit");
    printf("\n\n\tMasukkan pilihan   : ");
    op = input_pilihan();
    if(op==1){
    	system("cls");
    	waiting();
    	system("cls");
    	header();
    	printf("\n\n");
        input_data_mhs(mhs);
    }
    else if(op==2){
    	system("cls");
    	waiting();
    	system("cls");
    	header();
    	printf("\n\n");
        tampilkan_data_mhs(mhs);
    }
    else if(op==3){
        system("exit");
    }
    else{
        printf("\n\t\tOPSI YANG DIMASUKAN SALAH!");
        getch();
        system("cls");
        main();
    }

return 0;}

void input_data_mhs(mahasiswa mhs){
    int pengulangan;
    char kode,y,t;
    pengulangan=0;
   
    do{
    biodata induk,name;
    printf("\t\t\t\t    |======   **********************   =====|\n"
           "\t\t\t\t    |          INPUT DATA MAHASISWA         |\n"
           "\t\t\t\t    |======   **********************   =====|\n\n");
    printf("\tMasukan NIM Mahasiswa    : ");
    strcpy(mhs.NIM , input_desimal());
    fflush(stdin);//FFLASH ITU DIPAKE KETIKA KITA MENGINPUTKAN INTEGER DULUAN BARU CHAR,KALO GAADA FFLUSH DIA BAKAL ERROR KARENA ENTERNYA MASUK DI CHARACTERNYA
    printf("\n\tMasukan Nama Mahasiswa   : ");
    gets(mhs.nama);
    fflush(stdin);
    FILE *out=fopen("databases_mhs.txt","r");
    if(!out){
        printf("\n\tDATA BELUM ADA");
    }else{
        while(!feof(out)){
            fscanf(out,"%s # %[^#] #\n",&induk,&name);
        }
        fclose(out);
    }
    if(strcmp(mhs.NIM,induk)==0){
    	printf("\n\t\tDATA SUDAH ADA");
    }
    else{
        FILE *in=fopen("databases_mhs.txt","a");
        fprintf(in,"%s # %[^#] #\n",mhs.NIM,mhs.nama);
        fclose(in);
    }
    printf("\n\n\t\tApakah ingin kembali meninput data (y/t):");
    scanf("%s", &kode);
    if(kode=='y'){
        system("cls");
    }
    else if(kode=='t'){
        system("cls");
        main();
    }
    else{
        break;
    }
    }while(pengulangan<1);
}

void tampilkan_data_mhs(mahasiswa mhs){
    int pengulangan;
    char kode,y,t;
    pengulangan=0;
    do{
    biodata data;
    printf("\t\t\t\t    |======   **********************   =====|\n"
           "\t\t\t\t    |        TAMPILKAN DATA MAHASISWA       |\n"
           "\t\t\t\t    |======   **********************   =====|\n\n");
    printf("\n\tMasukan NIM mahasiswa yang ingin dicari : ");
    scanf("%s",&data);
    fflush(stdin);

FILE *in=fopen("databases_mhs.txt","r");
    if(in==NULL){
        printf("\n\t\tDATA TIDAK ADA\n");
    }else{
        while(!feof(in)){
            fflush(stdin);
            fscanf(in,"%s # %[^#] #\n",&mhs.NIM,&mhs.nama);
            if(strcmp(mhs.NIM,data)==0){
            printf("\n\t\tDATA MAHASISWA\n");
            printf("\tNIM       : %s\n",mhs.NIM);
            printf("\tNama      : %s\n",mhs.nama);
            }
        }
        fclose(in);
    }
    printf("\n\n\t\tApakah ingin kembali menampilkan data (y/t):");
    scanf("%s", &kode);
    if(kode=='y'){
        system("cls");
    }
    else if(kode=='t'){
        system("cls");
        main();
    }
    else{
        break;
    }
    }while(pengulangan<1);
}

void *input_desimal() {
	char ch;
	char *data;
	int cek = 0;
	data = (char *)malloc(sizeof(char)); 
	
	while ((ch = getch()) != 13)//jadi di input desimal nii fungsinya yaitu ngecek angka desimal,misal yanng dimasukin tu angka 0-9,nah jika user ngetk angka segitu pas running program dia akan muncul di terminal,kalo bukan dari itu dia bakal gak muncul di terminal
	{
		if ((ch >= '0' && ch <= '9')) {
		printf("%c", ch); 
		data[cek] = ch; 
		cek++;
		} 
	}
	data[cek] = '\0'; 
	return (void *)data;
}

int input_pilihan() {
	char ch;
	char *data;
	int cek = 0;
	data = (char *)malloc(sizeof(char)); 
	
	while ((ch = getch()) != 13)//jadi di input desimal nii fungsinya yaitu ngecek angka desimal,misal yanng dimasukin tu angka 0-9,nah jika user ngetk angka segitu pas running program dia akan muncul di terminal,kalo bukan dari itu dia bakal gak muncul di terminal
	{
		if ((ch >= '1' && ch <= '3')) {
		printf("%c", ch); 
		data[cek] = ch; 
		cek++;
		} 
	}
	data[cek] = '\0'; 
	return atoi(data);
}

void header() {
	printf("\t\t\t\t|===============================================|\n"
           "\t\t\t\t|==========  PRAKTIKUM ALPROG MODUL 4 ==========|\n"
           "\t\t\t\t|==========         KELOMPOK 1        ==========|\n"
           "\t\t\t\t|           *************************           |\n"
           "\t\t\t\t|========   Program 4.4 Data Mahasiswa  ========|\n"
           "\t\t\t\t|========       By Tjok Semarajaya      ========|\n"
           "\t\t\t\t|===============================================|\n\n");
}

void waiting(){

	system("cls");
		int a;
		for(a=0;a<=12;a++){
			printf("_______");
			Sleep(100);
		}
	system("cls");
}
