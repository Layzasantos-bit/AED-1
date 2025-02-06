#include <stdio.h>

// Função para calcular o MDC (Máximo Divisor Comum)
int MDC(int a, int b) {
    if (b == 0) return a;
    return MDC(b, a % b);
}

// Função para simplificar a fração
void simplificar(int *num, int *den) {
    int mdc = MDC(*num, *den);
    *num /= mdc;
    *den /= mdc;

    // Garantir que o sinal negativo fique no numerador
    if (*den < 0) {
        *num *= -1;
        *den *= -1;
    }
}

// Função para calcular a operação entre frações
void calcular(int n1, int d1, int n2, int d2, char op, int *resNum, int *resDen) {
    if (op == '+') {
        *resNum = n1 * d2 + n2 * d1;
        *resDen = d1 * d2;
    } else if (op == '-') {
        *resNum = n1 * d2 - n2 * d1;
        *resDen = d1 * d2;
    } else if (op == '*') {
        *resNum = n1 * n2;
        *resDen = d1 * d2;
    } else if (op == '/') {
        *resNum = n1 * d2;
        *resDen = n2 * d1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int n1, d1, n2, d2;
        char op;
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

        int resNum, resDen;
        calcular(n1, d1, n2, d2, op, &resNum, &resDen);

        int simpNum = resNum, simpDen = resDen;
        simplificar(&simpNum, &simpDen);

        printf("%d/%d = %d/%d\n", resNum, resDen, simpNum, simpDen);
    }

    return 0;
}
