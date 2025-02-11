#include <stdio.h>

int merge_count_split_inv(int arr[], int temp[], int left, int right) {
    int mid, i, j, k;
    int inv_count = 0;

    if (left < right) {
        mid = (left + right) / 2;

        inv_count += merge_count_split_inv(arr, temp, left, mid);
        inv_count += merge_count_split_inv(arr, temp, mid + 1, right);

        inv_count += merge_and_count(arr, temp, left, mid, right);
    }

    return inv_count;
}

int merge_and_count(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid-i + 1); // All the remaining elements in the left subarray are greater than arr[j]
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int count_inversions(int arr[], int n) {
    int temp[n];
    return merge_count_split_inv(arr, temp, 0, n - 1);
}

int main() {
    int N;
    
    while (1) {
        // Ler o número de elementos no caso de teste
        scanf("%d", &N);
        
        if (N == 0) break;  // Caso de término
        
        int arr[N];
        
        // Ler a sequência de números
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        
        // Contar o número de inversões
        int inversions = count_inversions(arr, N);
        
        // Determinar o vencedor com base no número de inversões
        if (inversions % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }

    return 0;
}
