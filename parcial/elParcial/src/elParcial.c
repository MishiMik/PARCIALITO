/*
 *
 * Servicio:
● id (comienza en 20000, autoincremental)
● descripción (máximo 25 caracteres)
● precio
 *
 * trabajo
 ● id (autoincremental)
● marcaBicicleta (Cadena) Validar
● rodadoBicicleta
● idServicio (debe existir) Validar
● fecha (Validar día, mes y año)
El array de servicios deberá ser hardcodeado.
Servicios (Limpieza: $250, Parche: $300, Centrado: $400, Cadena: $350)
*/

/*
for (i = 0; i < TAM - 1; i++)
{             for (j = i + 1; j < TAM; j++)
{                 //PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO){
	//CRITERIO DE ORDENAMIENTO
	if (list[i].sector == list[j].sector)
	{                 if (list[i].id > list[j].id)
	{
		//INTERCAMBIO POSICIONES EN ARRAY
		aux = list[i];
		list[i] = list[j];
		list[j] = aux;      }
	}

}
}
}
	}
	}
}
}
}
*/

#include "abml.h"


#define T 3


int main(void) {

	int opcion;
	int id[T]={20000, 1, 1};

	eServicio servicios[T];
	hardcodeo (servicios, 0, "limpieza", 250, &id);
	hardcodeo (servicios, 1, "parche", 250, &id);
	hardcodeo (servicios, 2, "cadena", 250, &id);
	opcion=menu();

	return 0;

}
	/*
	eBicicleta bicicletas[T];

	switch (opcion)
				{

				case 1:
					//ALTA
					if (Bicicleta_ALTA(bicicletas, T)==1) {
						printf("DADO DE ALTA EXITOSAMENTE\n");
					} else {
						printf("ERROR. SIN ESPACIO PARA ALMACENAR MAS BICICLETAS\n");
					}
					system("pause");
					break;
				case 2:
					//BAJA
					if (eBicicleta_BAJA(bicicletas, T)) {
						puts("\n * BAJA DE bicicletas EXITOSA");
						eServicio_MostrarTodos(bicicletas, T);
					} else {
						puts("\n * BAJA DE bicicletas CANCELADA");
					}
					system("pause");
					break;
				case 3:
					//MODIFICACION
					if (eBicicleta_Modificacion(bicicletas, bicicletas)) {
						puts("\n * MODIFICACION DE bicicletas EXITOSA\n");
						eServicio_MostrarTodos(bicicletas, T);
					} else {
						puts("\n * MODIFICACION DE bicicletas CANCELADA");
					}
					system("pause");
					break;
				case 4:
					//LISTADO bicicletas
					eBicicleta_MostrarTodos(bicicletas, T);
					system("pause");
					break;
				case 5:
					//ORDENAR Servicio
					int criterioDeOrdenamiento = 1; //PEDIR CRITERIO DE ORDENAMIENTO
					eBicicleta_Sort(servicios, T, criterioDeOrdenamiento);
					system("pause");
					break;
				case 6:
					char respuesta;
					printf("\n\aDesea salir? s/n");
					fflush(stdin);
					scanf("%s", &respuesta);
					if(respuesta=="s")
					{
					 continue;
					}
					else
					{
						opcion=menu();
					}


			}



	}



*/


