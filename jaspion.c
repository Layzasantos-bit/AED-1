#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINHA 81

typedef struct {
    char japones[101];
    char portugues[101];
} Traducao;

const char* traduzir_palavra(const char* palavra, Traducao* dicionario, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(palavra, dicionario[i].japones) == 0) {
            return dicionario[i].portugues;
        }
    }
    return palavra;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int t = 0; t < T; t++) {
        int M, N;
        scanf("%d %d", &M, &N);
        getchar();

        Traducao* dicionario = (Traducao*)malloc(M * sizeof(Traducao));
        for (int i = 0; i < M; i++) {
            fgets(dicionario[i].japones, sizeof(dicionario[i].japones), stdin);
            dicionario[i].japones[strcspn(dicionario[i].japones, "\n")] = '\0';

            fgets(dicionario[i].portugues, sizeof(dicionario[i].portugues), stdin);
            dicionario[i].portugues[strcspn(dicionario[i].portugues, "\n")] = '\0';
        }

        for (int i = 0; i < N; i++) {
            char linha[MAX_LINHA];
            fgets(linha, sizeof(linha), stdin);
            linha[strcspn(linha, "\n")] = '\0';

            char* palavra = strtok(linha, " ");
            int primeira = 1;

            while (palavra != NULL) {
                if (!primeira) {
                    printf(" ");
                }
                primeira = 0;
                printf("%s", traduzir_palavra(palavra, dicionario, M));
                palavra = strtok(NULL, " ");
            }
            printf("\n");
        }

        if (t < T - 1) {
            printf("\n");
        }

        free(dicionario);
    }

    return 0;
}
