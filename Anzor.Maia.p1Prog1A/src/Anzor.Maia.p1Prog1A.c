/*
 ============================================================================
 Name        : p1Prog1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_N 5
#define TAM 20

typedef struct{
	int idNotebook;
	char marca[20];
	char procesador [20];
	float precio;
} eNotebook;

float aplicarDescuento(float precio);

int contarCaracteres(char cadena[], char caracter);

int ordenamiento(eNotebook lista[], int tam);

void mostrarNotebook(eNotebook unaNotebook);

int mostrarNotebooks(eNotebook lista[], int tam);


int main(void) {

	//APLICAR DESCUNTO

		float num1 = 50;
		float resultado;
	      //BUSCAR CARACTER
		char palabra[TAM];
		char caracter = 'a';
		int veces;

	    eNotebook notebooks[TAM_N] =
	    {
	        {1,"I9","INTEL",122.5},
	        {4,"RYZEN 7","AMD",80.5},
	        {2,"CELERON","INTEL",50},
	        {3,"I9","INTEL",80.5},
	        {5,"RYZEN 3","AMD",72.5}
	    };



		resultado = aplicarDescuento(num1);
		printf("resultado co descuento %.2f", resultado);

//-------------------------------------


		printf("ingrese palabra: ");
		gets(palabra);

		veces = contarCaracteres(palabra,  caracter);
		printf("\ncantidad de veces que letra %c aparece: %d", caracter, veces);




	   //ORDENAR POR PRECIO Y MARCA

	    printf("\n --------------------------------------- \n\n");
	    printf("\n --------------------------------------- \n\n");
	    printf("\n --------------------------------------- \n\n");
	    for(int i= 0; i < TAM_N; i++ )
	    {
	        printf("  %d     %-10s    %-10s     %10.2f \n", notebooks[i].idNotebook, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
	    }

		ordenamiento(notebooks, TAM_N);

	    printf("\n --------------------------------------- \n\n");
	    printf("\n --------------------------------------- \n\n");
	    printf("\n --------------------------------------- \n\n");

	    for(int i= 0; i<TAM; i++ )
	    {
	        printf("  %d     %-10s    %-10s     %10.2f \n", notebooks[i].idNotebook, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
	    }






	return EXIT_SUCCESS;
}


 //----------funciones

float aplicarDescuento(float precio)
{
	float desc;
	float descuentoFinal;

	desc = precio * 5 / 100;
	descuentoFinal = precio - desc;

	return descuentoFinal;
}


int contarCaracteres(char cadena[], char caracter)
{
	int contador = 0;
	int tam;

	tam = strlen(cadena);

	if(cadena != NULL)
	{

		for(int i = 0; i < tam; i++)
		{
			if(cadena[i] == caracter)
			{
				contador++;
			}
		}
	}

	return contador;
}

void mostrarNotebook(eNotebook unaNotebook) {
	printf("    %-5d     %-10s    %-11s          $ %-12.2f ",
			unaNotebook.idNotebook,
			unaNotebook.marca,
			unaNotebook.procesador,
			unaNotebook.precio);
}


int mostrarNotebooks(eNotebook lista[], int tam){
	int ok = -1;
	int flag = 1;

	if(lista != NULL && tam > 0)
	{

		 printf("\n                   LISTA DE NOTEBOOKS                             \n");
		 printf(" ----------------------------------------------------------\n");
		 printf("    ID       MARCA         PROCESADOR          PRECIO       \n");
		 printf(" -----------------------------------------------------------\n\n");

		for(int i = 0; i < tam; i++)
		{
			mostrarNotebook(lista[i]);
			flag = 0;
			printf("\n");

		}
		printf("\n\n");

		if(flag == 1)
		{
			printf("No existen notebooks para mostrar.\n");
		}


		ok = 0;
	}

	return ok;
}


int ordenamiento(eNotebook lista[], int tam)
{
	int ok = 0;
	eNotebook aux;


    if(lista != NULL && tam >0)
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j= i + 1; j < tam ; j++)
            {

                if(strcmp(lista[i].marca, lista[j].marca) > 0 ||
                        (strcmp(lista[i].marca, lista[j].marca) == 0 && lista[i].precio > lista[j].precio))
                {

                    aux= lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }

            }
        }
        ok = 1;
    }
    return ok;
}
