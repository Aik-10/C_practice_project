#ifndef PERSONPROJECT_FILE_HANDLER_H
#define PERSONPROJECT_FILE_HANDLER_H
#include "person.h"

int saveSinglePersonToTempFile(struct person person);
int loadTempFilePersons(struct person persons[]);

#endif //PERSONPROJECT_FILE_HANDLER_H
