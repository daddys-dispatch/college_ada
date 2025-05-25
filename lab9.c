// Selection Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void main()
{
    srand(time(NULL));
    int sizes[] = {5000, 10000, 15000, 20000, 25000};
    FILE *fp = fopen("lab9.dat", "w");
    if (!fp)
    {
        printf("Failed to create data file.\n");
        EXIT_FAILURE;
    }

    printf("Array Size\tTime Taken (ms)\n");
    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++)
    {
        int n = sizes[i], *arr = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            arr[j] = rand();

        clock_t start = clock();
        selectionSort(arr, n);
        double time = ((double)(clock() - start)) * 1000.0 / CLOCKS_PER_SEC;

        printf("%d\t\t%.2f\n", n, time);
        fprintf(fp, "%d\t%.2f\n", n, time);
        free(arr);
    }
    fclose(fp);
}
