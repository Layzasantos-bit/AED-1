#include <stdio.h>

int main() {
    int A, B, C, D;

    // Lê os quatro valores
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Verifica as quatro combinações possíveis de três varetas
    if ((A + B > C && A + C > B && B + C > A) || 
        (A + B > D && A + D > B && B + D > A) ||
        (A + C > D && A + D > C && C + D > A) ||
        (B + C > D && B + D > C && C + D > B)) {
        printf("S\n");  // Se possível formar triângulo
    } else {
        printf("N\n");  // Se não for possível
    }

    return 0;
}
