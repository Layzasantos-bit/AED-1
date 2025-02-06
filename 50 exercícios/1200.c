#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore
typedef struct Node {
    char valor;
    struct Node *esq, *dir;
} Node;

// Função para criar um novo nó
Node* novoNo(char valor) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

// Função para inserir um nó na árvore
Node* inserir(Node* raiz, char valor) {
    if (raiz == NULL) return novoNo(valor);
    if (valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor) raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Variável global para controle de formatação
int primeiro;

// Função auxiliar para percursos (evita espaço extra no final)
void inOrder(Node* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esq);
        printf(primeiro ? "%c" : " %c", raiz->valor);
        primeiro = 0;
        inOrder(raiz->dir);
    }
}

void preOrder(Node* raiz) {
    if (raiz != NULL) {
        printf(primeiro ? "%c" : " %c", raiz->valor);
        primeiro = 0;
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

void postOrder(Node* raiz) {
    if (raiz != NULL) {
        postOrder(raiz->esq);
        postOrder(raiz->dir);
        printf(primeiro ? "%c" : " %c", raiz->valor);
        primeiro = 0;
    }
}

// Função para buscar um elemento na árvore
int buscar(Node* raiz, char valor) {
    if (raiz == NULL) return 0;
    if (raiz->valor == valor) return 1;
    if (valor < raiz->valor) return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

// Função para liberar memória da árvore
void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    Node* raiz = NULL;
    char comando[10], valor;

    while (scanf("%s%*c", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        } else if (strcmp(comando, "INFIXA") == 0) {
            primeiro = 1;
            inOrder(raiz);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            primeiro = 1;
            preOrder(raiz);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            primeiro = 1;
            postOrder(raiz);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (buscar(raiz, valor)) printf("%c existe\n", valor);
            else printf("%c nao existe\n", valor);
        }
    }

    liberarArvore(raiz);
    return 0;
}
