#include <stdio.h>
#include "../includes/file_handler.h"
#include "../includes/blood_type_handler.h"

int createNewPerson() {
    struct person newPerson;
    int c;

    printf("\nFullname:");
    if (scanf(" %[^\n]", newPerson.fullName) != 1) {
        printf("Invalid input for Fullname.\n");
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    printf("Address:");
    if (scanf(" %[^\n]", newPerson.address) != 1) {
        printf("Invalid input for Address.\n");
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    printf("Blood type:");
    if (scanf("%s", newPerson.bloodLabel) != 1 || getBloodTypeIndexByLabel(newPerson.bloodLabel) == -1) {
        printf("Invalid input for Blood type.\n");
        return 1;
    } else {
        newPerson.bloodType = getBloodTypeIndexByLabel(newPerson.bloodLabel);
    }

    printf("Age:");
    if (scanf("%d", &newPerson.age) != 1) {
        printf("Invalid input for Age.\n");
        return 1;
    }

    int saveStatus = saveSinglePersonToTempFile(newPerson);
    if ( saveStatus != 0 ) {
        perror("Error saving singe person to TEMP file.");
        return saveStatus;
    }

    printf("\nNew person saved to TEMP file");

    /* TODO: Push to old table list */
    return 0;
}
