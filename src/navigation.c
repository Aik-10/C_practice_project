#include <stdio.h>
#include "../includes/create_person.h"
#include "../includes/person.h"
#include "../includes/blood_type_handler.h"

static void printPerson(struct person* p) {
    char* bloodType = getBloodTypeLabelByIndex(p->bloodType);

    printf("Full Name: %s", p->fullName);
    printf("\nAddress: %s", p->address);
    printf("\nAge: %d", p->age);
    printf("\nBlood Type: %s", bloodType);
    printf("\n--------------------\n");
}

static void removeSingleSavedPerson(struct person savedPersons[], int* savePersonsCount) {
    printf("Name: asd\n");
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
