#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <time.h>
#include <windows.h>




#ifndef bibel_H
#define bibel_H
#define b 1024
#ifndef nbrEnregistrement
#define nbrEnregistrement 40000
#endif


#ifndef nbrEnregistrement
#define nbrEnregistrement 40000
#endif

#ifndef nbrSpecialite
#define nbrSpecialite 25
#endif

#ifndef nbrUniversite
#define nbrUniversite 106
#endif
 

///////////////////////////////////////////////////////////////////////////////////////


//// table index de specialite ///////////////////////////////////////////

typedef struct listeMatricule* pointeurListeMatricule;

typedef struct listeMatricule
{
	int matricule;
	pointeurListeMatricule suivant;
}listeMatricule;

typedef struct indexSpecialite
{
	char specialite[100];
	pointeurListeMatricule liste_matricule;		// la tete

}indexSpecialite;

typedef struct tableIndexSpecialite
{
	indexSpecialite tab[nbrSpecialite];
	int nbrElement;			//le nbr de specialité insere
}tableIndexSpecialite;
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
typedef struct i_j* pointeuri_j;

typedef struct i_j
{
	int i;
	int j;
	pointeuri_j suivant;

}i_j;
typedef struct Tbloc
{
    char chaine[b];  // le tableau de caractère
    int suivant;    // le numero du bloc suivant dans la liste
}Tbloc;
typedef struct Tbloc Buffer;
 typedef struct Entete
{
    int tete;
    int queu;
    int premPosLibre;
    int nbCharSupp;
    int nbEnreg;
    int nbBloc;
    int nb_lecture;
    int nb_ecriture;
} Entete;
typedef struct LObarreVC
{
	FILE *fichier;
	Entete entete;
	
}LObarreVC ;


typedef struct index
{
	int cle;
	int i;
	int j;
}index;

typedef struct tableIndex
{    
	int nbrElement;
	index tab[nbrEnregistrement];	
	
}tableIndex;
typedef struct  Enregistrement
{ int matricule;
	char nom[30];
	int dateDeNaissance;
	char wilaya[30];
	char sexe[3];
	char groupeSanguin[5];
	int  dateDeRecrutement;
	char grade[100];
	char specialite[100];
	char DernierDiplome[100];
	char EtablisementUniversitaire[200];	
}Enregistrement;

//////table index etablisement universitaire + la date//////////////////////////////////
typedef struct listeMatriculeDate* pointeurListeMatriculeDate;

typedef struct listeMatriculeDate
{
	int matricule;
	int date;
	pointeurListeMatriculeDate suivant;
}listeMatriculeDate;

typedef struct indexUniversite
{
	char universite[200];
	pointeurListeMatriculeDate liste_matricule_date;		// la tete

}indexUniversite;

typedef struct tableIndexUniversite
{
	indexUniversite tab[nbrUniversite];
	int nbrElement;			//le nbr de specialité insere
}tableIndexUniversite;
typedef struct  ChampEnregistrement
{ 
	
}ChampEnregistrement;

///////////////////////////////////////////////////////////////////////////////////////
 

void requetRegion(tableIndex *region,char *nomfichier);
int aleatoireNbr(int min, int max); 
int aleatoireChaine(char *nom); 
int aleatoireDate(int anneeMin, int anneeMax);
void aleatoireGroupeSanguin(char *groupeSanguin);
void aleatoireWilaya(char *wilaya);	
void aleatoireGrade(char *grade);
void aleatoireDernierDiplome(char *dernierDiplome);
void aleatoireSpecialite(char *specialite);
void aleatoireEtablisementUniversitaire(char *Universite);
Enregistrement*  enregistrement(char *chaine_glob);
void aff_entete(LObarreVC *fichier,int i , int valeur);
int entete(LObarreVC *fichier,int i );
void liredir(LObarreVC *fichier,int NbBloc,Tbloc *buf);
void ecriredir(LObarreVC *fichier,int NbBloc,Tbloc *buf);
int ouvrir(LObarreVC **f,char *chemin,char mode);
void fermer(LObarreVC *fichier);
int alloc_bloc(LObarreVC *fichier);
int annee(int  dateDeRecrutement);
int WilayaEst(char*wilaya);
int WilayaOuest(char *wilaya);
int WilayaCentre(char* wilaya);
void ecrireChaine(int n,char* ch,int* i,int*j,Tbloc *buf,LObarreVC *fichier);
void extraireChaine(int n,int *i,int *j,char* ch,Tbloc *buf,LObarreVC *fichier);
void ChargementInitial( tableIndex *tableau,tableIndexSpecialite *tabSpecialite ,tableIndexUniversite* tabUniversite,tableIndex * tableauEst,tableIndex *tableauOuest,tableIndex* tableauCentre,char* nomfichier);
void Recherche_sequentiel(char* nomfichier,int cle,int *trouv,int*i,int*j);
int rechercheDichotomiqueTableIndexDeCle(tableIndex *tableau,int *trouve,int c,int *i ,int *j);
int insertionTableIndexDeCle(tableIndex *tableau,int nouvelleCle,int ii ,int jj);
void supressionLogique(tableIndex *tableau,int cle,char* nomfichier);
void supressionPhysiqueTableIndex(tableIndex *tableau,int cle);
int rechercheSequencielTableIndexSpecialite(tableIndexSpecialite *tableauSpecialite,char *specialite);
void ajouteMatriculeTableIndexSpecialite(tableIndexSpecialite *tableauSpecialite,char *specialite, int matricule); //ajout un matricule dans la specialite
int rechercheSequencielTableIndexUniversite(tableIndexUniversite *tableauUniversite,char *universite) ;
void ajouteMatriculeTableIndexUniversite(tableIndexUniversite *tableauUniversite,char *universite, int matricule,int date); //ajout un matricule dans la specialite
pointeuri_j insertionListei_j(pointeuri_j tete,int i,int j);
pointeuri_j requetSpecialite(tableIndexSpecialite *tabSpecialite, tableIndex *index,char *specialite);
pointeuri_j requetUniversite(tableIndexUniversite *tableau,tableIndex *index,char *universite,int dateMin, int dateMax);
void affichageBloc(char* nomfichier );
void insertion(tableIndex *index,tableIndexSpecialite *tabSpecialite , tableIndexUniversite *tabUniversite ,tableIndex *tableauEst, tableIndex *tableauOuest,tableIndex* tableauCentre,char* nomfichier,char* chaine);
void affichageElementEntete(char* nomfichier);
void Reorganisation(char* nomfichier,char* nom_nouveaufichier,tableIndex *tableau,tableIndexSpecialite *tabSpecialite ,tableIndexUniversite* tabUniversite,tableIndex * tableauEst,tableIndex *tableauOuest,tableIndex* tableauCentre);
void ecrireIndexSpecialite(char *nomFich,tableIndexSpecialite *tableauSpecialite);
void lireIndexSpecialite(char *nomFich,tableIndexSpecialite *tableauSpecialite);
void ecrireIndexUniversite(char *nomFich,tableIndexUniversite *tableauUniversite);
void lireIndexUniversite(char *nomFich,tableIndexUniversite *tableauUniversite);
void lireIndex(char * nomfichier,tableIndex *index);
void ecrireIndex(char * nomfichier,tableIndex *index);
Enregistrement* decompChamp(char *chaine);
  void supressionLogiqueSpecialite(tableIndexSpecialite *tabSpecialite, tableIndex *index,char * nomfichier );
void ResultatRequeteUniversite(tableIndexUniversite *tableau,tableIndex *index,char *nomfichier);
 void  affichageInformationEnseignant(char*chaine);
void afficherEnseignantIndex(tableIndex* tableau,char* nomfichier);
void suppressionTableIndexSpecialite(tableIndexSpecialite *tabSpecialite,char* specialite,int matricule);
void suppressionTableIndexUniversite(tableIndexUniversite* tabUniversite,char *universite,int matricule );
void creerChaine(Enregistrement*enre,char*e);
 void ChangementEtablisement(int matricule,tableIndex* tableau,tableIndexUniversite *tabUniversite,tableIndexSpecialite *tabSpecialite,tableIndex* tableauEst,tableIndex* tableauOuest,tableIndex* tableauCentre,char *nomfichier);
void ajoutNouvelleEnseignant(tableIndex *index,tableIndexSpecialite *tableauSpecialite , tableIndexUniversite *tableauUniversite ,tableIndex *tableauEst, tableIndex *tableauOuest,tableIndex* tableauCentre,char* nomfichier);
void afficherInfo(int i,int j,char* nomfichier);
void Color(int couleurDuTexte,int couleurDeFond) ;
#endif //bibel_H