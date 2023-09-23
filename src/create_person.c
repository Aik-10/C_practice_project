#include <stdio.h>
#include "../includes/file_handler.h"

int createNewPerson() {
    struct person newPerson;
    int c;

    printf("\nFullname: ");
    if (scanf(" %[^\n]", newPerson.fullName) != 1) {
        printf("Invalid input for Fullname.\n");
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    printf("Address: ");
    if (scanf(" %[^\n]", newPerson.address) != 1) {
        printf("Invalid input for Address.\n");
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    printf("Blood type:");
    if (scanf("%d", &newPerson.bloodType) != 1) {
        printf("Invalid input for Blood type.\n");
        return 1;
    }

    printf("Age:");
    if (scanf("%d", &newPerson.age) != 1) {
        printf("Invalid input for Age.\n");
        return 1;
    }

    saveSinglePersonToTempFile(newPerson);

    return 0;
}
