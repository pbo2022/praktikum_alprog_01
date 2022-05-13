#include <stdio.h>
#include <math.h>
//#define 

float luassegitigasembarang (float a, float b, float c){
	return (a+b+c)/2;
}
float luasbelahketupat (float d1, float d2){
	return (d1*d2)/2;
}
float luasjajargenjang (float a, float t){
	return a*t;
}
float luastrapesium (float a, float b, float t){
	return (a*b)*t/2;
}
float luaslingkaran (float phi, float jarijari){
	return phi*jarijari*jarijari;
}
float kllsegitigasembarang (float a, float b, float c){
	return (a+b+c);
}
float kllbelahketupat (float sisi){
	return (4*sisi);
}
float klljajargenjang (float a, float b){
	return (2*(a+b));
}
float klltrapesium (float a, float b, float c, float d){
	return (a+b+c+d);
}
float klllingkaran (float phi, float jarijari){
	return (2*phi*jarijari);
}

int main(){
	float phi = 3.14159;
	float a, b, c, d, d1, d2, t, jarijari, sisi;
	int pilihan;
	int hasil;
	char jawaban = 'y';
	welcome();
	while(jawaban == 'y'){
	system("cls");
	}
}

void welcome(){
	float phi = 3.14159;
	float a, b, c, d, d1, d2, t, jarijari, sisi;
	int pilihan;
	int hasil;
	char jawaban = 'y';
	
	printf("\n\n\n\n\n\t\t************************************************************\n");
    printf("\t\t  ========================================================\n\n");
    printf("\t\t\t    SELAMAT DATANG DI SISTEM PENGHITUNGAN\n");
    printf("\t\t\t	     LUAS DAN KELILING \n");
    printf("\t\t  ========================================================");
	printf("\n\t\t************************************************************");
	printf("\n\n\n\n\n Press any key to continue......");
	getch();
	system("cls");

		printf ("\n 1.Segitiga Sembarang\n 2.Belah Ketupat\n 3.Jajar Genjang\n 4.Trapesium\n 5.Lingkaran\n");
		printf ("\n Masukkan pilihanmu : " );
		scanf ("%d", &pilihan);
		getch();
		system("cls");
	
		switch (pilihan){
			case 1:
				printf ("\n masukkan nilai a : " );
				scanf ("%f", &a);
				printf ("\n masukkan nilai b : " );
				scanf ("%f", &b);
				printf ("\n masukkan nilai c : " );
				scanf ("%f", &c);
		getch();
		system("cls");
				printf ("\n luas : %0.2f", luassegitigasembarang(a,b,c));
				printf ("\n keliling : %0.2f", kllsegitigasembarang(a,b,c));
			break;
			
			case 2:
				printf ("\n masukkan diameter 1 : " );
				scanf ("%f", &d1);
				printf ("\n masukkan diameter 2 : " );
				scanf ("%f", &d2);
				printf ("\n masukkan sisi : ");
				scanf ("%f", &sisi);
		getch();
		system("cls");
				printf ("\n luas : %0.2f", luasbelahketupat(d1,d2));
				printf ("\n keliling : %0.2f", kllbelahketupat(sisi));	
			break;
			
			case 3:
				printf ("\n masukkan alas : " );
				scanf ("%f", &a);
				printf ("\n masukkan tinggi : " );
				scanf ("%f", &t);
				printf ("\n masukkan  nilai a : " );
				scanf ("%f", &a);
				printf ("\n masukkan  nilai b : " );
				scanf ("%f", &b);
		getch();
		system("cls");
				printf ("\n luas : %0.2f", luasjajargenjang(a,t));
				printf ("\n keliling : %0.2f", klljajargenjang(a,b));
			break;
			
			case 4:
				printf ("\n masukkan nilai a : " );
				scanf ("%f", &a);
				printf ("\n masukkan nilai b : " );
				scanf ("%f", &b);
				printf ("\n masukkan tinggi : " );
				scanf ("%f", &t);
				printf ("\n masukkan nilai c : " );
				scanf ("%f", &c);
				printf ("\n masukkan nilai d : " );
				scanf ("%f", &d);
		getch();
		system("cls");
				printf ("\n luas : %0.2f", luastrapesium(a,b,t));
				printf ("\n keliling : %0.2f", klltrapesium(a,b,c,d));
			break;
			
			case 5:
				printf ("\n masukkan jarijari : " );
				scanf ("%f", &jarijari);
		getch();
		system("cls");
				printf ("\n luas : %0.2f", luaslingkaran(phi,jarijari));
				printf ("\n keliling : %0.2f", klllingkaran(phi,jarijari));
				
			default:
				printf ("\n\n pilihan tidak tersedia\n");
			break;
			
		}
		printf ("\nApakah Mengulang? : " );
		scanf (" %c", &jawaban);	
		if(jawaban == 'y'){
			main();
		}else{
			system("cls");
		}
	return 0;
}
