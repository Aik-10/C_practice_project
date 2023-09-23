#ifndef PERSONPROJECT_FILE_HANDLER_H
#define PERSONPROJECT_FILE_HANDLER_H
#include "person.h"

int saveSinglePersonToTempFile(struct person person);
int loadTempFilePersons(struct person persons[]);
int savePersonsToTempFile(struct person persons[], int* savePersonsCount);

#endif //PERSONPROJECT_FILE_HANDLER_H
