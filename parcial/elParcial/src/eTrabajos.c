/*
 * eTrabajos.c
 *
 *  Created on: 20 may. 2021
 *      Author: Usuario
 */


eBicicleta trabajosCargarDatos (eBicicleta array, int index)
{
	char respuesta;
	eBicicleta aux;

		printf("quiere proceder con el alta de datos? (s/n)");
		scanf("%s", &respuesta);

	while(respuesta=="s")
	{
		printf("\ningrese marca de la bicicleta :");
		scanf("%s", aux[index].marcaBicicleta);
		printf("\ningrese rodado de la bicicleta :");
		scanf("%d", aux[index].rodadoBicicleta);
		aux[index].isEmpty= OCUPADO;
	}
	return aux[index];
}

eBicicleta modificacion (eBicicleta array [], int tam, int id)
{
	int index;
	char respuesta;
	index=buscarPorIdBicicleta (array, tam, id);

	listadoBicicleta (array, index);
	printf("\n\aquiere continuar con la modificacion? (s/n)");
	scanf("%s", respuesta);

	if(respuesta=="s")
	{

		int opcion;
		printf("\n1. modificar marca.");
		printf("\n2. modificar servicio.");
		printf("\n3. salir.");
		printf("\nelija una opcion : ");
		scanf("%d", opcion);

		switch(opcion)
		{
		case 1:
			char auxMarca;
			printf("ingrese marca :");
			scanf("%s", auxMarca);

			if(validarMarca(auxMarca)==1)
			{
				strcpy(array[index].marcaBicicleta,auxMarca);
			}
			else
			{
				mensaje("Error, reingrese marca.");
				scanf("%s", auxMarca);
			}

			break;
		case 2:
			char auxServicio;

			auxServicio= menuServicios ();

			if(auxServicio>0 && auxServicio<5)
			{
				if(auxServicio==4)
				{
					break;
				}
				else
				{
					array[index].idServicio= auxServicio;
					mensajes("\n\amodificacion exitosa.");
				}

			}
			else
			{
				mensajes("\n\acancelacion exitosa.");
			}


					break;
		case 3:
					break;
		}

	}

	return array[index];
}
