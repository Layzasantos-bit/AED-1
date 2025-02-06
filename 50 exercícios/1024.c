#include <stdio.h>
#include <string.h>

void processar_criptografia(char *str) {
    int len = strlen(str);
    
    // Primeira passada: desloca letras 3 posições para a direita na tabela ASCII
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            str[i] += 3;
        }
    }
    
    // Segunda passada: inverte a string
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    // Terceira passada: desloca metade da string uma posição para a esquerda
    for (int i = len / 2; i < len; i++) {
        str[i] -= 1;
    }
}

int main() {
    int n;
    char linha[1001];
    
    scanf("%d", &n);
    getchar(); // Consumir o newline após o número de casos
    
    while (n--) {
        fgets(linha, sizeof(linha), stdin);
        
        // Remover newline do final, se presente
        linha[strcspn(linha, "\n")] = '\0';
        
        processar_criptografia(linha);
        
        printf("%s\n", linha);
    }
    
    return 0;
}
