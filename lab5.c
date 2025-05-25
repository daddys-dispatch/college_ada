// Topological Ordering
#include <stdio.h>

int n, colsum[10], cost[10][10], select[10] = {0};

void computeColSum()
{
    for (int j = 0; j < n; j++)
    {
        colsum[j] = 0;
        for (int i = 0; i < n; i++)
            colsum[j] += cost[i][j];
    }
}

void topoSort()
{
    printf("\nTopological Ordering: ");
    for (int i = 0; i < n; i++)
    {
        computeColSum();
        for (int j = 0; j < n; j++)
        {
            if (!select[j] && colsum[j] == 0)
            {
                printf("%d ", j);
                select[j] = 1;
                for (int k = 0; k < n; k++)
                    cost[j][k] = 0;
                break;
            }
        }
    }
    printf("\n");
}

void main()
{
    printf("Enter the number of vertices: "); // 5
    scanf("%d", &n);

    if (n < 1 || n > 10)
        printf("Invalid number of vertices. Please enter a number between 1 and 10.\n");

    printf("\nEnter the cost matrix:\n");
    // 0 1 1 0 0
    // 0 0 0 1 1
    // 0 0 0 1 0
    // 0 0 0 0 1
    // 0 0 0 0 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    topoSort();
}
