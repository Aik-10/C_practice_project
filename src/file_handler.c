#include <stdio.h>
#include <stdlib.h>
#include "../includes/person.h"

const int MAX_PERSON_AMOUNT = 10;
const char FILE_NAME[] = "saved_person.txt";

int saveSinglePersonToTempFile(struct person person) {
    const char* temp_dir = getenv("TEMP");
    if (temp_dir == NULL) {
        fprintf(stderr, "Failed to get the temporary directory path.\n");
        return -1;
    }

    char temp_file[256];
    snprintf(temp_file, sizeof(temp_file), "%s\\%s", temp_dir, FILE_NAME);

    FILE *file = fopen(temp_file, "a");
    if (file == NULL) {
        perror("ERROR: File opening with WRITE/APPEND permissions");
        return -1;
    }

    fprintf(file, "%255s|%255s|%d|%d\n", person.fullName, person.address, person.age, person.bloodType);

    fclose(file);

    return 0;
}

int loadTempFilePersons(struct person persons[], int *max_person) {
    const char* temp_dir = getenv("TEMP");

    if (temp_dir == NULL) {
        fprintf(stderr, "Failed to get the temporary directory path.\n");
        return -1;
    }

    char temp_file[256];
    snprintf(temp_file, sizeof(temp_file), "%s\\%s", temp_dir, FILE_NAME);

    FILE *file = fopen(temp_file, "r");
    if (file == NULL) {
        perror("ERROR: File opening with READ permissions");
        return -1;
    }

    int personAmount = 0;
    while (personAmount < *max_person && fscanf(file, "%255[^|]|%255[^|]|%d|%d[\\n]", persons[personAmount].fullName, persons[personAmount].address, &persons[personAmount].age, &persons[personAmount].bloodType ) == 4) {
        personAmount++;
    }

    fclose(file);

    return personAmount;
}
