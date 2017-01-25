#include "plateau_siam.h"
#include "entree_sortie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (1,2), (2,2) et (3,2)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //


    int kx=0;
    for(kx=0 ; kx<NBR_CASES ; ++kx)
    {
        int ky=0;
        for(ky=0 ; ky<NBR_CASES ; ++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }

    assert(plateau_etre_integre);
}

int plateau_etre_integre(const plateau_siam* plateau)
{
    assert(plateau!=NULL);
    assert(plateau_denombrer_type(plateau,elephant)>=0);
    assert(plateau_denombrer_type(plateau,rhinoceros)>=0);
    assert(plateau_denombrer_type(plateau,rocher)>=0);
    if(plateau_denombrer_type(plateau,elephant)>NBR_CASES) {return 0;}
    if(plateau_denombrer_type(plateau,rhinoceros)>NBR_CASES) {return 0;}
    if(plateau_denombrer_type(plateau,rocher)>NBR_ROCHERS) {return 0;}
    return 1;
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(x>=0 && x<NBR_CASES);
    assert(y>=0 && y<NBR_CASES);
    return &(plateau->piece[x][y]);
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(x>=0 && x<NBR_CASES);
    assert(y>=0 && y<NBR_CASES);
    return &(plateau->piece[x][y]);
}



int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
    assert(plateau!=NULL);
    //algorithme:
    //
    //initialiser compteur <-0
    //pour toutes les cases du plateau
    //si case courante est du type souhaite
    //incremente compteur
    //renvoie compteur
    int compteur=0;
    int kx=0,ky=0;
    for(kx=0;kx<NBR_CASES;kx++)
    {
        for(ky=0;ky<NBR_CASES;ky++)
        {
            const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
                    assert(piece!=NULL);
            if(piece->type==type) {compteur++;}
        }
    }
    return compteur;
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(x>=0 && x<NBR_CASES);
    assert(y>=0 && y<NBR_CASES);
    if(plateau->piece[x][y].type==case_vide) {return 0;}
    return 1;
}

void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}
