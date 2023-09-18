#ifndef PERSONPROJECT_FILE_HANDLER_H
#define PERSONPROJECT_FILE_HANDLER_H
#include "person.h"

int saveSinglePersonToTempFile(struct person person, char *file_name[]);
int loadTempFilePersons(struct person persons[], int *max_person);

#endif //PERSONPROJECT_FILE_HANDLER_H
