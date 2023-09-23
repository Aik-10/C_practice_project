#include "../includes/file_handler.h"
#include "../includes/navigation.h"
#include "../includes/general.h"

int main() {
    struct person savedPersons[MAX_PERSON_AMOUNT];

    int personsCount = loadTempFilePersons(savedPersons);
    if ( personsCount == -1 ) {
        return 1;
    }

    generalNavigationMenu(savedPersons, &personsCount);

    return 0;
}