#include <stdio.h>
#include "../includes/create_person.h"
#include "../includes/person.h"
#include "../includes/blood_type_handler.h"
#include "../includes/file_handler.h"

static void printPerson(struct person* p) {
    char* bloodType = getBloodTypeLabelByIndex(p->bloodType);

    printf("Full Name: %s", p->fullName);
    printf("\nAddress: %s", p->address);
    printf("\nAge: %d", p->age);
    printf("\nBlood Type: %s", bloodType);
    printf("\n--------------------\n");
}

int removePersonByIndex(struct person* persons, int* numberOfPersons, int index) {
    if (index < 0 || index >= *numberOfPersons) {
        printf("Invalid index for removal.\n");
        return -1;
    }

    for (int i = index; i < *numberOfPersons - 1; i++) {
        persons[i] = persons[i + 1];
    }

    (*numberOfPersons)--;

    return 0;
}

static void removeSingleSavedPerson(struct person savedPersons[], int* savePersonsCount) {
    printf("\nAll person displayed!\n\n");
    for (int i = 0; i < *savePersonsCount; i++) {
        char* bloodType = getBloodTypeLabelByIndex(savedPersons[i].bloodType);
        printf("Index: %d | Name: %s / Address: %s / Age %d / Blood type: %s\n", i, savedPersons[i].fullName, savedPersons[i].address, savedPersons[i].age, bloodType);
    }

    int validInput = 0;
    int selection;

    while (!validInput) {
        printf("Select person to remove list\n");
        printf("Selection:");

        if (scanf("%d", &selection) == 1) {
            if (!savedPersons[ selection ].fullName) continue;
            validInput = 1;
        } else {
            printf("\nInvalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }

    if ( removePersonByIndex(savedPersons, savePersonsCount, selection) == -1 ) {
        perror("Invalid index for removal");
        return;
    }
    savePersonsToTempFile(savedPersons, savePersonsCount);

}

static void showSavedPersonList(struct person savedPersons[], int* savePersonsCount) {
    printf("\nAll person displayed!\n\n");

    for (int i = 0; i < *savePersonsCount; i++) {
        printPerson(&savedPersons[i]);
    }
}

static void NavigationMenuAction(int *selection, struct person savedPersons[], int* savePersonsCount) {
    switch (*selection) {
        case 1:
            if ( *savePersonsCount <= 0 ) {
                printf("Cannot print empty list");
                return;
            }
            showSavedPersonList(savedPersons, savePersonsCount);
            break;
        case 2:
            createNewPerson(savedPersons, savePersonsCount);
            break;
        case 3:
            removeSingleSavedPerson(savedPersons, savePersonsCount);
            break;
    }
}

static int validateNavigationMenuSelection(int selection) {
    switch (selection) {
        case 1:
        case 2:
        case 3:
            return 1;
        case 4:
            printf("Exiting the program.\n");
            return 0;
    }
    return -1;
}

int generalNavigationMenu(struct person savedPersons[], int* savePersonsCount) {
    int selection;
    int validInput = 0;

    while (!validInput) {
        printf("Menu: Write your action below\n");
        printf("1. Print users (%d)\n", *savePersonsCount);
        printf("2. Create new user\n");
        printf("3. Remove selected user\n");
        printf("4. Exit\n");
        printf("Selection:");

        if (scanf("%d", &selection) == 1) {
            int isValid = validateNavigationMenuSelection(selection);

            if (isValid >= 1) {
                if ( selection == 4 ) {
                    return 1;
                }

                validInput = 1;
                NavigationMenuAction(&selection, savedPersons, savePersonsCount);
            } else if (isValid == 0) {
                return 1;
            }
        } else {
            printf("\nInvalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }

    return 0;
}

#pragma clang diagnostic pop