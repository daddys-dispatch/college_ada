#include <stdio.h>
int cost[10][10], n, colsum[10];
void ab()
{
    for (int j = 0; j < n; j++)
    {
        colsum[j] = 0;
        for (int i = 0; i < n; i++)
            colsum[j] += cost[i][j];
    }
}
void bd()
{
    int i, j, k, select[10] = {0};
    printf("Topological ordering is: \n");
    for (int i = 0; i < n; i++)
    {
        ab();
        for (j = 0; j < n; j++)
        {
            if (select[j] == 0 && colsum[j] == 0)
                break;
        }
        if (j < n)
        {
            printf("%d ", j);
            select[j] = 1;
            for (k = 0; k < n; k++)
                cost[j][k] = 0;
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the number of vertices (1-10): ");
    scanf("%d", &n);
    if (n < 1 || n > 10)
    {
        printf("Invalid number of vertices. Please enter a number between 1 and 10.\n");
        return 1;
    }
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    bd();
    return 0;
}