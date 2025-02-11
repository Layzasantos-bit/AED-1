#include <stdio.h>

int main() {
    int hora, minuto;
    
    while (scanf("%d:%d", &hora, &minuto) != EOF) {
        // Calcula o horário em minutos desde o início do dia
        int minutos_totais = hora * 60 + minuto;
        // 8:00 em minutos desde o início do dia
        int minutos_chegada = 8 * 60;
        // Calcula o atraso
        int atraso = minutos_totais + 60 - minutos_chegada;

        if (atraso < 0) atraso = 0;

        printf("Atraso maximo: %d\n", atraso);
    }

    return 0;
}
