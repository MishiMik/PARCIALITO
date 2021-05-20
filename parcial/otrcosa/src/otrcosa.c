/*
 A. ALTA TRABAJO
B. MODIFICAR TRABAJO: Se ingresará el id, permitiendo en un submenú modificar: ● La marca de la bicicleta
● El servicio
C. BAJA TRABAJO: Se ingresará el id del trabajo y se realizará una baja lógica.
D. LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad  de año por marca de la bicicleta.
E. LISTAR SERVICIOS
F. TOTAL en pesos por los servicios prestados.
===========================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int menuOpciones (void)
{
	int opcion;

	do{

	}
	while(opcion!=5)

	return opcion;
}

void array(int num[], int TAM)
{

	int i;

	for(i=0; i<TAM; i++)
	{
		num[i]=0;
	}

}




/*
 ============================================================================
 Name        : nidea2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 A. ALTA TRABAJO
B. MODIFICAR TRABAJO: Se ingresará el id, permitiendo en un submenú modificar: ● La marca de la bicicleta
● El servicio
C. BAJA TRABAJO: Se ingresará el id del trabajo y se realizará una baja lógica.
D. LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad  de año por marca de la bicicleta.
E. LISTAR SERVICIOS
F. TOTAL en pesos por los servicios prestados.
===========================================================================
 */
#include "eGen.h"
#define TAM_ESTRUCTURA 5

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eGen Gen[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eGen_Inicializar(Gen, TAM_ESTRUCTURA);

	//BUCLE DE MENU




