// Sum of Subsets
#include <stdio.h>

int count, d, s[10], x[10];

void sumOfSubset(int p, int k, int r)
{
    x[k] = 1;
    if (p + s[k] == d)
    {
        printf("\nSubset = %d\t", ++count);
        for (int i = 0; i <= k; i++)
            if (x[i])
                printf("%d ", s[i]);
    }
    else if (p + s[k] + s[k + 1] <= d)
        sumOfSubset(p + s[k], k + 1, r - s[k]);

    if (p + r - s[k] >= d && p + s[k + 1] <= d)
    {
        x[k] = 0;
        sumOfSubset(p, k + 1, r - s[k]);
    }
}

void main()
{
    int n, sum = 0;
    printf("Number of elements: "); // 5
    scanf("%d", &n);

    printf("Elements in increasing order: "); // 1 2 3 4 5
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        sum += s[i];
    }

    printf("Required Sum: "); // 8
    scanf("%d", &d);

    if (sum < d || s[0] > d)
        printf("\nNo Subset possible\n");
    else
        sumOfSubset(0, 0, sum);
    printf("\n");
}
