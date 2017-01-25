
/*#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"

#include <stdio.h>

void test_type_etre_animal()
{
    puts("Test type_etre_animal");

    if(type_etre_animal(elephant)!=1)
        puts("elephant KO");

    if(type_etre_animal(rhinoceros)!=1)
        puts("rhinoceros KO");

    if(type_etre_animal(rocher)!=0)
        puts("rocher KO");
    if(type_etre_animal(case_vide)!=0)
        puts("case vide KO");

    int k=0;
    for(k=4;k<20;++k)
        if(type_etre_animal(k)!=0)
            printf("valeur %d KO\n",k);

}

void test_lancement()
{
    test_type_etre_animal();
    // puis tous les autres tests a ajouter
    //  de maniere iterative ...
}



int main()
{

    //decommentez la ligne suivante pour lancer les tests
    test_lancement();

    //lancement du mode interactif
    mode_interactif_lancer();

    return 0;
}*/

#include "type_piece.h"
#include <stdio.h>
#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "mode_interactif.h"
#include "api_siam.h"
int main()
{
 /* char u='e';
  type_piece type=rhinoceros;
  piece_siam test;
  test.orientation=0;
  test.type=1;
  const char* nom_du_type=type_nommer(type);
  printf("le type est un %s. \n",nom_du_type);
  
  printf("le type est un  %s. \n",type_nommer(rocher));
  printf("%d\n",type_correspondre_caractere_animal(u));
  printf("%d\n", piece_etre_integre(&test));
  test_piece_etre_integre();
  test_type_etre_animal();
  test_piece_etre_animal();
  test_piece_etre_rocher();
  test_piece_etre_case_vide();*/
  /*coup_jeu coup;
  plateau_siam plateau;
  plateau_initialiser(&plateau);
  piece_siam* p1=plateau_obtenir_piece(&plateau,2,3);
  jeu_siam jeu;
  jeu.plateau=plateau;
  plateau_afficher(&plateau);
  puts(" ");
  p1->type=rocher;
  plateau_afficher(&plateau);
  puts(" ");
  test_coordonnees_etre_bordure_plateau();
  test_jeu_verifier_type_piece_a_modifier();
  test_jeu_obtenir_type_animal_courant();
  jeu_initialiser(&jeu);
  coup=api_siam_tenter_changer_orientation_piece_si_possible(&jeu, 1,1, 1);
  printf("coup valide ? %d\n",coup.valide);
  plateau_afficher(&jeu.plateau);*/
  mode_interactif_lancer();


  return 0;
}
