#include <stdio.h>
#include <stdlib.h>
#include "graficos.h"

void Matrices();

int main(void){
    system("clear");
    menu();
    Matrices();
    gotoxy(1,80);
	return 0;
}

void Matrices(){

	float mat1[3][3] = {}, mat2[3][3] = {}, suma[3][3] = {}; 
    int x, y;
    	FILE *calculadora;
	if((calculadora = fopen("resultados.txt","w+"))== NULL){
		printf("El archivo no existe\n");
	}else{
		    
		 gotoxy(4,6);   printf("\E[0;1;44m                                   Introduzca primera matriz                                    ");
	
    gotoxy(5,8);   printf("\E[00m     |     |     ");
    gotoxy(5,9);   printf("     |     |     "); 
    gotoxy(5,10);  printf("     |     |     ");

    for(x = 0 , y = 0; x < 3 , y < 17; x++ , y=y+6){
        gotoxy(5+y,8); scanf("%f", &mat1[0][x]);
    }
    for(x = 0 , y = 0; x < 3 , y < 17; x++ , y=y+6){
        gotoxy(5+y,9); scanf("%f", &mat1[1][x]);
    }
    for(x = 0 , y = 0; x < 3 , y < 17; x++ , y=y+6){
        gotoxy(5+y,10); scanf("%f", &mat1[2][x]);
    }

    gotoxy(4,12);  printf("\E[0;1;44m                                   Introduzca segunda matriz                                    ");
	
    gotoxy(5,14);  printf("\E[00m     |     |     ");
    gotoxy(5,15);  printf("     |     |     "); 
    gotoxy(5,16);  printf("     |     |     ");

    for(x = 0 , y = 0; x < 3 , y < 17; x++ , y=y+6){
        gotoxy(5+y,14); scanf("%f", &mat2[0][x]);
    }
    for(x = 0 , y = 0; x < 3 , y < 17; x++ , y=y+6){
        gotoxy(5+y,15); scanf("%f", &mat2[1][x]);
    }
    for(x = 0 , y = 0; x < 3 , y < 17; x++ , y=y+6){
        gotoxy(5+y,16); scanf("%f", &mat2[2][x]);
    }

	for(x = 0; x < 3; x++){
		for(y = 0; y < 3; y++){
			suma[x][y] = mat1[x][y] + mat2[x][y]; 
		}
	}
		}
		
		gotoxy(4,18); fprintf(calculadora,"\E[0;1;44m                                             Suma                                               ");
		    
    fprintf(calculadora," *Matriz* ");
    gotoxy(5,20);  fprintf(calculadora,"\E[00m%.3f|%.3f|%.3f", mat1[0][0], mat1[0][1], mat1[0][2]);
    gotoxy(5,21);  fprintf(calculadora,"%.3f|%.3f|%.3f", mat1[1][0], mat1[1][1], mat1[1][2]); 
    gotoxy(5,22);  fprintf(calculadora,"%.3f|%.3f|%.3f", mat1[2][0], mat1[2][1], mat1[2][2]); 
    
    gotoxy(24,21); fprintf(calculadora,"+");

    gotoxy(27,20);  fprintf(calculadora,"%.3f|%.3f|%.3f", mat2[0][0], mat2[0][1], mat2[0][2]);
    gotoxy(27,21);  fprintf(calculadora,"%.3f|%.3f|%.3f", mat2[1][0], mat2[1][1], mat2[1][2]); 
    gotoxy(27,22);  fprintf(calculadora,"%.3f|%.3f|%.3f", mat2[2][0], mat2[2][1], mat2[2][2]); 

    gotoxy(46,21);  fprintf(calculadora,"=");

    gotoxy(49,20);  fprintf(calculadora,"%.3f|%.3f|%.3f", suma[0][0], suma[0][1], suma[0][2]);
    gotoxy(49,21);  fprintf(calculadora,"%.3f|%.3f|%.3f", suma[1][0], suma[1][1], suma[1][2]); 
    gotoxy(49,22);  fprintf(calculadora,"%.3f|%.3f|%.3f", suma[2][0], suma[2][1], suma[2][2]); 

	fclose(calculadora);   



}
