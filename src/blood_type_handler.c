#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* BOOL_TYPE_WITH_NAMES[] = {
        "A+",
        "A-",
        "O-",
        "O+",
        "AB+",
        "AB-",
        "B-",
        "B+"
};

char* getBloodTypeLabelByIndex(int blood_index) {
    if (blood_index < 0 || blood_index >= sizeof(BOOL_TYPE_WITH_NAMES) / sizeof(BOOL_TYPE_WITH_NAMES[0])) {
        fprintf(stderr, "Invalid blood index: %d\n", blood_index);
    }

    char* str = (char*)malloc(strlen(BOOL_TYPE_WITH_NAMES[blood_index]));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(str, BOOL_TYPE_WITH_NAMES[blood_index]);
    return str;
}

int getBloodTypeIndexByLabel(char blood_label[]) {
    return 0;
}