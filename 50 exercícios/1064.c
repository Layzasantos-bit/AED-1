#include <stdio.h>

int main() {
    int count = 0;          // Contador de valores positivos
    double sum = 0.0;       // Soma dos valores positivos
    double value;           // Variável para ler os valores

    // Ler 6 valores
    for (int i = 0; i < 6; i++) {
        scanf("%lf", &value);  // Lê um número, que pode ser inteiro ou de ponto flutuante
        
        if (value > 0) {       // Verifica se o número é positivo
            count++;           // Incrementa o contador
            sum += value;      // Adiciona o valor à soma
        }
    }

    // Exibe o número de valores positivos
    printf("%d valores positivos\n", count);

    // Exibe a média dos valores positivos, com 1 casa decimal
    if (count > 0) {
        printf("%.1lf\n", sum / count);  // Calcula e imprime a média
    }

    return 0;
}
