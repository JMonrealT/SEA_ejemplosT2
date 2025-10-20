#include <stdio.h>

// Función simple para sumar dos números
int sumar(int a, int b) {
    int resultado = a + b;
    return resultado;
}

// Función simple para multiplicar
int multiplicar(int x, int y) {
    return x * y;
}

int main() {
    int num1 = 10;
    int num2 = 5;
    int suma, producto;
    int i;  // Declarar i antes del bucle para poder usar display
    
    printf("Números: %d y %d\n", num1, num2);
    
    suma = sumar(num1, num2);
    printf("Suma: %d\n", suma);
    
    producto = multiplicar(num1, num2);
    printf("Producto: %d\n", producto);
    
    // Un pequeño bucle para mostrar
    for (i = 1; i <= 3; i++) {
        printf("Iteración %d: %d x %d = %d\n", i, i, 
			num2, multiplicar(i, num2));
    }
    
    return 0;
}