#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include 	  <sys/wait.h>
#include    <string.h>
#include    "interactions.h"
#include    "moteur.h"
#define     TAILLE_MAX 256

int         main() {
  int end = 0;

  printf("========= Plannificateur de tâches =========\n\n");
  while (end == 0) {
    char *commande = recuperer_commande();
    char *delai = recuperer_delai();
    char *iterations = recuperer_iterations();

    printf("\n=== Execution de %s %s fois toutes les %s secondes ===\n\n", commande, iterations, delai);
    execution(commande, delai, iterations);

    if (!continuer()) {
      end = 1;
    }
    printf("\n\n");
  }

  return 0;
}
