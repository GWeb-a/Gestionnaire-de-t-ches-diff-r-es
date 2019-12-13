#ifndef _INTERACTIONS_H_
#define _INTERACTIONS_H_

/*
 * \brief Récupère le nombre de fois que l'utilisateur souhaite exécuter une
 * commande
 *
 * \return char * : la valeur entrée par l'utilisateur
 */
int         continuer();

 /*
  * \brief Demande à l'utilisateur s'il souhaite réexécuter une commande
  *
  * \return int : 1 si l'utilisateur souhaite relancer une commande ; une autre
  * valeur sinon
  */
char        *recuperer_iterations();

/*
 * \brief Récupère le temps en secondes qui doit s'écouler entre chaque
 * exécution de la commande
 *
 * \return char * : la valeur entrée par l'utilisateur
 */
char        *recuperer_delai();

/*
 * \brief Récupère la commande que souhaite exécuter l'utilisateur
 *
 * \return char * : la valeur entrée par l'utilisateur
 */
char        *recuperer_commande();

#endif /* _INTERACTIONS_H_ */
