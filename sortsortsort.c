#include <stdio.h>
#include <stdlib.h>

// Função de comparação personalizada para ordenação
int comparar(const void* a, const void* b, void* mod_ptr) {
    int M = *(int*)mod_ptr;
    int x = *(int*)a;
    int y = *(int*)b;

    int mod_x = x % M;
    int mod_y = y % M;

    if (mod_x != mod_y) {
        return mod_x - mod_y;  // Ordenar pelo módulo
    }

    // Critério para números ímpares e pares com mesmo módulo
    int impar_x = (x % 2 != 0);
    int impar_y = (y % 2 != 0);

    if (impar_x && !impar_y) {
        return -1;  // Ímpares antes de pares
    }
    if (!impar_x && impar_y) {
        return 1;   // Pares depois de ímpares
    }

    // Critério para desempate entre números ímpares
    if (impar_x && impar_y) {
        return y - x;  // Ímpares em ordem decrescente
    }

    // Critério para desempate entre números pares
    if (!impar_x && !impar_y) {
        return x - y;  // Pares em ordem crescente
    }

    return 0;  // Caso não entre em nenhum critério
}

int main() {
    int N, M;

    while (1) {
        scanf("%d %d", &N, &M);

        if (N == 0 && M == 0) {
            printf("0 0\n");
            break;
        }

        int numeros[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &numeros[i]);
        }

        // Ordenar usando qsort com função de comparação personalizada
        qsort_r(numeros, N, sizeof(int), comparar, &M);

        // Imprimir resultados
        printf("%d %d\n", N, M);
        for (int i = 0; i < N; i++) {
            printf("%d\n", numeros[i]);
        }
    }

    return 0;
}
