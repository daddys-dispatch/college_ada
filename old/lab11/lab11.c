#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
double timeMergeSort(int arr[], int n);

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

double timeMergeSort(int arr[], int n)
{
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
}

int main()
{
    srand(time(NULL));
    int step = 500;

    FILE *fp = fopen("lab11.dat", "w");
    if (fp == NULL)
    {
        printf("Failed to create data file.\n");
        return 1;
    }

    printf("n\tTime (ms)\n");

    for (int n = 5000; n <= 10000; n += step)
    {
        double totalTime = 0.0;

        for (int i = 0; i < 5; i++)
        {
            int *arr = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++)
            {
                arr[j] = rand() % 1000;
            }

            totalTime += timeMergeSort(arr, n);
            free(arr);
        }

        double averageTime = totalTime / 5.0;
        fprintf(fp, "%d\t%.2f\n", n, averageTime);
        printf("%d\t%.2f\n", n, averageTime);
    }

    fclose(fp);
    return 0;
}
