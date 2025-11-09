#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

void createGraph() {
    int e, u, v;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=0;

    printf("Enter edges (from to):\n");
    for(int i=0;i<e;i++) {
        scanf("%d%d",&u,&v);
        graph[u][v]=1;
    }
}

void dfs(int start) {
    printf("%d ", start);
    visited[start]=1;
    for(int i=0;i<n;i++)
        if(graph[start][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int q[MAX], front=0, rear=0;
    for(int i=0;i<n;i++) visited[i]=0;
    q[rear++]=start;
    visited[start]=1;
    while(front<rear) {
        int v=q[front++];
        printf("%d ", v);
        for(int i=0;i<n;i++)
            if(graph[v][i] && !visited[i]) {
                q[rear++]=i;
                visited[i]=1;
            }
    }
}

int main() {
    int start;
    createGraph();
    printf("Enter starting city: ");
    scanf("%d", &start);

    printf("\nCities reachable using DFS: ");
    for(int i=0;i<n;i++) visited[i]=0;
    dfs(start);

    printf("\nCities reachable using BFS: ");
    bfs(start);
    return 0;
}
