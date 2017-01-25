#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "poussee.h"
#include "plateau_siam.h"
#include "joueur.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const jeu_siam* jeu,
                                                        type_piece type)
{
        int j=0,i=0,e=0,r=0;
        for(i=0;i<NBR_CASES;i++)
        {
            for(j=0;j<NBR_CASES;j++)
            {
                if(jeu->plateau.piece[i][j].type==elephant) { e++;}
                if(jeu->plateau.piece[i][j].type==rhinoceros) { r++;}
            }
        }
        if(type==elephant)
        {
            if(e<5)
            {
               return 1;
            }
        }
        if(type==rhinoceros)
        {
            if(r<5)
            {
               return 1;
            }
            
        }

        return 0;
}


/*void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation)
{
    //coder cette fonction
}*/


int plateau_modification_changer_orientation_piece_etre_possible(const jeu_siam* jeu,int x0,int y0,orientation_deplacement orientation)
{
    assert( jeu!=NULL);
    if(joueur_etre_type_animal(jeu->joueur,jeu->plateau.piece[x0][y0].type)==1)
    {
        if(orientation != jeu->plateau.piece[x0][y0].orientation)
        {
            if(orientation < 4)
            {
                return 1;
            }
        }
    }
    return 0;
}



void plateau_modification_changer_orientation_piece(jeu_siam* jeu,int x0,int y0,orientation_deplacement orientation)
{
    assert( jeu!=NULL);
    if(plateau_modification_changer_orientation_piece_etre_possible(jeu,x0,y0,orientation)==1)
    {
        jeu->plateau.piece[x0][y0].orientation=orientation;
    }
}


int plateau_modification_deplacer_piece_etre_possible(const jeu_siam *jeu,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,orientation_deplacement orientation_finale)
{
    assert(jeu!=NULL);
    if(joueur_etre_type_animal(jeu->joueur,jeu->plateau.piece[x0][y0].type)==1)
    {
        if(direction_deplacement==0)
        {
            if((y0<4 && jeu->plateau.piece[x0][y0+1].type==3) || y0==4)
            {
                return 1;
            }
            if(direction_deplacement==orientation_finale && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
            {
                return 1;
            }
            return 0;
        }
        else if(direction_deplacement==1)
        {
            if((y0>0 && jeu->plateau.piece[x0][y0-1].type==3) || y0==0)
            {
                return 1;
            }
            if( direction_deplacement==orientation_finale && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
            {
                return 1;
            }
            return 0;
        }
        else if(direction_deplacement==2)
        {
            if((x0>0 && jeu->plateau.piece[x0-1][y0].type==3) || x0==0)
            {
                return 1;
            }
            if( direction_deplacement==orientation_finale && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
            {
                return 1;
            }
            return 0;
        }
        else if(direction_deplacement==3)
        {
            if((x0<4 && jeu->plateau.piece[x0+1][y0].type==3) || x0==4)
            {
                return 1;
            }
            if( direction_deplacement==orientation_finale && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
            {
                return 1;
            }
            return 0;
        }
    }
    return 0;
}


void plateau_modification_deplacer_piece(jeu_siam* jeu,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final)
{
        if(direction_deplacement==0)
        {
            if(y0<4 && jeu->plateau.piece[x0][y0+1].type==3)
            {
                jeu->plateau.piece[x0][y0+1]=jeu->plateau.piece[x0][y0];
                jeu->plateau.piece[x0][y0+1].orientation=orientation_final;
                jeu->plateau.piece[x0][y0].type=3;
                jeu->plateau.piece[x0][y0].orientation=4;
            }
            if(y0<4 && jeu->plateau.piece[x0][y0+1].type!=3 && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
            {
                poussee_realiser(jeu,x0,y0,direction_deplacement,orientation_final);
            }
            if(y0==4)
            {
                jeu->plateau.piece[x0][y0].type=3;
                jeu->plateau.piece[x0][y0].orientation=4;
            }
        }
        if(direction_deplacement==1)
        {
                if(y0>0 && jeu->plateau.piece[x0][y0-1].type==3)
                {
                    jeu->plateau.piece[x0][y0-1]=jeu->plateau.piece[x0][y0];
                    jeu->plateau.piece[x0][y0-1].orientation=orientation_final;
                    jeu->plateau.piece[x0][y0].type=3;
                    jeu->plateau.piece[x0][y0].orientation=4;
                }
                if(y0>0 && jeu->plateau.piece[x0][y0-1].type!=3 && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
                {
                    poussee_realiser(jeu,x0,y0,direction_deplacement,orientation_final);
                }
                if(y0==0)
                {
                    jeu->plateau.piece[x0][y0].type=3;
                    jeu->plateau.piece[x0][y0].orientation=4;
                }
         }
         if(direction_deplacement==2)
         {
                    if(x0>0 && jeu->plateau.piece[x0-1][y0].type==case_vide)
                    {
                        jeu->plateau.piece[x0-1][y0]=jeu->plateau.piece[x0][y0];
                        jeu->plateau.piece[x0-1][y0].orientation=orientation_final;
                        jeu->plateau.piece[x0][y0].type=3;
                        jeu->plateau.piece[x0][y0].orientation=4;
                    }
                    if(x0>0 && jeu->plateau.piece[x0-1][y0].type!=3 && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
                    {
                        poussee_realiser(jeu,x0,y0,direction_deplacement,orientation_final);
                    }
                    if(x0==0)
                    {
                        jeu->plateau.piece[x0][y0].type=3;
                        jeu->plateau.piece[x0][y0].orientation=4;
                    }
          }
          if(direction_deplacement==3)
          {
                  if(x0<4 && jeu->plateau.piece[x0+1][y0].type==case_vide)
                  {
                            jeu->plateau.piece[x0+1][y0]=jeu->plateau.piece[x0][y0];
                            jeu->plateau.piece[x0+1][y0].orientation=orientation_final;
                            jeu->plateau.piece[x0][y0].type=case_vide;
                            jeu->plateau.piece[x0][y0].orientation=4;
                   }
                   if(x0<4 && jeu->plateau.piece[x0+1][y0].type!=3 && poussee_etre_valide(jeu,x0,y0,direction_deplacement)==1)
                   {
                            poussee_realiser(jeu,x0,y0,direction_deplacement,orientation_final);
                   }
                   if(x0==4)
                   {
                       jeu->plateau.piece[x0][y0].type=3;
                       jeu->plateau.piece[x0][y0].orientation=4;
                   }
           }

}


