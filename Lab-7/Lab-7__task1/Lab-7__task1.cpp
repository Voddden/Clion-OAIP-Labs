#include "Validation.h"

void deleteWord(char* str, int index, int wordLength) {
    for (int i = index; str[i - 1] != '\0'; ++i)
        //str[i - wordLength] = str[i + 1];
        str[i] = str[i + wordLength + 1];
}

void operate(char* str, int k) {
    int g = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ') {
            g = 0;
            for (int k = i; str[k] != ' ' && str[k] != '\0'; ++k) ++g;
            int wordLength = g;
            if (wordLength > k)
                deleteWord(str, i, wordLength);
        }
    }
}

/* Дана строка. Удалить все слова большие k букв (вар. 9) */

int main() {
    int length = 100;
    char* str = (char*) malloc(length);
    printf("str =");
    fgets(str, length + 1, stdin);
    int k = inputNatural("k =");

    puts("---Initial string:");
    puts(str);

    operate(str, k);

    puts("---Final string: ");
    puts(str);
    return 0;
}
