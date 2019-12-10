#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_

 /*
  * \brief Teste si un fichier est exécutable
  *
  * \param nom : const char * : le chemin du fichier
  *
  * \return int : 0 si le fichier est non exécutable ou inexistant;
  * une autre valeur sinon
  */
int     est_executable(const char *nom);

/*
 * \brief Trouve un exécutable en cherchant dans la variable d'environnement
 * PATH
 *
 * \param chemin : char * : le chemin où se trouve l'exécutable y sera stocké
 * \param commande : const char * : nom de l'exécutable à chercher
 *
 * \return int : 0 si aucun exécutable n'a été trouvé ; une autre valeur sinon
 */
int     trouver_chemin(char *chemin, const char *commande);

/*
 * \brief Retourne le chemin du fichier exécutable relatif à une commande
 *
 * \param commande : char * : la commande donnée
 *
 * \return char * : le chemin vers l'exécutable trouvé ; NULL sinon
 */
char    *recuperer_chemin(char *commande);

#endif /* _PROTOTYPES_H_ */
