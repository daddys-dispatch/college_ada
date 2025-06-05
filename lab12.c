// N-Queens problem
#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k)
{
    for (int i = 1; i < k; i++)
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
            return 0;
    return 1;
}

int nQueens(int n)
{
    int x[10] = {0}, k = 1, count = 0;
    while (k > 0)
    {
        x[k]++;
        while (x[k] <= n && !place(x, k))
            x[k]++;
        if (x[k] <= n)
        {
            if (k == n)
            {
                printf("\nSolution %d:\n", ++count);
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                        printf("%c ", j == x[i] ? 'Q' : 'X');
                    printf("\n");
                }
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
            k--;
    }
    return count;
}

void main()
{
    int n;

    printf("Size of chess board: "); // 4
    scanf("%d", &n);

    printf("\nNumber of possibilities: %d\n", nQueens(n));
}
