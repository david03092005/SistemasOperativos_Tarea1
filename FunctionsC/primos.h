#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

class Primos {
 public:
    // Método para verificar si un número es primo
    bool isPrimo(int numero) {
        bool primo = true;
        int numeroDivisor = 2;

        // Verifica casos especiales para 0 y 1
        if (numero <= 1) {
            primo = false;
        } else {
            // Verifica si el número es primo
            while (primo && numero > numeroDivisor) {
                if (numero % numeroDivisor == 0) {
                    primo = false;
                } else {
                    numeroDivisor++;
                }
            }
        }
        return primo;
    }

    // Método para encontrar números primos en una lista dada
    void listPrimos(int * nums, int len) {
        for (int i = 0; i < len; i++) {
        	printf("%d: %s\n", nums[i], isPrimo(nums[i]) ? "es primo" : "no es primo");
    	}
    }

    // Método para generar números primos en un rango dado
    void rangesPrimos(int inicio, int fin) {
        for (int i = inicio; i <= fin; ++i) {
            if (isPrimo(i) == 0){
            	printf("%d ", i);
			}
        }
    }
};