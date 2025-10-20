#include <stdio.h>

int main() {
    int x;  // Variable no inicializada - generará warning
    printf("Valor de x: %d\n", x);
    return 0;
}
