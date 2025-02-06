#include <stdio.h>

int main() {
    int maior = -1, posicao = 0, valor;

    // Lê os 100 valores inteiros
    for (int i = 1; i <= 100; i++) {
        scanf("%d", &valor);

        // Verifica se o valor atual é maior que o maior encontrado
        if (valor > maior) {
            maior = valor;
            posicao = i;  // Armazena a posição (1-indexed)
        }
    }

    // Imprime o maior valor e sua posição
    printf("%d\n", maior);
    printf("%d\n", posicao);

    return 0;
}
