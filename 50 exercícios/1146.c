#include <stdio.h>

int main() {
    int X;

    // Lê números até que X seja 0
    while (scanf("%d", &X) && X != 0) {
        // Imprime os números de 1 até X
        for (int i = 1; i <= X; i++) {
            // Imprime o número, sem espaço após o último número
            if (i == X) {
                printf("%d\n", i);  // Último número da sequência, com quebra de linha
            } else {
                printf("%d ", i);  // Números intermediários seguidos de espaço
            }
        }
    }

    return 0;
}
