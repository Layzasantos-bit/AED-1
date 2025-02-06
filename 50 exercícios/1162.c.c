#include <stdio.h>

// Função auxiliar para realizar a contagem de inversões durante o merge sort
int merge_and_count(int arr[], int temp[], int left, int right) {
    int mid, i, j, k, inv_count = 0;

    if (left < right) {
        mid = (left + right) / 2;

        // Conta as inversões nas duas metades e na fusão
        inv_count += merge_and_count(arr, temp, left, mid);
        inv_count += merge_and_count(arr, temp, mid + 1, right);

        // Conta inversões durante a fusão
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

// Função para fazer a fusão dos dois sub-arrays e contar as inversões
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, inv_count = 0;

    // Realiza a fusão enquanto conta as inversões
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // Todos os elementos restantes em arr[i...mid] são maiores que arr[j]
        }
    }

    // Copia os elementos restantes de arr[i...mid]
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copia os elementos restantes de arr[j...right]
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copia de volta o array temporário para o original
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Função principal para contar as inversões
int count_inversions(int arr[], int n) {
    int temp[n];
    return merge_and_count(arr, temp, 0, n - 1);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int L;
        scanf("%d", &L);

        if (L == 0) continue;  // Caso de tamanho zero, não há necessidade de processar

        int arr[L];
        for (int j = 0; j < L; j++) {
            scanf("%d", &arr[j]);
        }

        // Contar o número de inversões (trocas necessárias)
        int swaps = count_inversions(arr, L);

        // Imprimir a resposta conforme o formato solicitado
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }

    return 0;
}
