#include <stdio.h>
#include <stdlib.h>

void strcopy(char* str1, char* str2) {
    for (int i = 0; str2[i] != '\0'; ++i) {
        str1[i] = str2[i];
    }
}

struct Human {
    char name[100], surname[100];
    int age;
};

void printHuman(Human human) {
    printf("name = %s\nsurname = %s\nage = %d", human.name, human.surname, human.age);
}

struct Point{
    int x;
    int y;
};

void printPoint(Point point) {
    printf("x = %d\ny = %d\n", point.x, point.y);
}

struct Student{
    char name[20], surname[20], lastname[20];
    unsigned number;
    double rate;
};

struct Group {
    char name[10];
    unsigned number;
    //Student list[30];
    struct Student list[30];
};

int main() {
//    Human human = {18, 95, "Danik"};
//    printHuman(human);
//    puts("\n");
//    Point point = {12, 1};
//    printPoint(point);

//    Human human = {"Danik", "Vodnev", 18};
//    printHuman(human);
//    human.age = 10;
//    //human.name = "123";
//    strcopy(human.name, "Sergey");
//    puts("\n");
//    printHuman(human);
//    puts("\n");


    Human human1;
    strcopy(human1.name, "Yana");
    strcopy(human1.surname, "Stankevich");
    human1.age = 15;
    Human* ptr = &human1;

    printHuman(human1);
    //printf("love = %s", ptr->name);
    return 0;
}