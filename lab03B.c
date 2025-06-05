// Warshal's Algorithm
#include <stdio.h>

void warshal(int p[][10], int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = p[i][j] || p[i][k] && p[k][j];
}

void main()
{
    int a[10][10], n;
    printf("Number of vertices: "); // 4
    scanf("%d", &n);

    printf("\nAdjacency matrix:\n");
    // 0 1 0 0
    // 0 0 0 1
    // 0 0 0 0
    // 1 0 0 0
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    warshal(a, n);
    printf("\nResultant path matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}