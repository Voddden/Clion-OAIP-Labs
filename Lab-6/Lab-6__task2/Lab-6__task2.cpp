#include "Validation.h"

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
//////
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapRows(int* a, int* b, int n) {
    int* temp = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        temp[i] = a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
    free(temp);
}

int** transpose(int** arr, int x, int y) {
    int** arr_T = allocation(y, x);
    for (int i = 0; i < x; i++) // транспонирование матрицы
        for (int j = 0; j < y; j++)
            arr_T[j][i] = arr[i][j];
    return arr_T;
}

void arrangeArr(int** arrInit, int m, int n) {
    int** arrT = transpose(arrInit, m, n);

    int* sumEven = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            if ((i + 1) % 2 == 0) {
                sumEven[j] += arrInit[i][j];
            }
        }
    }
    // причудливая модифицированная пузырьковая сортировка по убыванию
    for (int i = 0; i < m - 1; ++i) {
        for (int k = 0; k < m - 1 - i; ++k) {
            if (sumEven[k] < sumEven[k + 1]) {
                swap(sumEven[k], sumEven[k + 1]);
                swapRows(arrT[k], arrT[k + 1], n);
            }
        }
    }

    arrInit = transpose(arrT, m, n);
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

    // преобразование массива: (сортировка столбцов по возрастанию суммы четных элементов методом слияния)
    arrangeArr(arr, m, n);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    outputArr(arr, m, n);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}
