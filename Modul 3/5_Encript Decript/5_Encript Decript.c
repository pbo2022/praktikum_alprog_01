#include <stdio.h> 
#include <stdlib.h>//fflush
#include <conio.h>
#include <string.h>

int enkripsi(); 
int dekripsi();
void header();
int input_desimal();
char * input_string();
void reinpt();
int pilihan;


int main(){
	int input; 
	fflush(stdin);
	header();	
	printf("\n\t\t\tPilih operasi yang diinginkan:          \n");
	printf("\t\t\t[1] Enkripsi           			    	\n");
	printf("\t\t\t[2] Dekripsi                              \n");
	printf("\t\t\t[0] Keluar                             	\n");
	printf("\n\t\t\tMasukkan pilihan anda :  ");
	pilihan = input_pilihan();
	header();
	if (pilihan == 1) {
		system("cls");
		header();
		enkripsi(); 
    }
	else if (pilihan == 2) {
			system("cls");
			header();
			dekripsi(); 
	}
	else if (pilihan == 0) {
		return 0;
	}
	
}

int enkripsi(){ char s[100]; 
		int i, key;
		printf("\n\t\t\tMasukan pesan yang akan di-enkripsi : ");
		strcpy(s,input_string());
		printf("\n\t\t\tMasukkan jumlah pergeseran :");
		key = input_desimal();
		for(i = 0; s[i] != '\0'; ++i){
			if(s[i] >= 'A' && s[i] <= 'Z') { 
			s[i] = s[i] + 32;
		}
		if(s[i] >= 'a' && s[i] <= 'z'){ 
		s[i] = s[i] + key; 
		if(s[i] > 'z'){
			s[i] = s[i] - 26;
			}
		s[i] = s[i] - 32;
		} 
	}
	printf("\n\t\t\tHasil Enkripsi : %s", s); 
	reinpt();
}

int dekripsi(){ 
	char s[100]; 
	int i, key;
	printf("\n\t\t\tMasukan Pesan yang akan di-dekripsi: "); 
	strcpy(s,input_string());
	printf("\n\t\t\tMasukkan jumlah pergeseran :");
	key = input_desimal();
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'a' && s[i] <= 'z') { 
		s[i] = s[i] - 32;
	}
		if(s[i] >= 'A' && s[i] <= 'Z'){ 
			s[i] = s[i] - key; 
				if(s[i] < 'A'){
					s[i] = s[i] + 26;
				}
				s[i] = s[i] + 32; 
		}
	}
	
	printf("\n\t\t\tHasil Dekripsi : %s", s); 
	reinpt();
}

void header() {
	printf("\t\t\t\t|===============================================|\n"
           "\t\t\t\t|==========  PRAKTIKUM ALPROG MODUL 3 ==========|\n"
           "\t\t\t\t|==========         KELOMPOK 1        ==========|\n"
           "\t\t\t\t|           *************************           |\n"
           "\t\t\t\t|========   Program 3.5 Caesar Chiper  ========|\n"
           "\t\t\t\t|========       By Tjok Semarajaya      ========|\n"
           "\t\t\t\t|===============================================|\n\n");
}


void reinpt(){ 
	printf("\n\n\t\t\t============================================= ===\n");
	printf("\n\t\t\tApakah anda ingin mengulang program?");
	printf("\n\t\t\t[1] Untuk Kembali ke Menu Utama\n"); 
	printf("\t\t\t[2] Untuk Keluar Dari Program\n"); 
	printf("\n\t\t\tMasukan Pilihan \t= "); 
	scanf("%d",&pilihan);
	if(pilihan == 1){
	system("cls"); 
	main();
	}
	else if(pilihan == 2){ 
	system("cls"); 
	exit(0);
	} 
}

int input_desimal() {
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
	return atoi(data);
}

char * input_string() {
	char *data;
	data = (char *) malloc(sizeof(data));
	
	int idx = 0;
	char ch;
	while((ch = getch()) != 13) {
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' '){
			printf("%c",ch);
			data[idx] = ch;
			idx++;
		}
	}
	data[idx] = '\0';
	return data;
}

int input_pilihan() {
	char ch;
	char *data;
	int cek = 0;
	data = (char *)malloc(sizeof(char)); 
	
	while ((ch = getch()) != 13)//jadi di input desimal nii fungsinya yaitu ngecek angka desimal,misal yanng dimasukin tu angka 0-9,nah jika user ngetk angka segitu pas running program dia akan muncul di terminal,kalo bukan dari itu dia bakal gak muncul di terminal
	{
		if ((ch >= '0' && ch <= '2')) {
		printf("%c", ch); 
		data[cek] = ch; 
		cek++;
		} 
	}
	data[cek] = '\0'; 
	return atoi(data);
}
