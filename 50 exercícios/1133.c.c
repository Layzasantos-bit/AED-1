#include <stdio.h>

int main() {
    int X, Y;
    
    // Leitura dos valores X e Y
    scanf("%d %d", &X, &Y);
    
    // Determina o menor e o maior valor entre X e Y
    int start = (X < Y) ? X : Y;
    int end = (X > Y) ? X : Y;
    
    // Verificando e imprimindo os valores no intervalo
    for (int i = start + 1; i < end; i++) {
        if (i % 5 == 2 || i % 5 == 3) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
