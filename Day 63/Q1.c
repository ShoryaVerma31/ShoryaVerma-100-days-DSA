/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node** adjList, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void dfs(int v, struct Node** adjList, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adjList[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adjList, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int* visited = (int*)calloc(n, sizeof(int));

    printf("DFS Traversal: ");
    dfs(s, adjList, visited);

    return 0;
}