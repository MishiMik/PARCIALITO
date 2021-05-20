/*
 * mostrar.c
 *
 *  Created on: 19 may. 2021
 *      Author: Mica Tapia
 */


int menu (eBicicleta array[], int index){
	int opcion;

	do {


		printf("1. ALTA TRABAJO.");
		printf("2. MODIFICAR TRABAJO.");
		printf("3. BAJA TRABAJO.");
		printf("4. LISTAR TRABAJOS.");
		printf("5. TOTAL en pesos por los servicios prestados.");
		printf("6.  SALIR.");
		printf("INGRESE OPCION: ");
		scanf("%d", &opcion);

	}
	while(opcion!=6);

	switch (opcion)
	{
	case 1:
		if (bicicleta_ALTA(array, index)==1) {
			printf("\nDADO DE ALTA EXITOSAMENTE\n");
		} else {
		printf("ERROR. SIN ESPACIO PARA ALMACENAR MAS BICICLETAS\n");}					}
		system("pause");
			break;

	break;
	case 2:

		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}

	return opcion;
	}

int listadoBicicleta (eBicicleta arrayBicicleta[], int index)
{

	int confirmar;



	if(arrayBicicleta[index] == "NULL" && index <0 && arrayBicicleta[index])
	{
		confirmar=-1;
		mensajes("\a\nError, los datos ingresados no estan listados.\n")
	}
	else
	{
		confirmar=0;
		mensajes( "\a\nTodo correcto.\n")

		printf("%1d, %4s, %6d , %8s, %10d/%13d/%15d ", arrayBicicleta[index].idBicicleta,
				arrayBicicleta[index].marcaBicicleta,
				arrayBicicleta[index].rodadoBicicleta,
				arrayBicicleta[index].idServicio[index].decripcion,
				arrayBicicleta[index].fecha.dia,
				arrayBicicleta[index].fecha.mes,
				arrayBicicleta[index].fecha.anio);
	}


	return confirmar;
}

int mensajes (char mensaje)
{
	int resultado;
	if( mensaje!="NULL" && mensaje!="\0")
		{
		  resultado=1;
			printf("\a%s\n", mensaje);
		}
	else
	{
		resultado=0;
	}
	return resultado;

}


void listadoBicicletass (eBicicleta arrayBicicleta[], int tam)
{

	int i;
	int aux;

	for(i=0; i<tam; i++)
	{

		aux= buscarOcupados(arrayBicicleta[i]);

		if(aux!=-1)
		{
			listadoBicicleta (arrayBicicleta, aux);
		}
		else
		{
			mensajes("\a\nNo se ha dado de alta ni una bicicleta.\n");
		}

	}

}
