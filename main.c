#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include 	  <sys/wait.h>
#include    "prototypes.h"

char        *recuperer_iterations() {
  char *iterations = malloc(sizeof(char) * 4);

  printf("Nombre d'exécutions : ");
  scanf("%3s", iterations);

  return iterations;
}

char        *recuperer_delai() {
  char *delai = malloc(sizeof(char) * 4);

  printf("Délai entre chaque exécution (secondes) : ");
  scanf("%3s", delai);

  return delai;
}

char        *recuperer_commande() {
  char *commande = malloc(sizeof(char) * 30);

  printf("Commande à lancer : ");
  scanf("%29s", commande);

  return commande;
}

void        lancer_commande(pid_t pid_fils, char *commande) {
  pid_fils = fork();
  if (pid_fils == -1) {
    exit(1);
  }
  if (pid_fils == 0) {
    char *args[] = { commande, NULL };
    execv(recuperer_chemin(commande), args);
  }
  else {
    wait(NULL);
  }
}

int         main() {
  pid_t     pid_fils;
  int end = 0;

  printf("========= Plannificateur de tâches =========\n\n");
  while (end == 0) {
    char *commande = recuperer_commande();
    char *delai = recuperer_delai();
    char *iterations = recuperer_iterations();

    lancer_commande(pid_fils, commande);

    end = 1;
  }

  return 0;
}
