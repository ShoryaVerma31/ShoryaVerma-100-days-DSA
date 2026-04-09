/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v means u -> v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX], count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}