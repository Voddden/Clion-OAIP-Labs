#include "Sort.h"

void Sort(int** arr, int m, int n) {
    int* sumEven = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j) {
            if ((i + 1) % 2 == 0) {
                sumEven[j] += arr[i][j];
            }
        }
    }

    int* sortedSumEven = (int*) calloc(n, sizeof (int));
    for (int i = 0; i < n;++i)
        sortedSumEven[i] = sumEven[i];

    mergeSort(sortedSumEven, 0, n - 1);

    int* newIndexes = (int*)calloc(n, sizeof(int));

    int g = 0;
    for (int k = 0; k < n; ++k) {
        int temp = sumEven[k];
        for (int i = 0; i < n; ++i) {
            if (temp == sortedSumEven[i]) {
                newIndexes[g] = i;
                ++g;
            }
        }
    }

    for (int i = 0; i < n; ++i) {

    }
}

// Merge two arrays L and M into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two arrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        // m is the point where the array is divided into two arrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted arrays
        merge(arr, l, m, r);
    }
}

// преобразование массива:
