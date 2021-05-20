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



typedef struct {
	int idServicio;
	char decripcion;
	int rodadoBicicleta;
	int isEmpty;
} eServicio;

typedef struct {
	int idBicicleta;
	char marcaBicicleta[20];
	int precio;
	int idServicio;
	int isEmpty;
} eBicicleta;

typedef struct {
	int dia;
	char mes[15];
	int anio;
	int isEmpty;
} eFecha;

int Servicio_idIncremental = 2000;


/*IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs/
//ID AUTOINCREMENTAL
int Servicio_idIncremental = 2000;

void eGen_Inicializar(eServicio array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eGen_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Gen_idIncremental += 1;
}

int eGen_ObtenerIndexLibre(eGen array[], int TAM) {
	int confirmar = -1;
	int i;

	//si el array es real, y si el limite es valido.
	if (array != NULL && TAM > 0) {
		//recorro el array.
		for (i = 0; i < TAM; i++) {
			//pregunto si esta libre.
			if (array[i].isEmpty == LIBRE) {
				//obtengo la direccion del array disponible y rompo la iteracion.
				confirmar = i;
				break;
			}
		}
	}

	return confirmar;
}

int eGen_BuscarPorID(eGen array[], int TAM, int ID) {
	int confirmar = -1;
	int i;

	//si el array existe y el limite es valido.
	if (array != NULL && TAM > 0) {
		//recorro el array.
		for (i = 0; i < TAM; i++) {
			//busco si esta ocupado y si coincide con el id que estoy buscando.
			if (array[i].idGen == ID && array[i].isEmpty == OCUPADO) {
				//si se encuentra el id, devuelvo la direccion/index donde esta ese id y rompo la iteracion.
				confirmar = i;
				break;
			}
		}
	}

	return confirmar;
}

void eGen_MostrarUno(eGen Gen) {
	//mostrar solo un Gen.
	printf("%4d\n", Gen.idGen);
}

int eGen_MostrarTodos(eGen array[], int TAM) {
	int i;
	int confirmar = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Gen");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				eGen_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		confirmar = 1;
	}

	return confirmar;
}

int eGen_MostrarDadosDeBaja(eGen array[], int TAM) {
	int i;
	int confirmar = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Gen\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Gen
				eGen_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		confirmar = 1;
	}

	return confirmar;
}

eGen eGen_CargarDatos(void) {
	eGen auxiliar;
	/* CARGAR DATOS NECSARIOS PARA EL ALTA/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA
	return auxiliar;
}

eGen eGen_ModificarUno(eGen Gen) {
	eGen auxiliar = Gen;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL
	return auxiliar;
}

int eGen_Alta(eGen array[], int TAM) {
	int confirmar = 0;
	eGen auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = eGen_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = eGen_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.idGen = eGen_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		confirmar = 1;
	}

	return confirmar;
}

int eGen_Baja(eGen array[], int TAM) {
	int confirmar = 0;
	int idGen;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (eGen_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/

		//BUSCO INDEX POR ID EN ARRAY
		while (eGen_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");
			idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eGen_BuscarPorID(array, TAM, idGen);

		/*PREGUNTAR SI DESEA CONTINUAR/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		confirmar = 1;
	}

	return confirmar;
}

int eGen_Modificacion(eGen array[], int TAM) {
	int confirmar = 0;
	int idGen;
	int index;
	int flag = 0;
	eGen auxiliar;

	//LISTO TODOS LOS Gen
	if (eGen_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/

		//BUSCO INDEX POR ID EN ARRAY
		while (eGen_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");
			idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = eGen_BuscarPorID(array, TAM, idGen);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eGen_ModificarUno(array[index]);

		/*PREGUNTAR SI DESEA CONTINUAR/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		confirmar = 1;
	}

	return confirmar;
}

int eGen_Sort(eGen array[], int TAM, int criterio) {
	int confirmar = 0;
	int i;
	int j;
	eGen aux;

	/** EJEMPLO DE SORT CON ID DE Gen */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
/*	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idGen > array[j].idGen) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			confirmar = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idGen < array[j].idGen) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			confirmar = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			confirmar = 0;
			break;
		}
	}
	return confirmar;
}


	 *
	 * int getChar(char* resultado, char mensaje, char mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno;
	int auxiliarChar;

	retorno =-1;

	if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo>=maximo && reintentos>=0)
	{
		for(reintentos;reintentos<=0;reintentos--)
		{
			printf("%s",mensaje);
			fflush("stdin");
			scanf("%c",&resultado);
			if(resultado>minimo && resultado<maximo)
			{
				auxiliarChar=*resultado;
				retorno = 0;
				break;
			}else{
				printf("\nLa palabra ingresada no esta dentro del limite(%d-%d), intente nuevamente\n",minimo ,maximo);
			}
		}
	}
    return retorno;
}
	 */

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



typedef struct {
	int idServicio;
	char decripcion;
	int rodadoBicicleta;
	int isEmpty;
} eServicio;

typedef struct {
	int idBicicleta;
	char marcaBicicleta[20];
	int precio;
	int idServicio;
	int isEmpty;
} eBicicleta;

typedef struct {
	int dia;
	char mes[15];
	int anio;
	int isEmpty;
} eFecha;

int Servicio_idIncremental = 2000;


/*IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs/
//ID AUTOINCREMENTAL
int Servicio_idIncremental = 2000;

void eGen_Inicializar(eServicio array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eGen_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Gen_idIncremental += 1;
}

int eGen_ObtenerIndexLibre(eGen array[], int TAM) {
	int confirmar = -1;
	int i;

	//si el array es real, y si el limite es valido.
	if (array != NULL && TAM > 0) {
		//recorro el array.
		for (i = 0; i < TAM; i++) {
			//pregunto si esta libre.
			if (array[i].isEmpty == LIBRE) {
				//obtengo la direccion del array disponible y rompo la iteracion.
				confirmar = i;
				break;
			}
		}
	}

	return confirmar;
}

int eGen_BuscarPorID(eGen array[], int TAM, int ID) {
	int confirmar = -1;
	int i;

	//si el array existe y el limite es valido.
	if (array != NULL && TAM > 0) {
		//recorro el array.
		for (i = 0; i < TAM; i++) {
			//busco si esta ocupado y si coincide con el id que estoy buscando.
			if (array[i].idGen == ID && array[i].isEmpty == OCUPADO) {
				//si se encuentra el id, devuelvo la direccion/index donde esta ese id y rompo la iteracion.
				confirmar = i;
				break;
			}
		}
	}

	return confirmar;
}

void eGen_MostrarUno(eGen Gen) {
	//mostrar solo un Gen.
	printf("%4d\n", Gen.idGen);
}

int eGen_MostrarTodos(eGen array[], int TAM) {
	int i;
	int confirmar = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Gen");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				eGen_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		confirmar = 1;
	}

	return confirmar;
}

int eGen_MostrarDadosDeBaja(eGen array[], int TAM) {
	int i;
	int confirmar = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Gen\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Gen
				eGen_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		confirmar = 1;
	}

	return confirmar;
}

eGen eGen_CargarDatos(void) {
	eGen auxiliar;
	/* CARGAR DATOS NECSARIOS PARA EL ALTA/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA
	return auxiliar;
}

eGen eGen_ModificarUno(eGen Gen) {
	eGen auxiliar = Gen;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL
	return auxiliar;
}

int eGen_Alta(eGen array[], int TAM) {
	int confirmar = 0;
	eGen auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = eGen_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = eGen_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.idGen = eGen_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		confirmar = 1;
	}

	return confirmar;
}

int eGen_Baja(eGen array[], int TAM) {
	int confirmar = 0;
	int idGen;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (eGen_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/

		//BUSCO INDEX POR ID EN ARRAY
		while (eGen_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");
			idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eGen_BuscarPorID(array, TAM, idGen);

		/*PREGUNTAR SI DESEA CONTINUAR/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		confirmar = 1;
	}

	return confirmar;
}

int eGen_Modificacion(eGen array[], int TAM) {
	int confirmar = 0;
	int idGen;
	int index;
	int flag = 0;
	eGen auxiliar;

	//LISTO TODOS LOS Gen
	if (eGen_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/

		//BUSCO INDEX POR ID EN ARRAY
		while (eGen_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");
			idGen = 1; /*USAR FUNCION GET_INT DE LIBRERIA DE INPUTS/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = eGen_BuscarPorID(array, TAM, idGen);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eGen_ModificarUno(array[index]);

		/*PREGUNTAR SI DESEA CONTINUAR/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		confirmar = 1;
	}

	return confirmar;
}

int eGen_Sort(eGen array[], int TAM, int criterio) {
	int confirmar = 0;
	int i;
	int j;
	eGen aux;

	/** EJEMPLO DE SORT CON ID DE Gen */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
/*	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idGen > array[j].idGen) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			confirmar = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idGen < array[j].idGen) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			confirmar = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			confirmar = 0;
			break;
		}
	}
	return confirmar;
}


	 *
	 * int getChar(char* resultado, char mensaje, char mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno;
	int auxiliarChar;

	retorno =-1;

	if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo>=maximo && reintentos>=0)
	{
		for(reintentos;reintentos<=0;reintentos--)
		{
			printf("%s",mensaje);
			fflush("stdin");
			scanf("%c",&resultado);
			if(resultado>minimo && resultado<maximo)
			{
				auxiliarChar=*resultado;
				retorno = 0;
				break;
			}else{
				printf("\nLa palabra ingresada no esta dentro del limite(%d-%d), intente nuevamente\n",minimo ,maximo);
			}
		}
	}
    return retorno;
}
	 */

