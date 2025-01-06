#include <stdio.h>
#include <math.h>

int main() {
    // Declaração das variáveis para as coordenadas dos pontos
    double x1, y1, x2, y2;
    
    // Leitura dos valores das coordenadas
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    
    // Cálculo da distância entre os dois pontos
    double distancia = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    
    // Impressão do resultado com 4 casas decimais
    printf("%.4lf\n", distancia);
    
    return 0;
}
