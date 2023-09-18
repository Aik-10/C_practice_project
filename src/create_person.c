//
// Created by Lentokone on 18.9.2023.
//

#include <stdio.h>
#include "../includes/person.h"
#include "../includes/file_handler.h"

int createNewPerson() {
    struct person newPerson;

    printf("\nFullname: ");
    if (scanf(" %[^\n]", newPerson.fullName) != 1) {
        printf("Invalid input for Fullname.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nAddress: ");
    if (scanf(" %[^\n]", newPerson.address) != 1) {
        printf("Invalid input for Address.\n");
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nBlood type: ");
    if (scanf("%d", &newPerson.bloodType) != 1) {
        printf("Invalid input for Blood type.\n");
        return 1;
    }

    printf("\nAge: ");
    if (scanf("%d", &newPerson.age) != 1) {
        printf("Invalid input for Age.\n");
        return 1;
    }

    printf("You entered: %s\n", newPerson.fullName);
    printf("Your age is: %d\n", newPerson.age);

    saveSinglePersonToTempFile(newPerson);

    return 0;
}
