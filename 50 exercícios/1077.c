#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 300  // Tamanho máximo da expressão

// Estrutura da pilha
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para empilhar um elemento
void empilhar(Pilha *p, char c) {
    p->itens[++(p->topo)] = c;
}

// Função para desempilhar um elemento
char desempilhar(Pilha *p) {
    return p->itens[(p->topo)--];
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Função para verificar a precedência dos operadores
int precedencia(char op) {
    switch (op) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

// Função para converter uma expressão infixa para pós-fixa
void infixaParaPosfixa(char *infixa, char *posfixa) {
    Pilha p;
    inicializar(&p);
    int j = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        char simbolo = infixa[i];

        if (isalnum(simbolo)) {
            posfixa[j++] = simbolo;  // Adiciona operandos diretamente na saída
        } else if (simbolo == '(') {
            empilhar(&p, simbolo);
        } else if (simbolo == ')') {
            while (!pilhaVazia(&p) && p.itens[p.topo] != '(') {
                posfixa[j++] = desempilhar(&p);
            }
            desempilhar(&p);  // Remove '(' da pilha
        } else {  // Operadores
            while (!pilhaVazia(&p) && precedencia(p.itens[p.topo]) >= precedencia(simbolo)) {
                posfixa[j++] = desempilhar(&p);
            }
            empilhar(&p, simbolo);
        }
    }

    // Desempilha os operadores restantes
    while (!pilhaVazia(&p)) {
        posfixa[j++] = desempilhar(&p);
    }

    posfixa[j] = '\0';  // Termina a string de saída
}

int main() {
    int n;
    char infixa[MAX], posfixa[MAX];

    // Lê o número de casos de teste
    scanf("%d", &n);
    getchar();  // Limpa o buffer após a leitura de um número

    for (int i = 0; i < n; i++) {
        fgets(infixa, MAX, stdin);
        infixa[strcspn(infixa, "\n")] = '\0';  // Remove o caractere de nova linha

        infixaParaPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}
