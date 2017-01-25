#include "poussee.h"
#include "jeu_siam.h"
#include "coup_jeu.h"
#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
int poussee_etre_valide(const jeu_siam *jeu,int x,int y,orientation_deplacement orientation)
{
    int force=0;
    int i=0;
    if(x>=0)
    {
        if(joueur_etre_type_animal(jeu->joueur,jeu->plateau.piece[x][y].type)==0) { return 0; }
        if(jeu->plateau.piece[x][y].orientation!=orientation) { return 0; }
        force=2;
    }
    else
    {
        x=x+6;
        y=y+6;
        if(orientation==jeu->plateau.piece[x][y].orientation) { force=4;}
        else
        {
            force=2;
        }
    }
        if(orientation==haut)
        {
            do
            {

                     if(jeu->plateau.piece[x][y+i+1].type<2 && jeu->plateau.piece[x][y+i+1].orientation==haut) { force=force+2;}
                     if(jeu->plateau.piece[x][y+i+1].type<2 && jeu->plateau.piece[x][y+i+1].orientation==bas) { force=force-2;}
                     if(jeu->plateau.piece[x][y+i+1].type==rocher)
                     {
                         if(force%2==0)
                         {
                            force=force-1;
                         }
                         else
                         {
                             force=force-2;
                         }
                     }

                i++;
            }while(coordonnees_etre_dans_plateau(x,y+i)==1 && force>0 && jeu->plateau.piece[x][y+i].type!=case_vide);
        }
        if(orientation==bas)
        {
            do
            {
                     if(jeu->plateau.piece[x][y-i-1].type<2 && jeu->plateau.piece[x][y-i-1].orientation==bas) { force=force+2;}
                     if(jeu->plateau.piece[x][y-i-1].type<2 && jeu->plateau.piece[x][y-i-1].orientation==haut) { force=force-2;}
                     if(jeu->plateau.piece[x][y-i-1].type==rocher)
                     {
                         if(force%2==0)
                         {
                            force=force-1;
                         }
                         else
                         {
                             force=force-2;
                         }
                     }

                i++;
            }while(coordonnees_etre_dans_plateau(x,y-i)==1 && force>0 && jeu->plateau.piece[x][y-i].type!=case_vide);
        }
        if(orientation==gauche)
        {
            do
            {

                     if(jeu->plateau.piece[x-i-1][y].type<2 && jeu->plateau.piece[x-i-1][y].orientation==gauche) { force=force+2;}
                     if(jeu->plateau.piece[x-i-1][y].type<2 && jeu->plateau.piece[x-i-1][y].orientation==droite) { force=force-2;}
                     if(jeu->plateau.piece[x-i-1][y].type==rocher)
                     {
                         if(force%2==0)
                         {
                            force=force-1;
                         }
                         else
                         {
                             force=force-2;
                         }
                     }

                i++;
            }while(coordonnees_etre_dans_plateau(x-i,y)==1 && force>0 && jeu->plateau.piece[x-i][y].type!=case_vide);
        }
        if(orientation==droite)
        {

            do
             {

                if(jeu->plateau.piece[x+i+1][y].type<2 && jeu->plateau.piece[x+i+1][y].orientation==droite) { force=force+2;}
                 if(jeu->plateau.piece[x+i+1][y].type<2 && jeu->plateau.piece[x+i+1][y].orientation==gauche) { force=force-2;}
                 if(jeu->plateau.piece[x+i+1][y].type==rocher)
                 {
                     if(force%2==0)
                     {
                        force=force-1;
                     }
                     else
                     {
                         force=force-2;
                     }
                 }
                i++;
            }while(coordonnees_etre_dans_plateau(x+i,y)==1 && force>0 && jeu->plateau.piece[x+i][y].type!=case_vide);

        }
    
    if(force>0) { return 1;}
    return 0;
}

void poussee_realiser(jeu_siam *jeu,int x,int y,orientation_deplacement orientation,orientation_deplacement orientation_final)
{
    int i=0;
    if(orientation==haut && orientation_final==haut)
    {
        while(coordonnees_etre_dans_plateau(x,y+i)==1 && jeu->plateau.piece[x][y+i].type!=case_vide)
        {
            i++;
        };
        do
        {
            plateau_modification_deplacer_piece(jeu,x,y+i,orientation,jeu->plateau.piece[x][y+i].orientation);
            i--;
        }while(i!=-1);
    }
    if(orientation==bas && orientation_final==bas)
    {
        while(coordonnees_etre_dans_plateau(x,y-i)==1 && jeu->plateau.piece[x][y-i].type!=case_vide)
        {
            i++;
        };
        do
        {
            plateau_modification_deplacer_piece(jeu,x,y-i,orientation,jeu->plateau.piece[x][y-i].orientation);
            i--;
        }while(i!=-1);
    }
    if(orientation==gauche && orientation_final==gauche)
    {
        while(coordonnees_etre_dans_plateau(x-i,y)==1 && jeu->plateau.piece[x-i][y].type!=case_vide)
        {
            i++;
        };
        do
        {
            plateau_modification_deplacer_piece(jeu,x-i,y,orientation,jeu->plateau.piece[x-i][y].orientation);
            i--;
        }while(i!=-1);
    }
    if(orientation==droite && orientation_final==droite)
    {
        while(coordonnees_etre_dans_plateau(x+i,y)==1 && jeu->plateau.piece[x+i][y].type!=case_vide)
        {
            i++;
        };
        do
        {
            plateau_modification_deplacer_piece(jeu,x+i,y,orientation,jeu->plateau.piece[x+i][y].orientation);
            i--;
        }while(i!=-1);
    }

}
