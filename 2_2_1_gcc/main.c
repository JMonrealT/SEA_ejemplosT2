#include <stdio.h>
#include "operaciones.h"

int main() {
    int a = 10, b = 5;
    
    printf("a = %d, b = %d\n", a, b);
    printf("Suma: %d\n", suma(a, b));
    printf("Resta: %d\n", resta(a, b));
    printf("Multiplicación: %d\n", multiplicacion(a, b));
    
    return 0;
}
