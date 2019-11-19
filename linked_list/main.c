#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct cities {
  char name[50];
  char gidis[20];
  char donus[20];

  struct cities *next;


}city;
void displayCities(city *sehir);

int main(int argc,
         char *argv[]) {
  city istanbul;
  city ankara;
  city kars;

  strcpy(istanbul.name,"Istanbul");
  strcpy(istanbul.gidis,"20:00");
  strcpy(istanbul.donus,"22:00");
  istanbul.next = &ankara;

  strcpy(ankara.name,"Ankara");
  strcpy(ankara.gidis,"22:00");
  strcpy(ankara.donus,"15:00");
  ankara.next = &kars;

  strcpy(kars.name,"Kars");
  strcpy(kars.gidis,"15:00");
  strcpy(kars.donus,"19:00");
  kars.next = &istanbul;
  displayCities(&istanbul);

  return 0;
}

void displayCities(city *sehir) {
  for(; sehir!=NULL; sehir = sehir->next)
  {
    printf("Sehir ismi : %s  Gidis saati : %s Donus saati: %s \n\n",
           sehir->name,
           sehir->gidis,
           sehir->donus);
  }
}

