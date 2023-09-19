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

```C
char* bloodType = getBloodTypeLabel(persons[personAmount].bloodType);
printf("Name: %s / Address: %s / Age %d / Blood type: %s\n", persons[personAmount].fullName, persons[personAmount].address, persons[personAmount].age, bloodType);
free(bloodType);
```
