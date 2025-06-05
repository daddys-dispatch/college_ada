// Dijkstra's Algorithm
#include <stdio.h>
#include <stdlib.h>

int n, source, cost[10][10], dist[10], visited[10] = {0};

void dijkstra(int source)
{
    for (int i = 0; i < n; i++)
        dist[i] = cost[source][i];

    dist[source] = 0;
    visited[source] = 1;

    for (int i = 1; i < n; i++)
    {
        int min = 999, u = -1;

        for (int j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }

        if (u == -1)
            break;
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && cost[u][v] != 999)
                if (dist[v] > dist[u] + cost[u][v])
                    dist[v] = dist[u] + cost[u][v];
    }
}

void main()
{
    printf("Number of vertices: "); // 4
    scanf("%d", &n);

    printf("\nCost matrix:\n");
    // 2 4 6 8
    // 7 9 7 23
    // 54 6 8 3
    // 21 4 6 9
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("\nSource vertex: ", n - 1); // 2
    scanf("%d", &source);

    if (source < 0 || source >= n)
    {
        printf("Invalid source vertex\n");
        EXIT_FAILURE;
    }

    dijkstra(source);

    printf("\nShortest distance:", source);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == 999)
            printf("No path from %d to %d\n", source, i);
        else
            printf("Cost from %d to %d is %d\n", source, i, dist[i]);
    }
}
