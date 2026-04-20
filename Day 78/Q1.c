/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1005

typedef struct {
    int node, weight;
} Pair;

Pair heap[MAX * MAX];
int heapSize = 0;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(Pair val) {
    heap[++heapSize] = val;
    int i = heapSize;
    while (i > 1 && heap[i].weight < heap[i / 2].weight) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

Pair pop() {
    Pair top = heap[1];
    heap[1] = heap[heapSize--];
    
    int i = 1;
    while (1) {
        int left = 2 * i, right = 2 * i + 1, smallest = i;
        
        if (left <= heapSize && heap[left].weight < heap[smallest].weight)
            smallest = left;
        if (right <= heapSize && heap[right].weight < heap[smallest].weight)
            smallest = right;
        
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->to = v; e1->weight = w; e1->next = adj[u];
    adj[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u; e2->weight = w; e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    bool visited[MAX] = {false};
    int totalWeight = 0;

    // Start from node 1
    push((Pair){1, 0});

    while (heapSize > 0) {
        Pair curr = pop();
        int u = curr.node;

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += curr.weight;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            if (!visited[e->to]) {
                push((Pair){e->to, e->weight});
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}