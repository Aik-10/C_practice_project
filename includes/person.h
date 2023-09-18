//
// Created by Lentokone on 15.9.2023.
//

#ifndef PERSONPROJECT_PERSON_H
#define PERSONPROJECT_PERSON_H

typedef enum {
    A_POSITIVE,
    A_NEGATIVE,
    O_NEGATIVE,
    O_POSITIVE,
    AB_POSITIVE,
    AB_NEGATIVE,
    B_NEGATIVE,
    B_POSITIVE
} BloodType;

const char* BOOL_TYPE_NAMES[] = {
        "A+",
        "A-",
        "O-",
        "O+",
        "AB+",
        "AB-",
        "B-",
        "B+"
};

struct person {
    char fullName[255];
    char address[255];
    int age;
    BloodType bloodType;
};

#endif //PERSONPROJECT_PERSON_H
