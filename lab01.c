// Kurshal's Algorithm
#include <stdio.h>

void main()
{
    int min_cost = 0, ne = 1;
    int n, cost[20][20], parent[20];

    printf("Number of vertices: "); // 6
    scanf("%d", &n);

    printf("\nCost matrix:\n");
    // 23 34 56 78 34 12
    // 11 33 78 899 89 34
    // 222 44 66 87 98 444
    // 11 33 44 76 54 22
    // 14 56 78 89 90 54
    // 12 45 67 89 65 46
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nEdges of spanning tree:\n");
    while (ne < n)
    {
        int a, b, u, v, min = 999;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        while (parent[u])
            u = parent[u];

        while (parent[v])
            v = parent[v];

        if (u != v)
        {
            printf("Edge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}
