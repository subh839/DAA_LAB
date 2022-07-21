#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

// Djikstra's Algorithm
void djikstra(int graph[MAX][MAX], int n, int start)
{
    int dist[MAX] = {0},
        visited[MAX] = {0},
        path[MAX] = {0},
        u, v, w, i, j, k, min;
    for (i = 0; i < n; i++)
    {
        dist[i] = graph[start][i];
        path[i] = start;
    }
    visited[start] = 1;
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[u][j] < INF)
            {
                w = graph[u][j];
                if (dist[u] + w < dist[j])
                {
                    dist[j] = dist[u] + w;
                    path[j] = u;
                }
            }
        }
    }
    printf("\n Shortest Path from %d: ", start);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d <- ", path[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int graph[MAX][MAX], i, j, n, start;
    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    printf("\n Enter the starting node: ");
    scanf("%d", &start);
    djikstra(graph, n, start);
    return 0;
}
