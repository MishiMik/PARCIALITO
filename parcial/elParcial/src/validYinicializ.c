/*
 * validYinicializ.c
 *
 *  Created on: 19 may. 2021
 *      Author: Usuario
 */

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


int eBicicleta_ObtenerIndexLibre(eBicicleta array[], int TAM)
{
	int confirmar = -1;
	int i;

	//si el array es real, y si el limite es valido.
	if (array != "NULL" && TAM > 0)
	{
		//recorro el array.
		for (i = 0; i < TAM; i++)
		{
			//pregunto si esta libre.
			if (array[i].isEmpty == LIBRE)
			{
				//obtengo la direccion del array disponible y rompo la iteracion.
				confirmar = i;
				break;
			}
		}
	}

	return confirmar;
}




int hardcodeo (eServicio variable[], int tam, char descripcion, int precio, int id)
{
	int i;

	for(i=0; i<tam; i++)
	{
		while(variable!="NULL" && tam>-1)
		{
			variable[i].precio = precio;
			variable[i].decripcion =descripcion;
			variable[i].idServicio =obtenerIdServ(id);
			variable[i].isEmpty = OCUPADO;


		}
	}
	return 0;
}


int buscarPorIdBicicleta (eBicicleta array[], int tam, int id)
{
int retorno = -1;
    int i;

    //SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
    if (array != "NULL" && tam > 0)
    {
        //RECORRO TODO EL ARRAY
        for (i = 0; i < tam; i++)
        {
            //BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
            if (array[i].idBicicleta == id && array[i].isEmpty == OCUPADO)
            {
                //SI ENCONTRE EL ID
                //DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int validarMarca (char marca)
{
	int retorno;
	retorno=0;
	if(marca!= "NULL")
	{
		retorno=1;
	}

	return retorno;
}
