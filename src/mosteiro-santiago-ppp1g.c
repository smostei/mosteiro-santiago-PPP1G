#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebooks.h"

float aplicarDescuento(float precio); //Punto 1
int contarCaracteres(char cadena[], char caracter); //Punto 2
void ordenarNotebooksPorMarca(sNotebook notebooks[], int longitud); //Punto 3

int main() {

	//---Punto 1---
	printf("El descuento es de: %.2f\n", aplicarDescuento(100));
	//-------------

	//---Punto 2---
	char cadena[] = "te mando un abrazo";

	printf("\nel caracter 'a' se repite %d veces", contarCaracteres(cadena, 'a'));
	//-------------

	//---Punto 3---
	sNotebook notebooks[4] = {
			{0, "Intel", "Samsung", 100},
			{1, "Rayzen", "LG", 150},
			{2, "Random", "HP", 90},
			{3, "Intel i7", "HP", 120}
	};

	printf("\n\nArray desordenado: \n");

	for(int i = 0; i < 4; i++) {
		printf("\nId: %d", notebooks[i].id);
		printf("\nProcesador: %s", notebooks[i].procesador);
		printf("\nMarca: %s", notebooks[i].marca);
		printf("\nPrecio: %.2f", notebooks[i].precio);

		printf("\n\n");
	}

	ordenarNotebooksPorMarca(notebooks, 4);

	printf("Array ordenado por marca DESC (en caso de empate de marca, por precio DESC): \n");

	for(int i = 0; i < 4; i++) {
		printf("\nId: %d", notebooks[i].id);
		printf("\nProcesador: %s", notebooks[i].procesador);
		printf("\nMarca: %s", notebooks[i].marca);
		printf("\nPrecio: %.2f", notebooks[i].precio);

		printf("\n\n");
	}

	//-------------
}

float aplicarDescuento(float precio) {
	float precioConDescuento = precio;

	float descuento = 0.05;

	if(precio > 0 )
		precioConDescuento -= precio * descuento;
	else
		precioConDescuento = 0;


	return precioConDescuento;
}

int contarCaracteres(char cadena[], char caracter) {
	int caracterRepetido = 0;

	for(int i = 0; i < strlen(cadena); i++) {
		if(cadena[i] == caracter)
			caracterRepetido++;
	}

	return caracterRepetido;
}

void ordenarNotebooksPorMarca(sNotebook notebooks[], int longitud) {

	sNotebook auxNotebook;

	for(int i = 0; i < longitud - 1; i++) {
		for(int j = i + 1; j < longitud; j++) {
			if(strcmp(notebooks[i].marca, notebooks[j].marca) < 0) {
				auxNotebook = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxNotebook;
			} else if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0) {
				if(notebooks[i].precio < notebooks[j].precio) {
					auxNotebook = notebooks[i];
					notebooks[i] = notebooks[j];
					notebooks[j] = auxNotebook;
				}
			}
		}
	}
}
