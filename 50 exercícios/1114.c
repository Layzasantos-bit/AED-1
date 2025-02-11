#include <stdio.h>

int main() {
    int senha;

    // Enquanto a senha não for 2002, continua pedindo a senha
    while (1) {
        scanf("%d", &senha);

        // Verifica se a senha é a correta
        if (senha == 2002) {
            printf("Acesso Permitido\n");
            break;  // Sai do loop quando a senha for correta
        } else {
            printf("Senha Invalida\n");
        }
    }

    return 0;
}
