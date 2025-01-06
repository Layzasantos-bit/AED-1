#include <stdio.h>

int main() {
    int numero, horas_trabalhadas;
    float valor_por_hora, salario;

    // Leitura dos dados de entrada
    scanf("%d", &numero);               // Número do funcionário
    scanf("%d", &horas_trabalhadas);    // Número de horas trabalhadas
    scanf("%f", &valor_por_hora);       // Valor por hora

    // Cálculo do salário
    salario = horas_trabalhadas * valor_por_hora;

    // Exibição do resultado com a formatação correta
    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}
