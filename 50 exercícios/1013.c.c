#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, maiorAB, maiorFinal;

    // Entrada de três valores inteiros
    scanf("%d %d %d", &a, &b, &c);

    // Cálculo do maior entre a e b
    maiorAB = (a + b + abs(a - b)) / 2;

    // Cálculo do maior entre maiorAB e c
    maiorFinal = (maiorAB + c + abs(maiorAB - c)) / 2;

    // Saída do maior valor com a mensagem
    printf("%d eh o maior\n", maiorFinal);

    return 0;
}
