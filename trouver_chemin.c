#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int est_executable(const char *nom) {
  int result;
  struct stat info_stat;

  result = stat(nom, &info_stat);
  if (result < 0) {
    return 0;
  }
  if (!S_ISREG(info_stat.st_mode)) {
    return 0;
  }

  if (info_stat.st_uid == geteuid()) {
    return info_stat.st_mode & S_IXUSR;
  }
  if (info_stat.st_gid == getegid()) {
    return info_stat.st_mode & S_IXGRP;
  }

  return info_stat.st_mode & S_IXOTH;
}

int trouver_chemin(char *chemin, const char *commande) {
  char *recherche_chemin;
  char *debut;
  char *fin;
  int stop;
  int trouve;
  int longueur;

  if (strchr(commande, '/') != NULL) {
    if (realpath(commande, chemin) == NULL) {
      return 0;
    }
	  return est_executable(chemin);
  }

  recherche_chemin = getenv("PATH");
  if (recherche_chemin == NULL) {
    return 0;
  }
  if (strlen(recherche_chemin) <= 0) {
    return 0;
  }

  debut = recherche_chemin;
  stop = 0;
  trouve = 0;
  do {
    fin = strchr(debut, ':');
	  if (fin == NULL) {
      stop = 1;
	    strncpy(chemin, debut, PATH_MAX);
	    longueur = strlen(chemin);
    }
    else {
      strncpy(chemin, debut, fin - debut);
	    chemin[fin - debut] = '\0';
	    longueur = fin - debut;
    }

    if (chemin[longueur - 1] != '/') {
      strncat(chemin, "/", 1);
    }
	  strncat(chemin, commande, PATH_MAX - longueur);
	  trouve = est_executable(chemin);
	  if (!stop) {
      debut = fin + 1;
    }
  } while (!stop && !trouve);

  return trouve;
}

char *recuperer_chemin(char *commande) {
  char *chemin = malloc(sizeof(char) * (PATH_MAX+1));

  if (!trouver_chemin(chemin, commande)) {
    fprintf(stderr, "La commande %s n\'est pas executable.\n", commande);
    return NULL;
  }

  return chemin;
}
