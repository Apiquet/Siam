#include "coordonnees_plateau.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int coordonnees_etre_dans_plateau(int x,int y)
{
    if((x>=0 && x<NBR_CASES) && (y>=0 && y<NBR_CASES))
        return 1;
    return 0;
}

int coordonnees_etre_bordure_plateau(int x,int y)
{
    if(x==0||x==NBR_CASES-1){return 1;}
    if(y==0||y==NBR_CASES-1){return 1;}
    return 0;
}

void test_coordonnees_etre_bordure_plateau()
{
    puts("Test coordonnees_etre_bordure_plateau :");
    int i,j;
    i=0;
    for(j=0;j<5;j++)
    {
        if(coordonnees_etre_bordure_plateau(i,j)==0)
        {
            printf("coordonnees_etre_bordure_plateau KO %d %d",i,j);
        }
    }
    j=0;
    for(i=0;i<5;i++)
    {
        if(coordonnees_etre_bordure_plateau(i,j)==0)
        {
            printf("coordonnees_etre_bordure_plateau KO %d %d",i,j);
        }
    }
    for(i=1;i<4;i++)
    {
        for(j=1;j<4;j++)
        {
            if(coordonnees_etre_bordure_plateau(i,j)==1)
            {
                printf("coordonnees_etre_bordure_plateau KO %d %d",i,j);
            }
        }

    }
    i=NBR_CASES-1;
    for(j=0;j<5;j++)
    {
        if(coordonnees_etre_bordure_plateau(i,j)==0)
        {
            printf("coordonnees_etre_bordure_plateau KO %d %d",i,j);
        }
    }
    j=NBR_CASES-1;
    for(i=0;i<5;i++)
    {
        if(coordonnees_etre_bordure_plateau(i,j)==0)
        {
            printf("coordonnees_etre_bordure_plateau KO %d %d",i,j);
        }
    }
}

void coordonnees_appliquer_deplacement(int* x,int* y,orientation_deplacement orientation)
{
    assert(x!=NULL);
    assert(y!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));

    // Table de correspondance:
    //  haut   -> (x,y+1)
    //  bas    -> (x,y-1)
    //  gauche -> (x-1,y)
    //  droite -> (x+1,y)

    switch(orientation)
    {
    case haut:
        *y+=1;
        break;
    case bas:
        *y-=1;
        break;
    case gauche:
        *x-=1;
        break;
    case droite:
        *x+=1;
        break;
    default:
        printf("Probleme fonction %s\n",__FUNCTION__);
    }
}





