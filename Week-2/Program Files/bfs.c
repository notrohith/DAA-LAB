//CH.SC.U4CSE24140 - Rohith S
#include <stdio.h>
int main() {
    int n, i, j, start;
    int queue[50], front = 0, rear = 0;
    int visited[50] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter adjacency matrix:\n");3
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}
