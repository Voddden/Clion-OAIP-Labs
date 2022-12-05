#include "Validation.h"
#include "Sort.h"

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
void randArr(int** arr, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = rand() % 10 - rand() % 10;
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

void Free(int** arr, int m) {
    for (int i = 0; i < m; ++i)
        free(arr[i]);
    free(arr);
}



/* В матрице размером NxM выполнить сортировку столбцов по возрастанию суммы четных элементов методом слияния */

int main() {
    //srand(time(NULL));
    printf("Lab 6, task 2\n\n");
    printf("Matrix m x n\n");

    int m = inputNatural("m =");
    int n = inputNatural("n =");

    int** arr = allocation(m, n);

    int choice = inputNatural("---input matrix from keyboard - 1\t\trandom - 2\n");
    while (choice != 1 && choice != 2) {
        choice = inputNatural("---input matrix from keyboard - 1\t\trandom - 2\n");
    }

    switch (choice) {
        case 1:
            inputArr(arr, m, n); break;
        case 2:
            randArr(arr, m, n);
    }

    // вывод первоначального массива
    printf("\nInitial matrix:\n\n");
    outputArr(arr, m, n);

    // преобразование массива: ()
    //operate(arr, m, n);
    Sort(arr, m, n);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    outputArr(arr, m, n);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}
