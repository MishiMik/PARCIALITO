/*
 * abml.c
 *
 *  Created on: 19 may. 2021
 *      Author: Usuario
 */
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

int obtenerIDServ(int idIncremental) {

	idIncremental+=1;

	return idIncremental;
}


int bicicleta_Alta(eBicicleta array[], int TAM) {
	int confirmar = 0;
	eBicicleta auxBicicleta;

	//BUSCO ESPACIO EN ARRAY
	int index =  eBicicleta_ObtenerIndexLibre(array, TAM);

	if (index != -1)
	{
		auxBicicleta = eBicicleta_CargarDatos();
		auxBicicleta.idServicio = obtenerIdServicio(auxBicicleta[index].idServicio);
		auxBicicleta.isEmpty = OCUPADO;
		array[index] = auxBicicleta;
		confirmar = 1;
	}

	return confirmar;
}






