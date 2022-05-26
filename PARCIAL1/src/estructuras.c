/*
 * parcial.c
 *
 *  Created on: 20 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "validation.h"


int initVivienda(sVivienda* list, int len)
{
	int allOk = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; len > i; i++)
		{
			list[i].isEmpty = 1; // está vacío
		}
		allOk = 1;
	}
	return allOk;
}

int menu()
{
	int option;

	system("cls");
	printf("\n\n-----| MENÚ DE OPCIONES |-----");
	printf("\n\n1. ALTA VIVIENDA");
	printf("\n2. MODIFICAR VIVIENDA");
	printf("\n3. BAJA VIVIENDA");
	printf("\n4. LISTAR VIVIENDAS");
	printf("\n5. LISTAR CENSISTAS");
	printf("\n6. LISTAR DATOS DEL CENCISTA");
	printf("\n7. SALIR");
	printf("\n\nOpción: ");
	scanf("%d", &option);

	return option;
}

int searchFreeSpace(sVivienda* list, int len)
{
	int freeSpace = -1; //ocupado

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1) //vacío
			{
				freeSpace = i;
				break;
			}
		}
	}
	return freeSpace;
}

int addVivienda(sVivienda* list, int len, sCensista* listC, int lenC, int* nextId)
{
	int allOk = 0;
	int index;
	sVivienda auxVivienda;
	sCensista auxCensista;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("\n------|  ALTA  |------");

		index = searchFreeSpace(list, len);

		if(index == -1)
		{
			printf("\n\nNo hay espacio para agregar viviendas.");
		}
		else
		{
			auxVivienda.idVivienda = *nextId;
			(*nextId)++;

			getString(auxVivienda.calle, "\n\nIngrese nombre de la calle: ");
			validarLetras(auxVivienda.calle);
			firstCapitalChar(auxVivienda.calle);

			getIntNumber(&auxVivienda.cantidadPersonas,"\nIngrese cantidad de personas (solo números, hasta 20): ","\nERROR. Ingrese cantidad de personas (solo números, hasta 20): ", 1, 20);

			getIntNumber(&auxVivienda.cantidadHabitaciones,"\nIngrese cantidad de habitaciones (solo números, hasta 15): ","\nERROR. Ingrese cantidad de habitaciones (solo números, hasta 15): ", 1, 15);

			getIntNumber(&auxVivienda.tipoVivienda,"\nIngrese tipo de vivienda \n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n\nOpción: : ","\nERROR. Ingrese tipo de vivienda \n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n\nOpción: ", 1, 4);

			hardcodeoCensista(listC);
			getLegajo(&auxVivienda.legajoCensista,"\nIngrese legajo del censista: ","\nERROR. Ingrese legajo de censista EXISTENTE: ",100,101,102);


			auxVivienda.isEmpty = 0; //ocupado
			list[index] = auxVivienda;

			allOk = 1;
		}
	}
	return allOk;
}

int searchViviendaById(sVivienda* list, int len, int* id)
{
	int index = -1;

	if(list != NULL && len > 0 && id != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].idVivienda == *id) //El negado dice que mi empty está en 0, ya que estoy engando el 1, es lo mismo que poner (list[i].isEmpty)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

void printVivienda(sVivienda unaVivienda)
{
	printf("\n %d  %10s  %16d  %22d  %27d  %23d \n",
			unaVivienda.idVivienda,
			unaVivienda.calle,
			unaVivienda.cantidadPersonas,
			unaVivienda.cantidadHabitaciones,
			unaVivienda.tipoVivienda,
			unaVivienda.legajoCensista);
}

int menuModifyVivienda()
{
	int option;

	printf("\n1. Calle");
	printf("\n2. Cantidad de personas");
	printf("\n3. Cantidad de habitaciones");
	printf("\n4. Tipo de vivienda");
	printf("\nElija opción: ");
	scanf("%d", &option);

	return option;
}

int modifyVivienda(sVivienda* list, int len)
{
	int allOk = 0;
	int id;
	int index;
	char confirm;
	char auxCalle[25];
	int auxCantidadPersonas;
	int auxCantidadHabitaciones;
	int auxTipoVivienda;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("\n-----|  MODIFICACIÓN  |-----\n");
        printf("\n ID  \t    CALLE \t CANTIDAD DE PERSONAS  \t CANTIDAD DE HABITACIONES  \t TIPO DE VIVIENDA  \t LEGAJO DE CENSISTA");
		printViviendas(list, len);
		printf("\n\nIngrese el ID de la vivienda que quiera modificar: ");
		scanf("%d", &id);

		index = searchViviendaById(list, len, &id);

		if(index == -1)
		{
			printf("\nNo existe vivienda con ese ID.");
		}
		else
		{
			printVivienda(list[index]);

			printf("\n¿Confirma modificación? s/n: ");
			fflush(stdin);
			scanf("%c", &confirm);

			if(confirm == 's')
			{
				switch(menuModifyVivienda())
				{
					case 1:
						getString(auxCalle, "\nIngrese nueva calle: ");
						firstCapitalChar(auxCalle);
						validarLetras(auxCalle);
						strcpy(list[index].calle, auxCalle);
						break;

					case 2:
						getIntNumber(&auxCantidadPersonas, "\nIngrese nueva cantidad de personas (hasta 20): ", "ERROR. Ingrese nueva cantidad de personas (hasta 20): ", 1, 20);
						list[index].cantidadPersonas = auxCantidadPersonas;
						break;

					case 3:
						getIntNumber(&auxCantidadHabitaciones, "\nIngrese nueva cantidad de habitaciones (hasta 15): ", "\nERROR. Ingrese nueva cantidad de habitaciones (hasta 15): ", 1, 15);
						list[index].cantidadHabitaciones = auxCantidadHabitaciones;
						break;

					case 4:
						getIntNumber(&auxTipoVivienda, "\nIngrese nuevo tipo de vivienda \n\t1. Casa\n\t2. Departamento\n\t3. Casilla\n\t4. Rancho\n\n\tOpción: ", "\nERROR. Ingrese nuevo tipo de vivienda \n\t1. Casa\n\t2. Departamento\n\t3. Casilla\n\t4. Rancho\n\n\tOpción: ", 1, 10);
						list[index].tipoVivienda = auxTipoVivienda;
						break;

					default:
						printf("\nOpción inválida.");
						confirm = 'n';
						break;
				}
				list[index].isEmpty = 0;
				allOk = 1;
			}
			else
			{
				printf("\nSe ha cancelado la modificación.");
			}
		}
	}
	return allOk;
}

int removeVivienda(sVivienda* list, int len)
{
	int allOk = 0;

	if(list != NULL && len > 0)
	{
		int id;
		int index;
		char confirm;

		system("cls");
		printf("\n-----|  BAJA  |-----\n");
		printViviendas(list, len);
		printf("\n\nIngrese el ID de la vivienda que quiera dar de baja: ");
		scanf("%d", &id);

		index = searchViviendaById(list, len, &id);

		if(index == -1)
		{
			printf("\nNo existe vivienda con ese ID.");
		}
		else
		{
			printVivienda(list[index]);

			printf("\n¿Confirma la baja s/n?: ");
			fflush(stdin);
			scanf("%c", &confirm);

			if(confirm == 's')
			{
				list[index].isEmpty = 1; //baja logica
				allOk = 1;
			}
			else
			{
				printf("\nSe ha cancelado la baja.");
			}
		}
	}
	return allOk;
}

int resetVivienda(sVivienda* list, int len, int* flag)
{
	int allOk = 0;

	if(list != NULL && len > 0 && flag != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				*flag = 1;
				allOk = 1;
			}
			else
			{
				*flag = 0;
			}
		}
	}
	return allOk;
}

int printViviendas(sVivienda* list, int len)
{
	int allOk = 0;
	int flag = 0;

	if(list != NULL && len > 0)
	{

		system("cls");
		printf("\n-----|  LISTADO  |-----");
        printf("\n ID  \t    CALLE \t CANTIDAD DE PERSONAS  \t CANTIDAD DE HABITACIONES  \t TIPO DE VIVIENDA  \t LEGAJO DE CENSISTA");

		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty)
			{
				printVivienda(list[i]);
				flag = 1;
			}
		}

		if(!flag)
		{
			printf("\nNo hay personas para mostrar.");
		}
		allOk = 1;
	}
	return allOk;
}

void hardcodeoCensista(sCensista* list)
{
    sCensista aux[] = {
    						{100,"Ana",34,12032345},
							{101,"Juan",24,430154678},
							{102,"Sol",47,590237487}
                       };
    system("cls");
	printf("\n\n\t -----|  LISTADO CENSISTAS  |-----");
	printf("\n LEGAJO  \t    NOMBRE \t EDAD \t\t TELÉFONO\n");

    for(int i = 0; i < 3; i++)
	{
		list[i] = aux[i];

		printf("\n %d  %19s  %9d  %18d\n",
		    			aux[i].legajoCensista,
		    			aux[i].nombre,
		    			aux[i].edad,
		    			aux[i].telefono
			   );
	}
}

int ordenarViviendas(sVivienda* list, int len, int order)
{
    int allOk = 0;
    sVivienda aux;

    if(list != NULL && len > 0)
    {
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(order == 1) //ascendente
				{
					if((strcmp(list[i].calle, list[j].calle) > 0) || ((strcmp(list[i].calle, list[j].calle) == 0) && list[i].cantidadPersonas > list[j].cantidadPersonas))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
				else
				{
					if(order == 2) //descendente
					{
						if((strcmp(list[i].calle, list[j].calle) < 0) || ((strcmp(list[i].calle, list[j].calle) == 0) && list[i].cantidadPersonas < list[j].cantidadPersonas))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	   allOk = 1;
    }

    return allOk;
}

int hacerListado(sVivienda* list, int len)
{
	int allOk=0;
	int option;

	if(list != NULL && len > 0)
	{
			printf("\n¿En qué órden quiere la lista?");
			printf("\n   1. Ascendente");
			printf("\n   2. Decendente");
			printf("Ingrese opcion: ");
			scanf("%d", &option);

			if(option == 1)
			{
				ordenarViviendas(list, len, option);
				printViviendas(list, len);
			}
			else if(option == 2)
			{
				ordenarViviendas(list, len, option);
				printViviendas(list, len);
			}
			else
			{
				printf("Opcion invalida.");
			}

			allOk = 1;
	   }

return allOk;
}


void listadoDatosCensistas(sCensista* listCen, int lenCen, sVivienda* list, int len)
{

	if(list != NULL && len > 0 && listCen != NULL)
	{

		for(int i = 0; i < 3; i++){

			for(int j = 0; j < len; j++){

				if(listCen[i].legajoCensista == list[j].legajoCensista){

					printf("legajo censista %d, nombre %s, edad  %d, telefono  %d\n\n", listCen[i].legajoCensista, listCen[i].nombre ,listCen[i].edad ,listCen[i].telefono);
					printf("Calle          Cantidad Personas     |     Cantidad Habitaciones     |     Tipo de Vivienda    |      Legajo Censista      |      Numero ID    |\n" );
					printf("%s  %20d  %20d  %20d  %20d  %20d\n",list[i].calle, list[i].cantidadPersonas, list[i].cantidadHabitaciones, list[i].tipoVivienda, list[i].legajoCensista);


				}

			}

		}

	}

}
//int mostarrUnCwensista

