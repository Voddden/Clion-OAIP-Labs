#include "Validation.h"

/* Двумерный массив заполнить числами.
 * Количество чисел в строке может быть различным, последнее число - 0.
 * В каждой строке удалить все максимальные элементы */

int** allocation(int m, int n)
{
    int** mas;
    mas = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        mas[i] = (int*)malloc(n * sizeof(int)); //*(mas + i)
    }
    return mas;
}
void inputArr(int** arr, int m, int n) {
    char iHateC[] = "arr[.][.] =";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            iHateC[4] = i + 48;
            iHateC[7] = j + 48;
            arr[i][j] = inputInteger(iHateC);
        }
    }
}
// input of teeth`ed arrays
void inputModified(int** arr, int m, int* N){
    char iHateC[] = "arr[.][.] =";
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < N[i]; ++j){
            iHateC[4] = i + 48;
            iHateC[7] = j + 48;
            arr[i][j] = inputInteger(iHateC);
        }
    }
}
void randArr(int** arr, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = rand() % 100;
        }
    }
}
void outputArr(int** arr, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}
void outputModified(int** arr, int m, int* N){
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < N[i]; ++j) {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}
void Free(int** arr, int m) {
    for (int i = 0; i < m; ++i)
        free(arr[i]);
    free(arr);
}



void deleteElement(int* mas, int& length, int index) {
    for(int i = index; i < length - 1; ++i)
        mas[i] = mas[i + 1];
    mas = (int*)realloc(mas, --length);
}

int indexOfMax(int* mas, int length){
    int s = mas[0];
    for (int i = 1; i < length; ++i){
        if (s < mas[i])
            s = mas[i];
    }
    return s;
}

// преобразование массива:
void operate(int** arr, int m, int* N) {
    for (int i = 0; i < m; ++i)
        deleteElement(arr[i], N[i], indexOfMax(arr[i], N[i]));
}

int main() {
    srand(time(NULL));
    printf("Lab 5, task 2\n\n");
    printf("Matrix m x n\n");

    int m = inputNatural("m =");
    int n = inputNatural("n =");

    int* N = (int*)calloc(m, sizeof (int));
    for (int i = 0; i < m; ++i) N[i] = n;

    int** arr = allocation(m, n);

    int choice = inputNatural("---input matrix from keyboard - 1\t\trandom - 2\tteeth input - 3\n");
    while (choice != 1 && choice != 2 && choice != 3) {
        choice = inputNatural("---input matrix from keyboard - 1\t\trandom - 2\tteeth input - 3\n");
    }

    switch (choice) {
        case 1:
            inputArr(arr, m, n); break;
        case 2:
            randArr(arr, m, n); break;
        case 3:
            inputModified(arr, m, N);
    }

    // вывод первоначального массива
    printf("\nInitial matrix:\n\n");
    outputModified(arr, m, N);

    // преобразование массива: (удаление максимальных элементов в каждой из строк)
    //operate(arr, m, N);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    outputModified(arr, m, N);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}
