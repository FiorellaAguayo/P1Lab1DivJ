/*
 * validation.c
 *
 *  Created on: 21 may. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "validation.h"
#include <ctype.h>

int getIntNumber(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
    int retorno = -1;
    int numeroIngresado;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}

int getString(char* cadena, char* mensaje)
{
    int retorno = -1;
    //int i = 0;

    if(cadena != NULL && mensaje != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);
        /*while(cadena[i] > '\0')
        {
        	printf("%s", mensajeError);
        	fflush(stdin);
        	gets(cadena);
        }*/
        retorno = 0;
    }
    return retorno;
}

int firstCapitalChar(char name[])
{
	int i = 0;
	int error = -1;

	if(name != NULL)
	{
		strlwr(name);
		name[0] = toupper(name[0]);

		while(name[i] != '\0')
		{
		   if(name [i] == ' ')
		   {
			   name [i + 1] = toupper(name[i+1]);
		   }

		   i++;
		}
		    //puts(name);
	  error = 0;
	}
    return error;
}

int validarLetras(char* string)
{
    int i = 0;
    int error = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] != ' ' && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
            {
                error= -1;

                while(error < 0)
                {
                    printf("ERROR. Se debe ingresar letras unicamente: ");
                    fflush(stdin);
                    gets(string);
                    error = 0;
                    i = 0;
                }
            }
            i++;
        }
    }

    return error;
}

int getLegajo(int* entero, char* mensaje, char* mensajeError, int a, int b, int c)
{
	int retorno = 0;
	int legajoIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &legajoIngresado);

		while(legajoIngresado != a && legajoIngresado != b && legajoIngresado != c)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &legajoIngresado);
		}

		*entero = legajoIngresado;
		retorno = 0;
	}

	return retorno;
}


