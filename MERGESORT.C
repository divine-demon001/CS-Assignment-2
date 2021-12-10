#include <stdio.h>

void merge(int arr[], int l, int mid, int r)
{
    int i, j, k;
    int m = mid - l + 1; // Number of elements in first sub array
    int n = r - mid; // Number of elements in second half

    // create temporary arrays and copy the actual data to these for comparison
    int A[20], B[20];
    for (i = 0; i < m; i++)
        A[i] = arr[l + i];
    for (j = 0; j < n; j++)
        B[j] = arr[mid + 1 + j];

    // Now, merge these temporary arrays after comparison
    i = 0;
    j = 0;
    k = l;
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        }
        else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }

    // This step is done if any of the list has left out elements
    while (i < m) {
        arr[k] = A[i];
        i++;
        k++;
    }
    while (j < m) {
        arr[k] = B[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r) {
        // This method helps to avoid
        // overflow for large l and r
        int mid = l + (r - l) / 2;

        merge_sort(arr, l, mid); // Call for first half
        merge_sort(arr, mid + 1, r); // Call for second half
        merge(arr, l, mid, r); // Calling merge function
    }
}

int main()
{
    int arr[] = { 3, 8, 12, 9, 5, 26 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    merge_sort(arr, 0, n - 1);

    printf("\nAfter performing the merge sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}