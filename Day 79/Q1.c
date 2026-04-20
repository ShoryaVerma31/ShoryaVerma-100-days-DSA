/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10005
#define INF INT_MAX

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

struct HeapNode {
    int v, dist;
};

struct HeapNode heap[MAX];
int heapSize = 0;

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void pushUp(int i) {
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i = i / 2;
    }
}

void pushDown(int i) {
    int smallest = i;
    int l = 2*i, r = 2*i+1;

    if (l <= heapSize && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r <= heapSize && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        pushDown(smallest);
    }
}

void push(int v, int dist) {
    heap[++heapSize].v = v;
    heap[heapSize].dist = dist;
    pushUp(heapSize);
}

struct HeapNode pop() {
    struct HeapNode root = heap[1];
    heap[1] = heap[heapSize--];
    pushDown(1);
    return root;
}

void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w); 
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while (heapSize > 0) {
        struct HeapNode top = pop();
        int u = top.v;
        int d = top.dist;

        if (d > dist[u]) continue;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}