#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/person.h"
#include "../includes/general.h"

const char FILE_NAME[] = "saved_person.txt";

int savePersonsToTempFile(struct person persons[]) {
    return 0;
}

int saveSinglePersonToTempFile(struct person person) {
    const char* temp_dir = getenv("TEMP");
    if (temp_dir == NULL) {
        fprintf(stderr, "Failed to get the temporary directory path.\n");
        return -1;
    }

    size_t buffer_size = strlen(temp_dir) + strlen(FILE_NAME) + 2;
    if (buffer_size > MAX_PATH_LENGTH) {
        perror("Path length exceeds maximum allowed.\n");
        return -1;
    }

    char* temp_file = (char*)malloc(buffer_size);
    snprintf(temp_file, buffer_size, "%s/%s", temp_dir, FILE_NAME);

    FILE *file = fopen(temp_file, "a");
    if (file == NULL) {
        perror("ERROR: File opening with WRITE/APPEND permissions");
        return -1;
    }

    fprintf(file, "%s|%s|%d|%d\n", person.fullName, person.address, person.age, person.bloodType);

    fclose(file);
    free(temp_file);

    return 0;
}

int loadTempFilePersons(struct person persons[]) {
    const char* temp_dir = getenv("TEMP");

    if (temp_dir == NULL) {
        fprintf(stderr, "Failed to get the temporary directory path.\n");
        return -1;
    }

    size_t buffer_size = strlen(temp_dir) + strlen(FILE_NAME) + 2;

    if (buffer_size > MAX_PATH_LENGTH) {
        perror("Path length exceeds maximum allowed.\n");
        return -1;
    }

    char* temp_file = (char*)malloc(buffer_size);
    snprintf(temp_file, buffer_size, "%s/%s", temp_dir, FILE_NAME);

    FILE *file = fopen(temp_file, "r");
    if (file == NULL) {
        perror("ERROR: File opening with READ permissions");
        return -1;
    }

    int personAmount = 0;
    while (personAmount < MAX_PERSON_AMOUNT && fscanf(file, "%255[^|]|%255[^|]|%d|%d[\\n]", persons[personAmount].fullName, persons[personAmount].address, &persons[personAmount].age, &persons[personAmount].bloodType ) == 4) {
        personAmount++;
    }

    fclose(file);
    free(temp_file);

    return personAmount;
}
