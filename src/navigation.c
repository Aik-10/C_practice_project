#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showSavedPersonList() {
    printf("Name: asd\n");
}

void NavigationMenuAction(int *selection) {
    switch (*selection) {
        case 1:
            showSavedPersonList();
            break;
        case 2:
            createNewPerson();
            break;
        case 3:
            printf("Name: REMOVE SELECTED\n");
            break;
    }
}

int validateNavigationMenuSelection(int *selection) {
    switch (*selection) {
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


int generalNavigationMenu() {
    int selection;
    int validInput = 0;

    while (!validInput) {
        printf("Menu: Write your action below\n");
        printf("1. Print users\n");
        printf("2. Create new user\n");
        printf("3. Remove selected user\n");
        printf("4. Exit\n");
        printf("Selection: ");

        if (scanf("%d", &selection) == 1) {
            int isValid = validateNavigationMenuSelection(&selection);

            if (isValid >= 1) {
                validInput = 1;
                NavigationMenuAction(&selection);
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
