// Quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// void fnGenRandInput(int[], int);
// int fnPartition(int[], int, int);
// void fnQuickSort(int[], int, int);
// void fnSwap(int *, int *);
// double timeQuickSort(int[], int);

void fnSwap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int fnPartition(int a[], int l, int r)
{
    int i, j, p = a[l];

    i = l;
    j = r + 1;

    do
    {
        do
        {
            i++;
        } while (a[i] < p);
        do
        {
            j--;
        } while (a[j] > p);
        fnSwap(&a[i], &a[j]);
    } while (i < j);

    fnSwap(&a[i], &a[j]);
    fnSwap(&a[l], &a[j]);
    return j;
}

void fnQuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int s = fnPartition(a, l, r);
        fnQuickSort(a, l, s - 1);
        fnQuickSort(a, s + 1, r);
    }
}

void fnGenRandInput(int X[], int n)
{
    for (int i = 0; i < n; i++)
    {
        X[i] = rand() % 10000;
    }
}

double timeQuickSort(int arr[], int n)
{
    struct timeval tv;
    double start, end;

    gettimeofday(&tv, NULL);
    start = tv.tv_sec + (tv.tv_usec / 1000000.0);
    fnQuickSort(arr, 0, n - 1);
    gettimeofday(&tv, NULL);
    end = tv.tv_sec + (tv.tv_usec / 1000000.0);
    return (end - start) * 1000.0;
}

void main()
{
    srand(time(NULL));
    int step = 500;
    int *arr;
    FILE *fp = fopen("lab10.dat", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        EXIT_FAILURE;
    }

    printf("n\tTime (ms)\n");
    for (int n = 5000; n <= 10000; n += step)
    {
        double totalTime = 0.0;
        for (int i = 0; i < 5; i++)
        {
            arr = (int *)malloc(n * sizeof(int));
            fnGenRandInput(arr, n);
            totalTime += timeQuickSort(arr, n);
            free(arr);
        }
        double avgTime = totalTime / 5.0;
        fprintf(fp, "%d\t%.2f\n", n, avgTime);
        printf("%d\t%.2f\n", n, avgTime);
    }

    fclose(fp);
}
