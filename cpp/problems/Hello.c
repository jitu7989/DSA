#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Human {
    char name[50];
    int age;
    float height;
};

void print(struct Human* human) {
    printf("Human Name is %s",human->name);
    printf("Age: %d\n", human->age);
    printf("Height %.2f\n\n",human->height);
}

int main(){
    int* ptr = malloc(sizeof(int));
    if (ptr==NULL) {
        printf("Memory ALlocation Failed!/n");
        return 1;
    }
    struct Human stackPerson;
    strcpy(stackPerson.name,"Jitendra");
    stackPerson.age = 25;
    stackPerson.height = 5.9f;
    print(&stackPerson);

    // HEAP ALLOCATION
    struct Human* heapPerson = malloc(sizeof(struct Human));

    if (heapPerson==NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }
    strcpy(heapPerson->name,"Jane");
    heapPerson->age = 10;
    heapPerson->height = 2134.21f;
    print(heapPerson);

    *ptr = 10;
    printf("value: %d\n",*ptr);
    free(ptr);
    free(heapPerson);
    return 0;
}
