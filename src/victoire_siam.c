#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "poussee.h"
#include "plateau_siam.h"
#include "joueur.h"
#include "condition_victoire_partie.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int verification_nombre_rocher(const jeu_siam *jeu)
{
    int i=0,j=0, nbrocher=0;
    //nbrocher=plateau_denombrer_type(&(jeu->plateau),rocher); nous aurions du utiliser cette fonction mais nous en avons prit connaissance trop tard
    for(i=0;i<NBR_CASES;i++)
    {
        for(j=0;j<NBR_CASES;j++)
        {
            if(jeu->plateau.piece[i][j].type==rocher) { nbrocher ++;}
        }
    }
    assert(nbrocher<4);
    assert(nbrocher>1);
    if(nbrocher==2) {return 1;}
    return 0;
}

condition_victoire_partie victoire_jeu(const jeu_siam *jeu, int x, int y, orientation_deplacement orientation)
{
    condition_victoire_partie cv;
    condition_victoire_initialiser(&cv);
    if(orientation==haut)
    {
        while(y!=4)
        {
            y++;
            
        };
        while(jeu->plateau.piece[x][y].type==case_vide || jeu->plateau.piece[x][y].type==rocher || jeu->plateau.piece[x][y].orientation!=orientation)
        {
                y--;
        };
    }
    if(orientation==bas)
    {
        while(y!=0)
        {
            y--;
            
        };
        while(jeu->plateau.piece[x][y].type==case_vide || jeu->plateau.piece[x][y].type==rocher || jeu->plateau.piece[x][y].orientation!=orientation)
        {
                y++;
        };
    }
    if(orientation==gauche)
    {
        while(x!=0)
        {
            x--;
            
        };
        while(jeu->plateau.piece[x][y].type==case_vide || jeu->plateau.piece[x][y].type==rocher || jeu->plateau.piece[x][y].orientation!=orientation)
        {
                x++;
        };
    }
    if(orientation==droite)
    {
        while(x!=4)
        {
            x++;
            
        };
        while(jeu->plateau.piece[x][y].type==case_vide || jeu->plateau.piece[x][y].type==rocher || jeu->plateau.piece[x][y].orientation!=orientation)
        {
                x--;
        };
    }
    //printf("Le joueur numéro %d a gagné !!\n",joueur_obtenir_numero_a_partir_animal(jeu->plateau.piece[x][y].type));
    cv.victoire=1;
    cv.joueur=joueur_obtenir_numero_a_partir_animal(jeu->plateau.piece[x][y].type);
    return cv;
}