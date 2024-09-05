#include <stdio.h>

int factorial(int n);
void isPair();
void maxN();
void leapYear();
int fibonacci(int n);
void gano();
int power(int base, int exp);
int upperCase(char *text);
void upper();
int lowerCase(char *text);
void lower();
void ODH();

int main() {
	int op = 0;
	do{
		printf("1. Año bisiesto\n");
	    printf("2. Calcular factorial\n");
	    printf("3. Calcular la potencia\n");
	    printf("4. Par o impar\n");
	    printf("5. Fibonacci\n");
	    printf("6. Verificar mayusculas\n");
	    printf("7. Verificar minusculas\n");
	    printf("8. Numero mas grande\n");
	    printf("9. Numeros 1-10 en Oct, Dec, Hex\n");
	    printf("0. Para terminar la ejecucion\n");
	    printf("Seleccione el numero del punto de la tarea que desea probar: ");
	    scanf("%d", &op);
	    printf("\n \n");
	    switch (op) {
	        case 1:
	            leapYear();
	            break;
	        case 2: {
	            int num;
	            printf("Ingrese un número para calcular su factorial: ");
	            scanf("%d", &num);
	            printf("El factorial de %d es %d\n", num, factorial(num));
	            break;
	        }
	        case 3: {
	            int base, exp;
	            printf("Ingrese la base: ");
	            scanf("%d", &base);
	            printf("Ingrese el exponente: ");
	            scanf("%d", &exp);
	            printf("%d elevado a %d es %d\n", base, exp, power(base, exp));
	            break;
	        }
	        case 4:
	            isPair();
	            break;
	        case 5: {
	            int num;
	            printf("Ingrese un número para calcular el Fibonacci: ");
	            scanf("%d", &num);
	            printf("El Fibonacci de %d es %d\n", num, fibonacci(num));
	            break;
	        }
	        case 6:
	            upper();
	            break;
	        case 7:
	            lower();
	            break;
	        case 8:
	            maxN();
	            break;
	        case 9:
	            ODH();
	            break;
	        case 0:
	        	printf("Se termino la ejecucion");
	        	break;
	        default:
	            printf("Opción no válida\n");
	            break;
    	}
		printf("\n Enter para continuar \n\n\n");
		getchar();
    	getchar();
	}while(op != 0);
    return 0;
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: el factorial de 0 o 1 es 1
    } else {
        return n * factorial(n - 1); // Llamada recursiva para encontrar el factorial anterior
    }
}

void isPair() {
    int num;
    
    printf("Ingrese un número: ");
    scanf("%d", &num);
    
    if (num % 2 == 0) {
        printf("El numero %d es par\n", num);
    } else {
        printf("El numero %d es impar\n", num);
    }
}

void maxN() {
    int num1, num2, num3;
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);
    
    printf("El mayor es: ");
    if (num1 > num2 && num1 > num3) {
        printf("%d\n", num1);
    } else if (num2 > num1 && num2 > num3) {
        printf("%d\n", num2);
    } else {
        printf("%d\n", num3);
    }
}

void leapYear() {
    int year;
    
    printf("Ingrese un año para saber si es bisiesto: ");
    scanf("%d", &year);
    
    printf("El año %d", year);
    
    if (year % 4 == 0) {
        printf(" es bisiesto\n");
    } else {
        printf(" no es bisiesto\n");
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Los primeros dos números de Fibonacci son 0 y 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Suma de los dos números anteriores
    }
}

void gano() {
    int juegos, i, ganador;
    int sara = 0;
    int david = 0;
    
    printf("Cuántos juegos se van a enfrentar David y Sara: ");
    scanf("%d", &juegos);
    
    for (i = 1; i <= juegos; i++) {
        printf("\nEl juego número %d lo ganó: \n1)Sara \n2)David\nGanador: ", i);
        scanf("%d", &ganador);
        
        if (ganador == 1) {
            sara++;
        } else if (ganador == 2) {
            david++;
        } else {
            printf("\nJuego empatado\n");
        }   
    }
    
    if (sara > david) {
        printf("Sara ganó, en tu cara David\n");
    } else {
        printf("Soy David y me dejaron ganar\n");
    }
}

int power(int base, int exp) {
    int result = 1;
    if (exp != 0) {
        result = base * power(base, exp - 1); // Multiplicación repetida
    }
    return result;
}

int upperCase(char *text) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            return 1; // Si encuentra una mayúscula, retorna 1
        }
        i++;
    }
    return 0; // No encontró mayúsculas
}

void upper() {
    char str[101];
    printf("Ingrese una cadena (máx. 100 caracteres): ");
    scanf("%100s", str);

    if (upperCase(str)) {
        printf("La cadena contiene una mayúscula.\n");
    } else {
        printf("La cadena no contiene una mayúscula.\n");
    }
}

int lowerCase(char *text) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            return 1; // Si encuentra una minúscula, retorna 1
        }
        i++;
    }
    return 0; // No encontró minúsculas
}

void lower() {
    char str[101];
    printf("Ingrese una cadena (máx. 100 caracteres): ");
    scanf("%100s", str);

    if (lowerCase(str)) {
        printf("La cadena contiene una minúscula.\n");
    } else {
        printf("La cadena no contiene una minúscula.\n");
    }
}

void ODH() {
    printf("%-10s%-12s%-12s%-12s\n", "Número", "Octal", "Decimal", "Hexadecimal");
    printf("--------------------------------------------------------------\n");

    for (int i = 1; i <= 10; i++) {
        printf("%-10d%-12o%-12d%-12x\n", i, i, i, i);
    }
}
