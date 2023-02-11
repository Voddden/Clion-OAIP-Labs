#include <stdio.h>
#include <stdlib.h>

/* Вариант 7
1. С клавиатуры заполнить файл целыми числами.
*/

int main() {

    char* message = (char*)malloc(100);
    puts("Enter integer:");
    gets(message);
    int length = sizeof (message);

    FILE* filePointer = fopen("D://data.txt", "w");
    if (filePointer == NULL) {
        perror("Error! No file found");
        return 1;
    }

    int temp;
    for (int i = 0; i < length; ++i) {
        putc(message[i], filePointer);
    }
    fclose(filePointer);
    printf("File has been written");
    return 0;
}