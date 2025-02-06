#include <stdio.h>

int main() {
    // Lista com os meses em inglês
    const char* meses[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int n;
    scanf("%d", &n); // Lê o número correspondente ao mês

    // Imprime o nome do mês correspondente ao número
    printf("%s\n", meses[n - 1]);

    return 0;
}
