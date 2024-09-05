#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "primos.h"

using namespace std;

int main(){
	int num;
	Primos primos;
    cout << "Ingrese un numero para verificar si es primo: ";
    cin >> num;
    if (primos.isPrimo(num)) {
        cout << num << " es un numero primo." << endl;
    } else {
        cout << num << " no es un numero primo." << endl;
    }

    // Pide una lista de números e imprime por cada elemento de la lista si es primo.
    int tam;
    cout << "Ingrese el numero de elementos en la lista: ";
    cin >> tam;
	// Inicializa el arreglo con el tamaño que ingreso el usuario.
    int* arr = (int*)malloc(sizeof(int) * tam);
    if (arr == nullptr) {
    	return 404; // Si no hay suficiente espacio retorna error.
    }
	else{
		// Ingresa los elementos que quiere comprobar si son primos o no.
		for (int i = 0; i < tam; i++) {
	        cout << "Ingrese el elemento" << i + 1 << ": ";
	        scanf("%d", &arr[i]);
    	}
    	// Método para imprimir si el número en la posición i del arreglo es primo.
    	primos.listPrimos(arr, tam);
    	free(arr); // Libera la memoria que ocupaba el arreglo.
	}
    

    // Imprime los numeros primos en un rango dado. 
    int start, end;
    cout << "Ingrese el inicio del rango para encontrar numeros primos: ";
    cin >> start;
    cout << "Ingrese el final del rango para encontrar numeros primos: ";
    cin >> end;
    cout << "Numeros primos en el rango" << start << end << endl;
    primos.rangesPrimos(start, end);
    
	return 0;
}