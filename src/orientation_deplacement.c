#include "orientation_deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int orientation_etre_integre(orientation_deplacement orientation)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 5.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 5 pour designer un type valide.

    if(orientation<5)
        return 1;
    return 0;
}

int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement)
{
    if(direction_deplacement==0 || direction_deplacement==1 || direction_deplacement==2 || direction_deplacement==3)
        return 1;
    return 0;
}

const char* orientation_nommer(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere correspondante.

    switch(orientation)
    {
    case haut:
        return "haut"; break;
    case bas:
        return "bas"; break;
    case gauche:
        return "gauche"; break;
    case droite:
        return "droite"; break;
    case aucune_orientation:
        return "aucune"; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere courte correspondante.

    switch(orientation)
    {
    case haut:
        return "^"; break;
    case bas:
        return "v"; break;
    case gauche:
        return "<"; break;
    case droite:
        return ">"; break;
    case aucune_orientation:
        return "????"; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation_etre_integre_deplacement(orientation));

    // "Look up table" (LUT) convertissant une orientation vers
    //    son oppose
    // haut   <-> bas
    // droite <-> gauche


    switch(orientation)
    {
    case haut:
        return bas; break;
    case bas:
        return haut; break;
    case gauche:
        return droite; break;
    case droite:
        return gauche; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



int orientation_caractere_etre_integre(char orientation)
{
    if(orientation=='^' ||orientation=='<' ||orientation=='>' ||orientation=='v')
      return 1;
    return 0;
}


orientation_deplacement orientation_correspondre_caractere(char orientation)
{
    assert(orientation_caractere_etre_integre(orientation)==1);
    switch(orientation)// on retourne une cetaine valeur en fonction du caractère orientation
    {
    case '^':
        return 0; break;
    case 'v':
        return 1; break;
    case '<':
        return 2; break;
    case '>':
        return 3; break;
    default:
        printf("Erreur, orientation piece %c non reconnue",orientation);
        abort();
    }
}
