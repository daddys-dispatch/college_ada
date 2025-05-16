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
    int n, i;
    clock_t start, end;
    double cpu_time_used;
    int sizes[] = {5000, 10000, 15000, 20000, 25000};

    for (i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++)
    {
        n = sizes[i];
        int arr[n];
        srand(time(NULL));

        for (int j = 0; j < n; j++)
        {
            arr[j] = rand();
        }

        start = clock();
        selectionSort(arr, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort array of size %d: %f seconds\n", n, cpu_time_used);
    }
    return 0;
}
