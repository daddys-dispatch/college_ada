// Discrete & Continuous Knapsack
#include <stdio.h>

int n, m, p[10], w[10];

void greedyKnapsack()
{
    int k = 0;
    float profit = 0, maxRatio;

    printf("\nItems included: ");
    for (int i = 0; i < n; i++)
    {
        maxRatio = 0;
        for (int j = 0; j < n; j++)
            if (p[j] != 0 && (float)p[j] / w[j] > maxRatio)
            {
                maxRatio = (float)p[j] / w[j];
                k = j;
            }

        if (w[k] <= m)
        {
            printf("%d ", k);
            m -= w[k];
            profit += p[k];
            p[k] = 0;
        }
        else
            break;
    }

    printf("\nDiscrete knapsack profit: %.2f", profit);
    printf("\nContinuous knapsack profit: %.2f\n", profit += ((float)m / w[k]) * p[k]);
}

void main()
{
    printf("Enter number of items: "); // 3
    scanf("%d", &n);

    printf("Enter weights: "); // 2 1 1
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter prices: "); // 0 1 1
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter knapsack capacity: "); // 5
    scanf("%d", &m);

    greedyKnapsack();
}
