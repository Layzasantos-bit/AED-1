#include <stdio.h>
#define PI 3.14159

int main() {
    double R, volume;

    // Lê o valor do raio
    scanf("%lf", &R);

    // Calcula o volume da esfera
    volume = (4.0 / 3.0) * PI * R * R * R;

    // Imprime o resultado com 3 casas decimais
    printf("VOLUME = %.3lf\n", volume);

    return 0;
}
