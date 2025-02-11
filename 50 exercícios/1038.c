#include <stdio.h>

int main() {
    // Preços dos itens com base nos códigos
    float precos[] = {0.00, 4.00, 4.50, 5.00, 2.00, 1.50};
    
    int codigo, quantidade;
    
    // Lê o código do item e a quantidade
    scanf("%d %d", &codigo, &quantidade);
    
    // Calcula o total
    float total = precos[codigo] * quantidade;
    
    // Exibe o resultado com duas casas decimais
    printf("Total: R$ %.2f\n", total);
    
    return 0;
}
