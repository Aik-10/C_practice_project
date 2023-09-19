#include "../includes/file_handler.h"
#include "../includes/navigation.h"
#define MAX_PERSON_AMOUNT 10

int main() {
    struct person savedPersons[MAX_PERSON_AMOUNT];

    int personsCount = loadTempFilePersons(savedPersons);
    if ( personsCount == -1 ) {
        return 1;
    }

    generalNavigationMenu();

    return 0;
}
