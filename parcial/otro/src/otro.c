/*
 ============================================================================
 Name        : niidea.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef "abml.h"
#include "validYinicializ.h"


//* DEFINE
#define TC 30 //tamaño cadenas.
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//* ESTRUCTURA
typedef struct {
	int id;
	int isEmpty;
} eGen;
//*

/* INICIO CABECERAS DE FUNCION/
void eGen_Inicializar(eGen array[], int TAM);
int eGen_ObtenerID(void);
int eGen_ObtenerIndexLibre(eGen array[], int TAM);
int eGen_BuscarPorID(eGen array[], int TAM, int ID);
void eGen_MostrarUno(eGen Gen);
int eGen_MostrarTodos(eGen array[], int TAM);
int eGen_MostrarDadosDeBaja(eGen array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eGen_Sort(eGen array[], int TAM, int criterio);

//ABM
eGen eGen_CargarDatos(void);
eGen eGen_ModificarUno(eGen Gen);
int eGen_Alta(eGen array[], int TAM);
int eGen_Baja(eGen array[], int TAM);
int eGen_Modificacion(eGen array[], int TAM);
/* FIN CABECERAS DE FUNCION/

