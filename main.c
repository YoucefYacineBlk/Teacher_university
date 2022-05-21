#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibel.h"
#include <time.h>
#include <windows.h>




int main(int argc, char const *argv[])


{  
printf("TP2 SFSD 2019/2020\n");
printf("TP REALISE PAR :\n");
printf("BELKADI YOUCEF YACINE\n");
printf("KANAAN LOUEIY\n");
printf("G08\n");
 printf("---------------------BIENVENUE AU PROGRAMME-------------------- \n"); 
printf("Ce programme gere les differente procedure realisable sur un fichier d'enseignant \n");
printf("\n");
    Color(10,0);
    Tbloc* buf=malloc(sizeof(Tbloc));
LObarreVC *F=malloc(sizeof(LObarreVC));
    tableIndex tableau;  tableau.nbrElement=0;
    tableIndexSpecialite tabSpecialite  ;  tabSpecialite.nbrElement=0;
    tableIndexUniversite tabUniversite ;  tabUniversite.nbrElement=0;
    tableIndex  tableauEst ;  tableauEst.nbrElement=0;
    tableIndex tableauOuest ;  tableauOuest.nbrElement=0;
    tableIndex tableauCentre ;  tableauCentre.nbrElement=0;
    char nomfichier[30] = "ENSEIGNANT-MESRS.bin";
    int choix;
    srand(time(NULL));
    printf("1: chargement initial automatique                  2 :ancien fichier \n");
    scanf("%d",&choix);
    while (choix > 2)
    { printf("choisir : \n");
        scanf("%d",&choix);}
    if (choix == 1)          // chargement initial
    {
        ChargementInitial(&tableau,&tabSpecialite ,&tabUniversite,&tableauEst,&tableauOuest,&tableauCentre,nomfichier);
    }
    else 
    {
       lireIndexSpecialite("tableIndexSpecialite.bin",&tabSpecialite);
        lireIndexUniversite("tableIndexUniversite.bin",&tabUniversite);
        lireIndex("tableIndex.bin",&tableau);
        lireIndex("tableauEst.bin",&tableauEst);
        lireIndex("tableauOuest.bin",&tableauOuest);
        lireIndex("tableauCentre.bin",&tableauCentre);
    }

 menu:  printf("\n///////////////////////MENU\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("1 : Reorganisation\n2 : Ajouter un nouvel enseignant\n3 : Supprimer un enseignant\n4 : Requete universite");
    printf("\n5 : Supprimer tous les enregistrements relatifs a une specialite donnee\n6 : Afficher les informations d un enseignant");
    printf("\n7 : Consulter tous les enseignants exercant dans une region donnee\n8 : Modifier l\'Etablisement universitaire d un enseignant");
    printf("\n9 : Afficher l\'entete du fichier et nombre de lireDir et ecrireDir\n10 : afficher un bloc");
    printf("\n0: Quitter\n");
    printf("\nchoix : ");
    scanf("%d",&choix);
    while (choix > 10)
    {printf("\nchoix : ");
    scanf("%d",&choix);}

    switch(choix)
    {
        case 0: 
        {  printf("Merci \n");
        ecrireIndexSpecialite("tableIndexSpecialite.bin",&tabSpecialite);
        ecrireIndexUniversite("tableIndexUniversite.bin",&tabUniversite);
        ecrireIndex("tableIndex.bin",&tableau);
        ecrireIndex("tableauEst.bin",&tableauEst);
        ecrireIndex("tableauOuest.bin",&tableauOuest);
        ecrireIndex("tableauCentre.bin",&tableauCentre);

        } exit(EXIT_SUCCESS);

        case 1: 
        Color(15,0);
        {  printf("Reorganisation : \n");
        printf("Veuillez entrer le nouveau fichier : "); 
        tableau.nbrElement=0;
        tabSpecialite.nbrElement=0;
     tabUniversite.nbrElement=0;
     tableauEst.nbrElement=0;
     tableauOuest.nbrElement=0;
      tableauCentre.nbrElement=0;
        char nom_nouveaufichier[50];
        scanf("%s",&nom_nouveaufichier);
         Reorganisation(nomfichier,nom_nouveaufichier,&tableau,&tabSpecialite ,&tabUniversite,&tableauEst,&tableauOuest,&tableauCentre);
         strcpy(nomfichier,nom_nouveaufichier);
        } goto menu;

        case 2: 
        Color(12,0);
        {printf("Ajouter un nouvel enseignant\n");
        ajoutNouvelleEnseignant(&tableau,&tabSpecialite ,&tabUniversite ,&tableauEst,&tableauOuest,&tableauCentre,nomfichier);
        }goto menu;

        case 3: 
        Color(9,0);
        {  printf("Supprimer un enseignant\n");
        printf("Veuillez entrer le matricule de l\'enseignant a Supprimer : ");
        int matriculeSup;
        scanf("%d",&matriculeSup);
        lireIndex("tableIndex.bin",&tableau);
        supressionLogique(&tableau,matriculeSup,nomfichier);
        }goto menu;

       case 4: 
       Color(14,0);
        {  printf("Requete universite\n"); 
           ResultatRequeteUniversite(&tabUniversite,&tableau,nomfichier);
        }goto menu;

        case 5: 
        Color(10,0);
        { printf("Supprimer tous les enregistrements relatifs a une specialite donnee\n");

        supressionLogiqueSpecialite(&tabSpecialite,&tableau,nomfichier);

        }goto menu;

        case 6:
        Color(11,0); 
        {  printf("Afficher les informations d un enseignant\n");
            int matricule,trouve,i,j ;
            char chaineTaille[4]="";
            char chaine[500]="";
            printf("Veuillez entrer le matricule de l\'enseignant que vous voullez afficher ses informations : ");
            scanf("%d",&matricule);
            rechercheDichotomiqueTableIndexDeCle(&tableau,&trouve,matricule,&i ,&j);
            if (trouve == 1)
            {   afficherInfo(i,j,nomfichier);}
            else printf("%s\n","Ce matricule n\'existe pas ou il a ete supprime " );
         }goto menu;

        case 7: 
        Color(13,0);
        {  printf("Consulter tous les enseignants exercant dans une region donnee\n");
        int region;
      region:  printf("1.est  " );  printf("      2.Ouest"); printf("       3.Centre\n");
        printf(" Veuillez choisir l'indice de la region : \n" );
        scanf("%d",&region);
        if (region==1)  requetRegion(&tableauEst,nomfichier);
        else if (region==2)requetRegion(&tableauOuest,nomfichier);
        else if (region==3)  requetRegion(&tableauCentre,nomfichier);
         else
        { printf("entree non valide \n");
         goto region;
            
        }
        
        
        }goto menu;

        case 8: 
        Color(14,0);
        { printf("Modifier l Etablisement universitaire d un enseignant\n"); 
        int matriculeU;
        printf("Veuillez entrer le matricule : "); scanf("%d",&matriculeU);
        ChangementEtablisement(matriculeU,&tableau,&tabUniversite,&tabSpecialite,&tableauEst,&tableauOuest,&tableauCentre,nomfichier);
        }goto menu;

        case 9:
        { Color(15,0);
            printf("Afficher l\'entete du fichier et nombre de lireDir et ecrireDir\n");
            affichageElementEntete(nomfichier);
        }goto menu;

        case 10:
         {  Color(11,0);
            printf("afficher un bloc \n");
            affichageBloc(nomfichier );

         }goto menu;

}




    return 0;
}