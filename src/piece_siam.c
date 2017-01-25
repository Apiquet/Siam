#include "piece_siam.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int piece_etre_integre(const piece_siam* piece)
{
    assert( piece!=NULL);
    
    
    if( piece->type==0 || piece->type==1)
    {
      if( orientation_etre_integre_deplacement(piece->orientation)==1)
      {
        return 1;
      }
      return 0;
    }
    if( piece->type==2 || piece->type==3)
    {
      if (piece->orientation==4)
      {
        return 1;
      }
    }
    return 0;
}
void test_piece_etre_integre()
{ 

    puts("test_piece_etre_integre");
    int i,j;
    piece_siam p;
    for(i=0;i<100;i++)
    {
      p.type=i;
      for(j=0;j<100;j++)
      {
	p.orientation=j;
	if((i==0 || i==1) && (j<4))
	  if(piece_etre_integre(&p)!=1)
	    printf("Piece et orientation KO %d %d\n",i,j);
	if((i==2 || i==3) && (j==4))
	  if(piece_etre_integre(&p)!=1)
	    printf("Piece et orientation KO %d %d\n",i,j);
	if(i>4)
	  if(piece_etre_integre(&p)==1)
	    printf("Piece et orientation KO %d %d\n",i,j);
      }
    }
}
void piece_initialiser(piece_siam* piece)
{
    assert(piece!=NULL);

    piece_definir(piece,case_vide,aucune_orientation);

    assert(piece_etre_integre(piece));
}


int piece_etre_animal(const piece_siam* piece)
{
    assert(piece_etre_integre(piece)==1);
    if(piece->type==0 || piece->type==1) { return 1;}
    return 0;
}
void test_piece_etre_animal()
{
    piece_siam p;
    puts("Test: piece etre animal");
    int k;
    p.type=0;
    if(piece_etre_animal(&p)==0)
    {
        puts("Piece etre animal: elephant KO");
    }
    p.type=1;
    if(piece_etre_animal(&p)==0)
    {
        puts("Piece etre animal: rhinocéros KO");
    }
    for(k=2;k<100;k++)
    {
        p.type=k;
        if(piece_etre_animal(&p)==1)
        {
            printf("Piece_animal KO %d\n",k);
        }
    }
}

int piece_etre_rocher(const piece_siam* piece)
{
    assert(piece_etre_integre(piece)==1);
    if(piece->type==2) { return 1;}
    return 0;
}

void test_piece_etre_rocher()
{
    piece_siam p;
    puts("Test piece etre rocher");
    p.type=2;
    if(piece_etre_rocher(&p)==0) { puts("piece etre roche: rocher KO"); }
    int k;
    for(k=3;k<100;k++)
    {
        p.type=k;
        if(piece_etre_rocher(&p)==1)
        {
            printf("piece etre roche KO: %d\n",k);
        }
    }
    p.type=0;
    if(piece_etre_rocher(&p)==1) { puts("piece etre rocher KO: 0"); }
    p.type=1;
    if(piece_etre_rocher(&p)==1) { puts("piece etre rocher KO: 1"); }
}

int piece_etre_case_vide(const piece_siam* piece)
{
    assert(piece_etre_integre(piece)==1);
    if(piece->type==3) { return 1;}
    return 0;
}

void test_piece_etre_case_vide()
{
    puts("Test piece est case vide");
    piece_siam p;
    p.type=3;
    if(piece_etre_case_vide(&p)==0) { puts("piece etre case vide: case vide KO"); }
    int k;
    for(k=4;k<100;k++)
    {
        p.type=k;
        if(piece_etre_case_vide(&p)==1)
        {
            printf("piece etre case vide KO: %d\n",k);
        }
    }
    p.type=0;
    if(piece_etre_case_vide(&p)==1) { puts("piece etre case vide KO: 0"); }
    p.type=1;
    if(piece_etre_case_vide(&p)==1) { puts("piece etre case vide KO: 1"); }
    p.type=2;
    if(piece_etre_case_vide(&p)==1) { puts("piece etre case vide KO: 2"); }
}




void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
    assert( piece!=NULL);
    piece->type=type;
    piece->orientation=orientation;
    assert(piece_etre_integre(piece)==1);
}


void piece_definir_rocher(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,rocher,aucune_orientation);
    assert(piece_etre_integre(piece));
}

void piece_definir_case_vide(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,case_vide,aucune_orientation);
    assert(piece_etre_integre(piece));
}





orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    assert(piece_etre_animal(piece));

    return piece->orientation;
}


void piece_afficher(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s,%s",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

void piece_afficher_nom_cours(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s",type_nommer_nom_cours(piece->type));
    if(piece_etre_animal(piece))
        printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}


piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
    assert(nom_cours!=NULL);
    assert(strlen(nom_cours)==3);

    //Possibilites:
    //
    // - nom vaut "***" -> case vide
    // - nom vaut "RRR" -> rocher
    // - nom commence par "e-" ou "r-"
    //     Alors il s'agit d'un animal.
    //     -> Recuperer le 3eme caractere
    //     -> Le convertir dans l'orientation de l'animal.
    //  - Si aucun des cas precedent, alors affiche erreur.

    piece_siam piece;
    piece_initialiser(&piece);


    if(strncmp(nom_cours,"***",3)==0)
    {
        piece_definir_case_vide(&piece);
    }
    else if(strncmp(nom_cours,"RRR",3)==0)
    {
        piece_definir_rocher(&piece);
    }
    else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
        const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
        const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

        piece_definir(&piece,type,orientation);
    }
    else
    {
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    return piece;

}
