#include "api_siam.h"
#include "orientation_deplacement.h"
#include "coup_jeu.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "victoire_siam.h"

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
        
    /*
     * si coordonnées entrées (x,y) etre bordure plateau et case vise vide
     * alors introduction de la piece sur le plateau et coup valide vaut 1
     * si la case n'est pas vide
     * alors verification poussee possible
     * si oui introduction de la piece en poussant
     * */
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    if(plateau_modification_introduire_piece_etre_possible(jeu,joueur_obtenir_animal(jeu->joueur))==1)
    {
        if(coordonnees_etre_bordure_plateau(x,y)==1 && jeu->plateau.piece[x][y].type==3)
        {
            jeu->plateau.piece[x][y].type=joueur_obtenir_animal(jeu->joueur);
            jeu->plateau.piece[x][y].orientation=orientation;
            coup.valide=1;
            joueur_changer(&jeu->joueur);
            return coup;
        }
        if(((x==0 && orientation==droite) || (x==4 && orientation==gauche) || (y==0 && orientation==haut) || (y==4 && orientation==bas)) && orientation_inverser(orientation)!=jeu->plateau.piece[x][y].orientation)
        {
                if(poussee_etre_valide(jeu,x-6,y-6,orientation)==1)
                {

                    coup.valide=1;
                    poussee_realiser(jeu,x,y,orientation,orientation);
                    jeu->plateau.piece[x][y].type=joueur_obtenir_animal(jeu->joueur);
                    jeu->plateau.piece[x][y].orientation=orientation;
                    joueur_changer(&jeu->joueur);
                    coup.condition_victoire.victoire=verification_nombre_rocher(jeu);
                    if(coup.condition_victoire.victoire==1) 
                    { 
                        jeu_afficher(jeu);
                        coup.condition_victoire=victoire_jeu(jeu, x, y, orientation); 
                        
                    }
                    return coup;
                }
        }
    }
    coup.valide=0;
    return coup;

}

/*coup_jeu poussee_realiser(jeu_siam *jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation)
{
    if(joueur_etre_type_animal(jeu->joueur,jeu->plateau.piece[x][y].type)==1)
    {
        if(plateau_modification_introduire_piece_etre_possible(&jeu->plateau,x,y,jeu->plateau.piece[x][y].type,orientation)==1)
        {
            if(plateau_modification_changer_orientation_piece_etre_possible(&jeu->plateau,x,y,orientation)==1)
            {
                coup.valide=1;
                return coup;
            }
        }
    }
    coup.valide=0;
    return coup;
}*/



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    /*
     *si la case sur laquelle on veut deplacer la piece est occuppee
     * alors on verifie si la poussee est possible
     * si oui déplacement de la piece en poussant
     * sinon la piece ne bouge pas
     * */
    coup_jeu coup;
    coup_jeu_initialiser(&coup);


    if(plateau_modification_deplacer_piece_etre_possible(jeu,x,y,deplacement,orientation)==1)
    {

        coup.valide=1;
        plateau_modification_deplacer_piece(jeu,x,y,deplacement,orientation);
        coup.condition_victoire.victoire=verification_nombre_rocher(jeu);
        if(coup.condition_victoire.victoire==1) 
        { 
            jeu_afficher(jeu);
            coup.condition_victoire=victoire_jeu(jeu, x, y, orientation); 
            
        }
        joueur_changer(&jeu->joueur);
        return coup;
    }

    coup.valide=0;
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu, int x, int y, orientation_deplacement orientation)
{
    /*
     * verification piece etre animal :
         * si non pas d'orientation
         * si oui verification si l'orientation est nouvelle ou non:
             * si non l'orientation de la piece ne change pas
             * si oui l'orientation est modifiee
     * */
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    plateau_modification_changer_orientation_piece(jeu,x,y,orientation);
    if(jeu->plateau.piece[x][y].orientation==orientation)
    {
        coup.valide=1;
        joueur_changer(&jeu->joueur);
        return coup;
    }
    coup.valide=0;
    return coup;
}
