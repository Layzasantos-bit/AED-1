#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 2000
#define INF INT_MAX

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int vertex, cost;
} HeapNode;

typedef struct {
    HeapNode nodes[MAXN * MAXN];
    int size;
} MinHeap;

Edge* graph[MAXN];
int degree[MAXN];
bool hasBone[MAXN];
int dist[MAXN];

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->nodes[parent].cost <= heap->nodes[index].cost) break;
        swap(&heap->nodes[parent], &heap->nodes[index]);
        index = parent;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    while (2 * index + 1 < heap->size) {
        int left = 2 * index + 1, right = 2 * index + 2, smallest = left;
        if (right < heap->size && heap->nodes[right].cost < heap->nodes[left].cost) {
            smallest = right;
        }
        if (heap->nodes[index].cost <= heap->nodes[smallest].cost) break;
        swap(&heap->nodes[index], &heap->nodes[smallest]);
        index = smallest;
    }
}

void push(MinHeap* heap, int vertex, int cost) {
    heap->nodes[heap->size].vertex = vertex;
    heap->nodes[heap->size].cost = cost;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

HeapNode pop(MinHeap* heap) {
    HeapNode min = heap->nodes[0];
    heap->size--;
    heap->nodes[0] = heap->nodes[heap->size];
    heapifyDown(heap, 0);
    return min;
}

void dijkstra(int start, int n) {
    MinHeap heap = { .size = 0 };
    bool visited[MAXN] = {false};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[start] = 0;
    push(&heap, start, 0);

    while (heap.size > 0) {
        HeapNode node = pop(&heap);
        int u = node.vertex;
        if (visited[u]) continue;
        visited[u] = true;

        for (int j = 0; j < degree[u]; j++) {
            Edge e = graph[u][j];
            if (!visited[e.v] && dist[u] + e.w < dist[e.v]) {
                dist[e.v] = dist[u] + e.w;
                push(&heap, e.v, dist[e.v]);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++) {
            degree[i] = 0;
            hasBone[i] = false;
            graph[i] = malloc(M * sizeof(Edge));
        }

        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            graph[u][degree[u]] = (Edge){v, w};
            degree[u]++;
            graph[v][degree[v]] = (Edge){u, w};
            degree[v]++;
        }

        int K;
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            int b;
            scanf("%d", &b);
            hasBone[b - 1] = true;
        }

        dijkstra(0, N);

        printf(dist[N - 1] != INF ? "Yes\n" : "No\n");

        for (int i = 0; i < N; i++) free(graph[i]);
    }

    return 0;
}
