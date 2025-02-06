#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char linha[55];

    while (fgets(linha, sizeof(linha), stdin)) {
        int soma_tamanho = 0, qtd_palavras = 0, tamanho_atual = 0;
        int eh_palavra = 1; 

        for (int i = 0; linha[i] != '\0'; i++) {
            char c = linha[i];

            if (isalpha(c)) {
                tamanho_atual++;
            } else if (c == '.') {
                if (linha[i + 1] != '\0' && !isspace(linha[i + 1])) {
                    eh_palavra = 0;
                }
            } else if (isspace(c)) {
                if (tamanho_atual > 0 && eh_palavra) {
                    soma_tamanho += tamanho_atual;
                    qtd_palavras++;
                }
                tamanho_atual = 0;
                eh_palavra = 1;
            } else {
                eh_palavra = 0;
            }
        }

        if (tamanho_atual > 0 && eh_palavra) {
            soma_tamanho += tamanho_atual;
            qtd_palavras++;
        }

        int comprimento_medio = (qtd_palavras == 0) ? 0 : (soma_tamanho / qtd_palavras);

        if (comprimento_medio <= 3)
            printf("250\n");
        else if (comprimento_medio <= 5)
            printf("500\n");
        else
            printf("1000\n");
    }

    return 0;
}
