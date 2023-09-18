Sovellus on “Terminaali” pohjainen.

Ohjelman käynnistyessä, voit valita mitä suoritat,

Luot uuden henkilön
Tulostat kaikki henkilöt.
Poista kaikki
Poistaa tietyn henkilön

Ohjelman syötetään henkilötietoja (
    Fullname CHAR[],
    age INT,
    address CHAR[],
    Veriryhmä {A+, A-, O-, O+, AB+, AB-, B- ja B+}
).

Ohjelma tarkistaa jokaisen syötteen oikean tyypin, sekä estää duplicate datan syöttämisen

Ohjelma tallentaa kaikki lisätyt henkilöt teksti tiedostoon. `%temp%/saved_person.txt` (WIN), Henkilötiedot ladataan ohjelman muistiin tiedostosta, kun ohjelma käynnistyy.

Ohjelmassa ominaisuuksia on hajautettu eri tiedostoihin sekä omiin header tiedostoihin.

Ohjelman logiikkaa on hajautettu omiin funktioihin, jotta koodi on luottavampaa. 

-------------


void showSavedPersonList() {
printf("Name: asd\n");
}

int createNewPerson() {
struct person newPerson;

    printf("\nFullname: ");
    if (scanf(" %[^\n]", newPerson.fullName) != 1) {
        printf("Invalid input for Fullname.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nAddress: ");
    if (scanf(" %[^\n]", newPerson.address) != 1) {
        printf("Invalid input for Address.\n");
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nBlood type: ");
    if (scanf("%d", &newPerson.bloodType) != 1) {
        printf("Invalid input for Blood type.\n");
        return 1;
    }

    printf("\nAge: ");
    if (scanf("%d", &newPerson.age) != 1) {
        printf("Invalid input for Age.\n");
        return 1;
    }

    printf("You entered: %s\n", newPerson.fullName);
    printf("Your age is: %d\n", newPerson.age);

    saveSinglePersonToTempFile(newPerson);

    return 0;
}

void NavigationMenuAction(int *selection) {
switch (*selection) {
case 1:
showSavedPersonList();
break;
case 2:
createNewPerson();
break;
case 3:
printf("Name: REMOVE SELECTED\n");
break;
}
}

int validateNavigationMenuSelection(int *selection) {
switch (*selection) {
case 1:
case 2:
case 3:
return 1;
case 4:
printf("Exiting the program.\n");
return 0;
}
return -1;
}


/*
*
* char* bloodType = getBloodTypeLabel(persons[personAmount].bloodType);
  printf("Name: %s / Address: %s / Age %d / Blood type: %s\n", persons[personAmount].fullName, persons[personAmount].address, persons[personAmount].age, bloodType);
  free(bloodType);
* */

