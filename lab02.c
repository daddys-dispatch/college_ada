// Prim's Algorithm
#include <stdio.h>

void main()
{
    int min_cost = 0, ne = 1;
    int n, source, cost[20][20], visited[20];

    printf("Number of nodes: "); // 4
    scanf("%d", &n);

    printf("\nCost matrix:\n");
    // 23 567 1 4
    // 34 3 67 999
    // 2 4 65 34
    // 34 67 98 12
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nRoot node: "); // 1
    scanf("%d", &source);
    visited[source] = 1;

    printf("\nMinimum cost Spanning tree is\n");
    while (ne < n)
    {
        int a, b, u, v, min = 999;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][j] < min)
                {
                    if (visited[i] == 0)
                        continue;
                    else
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }

        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("Edge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}
