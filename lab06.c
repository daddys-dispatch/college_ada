// 0-1 Knapsack
#include <stdio.h>
int n, m, p[10], w[10];

int max(int a, int b)
{
    return (a > b ? a : b);
}

void knapsack()
{
    int v[10][10];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else
                v[i][j] = max(v[i - 1][j], p[i] + v[i - 1][j - w[j]]);
        }

    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            printf("%d", v[i][j]);
        printf("\n");
    }

    printf("\nItems included: ");
    while (n > 0)
    {
        if (v[n][m] != v[n - 1][m])
        {
            printf("%d", n);
            m = m - w[n];
        }
        n--;
    }
    printf("\n");
}

int main()
{
    printf("Number of items: "); // 3
    scanf("%d", &n);

    printf("Knapsack capacity: "); // 5
    scanf("%d", &m);

    printf("\nWeight of items: "); // 0 1 2
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Price of items: "); // 0 0 2
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    knapsack();
}