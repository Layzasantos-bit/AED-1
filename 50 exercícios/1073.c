#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  // Leitura do valor N

    // Percorrer todos os números de 1 até N
    for (int i = 2; i <= N; i += 2) {  // Começamos de 2 e pulamos de 2 em 2
        printf("%d^2 = %d\n", i, i * i);  // Imprime o quadrado do número par
    }

    return 0;
}
