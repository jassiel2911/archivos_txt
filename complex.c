#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graficos.h"
#include "lista.h"

const float pi = 3.14159265;
const float radian = 57.296;

void suma();
void multiplicacion();
void potencia();

int main(void){

    system("clear");
    menuComplejos();
    suma();

    system("clear");
    menuComplejos();
    multiplicacion();

    system("clear");
    menuComplejos();
    potencia();

    gotoxy(1,80);

    return 0;
}

void suma(){
    nodo *lista, *elemento;
    float r, i, R, I;
    FILE *calculadora;
    if((calculadora = fopen("resultados.txt","w+"))== NULL){
		printf("El archivo no existe\n");
	}else{

    gotoxy(4,6); printf("\E[0;1;44m                                     SUMA DE COMPLEJOS                                          ");
    gotoxy(4,8); printf("\E[00mIngrese la parte real: ");
    gotoxy(27,8); scanf("%f",&r);
    gotoxy(4,10); printf("\E[00mIngrese la parte imaginaria: ");
    gotoxy(33,10); scanf("%f",&i);
     
    elemento = crearNodo(r,i);
    lista = insertarNodo(elemento);
    R = guardarReal(lista);
    I = guardarImaginario(lista);

    system("clear");
    menu();

    gotoxy(4,12); printf("\E[00m[(%.3f) + (%.3f)i]",r,i);

    gotoxy(4,6); printf("\E[0;1;44m                                     SUMA DE COMPLEJOS                                          ");
    gotoxy(4,8); printf("\E[00mIngrese la parte real: ");
    gotoxy(27,8); scanf("%f",&r);
    gotoxy(4,10); printf("\E[00mIngrese la parte imaginaria: ");
    gotoxy(33,10); scanf("%f",&i);

    elemento = crearNodo(r,i);
    lista = insertarNodo(elemento);
    R += guardarReal(lista);
    I += guardarImaginario(lista);


    fprintf(calculadora," + ");

    fprintf(calculadora,"\E[00m[(%.3f) + (%.3f)i]",r,i);

    menu();

    fprintf(calculadora,"\E[00m = ");
    fprintf(calculadora,"\E[00m[(%.3f) + (%.3fi)]", R, I);
    
    fclose(calculadora);
	}
}

void multiplicacion(){
    nodo *lista, *elemento;
    float r, i, R, I, R1, I1, R2, I2;
    FILE *calculadora;
    if((calculadora = fopen("resultados.txt","w+"))== NULL){
		printf("El archivo no existe\n");
	}else{

    gotoxy(4,6); printf("\E[0;1;44m                                 MULTIPLICACION DE COMPLEJOS                                     ");
    gotoxy(4,8); printf("\E[00mIngrese la parte real: ");
    gotoxy(27,8); scanf("%f",&r);
    gotoxy(4,10); printf("\E[00mIngrese la parte imaginaria: ");
    gotoxy(33,10); scanf("%f",&i);
     
    elemento = crearNodo(r,i);
    lista = insertarNodo(elemento);
    R1 = guardarReal(lista);
    I1 = guardarImaginario(lista);

    system("clear");
    menu();

    gotoxy(4,12); printf("\E[00m[(%.3f) + (%.3f)i]",r,i);

    gotoxy(4,6); printf("\E[0;1;44m                                 MULTIPLICACION DE COMPLEJOS                                     ");
    gotoxy(4,8); printf("\E[00mIngrese la parte real: ");
    gotoxy(27,8); scanf("%f",&r);
    gotoxy(4,10); printf("\E[00mIngrese la parte imaginaria: ");
    gotoxy(33,10); scanf("%f",&i);

    elemento = crearNodo(r,i);
    lista = insertarNodo(elemento);
    R2 = guardarReal(lista);
    I2 = guardarImaginario(lista);

    R = (R1 * R2) - (I1 * I2);
    I = (R1 * I2) + (R2 * I1);

    fprintf(calculadora," · ");

    fprintf(calculadora,"\E[00m[(%.3f) + (%.3f)i]",r,i);

    menu();

    fprintf(calculadora,"\E[00m = ");
    fprintf(calculadora,"\E[00m[(%.3f) + (%.3fi)]", R, I);
    fclose(calculadora);
	}
}

void potencia(){
    nodo *lista, *elemento;
    float r, i, R, I, modulo, angulo, exponente, aux1, aux2;
    FILE *calculadora;
    if((calculadora = fopen("resultados.txt","w+"))== NULL){
		printf("El archivo no existe\n");
	}else{

    gotoxy(4,6); printf("\E[0;1;44m                                POTENCIA DE COMPLEJOS                                           ");
    gotoxy(4,8); printf("\E[00mIngrese la parte real: ");
    gotoxy(27,8); scanf("%f",&r);
    gotoxy(4,10); printf("\E[00mIngrese la parte imaginaria: ");
    gotoxy(33,10); scanf("%f",&i);
    gotoxy(4,12); printf("\E[00mIngrese exponente: ");
    gotoxy(23,12); scanf("%f",&exponente);
     
    elemento = crearNodo(r,i);
    lista = insertarNodo(elemento);
    R = guardarReal(lista);
    I = guardarImaginario(lista);   

    aux1 = (R*R) + (I*I);
    modulo = sqrt(aux1);
    aux2 = atan(I/R) * radian;

    angulo = exponente*(aux2);

    if(angulo < 0){
        angulo = (180 - (angulo));
    } else if(angulo > 180) {
        angulo = (angulo) - 180;
    } else {
        angulo = (angulo);
    }
   
    R = cos(angulo*(pi/180));
    I = sin(angulo*(pi/180));
    R = pow(modulo,exponente) * R;
    I = pow(modulo,exponente) * I;

    fprintf(calculadora,"\E[00m[(%.3f) + (%.3f)i]",r,i);
    fprintf(calculadora,"%.3f",exponente);

    fprintf(calculadora,"\E[00m = ");
    fprintf(calculadora,"\E[00m[(%.3f) + (%.3fi)]", R, I);
    
    fclose(calculadora);
	}
}
