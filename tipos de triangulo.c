#include <stdio.h>

int main() {
    double A, B, C;
    
    // Leitura dos valores A, B e C
    scanf("%lf %lf %lf", &A, &B, &C);
    
    // Ordenando os valores de A, B, C para garantir que A seja o maior
    if (A < B) {
        double temp = A;
        A = B;
        B = temp;
    }
    if (A < C) {
        double temp = A;
        A = C;
        C = temp;
    }
    if (B < C) {
        double temp = B;
        B = C;
        C = temp;
    }
    
    // Verificando se pode formar um triângulo
    if (A >= B + C) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        // Verificando o tipo de triângulo
        if (A * A == B * B + C * C) {
            printf("TRIANGULO RETANGULO\n");
        } else if (A * A > B * B + C * C) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else {
            printf("TRIANGULO ACUTANGULO\n");
        }

        // Verificando se é equilátero ou isósceles
        if (A == B && B == C) {
            printf("TRIANGULO EQUILATERO\n");
        } else if (A == B || B == C || A == C) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    
    return 0;
}
