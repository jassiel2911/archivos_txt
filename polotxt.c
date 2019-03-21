#include <stdio.h>
#include <stdlib.h>
#include "graficos.h"

void polinomios();

int main(void){
	system("clear");
    menuAlterno();
	polinomios();
	gotoxy(1,80);
	return 0;
}

void polinomios(){
	
	float pol1[3], pol2[3], pol3[3]; 
	int i, j;
	
	FILE *calculadora;
	if((calculadora = fopen("resultados.txt","w+"))== NULL){
		printf("El archivo no existe\n");
	}else{
	
	system("clear");
	menuAlterno();

	gotoxy(4,6); printf("\E[0;1;44m									PRIMER POLINOMIO										");

	gotoxy(12,9);  printf("\E[00m2");	
	gotoxy(4,10);  printf("\E[00m(     )x  + ");	
	gotoxy(5,10);  scanf("%f", &pol1[0]);
	gotoxy(16,10); printf("\E[00m(     )x + ");	
	gotoxy(17,10); scanf("%f", &pol1[1]);
	gotoxy(27,10); printf("(     )");	
	gotoxy(28,10); scanf("%f", &pol1[2]);

	system("clear");
	menuAlterno();

	gotoxy(4,6);   printf("\E[0;1;44m                                 		SEGUNDO POLINOMIO      			                             ");

	gotoxy(12,9);  printf("\E[00m2");	
	gotoxy(4,10);  printf("\E[00m(     )x  + ");	
	gotoxy(5,10);  scanf("%f", &pol2[0]);
	gotoxy(16,10); printf("\E[00m(     )x + ");	
	gotoxy(17,10); scanf("%f", &pol2[1]);
	gotoxy(27,10); printf("(     )");	
	gotoxy(28,10); scanf("%f", &pol2[2]);

	for(i = 0; i < 3; i++){
		pol3[i] = pol1[i] + pol2[i];
	}

	system("clear");
	menuAlterno();
	
		}
	
		gotoxy(4,6); fprintf(calculadora,"\E[0;1;44m									SUMA DE POLINOMIOS										");

		gotoxy(12,9);  fprintf(calculadora,"\E[00m2");	
		gotoxy(4,10);  fprintf(calculadora,"\E[00m(%.3f)x  + ", pol1[0]);	
		gotoxy(16,10); fprintf(calculadora,"\E[00m(%.3f)x + ", pol1[1]);	
		gotoxy(27,10); fprintf(calculadora,"(%.3f)", pol1[2]);	

	gotoxy(34,10); fprintf(calculadora," + ");	

		gotoxy(45,9);  fprintf(calculadora,"\E[00m2");	
		gotoxy(37,10); fprintf(calculadora,"\E[00m(%.3f)x  + ", pol2[0]);	
		gotoxy(49,10); fprintf(calculadora,"\E[00m(%.3f)x + ", pol2[1]);	
		gotoxy(60,10); fprintf(calculadora,"(%.3f)", pol2[2]);	

	gotoxy(67,10); fprintf(calculadora," = ");

		gotoxy(12,12); fprintf(calculadora,"\E[00m2");	
		gotoxy(4,13);  fprintf(calculadora,"\E[00m(%.3f)x  + ", pol3[0]);	
		gotoxy(16,13); fprintf(calculadora,"\E[00m(%.3f)x + ", pol3[1]);	
		gotoxy(27,13); fprintf(calculadora,"(%.3f)", pol3[2]);	
		
	fclose(calculadora); 
}
