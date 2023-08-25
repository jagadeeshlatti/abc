#include <stdio.h>
#include <time.h>

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
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
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(void)
{
    int n;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    int arr[n];

    // printf("Enter the elements: ");
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &arr[i]);
    
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    clock_t st, end;
    st = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    double time_taken = (((double)(end - st)) / CLOCKS_PER_SEC);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %lf micro seconds\n", time_taken * 1000000);
}