//CH.SC.U4CSE24140 - Rohith S
#include <stdio.h>
int n;
int graph[50][50];
int visited[50];
void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}
int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("DFS traversal: ");
    dfs(start);
    return 0;
}
