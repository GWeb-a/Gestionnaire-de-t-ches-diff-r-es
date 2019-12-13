#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include 	  <sys/wait.h>
#include    <string.h>
#define     TAILLE_MAX 256

int         continuer() {
  char *continuer = malloc(sizeof(char) * 4);

  printf("\n\nVoulez-vous continuer ? (Oui : 1) : ");
  fgets(continuer, TAILLE_MAX, stdin);
  strtok(continuer, "\n");

  return atoi(continuer);
}

char        *recuperer_iterations() {
  char *iterations = malloc(sizeof(char) * 4);

  printf("Nombre d'exécutions : ");
  fgets(iterations, TAILLE_MAX, stdin);
  strtok(iterations, "\n");

  return iterations;
}

char        *recuperer_delai() {
  char *delai = malloc(sizeof(char) * 4);

  printf("Délai entre chaque exécution (secondes) : ");
  fgets(delai, TAILLE_MAX, stdin);
  strtok(delai, "\n");

  return delai;
}

char        *recuperer_commande() {
  char *commande = malloc(sizeof(char) * 30);

  printf("Commande à lancer : ");
  fgets(commande, TAILLE_MAX, stdin);
  strtok(commande, "\n");

  return commande;
}
