#include "type_piece.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int type_etre_integre(type_piece type)
{
    // L'enumeration designe un type integre si elle est comprise
    //  entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.
    if(type<4)
        return 1;
    return 0;
}


int type_etre_animal(type_piece type)
{

    if(type==0 || type==1) { return 1;}
    return 0;
}
void test_type_etre_animal()
{
   puts("test type_etre_animal");
    if(type_etre_animal(elephant)!=1)
      puts("elephant KO");
    if(type_etre_animal(rhinoceros)!=1)
      puts("rhinoceros KO");
    if(type_etre_animal(rocher)!=0)
      puts("rocher KO");if(type_etre_animal(case_vide)!=0)
      puts("case vide KO");
    int k=0;
    for(k=4;k<100;++k)
      if(type_etre_animal(k)!=0)
	printf("valeur %d KO\n",k);
}

const char* type_nommer(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere correspondante.

    switch(type)
    {
    case elephant:
        return "elephant"; break;
    case rhinoceros:
        return "rhinoceros"; break;
    case rocher:
        return "rocher"; break;
    case case_vide:
        return "vide"; break;
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


const char* type_nommer_nom_cours(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere courte correspondante.

    switch(type)
    {
    case elephant:
        return "e"; break;
    case rhinoceros:
        return "r"; break;
    case rocher:
        return "RRR"; break;
    case case_vide:
        return "***"; break;
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

int type_caractere_animal_etre_integre(char type)
{
    // Verifie que le caractere correspond a elephant (e) ou rhinoceros (r).
    if(type=='e' || type=='r')
        return 1;
    return 0;
}

type_piece type_correspondre_caractere_animal(char type)
{
    assert(type=='e' || type=='r');
    type_piece type_enum=elephant;
    if(type=='e')
      type_enum=elephant;
    else
      type_enum=rhinoceros;
    return type_enum;
}
