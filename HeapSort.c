#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(void)
{
    int n;
    printf("Enter the size of array: ");
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
    heapSort(arr, n);
    end = clock();
    double time_taken = (((double)(end - st)) / CLOCKS_PER_SEC);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %lf micro seconds\n", time_taken * 1000000);
}