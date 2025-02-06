#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na árvore binária de busca
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Função para realizar o percurso em largura (BFS)
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[500];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d", current->value);

        if (front < rear || current->left || current->right) printf(" "); // Espaço apenas entre números

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("\n");
}

// Função principal
int main() {
    int C;
    scanf("%d", &C);

    for (int caseNum = 1; caseNum <= C; caseNum++) {
        int N;
        scanf("%d", &N);

        Node* root = NULL;
        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        }

        printf("Case %d:\n", caseNum);
        levelOrder(root);

        if (caseNum != C) printf("\n"); // Linha em branco apenas entre os casos
    }

    return 0;
}
