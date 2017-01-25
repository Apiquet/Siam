#include "jeu_siam.h"
#include "joueur.h"

#include "entree_sortie.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int jeu_etre_integre(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //verification du joueur integre
    const int joueur=jeu->joueur;
    if(joueur_etre_integre(joueur)==0)
        return 0;

    //verification du plateau integre
    const plateau_siam* plateau=&jeu->plateau;
    if(plateau_etre_integre(plateau)==0)
        return 0;

    return 1;
}


void jeu_initialiser(jeu_siam* jeu)
{

    assert(jeu!=NULL);

    //initialise le plateau
    //initialise le joueur

    plateau_initialiser(&jeu->plateau);
    jeu->joueur=0;
    /*jeu->plateau.piece[0][1].type=1;
    jeu->plateau.piece[0][1].orientation=droite;

    jeu->joueur=0;
    jeu->plateau.piece[1][1].type=0;
    jeu->plateau.piece[1][1].orientation=gauche;

    jeu->joueur=0;
    jeu->plateau.piece[2][1].type=0;
    jeu->plateau.piece[2][1].orientation=droite;*/
}





void jeu_changer_joueur(jeu_siam* jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    joueur_changer(&jeu->joueur);

    assert(jeu_etre_integre(jeu));

}


int jeu_verifier_type_piece_a_modifier(const jeu_siam* jeu,int x,int y)
{
    assert(jeu!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));
    if(jeu->joueur==0&&jeu->plateau.piece[x][y].type==elephant){return 1;}
    if(jeu->joueur==1&&jeu->plateau.piece[x][y].type==rhinoceros){return 1;}
    return 0;
}
void test_jeu_verifier_type_piece_a_modifier()
{
    puts("test_jeu_verifier_type_piece_a_modifier:");
    jeu_siam jeu;
    jeu.joueur=0;
    jeu.plateau.piece[1][1].type=elephant;
    if(jeu_verifier_type_piece_a_modifier(&jeu,1,1)==0) { puts("jeu_verifier_type_piece_a_modifier KO joueur 0 elephant vaut 0");}
    jeu.joueur=1;
    jeu.plateau.piece[1][1].type=rhinoceros;
    if(jeu_verifier_type_piece_a_modifier(&jeu,1,1)==0) { puts("jeu_verifier_type_piece_a_modifier KO joueur 1 rhinoceros vaut 0");}
    jeu.joueur=0;
    jeu.plateau.piece[1][1].type=rhinoceros;
    if(jeu_verifier_type_piece_a_modifier(&jeu,1,1)==1) { puts("jeu_verifier_type_piece_a_modifier KO joueur 0 rhinoceros vaut 1");}
    jeu.joueur=1;
    jeu.plateau.piece[1][1].type=elephant;
    if(jeu_verifier_type_piece_a_modifier(&jeu,1,1)==1) { puts("jeu_verifier_type_piece_a_modifier KO joueur 1 elephant vaut 1");}
}

void jeu_afficher(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //utilisation d'une fonction generique avec affichage sur
    //  la ligne de commande.
    entree_sortie_ecrire_jeu_pointeur_fichier(stdout,jeu);
}



type_piece jeu_obtenir_type_animal_courant(const jeu_siam* jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu)==1);
    if(jeu->joueur==0) {return elephant;}
    if(jeu->joueur==1) {return rhinoceros;}
    return elephant;
}
void test_jeu_obtenir_type_animal_courant()
{
    puts("test_jeu_obtenir_type_animal_courant:");
    jeu_siam jeu;
    plateau_initialiser(&jeu.plateau);
    jeu.joueur=0;
    if(jeu_obtenir_type_animal_courant(&jeu)==rhinoceros) { puts("jeu_obtenir_type_animal_courant KO joueur 0 return rhinoceros");}
    jeu.joueur=1;
    if(jeu_obtenir_type_animal_courant(&jeu)==elephant) { puts("jeu_obtenir_type_animal_courant KO joueur 1 return elephant");}
}
