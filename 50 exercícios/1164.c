#include <stdio.h>

// Função para verificar se o número é perfeito
int eh_perfeito(int x) {
    int soma = 0;
    
    // Soma dos divisores próprios de x
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            soma += i;
        }
    }

    // Se a soma for igual a x, o número é perfeito
    return soma == x;
}

int main() {
    int N, X;

    // Lê o número de casos de teste
    scanf("%d", &N);

    // Para cada caso de teste
    for (int i = 0; i < N; i++) {
        scanf("%d", &X);

        // Verifica se o número é perfeito e imprime o resultado
        if (eh_perfeito(X)) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }
    }

    return 0;
}
