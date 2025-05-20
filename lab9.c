#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    srand(time(NULL));
    int sizes[] = {5000, 10000, 15000, 20000, 25000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("lab9.dat", "w");
    if (fp == NULL)
    {
        printf("Failed to create data file.\n");
        return 1;
    }

    printf("n\tTime (ms)\n");

    for (int i = 0; i < num_sizes; i++)
    {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand();
        }

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double time_ms = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d\t%.2f\n", n, time_ms);
        fprintf(fp, "%d\t%.2f\n", n, time_ms);
        free(arr);
    }

    fclose(fp);
    return 0;
}
