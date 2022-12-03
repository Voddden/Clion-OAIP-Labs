#include "Validation.h"

/* Двумерный массив заполнить числами.
 * Количество чисел в строке может быть различным, последнее число - 0.
 * В каждой строке удалить все максимальные элементы */

// input of teeth`ed arrays
void input(int** arr, int* N){
    for (int i = 0; ; ++i) {
        char iHateC[] = "arr[x][y] =";
        iHateC[4] = i;
        int j = 0;
        while (true){
            iHateC[6] = j;
            arr[i][j] = inputInteger(iHateC);
            ++j;
            if (arr[i][j] != 0) break;
        }
    }
}

void output(int** arr, int m, int* N){
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

    int m = inputNatural("m =");

    int* N = (int*)calloc(m, sizeof (int));
    for (int i = 0; i < m; ++i) N[i] = 1;

    int** arr = (int**)calloc(m, sizeof(int));
    for (int i = 0; i < m; ++i)
        arr[i] = (int*)calloc(1, sizeof(int));

    // ввод массива с клавиатуры
    input(arr, m, N);

    // вывод первоначального массива
    printf("\nInitial matrix:\n\n");
    output(arr, m, N);

    // преобразование массива: (удаление максимальных элементов в каждой из строк)
    //operate(arr, m, N);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    output(arr, m, N);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}
