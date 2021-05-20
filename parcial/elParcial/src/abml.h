/*Servicio:
● id (comienza en 20000, autoincremental)
● descripcion (maximo 25 caracteres)
● precio
 *
 * trabajo
 ● id (autoincremental)
● marcaBicicleta (Cadena) Validar
● rodadoBicicleta
● idServicio (debe existir) Validar
● fecha (Validar dia, mes y anio)*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "eServicios.h"
#include "eTrabajos.h"
#include "mostrar.h"
#include "validYinicializ.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
//* ESTRUCTURA
typedef struct {
	char decripcion;
	int precio;
	int idServicio;
	int isEmpty;
} eServicio;

typedef struct {
	int dia;
	char mes[15];
	int anio;
	int isEmpty;
} eFecha;

typedef struct {
	int idBicicleta;
	char marcaBicicleta[20];
	int	rodadoBicicleta;;
	eServicio idServicio;
	eFecha fecha;
	int isEmpty;
} eBicicleta;



int obtenerIDServ(int idIncremental);


int Bicicleta_Alta(eBicicleta array[], int TAM);

