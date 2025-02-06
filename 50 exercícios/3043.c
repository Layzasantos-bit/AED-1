#include <stdio.h>
#include <string.h>

#define MAX 20

int inimizades[MAX][MAX]; // Matriz de adjacência

// Verifica se o subconjunto é válido (sem inimizades)
int conjunto_valido(int mask, int n) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) { // Se o aluno i está no conjunto
            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) && inimizades[i][j]) {
                    return 0; // Conflito encontrado
                }
            }
        }
    }
    return 1; // Conjunto válido
}

int main() {
    int n, t = 1;
    while (scanf("%d", &n) && n > 0) {
        memset(inimizades, 0, sizeof(inimizades));

        // Leitura das inimizades
        for (int i = 0; i < n; i++) {
            int x;
            while (scanf("%d", &x) && x != 0) {
                inimizades[i][x - 1] = 1;
                inimizades[x - 1][i] = 1; // Relação é bidirecional
            }
        }

        int max_comissao = 0;
        int total_subsets = 1 << n; // 2^n subconjuntos possíveis

        // Verificação de todos os subconjuntos
        for (int mask = 0; mask < total_subsets; mask++) {
            if (conjunto_valido(mask, n)) {
                int count = __builtin_popcount(mask); // Conta bits ativos
                if (count > max_comissao) {
                    max_comissao = count;
                }
            }
        }

        // Saída do resultado
        printf("Teste %d\n%d\n\n", t++, max_comissao);
    }

    return 0;
}
