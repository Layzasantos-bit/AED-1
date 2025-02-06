#include <stdio.h>
#include <string.h>

int main() {
    char palavra[21]; // máximo de 20 caracteres + 1 para o '\0' terminador
    
    // Continuar até o final do arquivo (EOF)
    while (scanf("%s", palavra) != EOF) {
        // Verificar o tamanho da palavra
        if (strlen(palavra) >= 10) {
            printf("palavrao\n");
        } else {
            printf("palavrinha\n");
        }
    }

    return 0;
}
