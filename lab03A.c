// Floyd's Algorithm
#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd(int p[][10], int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

void main()
{
    int a[10][10], n;
    printf("Number of vertices: "); // 4
    scanf("%d", &n);

    printf("\nCost matrix:\n");
    // 38 66 2 888
    // 23 6 89 999
    // 999 7 45 222
    // 23 999 56 23
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    floyd(a, n);
    printf("\nShortest path:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
