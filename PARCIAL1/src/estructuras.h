/*
 * parcial.h
 *
 *  Created on: 20 may. 2022
 *      Author: Aguayo Fiorella
 */

#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct
{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;

}sVivienda;

typedef struct
{
	int legajoCensista;
	char nombre[30];
	int edad;
	int telefono;
}sCensista;


#endif // ESTRUCTURAS_H_INCLUDED

/**
 * @fn int menu()
 * @brief Mostrar un menu princial de opciones
 * @return allOk int Retorna el numero ingresado
 */
int menu();

/**
 * @fn int initVivienda(sVivienda*, int)
 * @brief Inicializar los campos isEmpty del array en 1
 * @param list array de viviendas
 * @param len tamaño del array
 * @return option Retorna -1 si no funciona y el indice si isEmpty está en 1
 */
int initVivienda(sVivienda* list, int len);

/**
 * @fn int searchFreeSpace(sVivienda*, int)
 * @brief Buscar un espacio libre en el array
 * @param list array de viviendas
 * @param len tamaño del array
 * @return freeSpace Retorna -1 si el lugar esta vacio y el indice si esta ocupado
 */
int searchFreeSpace(sVivienda* list, int len);

/**
 * @fn int addVivienda(sVivienda*, int, sCensista*, int, int*)
 * @brief Añadir una vivienda con los datos ingresados por el usuario
 * @param list array de viviendas
 * @param len tamaño del array de viviendas
 * @param listC array de censistas
 * @param lenC tamaño del array de censista
 * @param nextId puntero a entero del id
 * @return allOk Retorna 0 si sale allOk y -1 si sale mal
 */
int addVivienda(sVivienda* list, int len, sCensista* listC, int lenC, int* nextId);

/**
 * @fn int searchViviendaById(sVivienda*, int, int*)
 * @brief Buscar una vivienda a partir de un id
 * @param list array de viviendas
 * @param len tamaño de viviendas
 * @param id Puntero a entero del id
 * @return index Retorna -1 si el id no existe y el indice si existe
 */
int searchViviendaById(sVivienda* list, int len, int* id);

/**
 * @fn void printVivienda(sVivienda)
 * @brief Mostrar una vivienda
 * @param unaVivienda variable en el que se guardan los campos de la estructura
 */
void printVivienda(sVivienda unaVivienda);

/**
 * @fn int menuModifyVivienda()
 * @brief Mostrar un menu de opciones
 * @return option int Retorna el numero ingresado
 */
int menuModifyVivienda();

/**
 * @fn int modifyVivienda(sVivienda*, int)
 * @brief Modificar los datos que el usuario quiera de la vivienda añadida
 * @param list array de viviendas
 * @param len tamaño del array
 * @return int allOk Retorna -1 si sale mal y 0 si sale bien
 */
int modifyVivienda(sVivienda* list, int len);

/**
 * @fn int removeVivienda(sVivienda*, int)
 * @brief Bajar la vivienda que el usuario quiera
 * @param list array de viviendas
 * @param len tamaño del array
 * @return int allOk Retorna 0 si sale mal y 1 si sale bien
 */
int removeVivienda(sVivienda* list, int len);

/**
 * @fn int resetVivienda(sVivienda*, int, int*)
 * @brief Vuelve a poner en 1 los isEmpty para que este vacio el lugar de la vivienda que se dio de baja
 * @param list array de viviendas
 * @param len tamaño del array
 * @param flag bandera que devuelve 1 si esta el lugar vacio y 0 si esta ocupado
 * @return allOk Retorna que si esta mal devuelve 0 y si esta bien devuelve 1
 */
int resetVivienda(sVivienda* list, int len, int* flag);

/**
 * @fn int printViviendas(sVivienda*, int)
 * @brief Mostrar lista de viviendas
 * @param list array de viviendas
 * @param len tamaño de viviendas
 * @return allOk Retorna que si esta mal devuelve 0 y si esta bien devuelve 1
 */
int printViviendas(sVivienda* list, int len);

/**
 * @fn void hardcodeoCensista(sCensista*)
 * @brief Muestra una carga forzada de los censistas
 * @param list array de censista
 */
void hardcodeoCensista(sCensista* list);

/**
 * @fn int ordenarViviendas(sVivienda*, int, int)
 * @brief Ordena el array segun el criterio ingresado
 * @param list array de viviendas
 * @param len tamaño de array
 * @param order numero ingresado
 * @return allOk Retorna 0 si esta mal y 1 si esta bien
 */
int ordenarViviendas(sVivienda* list, int len, int order);

/**
 * @fn int elegirListado(sVivienda*, int)
 * @brief Mostrar el listado armado segun los criterios elegidos
 * @param list array de viviendas
 * @param len tamaño del array
 * @return allOk Retorna 0 si esta mal y 1 si esta bien
 */
int hacerListado(sVivienda* list, int len);

int listadoDatosCensistas(sCensista* listCen, int lenCen, sVivienda* list, int len);
