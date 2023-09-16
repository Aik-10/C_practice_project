#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

const int MAX_PERSON_AMOUNT = 10;

char* getBloodTypeLabel(int blood_index) {
    if (blood_index < 0 || blood_index >= sizeof(BOOL_TYPE_NAMES) / sizeof(BOOL_TYPE_NAMES[0])) {
        fprintf(stderr, "Invalid blood index: %d\n", blood_index);
    }

    char* str = (char*)malloc(strlen(BOOL_TYPE_NAMES[blood_index]));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(str, BOOL_TYPE_NAMES[blood_index]);
    return str;
}

int loadTempFilePersons(struct person persons[]) {
    const char* temp_dir = getenv("TEMP");

    if (temp_dir == NULL) {
        fprintf(stderr, "Failed to get the temporary directory path.\n");
        return -1;
    }

    char temp_file[256];
    snprintf(temp_file, sizeof(temp_file), "%s\\saved_person.txt", temp_dir);

    FILE *file = fopen(temp_file, "r");
    if (file == NULL) {
        perror("ERROR: File opening");
        return -1;
    }

    int personAmount = 0;
    while (personAmount < MAX_PERSON_AMOUNT && fscanf(file, "%255[^|]|%255[^|]|%d|%d[\\n]", persons[personAmount].fullName, persons[personAmount].address, &persons[personAmount].age, &persons[personAmount].bloodType ) == 4) {
        personAmount++;
    }

    fclose(file);

    return personAmount;
}

void showSavedPersonList() {
    printf("Name: PERSELISTASD\n");
}

void NavigationMenuAction(int selection) {
    switch (selection) {
        case 1:
            showSavedPersonList();
            break;
        case 2:
            printf("Name: NAVLIST\n");
            break;
        case 3:
            printf("Name: REMOVE SELECTED\n");
            break;
    }
}

int validateNavigationMenuSelection(int selection) {
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

int createNewPerson() {
    char fullName[254], address[254], bloodType[3];
    int age;
    printf("Menu: Write your action below\n");
    scanf()
}

int navigationMenu() {
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
            int isValid = validateNavigationMenuSelection(selection);

            if (isValid >= 1) {
                validInput = 1;
                NavigationMenuAction(selection);
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

int main() {
    struct person savedPersons[MAX_PERSON_AMOUNT];

    int personsCount = loadTempFilePersons(savedPersons);
    if (personsCount == -1) {
        return 1;
    }

    navigationMenu();

    return 0;
}

/*
 *
 * char* bloodType = getBloodTypeLabel(persons[personAmount].bloodType);
        printf("Name: %s / Address: %s / Age %d / Blood type: %s\n", persons[personAmount].fullName, persons[personAmount].address, persons[personAmount].age, bloodType);
        free(bloodType);
 * */