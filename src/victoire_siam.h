/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Plateau modification a pour role de verifier les regles de
 *  deplacement de pieces du jeu sur le plateau ainsi que leur
 *  mise en place.
 * Ce sont ces fonctions qui permettent de manipuler le plateau
 *  a haut niveau en suivant les regles du jeu.
 *
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * On distingue 3 modifications possibles:
 *  - introduction d'une nouvelle piece du jeu.
 *  - deplacement d'une piece existante.
 *  - changement d'orientation d'une piece existante sans deplacement.
 *
 * Dans chacun des cas, on separe:
 *  - L'etude de la faisabilite de l'action sur un plateau.
 *  - La mise en place de l'action en la supposant valide.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Le niveau d'abstraction associee a plateau_modification comprend
 *  l'application des regles du jeu et leur mise en place sur un
 *  plateau du jeu. La notion de joueur n'est pas prise en compte
 *  a ce niveau, ainsi on supposera que tout animal est jouable.
 * Ce sera a niveau d'abstraction plus eleve de verifier qu'il
 *  s'agit de l'animal du joueur courant.
 *
 * Ce niveau d'abstraction delegue la mise en place technique
 *  de la poussee a un autre ensemble de fichier.
 *
 */



/*#ifndef VICTOIRE_H
#define VICTOIRE_H*/

/**
 *  Plateau_modification necessite la notion d'abstraction de plateau.
 */
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "poussee.h"
#include "condition_victoire_partie.h"



int verification_nombre_rocher(const jeu_siam *jeu);


condition_victoire_partie victoire_jeu(const jeu_siam *jeu, int x, int y, orientation_deplacement orientation);







//#endif