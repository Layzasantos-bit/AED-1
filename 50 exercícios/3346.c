#include <stdio.h>

int main() {
    double F1, F2, resultado;

    // Entrada dos valores
    scanf("%lf %lf", &F1, &F2);

    // Cálculo da flutuação total
    resultado = ((100 + F1) * (100 + F2) / 100) - 100;

    // Saída com 6 casas decimais
    printf("%.6lf\n", resultado);

    return 0;
}
