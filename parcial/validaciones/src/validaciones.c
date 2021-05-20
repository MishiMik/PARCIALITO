/*
 ============================================================================
 Name        : validaciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "abml.h"




void eServicioInicializar(eServicio array[], int TAM) {
	int i;

	//si existe y el limite es valido.
	if (array != NULL && TAM > 0) {
		//recorro array
		for (i = 0; i < TAM; i++) {
			//lo inicializo en estado libre.
			array[i].isEmpty = LIBRE;
		}
	}
}
