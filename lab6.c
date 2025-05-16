#include <stdio.h>
int n, m, p[10], w[10];

int max(int a, int b)
{
    return (a > b ? a : b);
}

void knapsack_DP()
{
    int v[10][10], i, j;
    for (i = 0; i <= n; i++)

    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else
                v[i][j] = max(v[i - 1][j], p[i] + v[i - 1][j - w[j]]);
        }
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
            printf("%d", v[i][j]);
        printf("\n");
    }

    printf("Items includes are: ");
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
    int i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight of n items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter the price of n items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter the capicity of knapsack: ");
    scanf("%d", &m);

    knapsack_DP();
}