#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char vet[100]; // Vamos usar um tamanho adequado para armazenar a string

    // Lê as linhas de entrada até o final
    while (fgets(vet, sizeof(vet), stdin) != NULL) {
        int a = 1; // Variável para alternar a capitalização, começa em 1 (maiúscula)

        // Percorre cada caractere da string
        for (int i = 0; vet[i] != '\0'; i++) {
            if (vet[i] != ' ') { // Ignora espaços
                if (a % 2 != 0) { // Caso a posição seja ímpar (considerando apenas letras)
                    vet[i] = toupper(vet[i]); // Converte para maiúscula
                } else {
                    vet[i] = tolower(vet[i]); // Converte para minúscula
                }
                a++; // Alterna a capitalização para a próxima letra
            }
        }

        // Imprime a sentença transformada
        printf("%s", vet);
    }

    return 0;
}
