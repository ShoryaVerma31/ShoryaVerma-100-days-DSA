/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

bool dfs(struct Graph* graph, int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    struct Node* temp = graph->adj[node];
    while (temp) {
        int neighbor = temp->dest;

        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; 
        }

        temp = temp->next;
    }

    recStack[node] = false; 
    return false;
}

bool hasCycle(struct Graph* graph) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}