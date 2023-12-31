#include "../includes/file_handler.h"
#include "../includes/navigation.h"
#include "../includes/general.h"

int main() {
    struct person savedPersons[MAX_PERSON_AMOUNT];

    int personsCount = loadTempFilePersons(savedPersons);
    if ( personsCount == -1 ) {
        return 1;
    }

    while (1) {
        int selection = generalNavigationMenu(savedPersons, &personsCount);
        if ( selection == 1 ) {
            break;
        }
    }

    return 0;
}