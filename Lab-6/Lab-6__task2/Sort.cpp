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
}


void merge(int* arr, int p, int q, int r) {
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}