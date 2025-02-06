#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Função principal
int main() {
    int N;

    while (scanf("%d", &N), N) {  // Continua enquanto N for diferente de 0
        while (1) {
            int sequence[MAX];
            scanf("%d", &sequence[0]);

            if (sequence[0] == 0) {
                printf("\n");  // Linha em branco entre blocos de entrada
                break;
            }

            // Lê o restante da sequência
            for (int i = 1; i < N; i++) {
                scanf("%d", &sequence[i]);
            }

            int stack[MAX], top = -1;
            int next_wagon = 1;  // Próximo vagão a ser empilhado
            int index = 0;       // Índice da sequência desejada

            // Simulação do processo
            while (next_wagon <= N) {
                stack[++top] = next_wagon++;  // Empilha o próximo vagão

                // Enquanto o topo da pilha for igual ao próximo da sequência desejada
                while (top >= 0 && stack[top] == sequence[index]) {
                    top--;      // Desempilha
                    index++;    // Avança para o próximo da sequência
                }
            }

            // Se conseguimos ordenar todos os vagões
            if (index == N) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
