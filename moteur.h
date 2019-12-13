#ifndef MOTEUR_H_
#define MOTEUR_H_

/*
 * \brief Compte le nombre d'espaces dans la commande entrée par l'utilisateur
 *
 * \param commande : char * : la commande que l'on souhaite exécuter
 *
 * \return int : le nombre d'espaces dans la commande
 */
int         nombre_espaces(char *commande);

/*
 * \brief Exécute la commande dans un processus fils
 *
 * \param commande : char *[] : les arguments d'une commande sans option
 * \param commande : char *[] : les arguments d'une commande avec option(s)
 * \param commande : char * : une copie de la commande
 * \param trouve : char * : le retour de la fonction strchr qui vaut NULL s'il
 * n'y a aucune option
 */
void        executer_commande(char *args[], char *args_opt[], char *cpy_cmd, char *trouve);

/*
 * \brief Découpe la commande pour récupérer l'exécutable et ses options, puis
 * exécute la commande
 *
 * \param commande : char * : la commande que l'on souhaite exécuter
 */
void        lancer_commande(char *commande);

/*
 * \brief Lance toutes les x secondes une commande y fois
 *
 * \param commande : char * : la commande à exécuter
 * \param delai : char * : le délai à respecter entre chaque iteration
 * \param iterations : char * : le nombre de fois où la commande sera executée
 */
void        execution(char *commande, char *delai, char *iterations);

#endif /* MOTEUR_H_ */
