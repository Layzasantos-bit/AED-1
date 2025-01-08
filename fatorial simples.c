#include <stdio.h>

int main() {
    int N;
    int fatorial = 1;

    // Leitura do valor de N
    scanf("%d", &N);

    // Cálculo do fatorial
    for (int i = 1; i <= N; i++) {
        fatorial *= i;
    }

    // Imprimir o fatorial
    printf("%d\n", fatorial);

    return 0;
}
