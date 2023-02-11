#include <stdlib.h>
#include <stdio.h>

struct Human {
    char name[30];
    char surname[30];
    char lastname[30];
    char adress[30];
    unsigned phoneNumber;
    unsigned age;
};

void strcopy(char* str1, char* str2) {
    int i;
    for (i = 0; str2[i] != '\0'; ++i) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}

void printHuman(Human human) {
    printf("name = %s\nsurname = %s\nlastname = %s\nadress = %s\nphone number = %d\nage = %d\n", human.name, human.surname, human.lastname, human.adress, human.phoneNumber, human.age);
}

void printArray(struct Human arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("name = %s\nsurname = %s\nlastname = %s\nadress = %s\nphone number = %d\nage = %d\n", arr[i].name, arr[i].surname, arr[i].lastname, arr[i].adress, arr[i].phoneNumber, arr[i].age);
    puts("\n");
    }
}

int main() {
    struct Human arr[] = {
            {"Danik", "Vodnev", "Ivanovich", "Surganova 68", 16663010, 18},
            {"Lera", "Kuzhahanova", "Erkenevna", "Minsk", 12312323, 29},
            {"Kristina", "Burmatova", "Batskovna", "Minsk", 123123123, 29}
    };
//    strcopy(arr[0].name, "Vlad");
//    strcopy(arr[0].surname, "Mezen");
//    strcopy(arr[0].lastname, "Batskavich");
//    strcopy(arr[0].adress, "Shirokaya 38, korpus 4");
//    arr[0].phoneNumber = 1663010;
//    arr[0].age = 18;
    //printHuman(arr[0]);
    printArray(arr, 3);
    return 0;
}
