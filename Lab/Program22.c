
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX], visited[MAX], n;

void create() {
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v), vertices from 0 to %d:\n", n - 1);

    for (i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Graph created successfully!\n");
}

void bfs() {
    int queue[MAX], front = 0, rear = 0;
    int start, i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs_visit(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs_visit(i);
    }
}

void dfs() {
    int start, i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS: ");
    dfs_visit(start);
    printf("\n");
}

int main() {
    int ch;

    do {
        printf("\n1. Create Graph");
        printf("\n2. BFS");
        printf("\n3. DFS");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: bfs(); break;
            case 3: dfs(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 4);

    return 0;
}
