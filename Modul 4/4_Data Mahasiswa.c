#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isalpha

typedef char biodata[500];
typedef struct
 {
	biodata Nama; 
	biodata NIM;
} mahasiswa;

int jumlahHuruf;
int jumlahAlphabet[256];
int checkNumeric;

void inputDataMahasiswa(mahasiswa mhs);
void cariDataMahasiswa(mahasiswa mhs);
void tampilDataMahasiswa(mahasiswa mhs);
int validasiInt(int *var);

int main() 
{
	system("cls");
	mahasiswa mhs; 
	char update; 
	int pilihan;
	printf("\t\t\t\t|===============================================|\n"
           "\t\t\t\t|==========  PRAKTIKUM ALPROG MODUL 4 ==========|\n"
           "\t\t\t\t|==========         KELOMPOK 1        ==========|\n"
           "\t\t\t\t|           *************************           |\n"
           "\t\t\t\t|========   Program 4.4 Data Mahasiswa  ========|\n"
           "\t\t\t\t|========       By Tjok Semarajaya      ========|\n"
           "\t\t\t\t|===============================================|\n\n");
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t=              1. Input Data                  =\n");
	printf("\t\t\t\t=              2. Cari Data                   =\n");
	printf("\t\t\t\t=              3. Tampilkan Data              =\n");
	printf("\t\t\t\t=              4. Keluar                      =\n");
	printf("\t\t\t\t===============================================\n");
	printf("\nMasukkan pilihan   : ");
	
	if (validasiInt(&pilihan) != 1)
	 {
		printf("\nInput salah! Input Harus Berapa Angka 1 sd 4.\nSilahkan coba lagi.\n");
		main(); 
	}

	switch (pilihan) {
		case 1:
			inputDataMahasiswa(mhs); 
			break;
		case 2:
			cariDataMahasiswa(mhs); 
			break;
		case 3:
			tampilDataMahasiswa(mhs); 
			break;
		case 4:
			printf("Terimakasih, Sampai Jumpa! \n"); exit(0);
			break; 
		default:
			printf("Input Anda Salah\n"); 
			system("pause");
			system("cls"); 
			main();
	} 
	return 0;
}
int get_size(const char *file_name) //untuk mengetahui posisi cursor di file.txt
{
	FILE *file = fopen(file_name, "r"); 
	
	if (file == NULL)
		return 0;

	fseek(file, 0, SEEK_END); //fungsinya untuk memindahkan cursor di file.txtnya 
	int size = ftell(file); //memberitahu posisi cursor di pinter file itu,lalu menyimpannya di variabel size
	fclose(file);
		
	return size; 
}

void inputDataMahasiswa(mahasiswa mhs)
{
	system("cls");
	int alphabet = 0, length, digit = 0, history = 0, i; 
	char pilih, check;
	char code;
	
	biodata noInduk, nama; //inisiasi data
	const char *dataNim = "";
	const char *dataInduk = "";
	const char *dataNama = "";

	printf("===============================================\n");
	printf("==          MENU INPUT DATA MAHASISWA        ==\n");
	printf("===============================================\n");
	printf("Masukan NIM Mahasiswa    : ");

	if (fgets(mhs.NIM, sizeof(mhs.NIM), stdin) != NULL) 
	{
		char *ptr = strchr(mhs.NIM, '\n'); 
		if (ptr)
		{

			*ptr = '\0';
		}	 
	}
	length = strlen(mhs.NIM);//mengetahui panjang nim yang dimasukkan
	// validasi NIM hanya menerima angka 
	for (i = 0; i < length; i++)
	{
		// check alphabets
		if (isalpha(mhs.NIM[i]) != 0) //isalpha fungsinya untuk mengetahui apakah valuenya alfabet atau tidak,kalau bukan alfabet = 0,kalau alfabet selain 0
		alphabet++;
	}
	if (alphabet > 0) {
		printf("Masukkan NIM yang benar!\n");
		printf("ERROR: NIM tidak boleh ada alphabet!\n"); 
		inputDataMahasiswa(mhs);
	}
	fflush(stdin);
	// validasi NIM minimal 1 karakter 
	if (length <= 1)
	{
	printf("Masukkan NIM dengan benar!\n"); 
	printf("ERROR: NIM yang dimasukan kosong!\n"); 
	inputDataMahasiswa(mhs);
	} 
	else 
	{
		// validasi NIM tidak boleh ada spasi 
		if (strchr(mhs.NIM, ' '))//mengecek apakah di nimnya ada spasi atau endak
		{
			printf("Masukkan NIM yang benar!\n"); 
			printf("ERROR: NIM tidak boleh ada spasi!\n"); 
			inputDataMahasiswa(mhs);
		} 
	}
	fflush(stdin);
	
	printf("Masukan Nama Mahasiswa   : "); 
	gets(mhs.Nama);
	length = strlen(mhs.Nama); 
	for (i = 0; i < length; i++) {
		// check for digits
		if (isdigit(mhs.Nama[i]) != 0) //kalau bukan angka dia 0,kalau angka lebih dari 0
			digit++;
	}
	if (digit > 0) 
	{
		printf("Masukkan Nama yang benar!\n"); 
		printf("ERROR: Nama tidak boleh ada angka!\n"); 
		inputDataMahasiswa(mhs);
	}
fflush(stdin);

	// validasi Nama minimal 1 karakter 
	if (length <= 1)
	{
		printf("Masukkan Nama dengan benar!\n");
		printf("ERROR: Nama yang dimasukan kosong atau kurang dari 4 angka!\n");
		inputDataMahasiswa(mhs); 
	}
	fflush(stdin);
	printf("===============================================\n"); 
	FILE *out = fopen("data.mahasiswa.txt", "r");
	history = 0; 
	if (!out)
	{
	printf("\nDATA BELUM ADA\n"); 
	}
	else 
	{
		if (get_size("data.mahasiswa.txt") == 0) //jika cursor berada di awal,karena 0
		{
			history = 0; 
		}
		else 
		{
			while (!feof(out))//selama belum mencapai akhir dari file tersebut
			{
				fflush(stdin);
				fscanf(out, "%s # %[^#] #\n", &noInduk, &nama); 
				const char *dataNim = mhs.NIM;
				const char *dataInduk = noInduk; 
				if (strcmp(dataNim, dataInduk) == 0) //untuk mengecek apakah nim yang baru diinputkan sudah ada ndak di file.txt
				{
					history = history + 1; 
				}
			} 
			}
		fclose(out); 
	}
	if (history > 0) 
	{
		printf("\n\nDATA SUDAH ADA"); 
		history = 0;
	} 
	else 
	{
		printf("\nDATA BERHASIL DIMASUKKAN");
		FILE *in = fopen("data.mahasiswa.txt", "a"); 
		const char *dataNim = mhs.NIM;
		const char *dataNama = mhs.Nama;
		fprintf(in, "%s # %s # \n", dataNim, dataNama); 
		fclose(in);
	}
	printf("\n\nApakah Anda Ingin Mengulang Program?\nMasukkan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama."); 
	do
	{
		printf("\n(y/n): ");
		if ((scanf("%c%c", &pilih, &check)) != 2 || check != '\n')
		{
			printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
		} 
		else 
		{
			if (pilih == 'Y' || pilih == 'y') 
			{
				system("cls"); 
				inputDataMahasiswa(mhs);
			}
			else if (pilih == 'N' || pilih == 'n') 
			{
				system("cls"); 
				main();
			} 
			else 
			{
				printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
			} 
		}
	} 
	while (1); 
}

void cariDataMahasiswa(mahasiswa mhs) 
{
	system("cls"); 
	
	int history;
	char code, y, Y, n, N; 
	char pilih, check;
	
	biodata data;
	printf("===============================================\n");
	printf("==          MENU CARI DATA MAHASISWA         ==\n");
	printf("===============================================\n");
	printf("Masukan NIM Mahasiswa    : "); 
	scanf("%s", &data);
	fflush(stdin);
	printf("===============================================\n"); 
	FILE *in = fopen("data.mahasiswa.txt", "r");
	history = 0; 
	if (in == NULL) {
		printf("\nData Tidak Ditemukan"); 
	}
	else 
	{
		while (!feof(in)) 
		{
			fflush(stdin);
			fscanf(in, "%s # %[^#] #\n", &mhs.NIM, &mhs.Nama); 
			if (strcmp(mhs.NIM, data) == 0)//untuk nyocokin inputan dengan yang ada di file txt
			{
				printf("NIM       : %s\n", mhs.NIM); 
				printf("Nama      : %s\n", mhs.Nama); 
				history = history + 1;
			}
		}
		fclose(in);
		if (history == 0) 
		{
			printf("\nData Tidak Ditemukan"); 
		}
			history = 0; 
	}
	
	printf("\n\nApakah Anda Ingin Mengulang Program?\nMasukkan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.");
	do 
	{
		printf("\n(y/n): ");
		if ((scanf("%c%c", &pilih, &check)) != 2 || check != '\n') //selama inputannya tidak dua karakter,misalnya TTT\n atau endak ada inputan enter maka dia error
		{
			printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
		} 
		else 
		{
			if (pilih == 'Y' || pilih == 'y') 
			{
				system("cls"); 
				cariDataMahasiswa(mhs);
			}
			else if (pilih == 'N' || pilih == 'n') 
			{
				system("cls"); 
				main();
			} 
			else 
			{
				printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
			} 
		}
	} 
	while (1); 
}

void tampilDataMahasiswa(mahasiswa mhs) 
{
	int no = 1; 
	system("cls");
	
	printf("===============================================\n");
	printf("==             DATA MAHASISWA                ==\n");
	printf("===============================================\n");
	FILE *in = fopen("data.mahasiswa.txt", "r"); 
	if (in == NULL)
	{
		printf("\n\nData Tidak Tersedia"); }
	else 
	{
		while (!feof(in)) //selama belum mencapai akhir dari file
		{
			fflush(stdin);
			fscanf(in, "%s # %[^#] #\n", &mhs.NIM, &mhs.Nama); //scanf file txtnya
			printf("%d.  NIM       : %s\n", no, mhs.NIM);//tampilkan ke layar
			no++;
			printf("    Nama      : %s\n", mhs.Nama);
			printf("===============================================\n");
		} 
	fclose(in);
	}
		printf("\nAnda Akan Kembali ke Menu Utama\n"); 
		system("pause");
		system("cls"); 
		main();
}

int validasiInt(int *var) 
{
	char buff[1024]; 
	char cek;

	if (fgets(buff, sizeof(buff), stdin) != NULL) {
		if (sscanf(buff, "%d %c", var, &cek) == 1) 
		{
			return 1; 
		}
	} 
	return 0;
}

