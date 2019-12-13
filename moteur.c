#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include 	  <sys/wait.h>
#include    <string.h>
#include    "trouver_chemin.h"
#define     TAILLE_MAX 256

int         nombre_espaces(char *commande) {
  int i;
  int sp = 0;

  for (i = 0; commande[i] != '\0'; i++) {
    if (commande[i] == ' ')
      sp++;
  }
  return sp;
}

void        executer_commande(char *args[], char *args_opt[], char *cpy_cmd, char *trouve) {
  pid_t pid_fils;
  char *chemin = recuperer_chemin(cpy_cmd);

  pid_fils = fork();
  if (pid_fils == -1) {
    exit(1);
  }
  if (pid_fils == 0) {
    if (chemin) {
      if (!trouve) {
        execv(recuperer_chemin(cpy_cmd), args);
      }
      else {
        execv(recuperer_chemin(args_opt[0]), args_opt);
      }
    }
    else
      exit(0);
  }
  else {
    wait(NULL);
  }
}

void        lancer_commande(char *commande) {
  int taille_tab = nombre_espaces(commande) + 2;
  char *trouve = strchr(commande, ' ');
  char *args_opt[taille_tab];
  char *cpy_cmd = malloc(sizeof(char) * strlen(commande) + 1);
  int i;

  strcpy(cpy_cmd, commande);
  for (i = 0; i < taille_tab; i++) {
    args_opt[i] = (char *)malloc(sizeof(char) * TAILLE_MAX);
  }

  /* S'il y a une option */
  if (trouve) {
    i = 0;
    char *sptr = malloc(sizeof(char) * TAILLE_MAX);
    sptr = strtok(cpy_cmd, " ");
    while (sptr) {
      if (sptr)
        strcpy(args_opt[i], sptr);
      sptr = strtok(NULL, " ");
      i++;
    }
  }
  args_opt[taille_tab - 1] = NULL;
  char *args[] = { cpy_cmd, NULL };
  executer_commande(args, args_opt, cpy_cmd, trouve);
}

void        execution(char *commande, char *delai, char *iterations) {
  for (int it = 0; it < atoi(iterations); it++) {
    lancer_commande(commande);
    if (it + 1 != atoi(iterations)) {
      sleep(atoi(delai));
    }
  }
}
