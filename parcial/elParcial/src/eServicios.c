/*
 * eServicios.c
 *"limpieza", 250, &id);
	hardcodeo (servicios, 1, "parche", 250, &id);
	hardcodeo (servicios, 2, "cadena", 250
 *  Created on: 20 may. 2021
 *      Author: Usuario
 */


int menuServicios (void)
{
	int opcion;

	printf("1.limpieza _ $250");
	printf("2.parche _ $250");
	printf("3.cadena _ $250");
	printf("4. cancelar.");
	scanf("%d", opcion);

	while(opcion=="NULL" || opcion >5 || opcion <0)
	{
		printf("\n\aError, reingrese opcion : ");
		scanf("%d", opcion);
	}

	return opcion;
}
