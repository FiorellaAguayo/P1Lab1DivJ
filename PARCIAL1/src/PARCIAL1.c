/*
 ============================================================================
 Name        : PARCIAL1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "validation.h"
#define LEN 100
#define LENC 3

int main()
{
	setbuf(stdout, NULL);

	sVivienda list[LEN];
	sCensista listCen[LENC];
	char confirm = 's';
	int nextId = 20000;
	int flag = 0;

	if(!initVivienda(list, LEN))
    {
        printf("\nOcurrió un problema al hacer la inicialización.");
    }

	while(confirm == 's')
	{
		switch(menu())
		{
			case 1:
				//alta vivienda
				if(addVivienda(list, LEN, listCen, LENC, &nextId))
				{
				    printf("\n¡ALTA EXITOSA!\n");
					flag = 1;
				}
				else
				{
				    printf("\nATENCIÓN. Hubo un problema al hacer el alta.\n");
				}
				break;
			case 2:
				//modificar vivienda
				if(flag)
				{
					if(modifyVivienda(list, LEN))
					{
						printf("\n¡MODIFICACIÓN EXITOSA!\n");
					}
					else
					{
						printf("\nATENCIÓN. Hubo un problema al hacer la modificación.\n");
					}
				}
				else
				{
					printf("\nNo hay ninguna vivienda para modificar.\n");
				}

				break;
			case 3:
				//baja vivienda
				if(flag)
				{
					if(removeVivienda(list, LEN))
					{
						printf("\n¡BAJA EXITOSA!\n");
						system("pause");
						resetVivienda(list, LEN, &flag);
					}
					else
					{
						printf("\nATENCIÓN. Hubo un problema al hacer la baja.\n");
						system("pause");
					}
				}
				else
				{
					printf("\nNo hay ninguna vivienda para dar de baja.\n");
				}
				break;
			case 4:
				//listar viviendas
				if(flag)
                {
                    if(hacerListado(list, LENC))
                    {
                       printf("\n¡LISTADO DE VIVIENDAS EXITOSO!\n");
                    }
                    else
                    {
                        printf("\nATENCIÓN. Ocurrió un problema al mostrar el listado.\n");
                    }
                }
                else
                {
                    printf("\nNo hay ninguna vivienda para mostrar.\n");
                }
				break;
			case 5:
				//listar censistas
				hardcodeoCensista(listCen);
				printf("\n¡LISTADO DE CENSISTAS EXISTOSO!\n");
				break;
			case 6:
				//listar datos censista
				printf("hola");
				listadoDatosCensistas(listCen, LENC, list, LEN);
				break;
			case 7:
				//salir
				confirm = 'n';
				break;
			default:
				printf("\nERROR. Ingrese opción válida.\n");
				break;
		}
	}
	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}
