#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibel.h"
#include <time.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

int aleatoireNbr(int min, int max)       // renvoi un nbr aleatoire entre [min,max]
{ if (min==max) {return min;}
else if (min<max)
{
return (rand()%(max+1-min)+min);
}
else {return (rand()%(min+1-max)+max);}
 }

//---------------------------------------------------------------------------------------------//

 int aleatoireChaine(char *nom) // nom chaine de caractere aleatoire et return la taille de cette chaine
{    strcpy(nom,"");
char chaine[31]="";
int tailleNom = aleatoireNbr(4,30);


for (int i = 0; i < tailleNom ; ++i)
{
chaine[i]=aleatoireNbr(97,122);
}
strcpy(nom,chaine);
return tailleNom;
}

//-----------------------------------------------------------------------------------------------//

int aleatoireDate(int anneeMin, int anneeMax) // genrer une date du [anneeMin,anneeMax]
{ // de la forme int anneeMoisJour
int anneeMoisJour,jour;
int annee = aleatoireNbr(anneeMin,anneeMax);
int mois = aleatoireNbr(1,12);

if (mois == 2)         // fevrier
{
if ((annee%4 == 0))     // bissextile
  { jour = aleatoireNbr(1,29);}
else {jour = aleatoireNbr(1,28);}
}
else if (mois == 4 || mois == 6 ||mois == 9 ||mois == 11)
{
jour = aleatoireNbr(1,30);
}
else {jour = aleatoireNbr(1,31);}

anneeMoisJour = annee*10000+mois*100+jour;
return anneeMoisJour;

}
//------------------------------------------------------------------------------------------------//

void aleatoireGroupeSanguin(char *groupeSanguin) // retourne GroupeSanguin aleatoire
{
char tabGroupeSanguin[8][4]={"O+","A+","B+","O-","A-","AB+","B-","AB-"};
strcpy(groupeSanguin,tabGroupeSanguin[aleatoireNbr(0,7)]);
}

//------------------------------------------------------------------------------------------------//
void aleatoireWilaya(char *wilaya) // retourne wilaya aleatoire
{
char tabWilaya[58][20]={"Adrar", "Chlef", "Laghouat", "Oum El Bouaghi", "Batna", "Bejaia", "Biskra", "Bechar",
"Blida", "Bouira", "Tamanrasset", "Tebessa", "Tlemcen", "Tiaret", "Tizi Ouzou", "Alger", "Djelfa", "Jijel", "Setif",
 "Saida", "Skikda", "Sidi Bel Abbes", "Annaba", "Guelma", "Constantine", "Medea", "Mostaganem", "M'Sila", "Mascara",
  "Ouargla", "Oran", "El Bayadh", "Illizi", "Bordj Bou Arreridj", "Boumerdes", "El Tarf", "Tindouf", "Tissemsilt",
   "El Oued", "Khenchela", "Souk Ahras", "Tipaza", "Mila", "Ain Defla", "Naama", "Ain Temouchent", "Ghardaia",
    "Relizane", "El M'Ghair", "El Meniaa", "Ouled Djellal", "Bordj Baji Mokhtar", "Beni Abbes", "Timimoun",
    "Touggourt", "Djanet", "In Salah", "In Guezzam"};

strcpy(wilaya,tabWilaya[aleatoireNbr(0,57)]);
}

// -----------------------------------------------------------------------------------------------//

void aleatoireGrade(char *grade)     //renvoie un grade aleatoire
{
char tabGrade[6][30]={"Professeur(e)","Maitre de conferences Rang A","Maitre de conferences Rang B",
"Maitre assistant(e) Rang A","Maitre assistant(e) Rang B","Assistant(e)"};

strcpy(grade,tabGrade[aleatoireNbr(0,5)]);
}

// -----------------------------------------------------------------------------------------------//
void aleatoireDernierDiplome(char *dernierDiplome)
{
   char tabDiplome[5][21]={"Doctorat d Etat","Doctorat en sciences","PhD","HDR","Magister"} ;
   strcpy(dernierDiplome,tabDiplome[aleatoireNbr(0,4)]);
}

//------------------------------------------------------------------------------------------------//
void aleatoireSpecialite(char *specialite)
{
char tabSpecialite[25][30]={"Droit", "Sciences Politiques", "Lettres et langues etrangeres" ,
"Lettres et langue arabe", "Informatique", "Mathematiques", "Chimie", "Physique", "Medecine",
"Pharmacologie", "Biologie", "Sciences Commerciales", "Sciences de Gestion", "Sciences Economiques",
"Electronique", "electrotechnique", "Genie Civil", "Genie des procedes", "Architecture", "Genie mecanique",
"hydraulique", "Sciences Islamiques", "Sciences Humaines", "Sociologie", "Agronomie"};
strcpy(specialite,tabSpecialite[aleatoireNbr(0,24)]);
}

// -----------------------------------------------------------------------------------------------//
void aleatoireEtablisementUniversitaire(char *Universite)
{
char tabUniversite[106][200]= {  "Universite de Bechar - Mohamed Tahri -",
"Universite  de Mascara - Mustapha Stambouli -", "Universite de Saida - Tahar Moulay -",
"Universite  de Tlemcen - Abou Bekr Belkaid -", "Universite  d'Adrar - Ahmed Draya -",
"Universite  de Tiaret - Ibn Khaldoun -", "Universite  Sidi Bel Abbes - Djillali Liabes -",
"Universite de Mostaganem - Abdelhamid Ibn Badis -", "Universite d'Oran1 - Ahmed Ben Bella -",
"Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf d'Oran -",
"Universite  d'Oran 2 - Mohamed Ben Ahmed -", "Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi -",
"Centre Universitaire  de Ain Temouchent - Belhadj Bouchaib -", "Centre universitaire de Relizane - Ahmed Zabana -",
 "Centre universitaire   de Naama - Ahmed Salhi -", "Centre universitaire   d'El Bayadh - Nour Bachir -",
"Centre universitaire de Tindouf-Ali Kafi-","Centre universitaire de Maghnia",
"Annexe de Sougheur (Voir Universite de Tiaret)","Annexe de Ksar Chellala (Voir Universite de Tiaret)",
"Ecole Nationale Polytechnique d'Oran - Maurice Audin -","Ecole  Superieure d'Informatique (Sidi Bel Abbes)-08 Mai 1945",
"Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen","Ecole Superieure d'Economie d'Oran ex EPSECG Oran",
"Ecole Superieure de Management de Tlemcen ex EPSECG Tlemcen","Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran", "Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem", "Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran", "Ecole Normale Superieure de Mostaganem","Ecole Normale Superieure d'Oran", "Ecole normale superieure de Bechar", "Universite  de Bouira - Akli Mohand Oulhadj -", "Universite  de Djelfa - Ziane Achour -", "Universite de Ghardaia", "Universite  de Khemis Miliana - Djilali Bounaama -", "Universite des sciences et de la technologie d'Alger, Houari Boumediene", "Universite  Medea - Yahia Fares -", "Universite de Bejaia - Abderrahmane Mira -", "Universite  de Chlef - Hassiba Benbouali -", "Universite  de Boumerdes - M'hamed Bougara -", "Universite de Tizi Ouzou - Mouloud Maameri -", "Universite de Laghouat - Amar Telidji -", "Universite  Blida 1 - Saad Dahlab -", "Universite de Blida 2 - Lounici Ali -", "Universite d'Alger 1 - Benyoucef Benkhedda -", "Universite d'Alger 2 - Abou el Kacem Saadallah -", "Universite d'Alger 3 - Brahim Soltane Chaibout -", "Universite de la Formation Continue", "Centre universitaire  de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk -", "Centre universitaire  de Tipaza - Abdallah Morsli -", "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar -", "Centre universitaire Aflou", "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger", "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger", "Ecole Nationale Superieure des sciences politiques", "Ecole nationale superieure de journalisme et des sciences de l'information", "Ecole Nationale Superieure de Technologie", "Ecole nationale superieure de management", "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral", "Ecole Superieure de Commerce - Mouloud Kacem Nait Belkacem -", "Ecole nationale superieure en statistique et en economie appliquee", "Ecole nationale superieure d'informatique ( Alger )", "Ecole des hautes etudes commerciales", "Ecole nationale superieure agronomique - Khalef Abdellah alias Kasdi Merbah -", "Ecole Polytechnique d'architecture et d'Urbanisme - Hocine Ait Ahmed -", "Ecole nationale superieure veterinaire - Rabie Bouchama -", "Ecole nationale superieure des travaux publics -  Francis Jeanson -", "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah -", "Ecole Nationale Polytechnique", "Ecole normale superieure de Laghouat - Taleb Abderrahmane -", "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi-", "Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili-", "Ecole preparatoire en sciences economiques commerciales et sciences de gestion , Kolea", "Universite  de Jijel - Mohammed Seddik Ben yahia -", "Universite de Tebessa - Larbi Tebessi -", "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi -", "Universite d'El Tarf - Chadli Bendjedid -", "Universite  de Khenchela - Abbas Laghrour -", "Universite  de Oum El Bouaghi - Larbi Ben M'hidi -", "Universite d'El Oued - Hamma Lakhdar-", "Universite de Souk Ahras - Mohammed-Cherif Messaadia -", "Universite  de Annaba - Badji Mokhtar -", "Universite  du 20 Aout 1955 de Skikda", "Universite  8 Mai 1945 de Guelma", "Universite de Batna 1 - Hadj Lakhder -", "Universite  de Biskra - Mohamed Khider -", "Universite  de M'sila - Mohamed Boudiaf -", "Universite  de Ouargla - Kasdi Merbah -", "Universite des sciences islamiques Emir Abdelkader de Constantine", "Universite  de Setif 1 - Ferhat Abbas -", "Universite  de Setif 2 - Mohamed Lamine Debaghine -", "Universite  de Constantine 2 - Abdelhamid Mehri -", "Universite  de Constantine 1 - Freres Mentouri -", "Universite de Constantine 3 -Salah Boubnider-", "Universite de Batna 2 - Mustapha Ben Boulaid -", "Centre Universitaire de Mila - Abdelhafid Boussouf -", "Centre Universitaire de Barika - Si El Haoues -", "Ecole nationale superieure des mines et de la metallurgie -Amar Laskri-", "Ecole Nationale Polytechnique de Constantine -Malek Bennabi-", "Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar -", "Ecole Superieure des Sciences de Gestion de Annaba ex EPSECG Annaba", "Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba", "Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine", "Ecole normale superieure de Constantine -Assia Djebar -", "Ecole normale superieure d'enseignement technologique de Skikda", "Ecole normale superieure de setif - Messaoud Zeghar -"};


strcpy(Universite,tabUniversite[aleatoireNbr(0,105)]);
}

//-------------------------------------------------------------------------------------------------------//

Enregistrement* enregistrement(char *e)
{    Enregistrement *enre=malloc(sizeof(Enregistrement));
int entier,dateDeNaissance,dateDeRecrutement;
              // char e[1000]="";
char chaine[1000]="";
int matricule=aleatoireNbr(111111,999999);
enre->matricule=matricule;
//printf("%d\n",enre->matricule );
//printf("%d\n", enre->matricule );
ltoa(matricule,chaine,10); // matricule
strcpy(e,chaine);
aleatoireChaine(chaine);
// enre->nom=chaine;
strcpy(enre->nom,chaine);
// printf("%s\n", enre->nom ); //nom/prenom
strcat(e,chaine);
strcat(e,"#");
dateDeNaissance=aleatoireDate(1953,1993);
enre->dateDeNaissance=dateDeNaissance;
//printf("%d\n", enre->dateDeNaissance );
ltoa(dateDeNaissance,chaine,10); // date de naissance
strcat(e,chaine);
strcat(e,"#");
//printf("%s\n",e );
//strcpy(chaine,"");
aleatoireWilaya(chaine);
//printf("%s\n",chaine );
    // enre->wilaya=chaine;
//wilaya
strcpy(enre->wilaya,chaine);

//printf("%s\n", enre->wilaya );
strcat(e,chaine);
//printf("%s\n",e );
strcat(e,"#");
entier=aleatoireNbr(1,2); // sexe
if (entier==1)
{strcpy(chaine,"f"); }
else {strcpy(chaine,"m");}
// enre->sexe=chaine;
strcpy(enre->sexe,chaine);
//printf("%s\n", enre->sexe );
strcat(e,chaine);
strcat(e,"#");

aleatoireGroupeSanguin(chaine); //groupe sanguin              
// enre->groupeSanguin=chaine;
strcpy(enre->groupeSanguin,chaine);
// printf("%s\n",enre->groupeSanguin );
strcat(e,chaine);
strcat(e,"#");

dateDeRecrutement=aleatoireDate(1980,2019);
while (dateDeNaissance>=dateDeRecrutement)
{dateDeRecrutement=aleatoireDate(1980,2019);}
   enre->dateDeRecrutement=dateDeRecrutement;

  // printf("%d\n", enre->dateDeRecrutement );
ltoa(dateDeRecrutement,chaine,10); // date de recrutement
strcat(e,chaine);
strcat(e,"#");

aleatoireGrade(chaine);
     // enre->grade=chaine;
strcpy(enre->grade,chaine);
//printf("%s\n", enre->grade );
strcat(e,chaine);
strcat(e,"#");

aleatoireSpecialite(chaine);
// enre->specialite=chaine;
strcpy(enre->specialite,chaine);
//printf("%s\n", enre->specialite );
strcat(e,chaine);
strcat(e,"#");

aleatoireDernierDiplome(chaine);
// enre->DernierDiplome=chaine;
strcpy(enre->DernierDiplome,chaine);
//printf("%s\n", enre->DernierDiplome );
strcat(e,chaine);
strcat(e,"#");

aleatoireEtablisementUniversitaire(chaine);
// enre->EtablisementUniversitaire=chaine;
strcpy(enre->EtablisementUniversitaire,chaine);
//printf("%s\n", enre->EtablisementUniversiataire );
strcat(e,chaine);
    // printf("%d   %s      %s   \n", enre->matricule,enre->EtablisementUniversiataire, enre->DernierDiplome );
    return enre;
    //ltoa(strlen(e),chaine,10);
   //  strcpy(chaine_glob,chaine);
    // strcat(chaine_glob,"F");
    // strcat(chaine_glob,e);


}
void aff_entete(LObarreVC *fichier,int i , int valeur)
{

    switch(i)
    {
    case 1: {   fichier->entete.tete=valeur;}break;
    case 2: {fichier->entete.queu=valeur;}break;
    case 3: {  fichier->entete.premPosLibre=valeur; }break;
        case 4: {  fichier->entete.nbCharSupp=valeur; }break;    
    case 5: { fichier->entete.nbEnreg=valeur;}break;
    case 6: {  fichier->entete.nbBloc=valeur; }break;
    case 7: {  fichier->entete.nb_lecture=valeur;}break;
    case 8: { fichier->entete.nb_ecriture=valeur;}break;
    };
}
int entete(LObarreVC *fichier,int i )
{
switch(i)
    {
    case 1: {   return (fichier->entete.tete);}break;
    case 2: {return (fichier->entete.queu);}break;
    case 3: {  return (fichier->entete.premPosLibre) ;}break;
    case 4: {  return (fichier->entete.nbCharSupp); }break;
        case 5: {  return (fichier->entete.nbEnreg); }break;
    case 6: { return (fichier->entete.nbBloc);}break;
    case 7: {  return (fichier->entete.nb_lecture);}break;
    case 8: { return (fichier->entete.nb_ecriture);}break;
    };
}
void liredir(LObarreVC *fichier,int NbBloc,Tbloc *buf)
{

fseek(fichier->fichier, sizeof(Entete) + (NbBloc-1) * sizeof(Tbloc),SEEK_SET);
 
 fread(buf,  sizeof(Tbloc),1, fichier->fichier);

 // rewind(fichier->fichier);
 aff_entete(fichier,7,entete(fichier,7)+1);



}
void ecriredir(LObarreVC *fichier,int NbBloc,Tbloc *buf)
{
rewind(fichier->fichier);
fseek(fichier->fichier, sizeof(Entete) + (NbBloc-1) * sizeof(Tbloc),SEEK_SET);
fwrite(buf,sizeof(Tbloc),1,fichier->fichier);
//rewind(fichier->fichier);
aff_entete(fichier,8,entete(fichier,8)+1);
}

int ouvrir(LObarreVC **f,char chemin[20],char mode)
{
    *f = malloc(sizeof(LObarreVC));
    Tbloc *buf=malloc(sizeof(Tbloc));
    char s[3];

    if((mode == 'A') || (mode == 'a')) sprintf(s,"rb+");
    else if ((mode == 'N') || (mode == 'n')) sprintf(s,"wb+");
    else return 0;

    (*f)->fichier = fopen(chemin, s);
    if((*f)->fichier == NULL)   return 0;

    if((mode == 'A') || (mode == 'a'))
    {
        fread(&((*f)->entete), sizeof(Entete), 1, (*f)->fichier);
    }
    else if ((mode == 'N') || (mode == 'n'))
    {
   
    aff_entete(*f,1,1);
        aff_entete(*f,2,1);
        aff_entete(*f,3,0);
        aff_entete(*f,4,0);
        aff_entete(*f,5,0);
        aff_entete(*f,6,1);
        aff_entete(*f,7,0);
        aff_entete(*f,8,0);
        fwrite(&((*f)->entete),sizeof(Entete),1,(*f)->fichier);
        liredir(*f,1,buf);
         buf->suivant=-1;
         sprintf(buf->chaine,"%s","");
         ecriredir(*f,1,buf);
    }
    return 1;
   

}
void fermer(LObarreVC *fichier)
{
    //Sauvegarde de l'entete
    rewind(fichier->fichier);
   
    fwrite(&(fichier->entete), sizeof(Entete), 1, fichier->fichier);
   
    fclose(fichier->fichier);
    free(fichier);
}                                                    
int alloc_bloc(LObarreVC *fichier)
{  
    Tbloc* buf = malloc(sizeof(Tbloc));            
    liredir(fichier,entete(fichier,2),buf);
    buf->suivant = entete(fichier,6)+1;
    ecriredir(fichier,entete(fichier,2),buf);
    aff_entete(fichier,2,entete(fichier,2)+1);
    buf->suivant = -1;
    sprintf(buf->chaine,"%s","");
    ecriredir(fichier,entete(fichier,2),buf);
    aff_entete(fichier,6,entete(fichier,6)+1);
    return entete(fichier,2);
}
void ecrireChaine(int n,char* ch,int* i,int*j,Tbloc *buf,LObarreVC *fichier)

{
for (int k = 0; k < n; ++k)
{
if ((*j)<b)
{
buf->chaine[*j]=ch[k];
(*j)++;
}
else
{
ecriredir(fichier,*i,buf);
(*i)=alloc_bloc(fichier);

for (int i = 0; i < b; ++i)
{
buf->chaine[i]='\0';
}


buf->chaine[0]=ch[k];
(*j)=1;
}
}

}
void  extraireChaine(int n,int *i,int *j,char* ch,Tbloc *buf,LObarreVC *fichier)
{
for (int k = 0; k < n; ++k)
{
if ((*j)<b)
{  
           ch[k]=buf->chaine[(*j)];
           (*j)++;

}
else
{    
(*i)=buf->suivant;
             
liredir(fichier,(*i),buf);

ch[k]=buf->chaine[0];
(*j)=1;
}
}
}
int annee(int  dateDeRecrutement)
{
return dateDeRecrutement/10000;
}
int WilayaEst(char*wilaya)
{  char  est[100][200]={"Universite  de Jijel - Mohammed Seddik Ben yahia -",
"Universite  du 20 Aout 1955 de Skikda", "Universite  8 Mai 1945 de Guelma",
"Universite de Batna 1 - Hadj Lakhder -","Universite  de Biskra - Mohamed Khider -",
                "Universite des sciences islamiques Emir Abdelkader de Constantine",
"Universite  de Setif 1 - Ferhat Abbas -", "Universite  de Setif 2 - Mohamed Lamine Debaghine -","Universite  de Constantine 2 - Abdelhamid Mehri -",
"Universite  de Constantine 1 - Freres Mentouri -", "Universite de Constantine 3 -Salah Boubnider-", "Universite de Batna 2 - Mustapha Ben Boulaid -",
 "Ecole Nationale Polytechnique de Constantine -Malek Bennabi-","Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar -",
"Ecole Superieure des Sciences de Gestion de Annaba ex EPSECG Annaba","Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba",
"Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine",
"Ecole normale superieure de Constantine -Assia Djebar -",
                "Ecole normale superieure d'enseignement technologique de Skikda",
                      "Ecole normale superieure de setif - Messaoud Zeghar -","Ecole nationale superieure en statistique et en economie appliquee",
         "Ecole des hautes etudes commerciales",
        "Ecole nationale superieure agronomique - Khalef Abdellah alias Kasdi Merbah -",
        "Ecole Polytechnique d'architecture et d'Urbanisme - Hocine Ait Ahmed -",
        "Ecole nationale superieure veterinaire - Rabie Bouchama -",
       
         "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah -",
          "Ecole normale superieure de Laghouat - Taleb Abderrahmane -", "Universite de Tizi Ouzou - Mouloud Maameri -",
   "Universite de Laghouat - Amar Telidji -",

    "Centre universitaire  de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk -",
    "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar -", "Centre universitaire Aflou",
     
   
     "Ecole nationale superieure de journalisme et des sciences de l'information",
      "Ecole Nationale Superieure de Technologie", "Ecole nationale superieure de management",
      "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral",
       "Ecole Superieure de Commerce - Mouloud Kacem Nait Belkacem -" };

int trouv=0;
int i=0;
while((trouv==0)&&(i!=27))
{

if (strcmp(wilaya,est[i])==0)
{
trouv=1;
}
else i++;
}



return trouv;
}
int WilayaOuest(char *wilaya)
{   char ouest[100][200]={"Universite de Bechar - Mohamed Tahri -","Universite  de Mascara - Mustapha Stambouli -",
"Universite de Saida - Tahar Moulay -","Universite  de Tlemcen - Abou Bekr Belkaid -","Universite  d'Adrar - Ahmed Draya -",
"Universite  de Tiaret - Ibn Khaldoun -","Universite  Sidi Bel Abbes - Djillali Liabes -","Universite de Mostaganem - Abdelhamid Ibn Badis -",
"Universite d'Oran1 - Ahmed Ben Bella -","Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf d'Oran -",
"Universite  d'Oran 2 - Mohamed Ben Ahmed -","Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi -",
"Centre Universitaire de Ain Temouchent - Belhadj Bouchaib -","Centre universitaire de Relizane - Ahmed Zabana -",
"Centre universitaire de Naama - Ahmed Salhi -","Centre universitaire de Tindouf-Ali Kafi-",
"Ecole  Superieure d'Informatique (Sidi Bel Abbes)-08 Mai 1945","Ecole Nationale Polytechnique d'Oran - Maurice Audin -",
"Ecole Superieure de Management de Tlemcen ex EPSECG Tlemcen","Ecole Superieure d'Economie d'Oran ex EPSECG Oran",
"Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen","Centre universitaire de Maghnia",
"Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran",
"Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran","Centre universitaire   d'El Bayadh - Nour Bachir -",
"Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem",
"Ecole Normale Superieure de Mostaganem","Ecole Normale Superieure d'Oran",
"Ecole normale superieure de Bechar","Annexe de Sougheur (Voir Universite de Tiaret)","Annexe de Ksar Chellala (Voir Universite de Tiaret)",
   "Universite  de Bouira - Akli Mohand Oulhadj -",  "Universite  de Djelfa - Ziane Achour -", "Universite de Ghardaia",
  "Universite  de Khemis Miliana - Djilali Bounaama -", "Universite  Medea - Yahia Fares -",
  "Universite de Bejaia - Abderrahmane Mira -"};
int trouv=0;
int i=0;
while((trouv==0)&&(i!=17))
{

if (strcmp(wilaya,ouest[i])==0)
{
trouv=1;
}
else i++;
}



return trouv;

}
int WilayaCentre(char* wilaya)
{   char centre[100][200]={ "Universite  Blida 1 - Saad Dahlab -",
   "Universite de Blida 2 - Lounici Ali -", "Universite d'Alger 1 - Benyoucef Benkhedda -",
    "Universite d'Alger 2 - Abou el Kacem Saadallah -", "Universite d'Alger 3 - Brahim Soltane Chaibout -", "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger",
"Ecole nationale superieure d'informatique ( Alger )",
"Ecole nationale superieure des travaux publics -  Francis Jeanson -",
"Ecole Nationale Polytechnique","Universite des sciences et de la technologie d'Alger, Houari Boumediene",
"Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi-","Universite  de Chlef - Hassiba Benbouali -",
"Universite  de Boumerdes - M'hamed Bougara -",
"Universite de la Formation Continue", "Centre universitaire  de Tipaza - Abdallah Morsli -",
  "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger",
     "Ecole Nationale Superieure des sciences politiques",  "Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili-",
           "Ecole preparatoire en sciences economiques commerciales et sciences de gestion , Kolea",
            "Universite de Tebessa - Larbi Tebessi -",
            "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi -",
             "Universite d'El Tarf - Chadli Bendjedid -", "Universite  de Khenchela - Abbas Laghrour -",
              "Universite  de Oum El Bouaghi - Larbi Ben M'hidi -", "Universite d'El Oued - Hamma Lakhdar-",
              "Universite de Souk Ahras - Mohammed-Cherif Messaadia -", "Universite  de Annaba - Badji Mokhtar -",
               
                         "Universite  de M'sila - Mohamed Boudiaf -", "Universite  de Ouargla - Kasdi Merbah -",
                                                 
                   "Centre Universitaire de Mila - Abdelhafid Boussouf -", "Centre Universitaire de Barika - Si El Haoues -",
                   "Ecole nationale superieure des mines et de la metallurgie -Amar Laskri-"};
int trouv=0;
int i=0;
while((trouv==0)&&(i!=14))
{

if (strcmp(wilaya,centre[i])==0)
{
trouv=1;
}
else i++;
}



return trouv;
}

void ChargementInitial( tableIndex *tableau,tableIndexSpecialite *tabSpecialite ,tableIndexUniversite* tabUniversite,tableIndex * tableauEst,tableIndex *tableauOuest,tableIndex* tableauCentre,char* nomfichier)
{
int i,j;
LObarreVC *fichier=NULL;
Tbloc* buf = malloc(sizeof(Tbloc));
Enregistrement *enregi=malloc(sizeof(Enregistrement));


if (ouvrir(  &fichier,nomfichier , 'n')==1)
{  int nb;
   char  eff[1]="F";
    char taille[3]="";
int cle_index=0;
int j2=0;
int i2=0;
      printf("Veuillez introduire le nombre d’Enseignant  que vous voulez charger dans le fichier \n");
   
    scanf("%d",&nb);
   
    i=entete(fichier,2);
       j=entete(fichier,3);
       char chaine[1000]="";
       int ind;
      liredir(fichier,i,buf);
      for (int k = 0; k < nb; ++k)
          {     strcpy(chaine,"");
                strcpy(taille,"");
                 int trouve=0;
                 int annee2;
                    enregi=enregistrement(chaine);
                    int annee3=enregi->dateDeRecrutement;
                   
                    annee2=annee(annee3);
                   
                    ind=rechercheDichotomiqueTableIndexDeCle(tableau,&trouve, enregi->matricule, &i2 ,&j2);
                    if (trouve==0)
                    {
                   
        insertionTableIndexDeCle(tableau, enregi->matricule, i , j);
           if (WilayaEst(enregi->EtablisementUniversitaire)==1)
           {  
           
            insertionTableIndexDeCle(tableauEst, enregi->matricule, i , j);
           }
            if (WilayaOuest(enregi->EtablisementUniversitaire)==1)
           {
            insertionTableIndexDeCle(tableauOuest, enregi->matricule, i , j);
           }
           if (WilayaCentre(enregi->EtablisementUniversitaire)==1)
           {
            insertionTableIndexDeCle(tableauCentre, enregi->matricule, i , j);
           }
           
        ajouteMatriculeTableIndexSpecialite(tabSpecialite,enregi->specialite, enregi->matricule);
        ajouteMatriculeTableIndexUniversite(tabUniversite,enregi->EtablisementUniversitaire, enregi->matricule,annee2);
        ltoa(strlen(chaine),taille,10);
    ecrireChaine(3,taille,&i,&j,buf,fichier);
    ecrireChaine(1,"F",&i,&j,buf,fichier);
    ecrireChaine(strlen(chaine),chaine,&i,&j,buf,fichier);
             
              aff_entete(fichier,5,entete(fichier,5)+1);
    }  
          }
          ecriredir(fichier,i,buf);
         
          aff_entete(fichier,3,j);
          fermer(fichier);
}
else printf("le fichier ne s'est pas ouvert correctement\n");
}
void   Recherche_sequentiel(char* nomfichier,int cle,int *trouv,int*i,int*j)
{
LObarreVC *F=NULL;
Tbloc* buf = malloc(sizeof(Tbloc));

char taille[10]="";
char cle_ex[10]="";
char eff[1]="";
char cle_[10]="";
ltoa(cle,cle_,10);

if (ouvrir(&F,nomfichier,'a')==1)
{  
(*i)=entete(F,1);
(*j)=0;
(*trouv)=0;
liredir(F,*i,buf);

  while(((*i!= entete(F,2)) || ((*i==entete(F,2)) && (*j<entete(F,3)))) && (*trouv==0))
  {
 
                strcpy(taille,"");
                strcpy(eff,"");
                strcpy(cle_ex,"");
  extraireChaine(3,i,j,taille,buf,F);
 
  extraireChaine(1,i,j,eff,buf,F);
 
  extraireChaine(6,i,j,cle_ex,buf,F);
  if ((atoi(cle_ex)==cle)&& (eff[0]=='F'))
  {
       (*trouv)=1;

  }
  else {
  (*j)+=atoi(taille)-6;
  if ((*j)>=b)
  {
  (*j)-=b;  *i=buf->suivant;
  liredir(F,*i,buf);
  }
  }


  }
}

else printf("le fichier n est pas ouvert correctement\n");

}
int rechercheDichotomiqueTableIndexDeCle(tableIndex *tableau,int *trouve,int c,int *i ,int *j)
{ if (tableau->nbrElement == 0)
{ *trouve=0;
return 0;
}
else{
int sup,inf,indice;
inf=0; sup=tableau->nbrElement-1;
*trouve=0;
while ((inf<=sup) && (*trouve == 0) )
{
indice = (sup+inf)/2;
if (c == tableau->tab[indice].cle)
{
*trouve=1;
*i = tableau->tab[indice].i;
*j = tableau->tab[indice].j;
return indice;
}
else if (c < tableau->tab[indice].cle) sup = indice - 1;
else inf = indice + 1;

}
if (trouve == 0)
{
return inf;
}
}


}

int insertionTableIndexDeCle(tableIndex *tableau,int nouvelleCle,int ii ,int jj)
{ int trouve = 0;

int indice = rechercheDichotomiqueTableIndexDeCle(tableau,&trouve,nouvelleCle,&ii ,&jj);
if (trouve == 0){
if (indice < tableau->nbrElement ){
int k = tableau->nbrElement;
int j = k-1;
if (k != 0){
while (j != indice)
{
tableau->tab[k] = tableau->tab[j];
j--; k--;
}
tableau->tab[k] = tableau->tab[j];
}}
tableau->tab[indice].cle = nouvelleCle;
tableau->tab[indice].i = ii;
tableau->tab[indice].j = jj;
tableau->nbrElement=tableau->nbrElement+1;

}
return trouve;
}

void supressionPhysiqueTableIndex(tableIndex *tableau,int cle)
{
int trouve,i,j;
int indice = rechercheDichotomiqueTableIndexDeCle(tableau,&trouve,cle,&i ,&j);
if (trouve == 1)
{
j = indice;
i = j + 1;
if (i <= tableau->nbrElement)
{
while (j != tableau->nbrElement)
{
tableau->tab[j] = tableau->tab[i];
j++; i++;
}
// tableau->tab[j] = tableau->tab[i];
}
tableau->nbrElement=tableau->nbrElement-1;
}

}

void supressionLogique(tableIndex *tableau,int cle,char* nomfichier)
{
int trouve,i,j,i2,j2;
char taille[4]="";
Tbloc* buf=malloc(sizeof(Tbloc));
int indice = rechercheDichotomiqueTableIndexDeCle(tableau,&trouve,cle,&i ,&j);
if (trouve == 1)
{  
LObarreVC *F=malloc(sizeof(LObarreVC));
if (ouvrir(&F,nomfichier,'a')==1)
 
{   liredir(F,i,buf);
extraireChaine(3,&i,&j,taille,buf,F);
buf->chaine[j]='V';
ecriredir(F,i,buf);
aff_entete(F,4,entete(F,4)+1);

}
fermer(F);

j2 = indice;
i2 = j2 + 1;
if (i2 <= tableau->nbrElement)
{
while (j2 != tableau->nbrElement)
{
tableau->tab[j2] = tableau->tab[i2];
j2++; i2++;
}
}
tableau->nbrElement=tableau->nbrElement-1;
}
else printf("le matricle n\'existe pas \n");

}



int rechercheSequencielTableIndexSpecialite(tableIndexSpecialite *tableauSpecialite,char *specialite)
{ int i=0;

if (tableauSpecialite->nbrElement != 0){

while((i != tableauSpecialite->nbrElement) && (strcmp(specialite,tableauSpecialite->tab[i].specialite) != 0))
{  
i++;

}
if (strcmp(specialite,tableauSpecialite->tab[i].specialite) == 0) return i;
else return aleatoireNbr(-10,-1);}
else return -1;
}
///////////////////////////////////////////////////////////////////////////////////////
void ajouteMatriculeTableIndexSpecialite(tableIndexSpecialite *tableauSpecialite,char *specialite, int matricule) //ajout un matricule dans la specialite
{ pointeurListeMatricule p=NULL;
int i=rechercheSequencielTableIndexSpecialite(tableauSpecialite,specialite);
if (i>=0) //la specialite existe
{
//recherche du matricule dans le champs specialite
p = tableauSpecialite->tab[i].liste_matricule;
if (p==NULL)
{
pointeurListeMatricule q1 = malloc(sizeof(listeMatricule));
if (q1 == NULL)
exit(EXIT_FAILURE);
q1->suivant=NULL;  q1->matricule=matricule;p=q1;
}
while ((p->suivant != NULL) && (p->matricule != matricule ))
{
p=p->suivant;
}
if (p->matricule != matricule) //inserstion du matricule a la fin de la liste des matricules
{
pointeurListeMatricule q = malloc(sizeof(q));
if (q == NULL)
exit(EXIT_FAILURE);
q->suivant=NULL; p->suivant=q; q->matricule=matricule;
}
}
else //la specialite n'existe pas
{  
strcpy(tableauSpecialite->tab[tableauSpecialite->nbrElement].specialite,specialite);
p = malloc(sizeof(p));
p->matricule = matricule;
tableauSpecialite->tab[tableauSpecialite->nbrElement].liste_matricule = p;

tableauSpecialite->nbrElement+=1;
p->suivant=NULL;

}
}
void suppressionTableIndexSpecialite(tableIndexSpecialite *tabSpecialite,char* specialite,int matricule)
{
int indice = rechercheSequencielTableIndexSpecialite(tabSpecialite,specialite);
int i,j,trouve;
int stop=0;
pointeuri_j tete = NULL;
if (indice>=0) // specialite existe
{
pointeurListeMatricule p = tabSpecialite->tab[indice].liste_matricule;
pointeurListeMatricule pere = NULL;
while((p!=NULL)&&(stop==0))
{    
if (p->matricule=matricule)
{
if (p == tabSpecialite->tab[indice].liste_matricule)
{  
tabSpecialite->tab[indice].liste_matricule = p->suivant;
free(p);

p =  tabSpecialite->tab[indice].liste_matricule;

stop=1;
}
else
{
pere->suivant=p->suivant;
free(p);
p = pere;
stop=1;
}
}
else {
pere=p;
p=p->suivant;}

}
}}
void suppressionTableIndexUniversite(tableIndexUniversite* tabUniversite,char *universite,int matricule )
{
int indice = rechercheSequencielTableIndexUniversite(tabUniversite,universite);

int i,j,trouve;
int stop=0;
pointeuri_j tete = NULL;
if (indice>=0) // universite existe
{  
pointeurListeMatriculeDate p = tabUniversite->tab[indice].liste_matricule_date;
pointeurListeMatriculeDate pere = NULL;
while((p!=NULL)&&(stop==0))
{ if (p->matricule=matricule)
{


if (p == tabUniversite->tab[indice].liste_matricule_date)
{
tabUniversite->tab[indice].liste_matricule_date = p->suivant;
free(p);
p =  tabUniversite->tab[indice].liste_matricule_date;
stop=1;
}
else
{
pere->suivant=p->suivant;
free(p);
p = pere;
stop=1;
}}
else {
pere = p;
p=p->suivant;}}


}}
////////////////////////////////////////////////////////////////////////////////////////



int rechercheSequencielTableIndexUniversite(tableIndexUniversite *tableauUniversite,char *universite)
{ int i=0;

if (tableauUniversite->nbrElement != 0){


while((i != tableauUniversite->nbrElement) && (strcmp(universite,tableauUniversite->tab[i].universite) != 0))
{
i++;

}
if (strcmp(universite,tableauUniversite->tab[i].universite) == 0) return i;
else return -1;}
else return -1;
}
///////////////////////////////////////////////////////////////////////////////////////
void ajouteMatriculeTableIndexUniversite(tableIndexUniversite *tableauUniversite,char *universite, int matricule,int date) //ajout un matricule dans la specialite
{ pointeurListeMatriculeDate p=malloc(sizeof(listeMatriculeDate));
int i=rechercheSequencielTableIndexUniversite(tableauUniversite,universite);

if (i>=0) //l'universite existe
{  
//recherche du matricule dans le champs universite
p = tableauUniversite->tab[i].liste_matricule_date;
if (p==NULL)
{
           pointeurListeMatriculeDate q1 = malloc(sizeof(listeMatriculeDate));
if (q1 == NULL)
exit(EXIT_FAILURE);

q1->suivant=NULL;  q1->matricule=matricule; q1->date = date;
p=q1;
}
while ((p->suivant != NULL) && (p->matricule != matricule ))
{
p=p->suivant;
}
if (p->matricule != matricule) //inserstion du matricule a la fin de la liste des matricules
{
pointeurListeMatriculeDate q = malloc(sizeof(listeMatriculeDate));
if (q == NULL)
exit(EXIT_FAILURE);

q->suivant=NULL; p->suivant=q; q->matricule=matricule; q->date = date;

}
}
else //l'universite n'existe pas
{  
strcpy(tableauUniversite->tab[tableauUniversite->nbrElement].universite,universite);
//p = malloc(sizeof(p));
p->matricule = matricule; p->date = date;
tableauUniversite->tab[tableauUniversite->nbrElement].liste_matricule_date = p;

tableauUniversite->nbrElement+=1;
p->suivant=NULL;

}
}

////////////////////////////////////////////////////////////////////////////////////////
pointeuri_j insertionListei_j(pointeuri_j tete,int i,int j)
{
if (tete == NULL) //liste vide
{
tete = malloc(sizeof(i_j));
tete->i=i;
tete->j=j;
tete->suivant = NULL;
return tete;
}
else // liste non vide
{ pointeuri_j p = tete;
pointeuri_j pere = NULL;
while ((p->suivant != NULL) && (p->i < i))
{
pere = p;
p = p->suivant;
}
if (p->i > i)
{
if (pere == NULL)
{
pointeuri_j q = malloc(sizeof(i_j));
q->i=i;
q->j=j; q->suivant = tete;
tete = q;
}
else{
pointeuri_j q = malloc(sizeof(i_j));
q->i=i;
q->j=j; q->suivant = p;
pere->suivant = q;}
}
else
{
pointeuri_j q = malloc(sizeof(i_j));
q->i=i;
q->j=j; q->suivant = p->suivant;
p->suivant = q;
} return tete;
}
}
////////////////////////////////////////////////////////////////////////////////////////
pointeuri_j requetSpecialite(tableIndexSpecialite *tabSpecialite, tableIndex *index,char *specialite)
{
int indice = rechercheSequencielTableIndexSpecialite(tabSpecialite,specialite);
int i,j,trouve;
pointeuri_j tete = NULL;
if (indice>=0) // specialite existe
{
pointeurListeMatricule p = tabSpecialite->tab[indice].liste_matricule;
pointeurListeMatricule pere = NULL;
while (p != NULL)
{
// recherche du matricule dans la table index
rechercheDichotomiqueTableIndexDeCle(index,&trouve,p->matricule,&i ,&j);
if (trouve == 1) // le matricule existe (il n'est pas effacer)
{
// insertion de i et j dans table i_j

tete = insertionListei_j (tete,i,j);
}
else // le matricule a ete affacer donc il faut le supprimer
{ // suppression du maillon p
if (p == tabSpecialite->tab[indice].liste_matricule)
{
tabSpecialite->tab[indice].liste_matricule = p->suivant;
free(p);
p =  tabSpecialite->tab[indice].liste_matricule;
}
else
{
pere->suivant=p->suivant;
free(p);
p = pere;
}
}
pere = p;
p=p->suivant;
}
}
return tete;
}
////////////////////////////////////////////////////////////////////////////////////////
pointeuri_j requetUniversite(tableIndexUniversite *tableau,tableIndex *index,char *universite,int dateMin, int dateMax)
{  
int indice = rechercheSequencielTableIndexUniversite(tableau,universite);

int i,j,trouve;
pointeuri_j tete = NULL;
if (indice>=0) // universite existe
{  
pointeurListeMatriculeDate p = tableau->tab[indice].liste_matricule_date;
pointeurListeMatriculeDate pere = NULL;
if (p==NULL)
{
 printf("aucun element ne correspond\n");
}

while (p != NULL)
{
if ((p->date >= dateMin) && (p->date <= dateMax)) { // date appartient à l'intervale
// recherche du matricule dans la table index
rechercheDichotomiqueTableIndexDeCle(index,&trouve,p->matricule,&i ,&j);
if (trouve == 1) // le matricule existe (il n'est pas effacer)
{
               
// insertion de i et j dans table i_j

tete = insertionListei_j (tete,i,j);
}
else // le matricule a ete affacer donc il faut le supprimer
{ // suppression du maillon p
if (p == tableau->tab[indice].liste_matricule_date)
{
tableau->tab[indice].liste_matricule_date = p->suivant;
free(p);
p =  tableau->tab[indice].liste_matricule_date;
}
else
{
pere->suivant=p->suivant;
free(p);
p = pere;
}
}}
pere = p;
p=p->suivant;
}
}

return tete;

}
void affichageBloc(char* nomfichier )
{   LObarreVC *F=malloc(sizeof(LObarreVC));
	Tbloc* buf=malloc(sizeof(Tbloc));
	ouvrir(&F,nomfichier,'a');
	int choix;
   saisie: printf("entrer le numero du bloc a afficher :\n");
	scanf("%d",&choix);
	if (choix>entete(F,2))
	{
		printf("entree superieure au numero du dernier bloc \n" );
		goto saisie;
	}
	liredir(F,choix,buf);

	printf("\n   -----------------------------le contenu du %d bloc --------------------------------\n",choix);
	for (int j = 0; j < b; ++j)
	{
         
		printf("%c|",buf->chaine[j] );
		if ((j%50==49)&&(j!=0))
		{
			printf("\n");
		}
	}
	fermer(F);
}


void insertion(tableIndex *index,tableIndexSpecialite *tabSpecialite , tableIndexUniversite *tabUniversite ,tableIndex *tableauEst, tableIndex *tableauOuest,tableIndex* tableauCentre,char* nomfichier,char* chaine)
{   LObarreVC *F=malloc(sizeof(LObarreVC));
Enregistrement *enregi=malloc(sizeof(Enregistrement));
int trouve=0;
int i=0,j=0;
Tbloc *buf=malloc(sizeof(Tbloc));
enregi=decompChamp(chaine);
    int cle=enregi->matricule;
char chainelongueur[3]="";
rechercheDichotomiqueTableIndexDeCle(index,&trouve,cle,&i ,&j);
if (trouve==0)
{    
ouvrir(&F,nomfichier,'a');
int z=0;
int y=0;

z=entete(F,2);
y=entete(F,3);
int annee2=annee(enregi->dateDeRecrutement);

insertionTableIndexDeCle(index, enregi->matricule, z , y);
if (WilayaEst(enregi->EtablisementUniversitaire)==1)
           {  
           
            insertionTableIndexDeCle(tableauEst, enregi->matricule, i , j);
           }
           else{ if (WilayaOuest(enregi->EtablisementUniversitaire)==1)
           {
            insertionTableIndexDeCle(tableauOuest, enregi->matricule, i , j);
           }
           else
           {
            insertionTableIndexDeCle(tableauCentre, enregi->matricule, i , j);
           }}

ajouteMatriculeTableIndexSpecialite(tabSpecialite,enregi->specialite, enregi->matricule);
 ajouteMatriculeTableIndexUniversite(tabUniversite,enregi->EtablisementUniversitaire, enregi->matricule,annee2);
 
         
liredir(F,z,buf);
      ltoa(strlen(chaine),chainelongueur,10);
     
      ecrireChaine(3,chainelongueur,&z,&y,buf,F);

      ecrireChaine(1,"F",&z,&y,buf,F);
    ecrireChaine(strlen(chaine),chaine,&z,&y,buf,F);
    aff_entete(F,5,entete(F,5)+1);
   
ecriredir(F,z,buf);
if (z!=entete(F,2))
{
aff_entete(F,2,z);}
         
          aff_entete(F,3,y);
fermer(F);


}

}
void affichageElementEntete(char* nomfichier)
{   LObarreVC *F=malloc(sizeof(LObarreVC));

ouvrir(&F,nomfichier,'a');
printf("\nL\'indice du premier bloc %d  \n",entete(F,1));
printf(" l\'indice du dernier bloc est %d\n", entete(F,2));
printf(" la premiere position libre  est %d\n",entete(F,3));
printf(" le nombre de caractere suprimes logiquement %d\n",entete(F,4) );
printf(" le nombre d\'enregistrement total %d\n",entete(F,5) );
printf("le nombre de bloc %d\n",entete(F,6) );
printf(" le nombre de lecture %d\n",entete(F,7) );
printf("le nombre d\'ecriture   %d\n",entete(F,8));
fermer(F);

}
void Reorganisation(char* nomfichier,char* nom_nouveaufichier,tableIndex *tableau,tableIndexSpecialite *tabSpecialite ,tableIndexUniversite* tabUniversite,tableIndex * tableauEst,tableIndex *tableauOuest,tableIndex* tableauCentre)
{
Tbloc* buf1=malloc(sizeof(Tbloc));
Tbloc* buf2=malloc(sizeof(Tbloc));
LObarreVC *F=malloc(sizeof(LObarreVC));
LObarreVC *F1=malloc(sizeof(LObarreVC));

// LObarreVC *F=malloc(sizeof(LObarreVC));
int i1=0,i2=0,j1=0,j2=0;
if (ouvrir(&F,nomfichier,'a')==1)
{  

ouvrir(&F1,nom_nouveaufichier,'n');
        i1=entete(F,1);
        i2=1;
        liredir(F,i1,buf1);
        Enregistrement *enregi=malloc(sizeof(Enregistrement));
        //liredir(F1,i2,buf2);

        while (((i1!= entete(F,2)) || ((i1==entete(F,2)) && (j1<entete(F,3)))))
        {     char chainelongueur[4]="";
        char supp[2]="";
        char chaine[500]="";
       
        extraireChaine(3,&i1,&j1,chainelongueur,buf1,F);
        extraireChaine(1,&i1,&j1,supp,buf1,F);
        extraireChaine(atoi(chainelongueur),&i1,&j1,chaine,buf1,F);
       
       
       

        if (supp[0]=='F')
        {  
                 
                 enregi=decompChamp(chaine);
                 insertionTableIndexDeCle(tableau, enregi->matricule, i2 , j2);
           if (WilayaEst(enregi->EtablisementUniversitaire)==1)
           {  
           
            insertionTableIndexDeCle(tableauEst, enregi->matricule, i2 , j2);
           }
            if (WilayaOuest(enregi->EtablisementUniversitaire)==1)
           {
            insertionTableIndexDeCle(tableauOuest, enregi->matricule, i2 , j2);
           }
           if (WilayaCentre(enregi->EtablisementUniversitaire)==1)
           {
            insertionTableIndexDeCle(tableauCentre, enregi->matricule, i2 , j2);
           }
           
        ajouteMatriculeTableIndexSpecialite(tabSpecialite,enregi->specialite, enregi->matricule);
        ajouteMatriculeTableIndexUniversite(tabUniversite,enregi->EtablisementUniversitaire, enregi->matricule,annee(enregi->dateDeRecrutement));
       
        ecrireChaine(3, chainelongueur,&i2,&j2,buf2,F1);
        ecrireChaine(1,supp,&i2,&j2,buf2,F1);
        ecrireChaine(atoi(chainelongueur),chaine,&i2,&j2,buf2,F1);
       
        aff_entete(F1,5,entete(F1,5)+1);
       
       
        }
        else
        {  
         // aff_entete(F,4,entete(F,4)-1);
        //(j1)+=atoi(chainelongueur);
  if ((j1)>=b)
  {
  (j1)-=b;  i1=buf1->suivant;
  liredir(F,i1,buf1);
 
  }
        }
        }
         ecriredir(F1,i2,buf2);
        aff_entete(F1,3,j2);
        if (i2!=entete(F1,2))
        {
        aff_entete(F1,2,i2);
        }
        fermer(F1);
        fermer(F);

}
}

////////////////////////////////////////////////////////////////////////////////////////
void ecrireIndexSpecialite(char *nomFich,tableIndexSpecialite *tableauSpecialite)
{
FILE *fich = fopen(nomFich,"wb+");
char chaine[100];
pointeurListeMatricule p=NULL;
int separateur = 0;

if (fich == NULL)
{
fprintf(stderr, "Erreur ouverture fichier index specialite\n" );
exit(EXIT_FAILURE);
}
fwrite(&tableauSpecialite->nbrElement,sizeof(int), 1,fich);
for (int i = 0; i < tableauSpecialite->nbrElement; ++i)
{
fwrite(&tableauSpecialite->tab[i].specialite, sizeof(char[100]), 1,fich);  // la specialite
// inserer la liste des matricules
p = tableauSpecialite->tab[i].liste_matricule;
while (p != NULL)
{
fwrite(&p->matricule,sizeof(int), 1,fich);
p = p->suivant;
}
fwrite(&separateur, sizeof(int), 1,fich);
}
// fwrite(&laDonne, sizeof(le type de la donne), 1,fich);

fclose(fich);
}

/////////////////////////////////////////////////////////////////
void lireIndexSpecialite(char *nomFich,tableIndexSpecialite *tableauSpecialite)
{
FILE *fich = fopen(nomFich,"rb");
int nbrElement;
tableauSpecialite->nbrElement = 0;
int matricule ; //
char specialite[100];
if (fich == NULL)
{
fprintf(stderr, "Erreur ouverture fichier index specialite\n" );
exit(EXIT_FAILURE);
}
fread(&nbrElement , sizeof(int),1,fich);

for (int i = 0; i < nbrElement; ++i)
{
fread(&specialite , sizeof(char[100]),1,fich);
fread(&matricule , sizeof(int),1,fich);
while (matricule != 0)
{
ajouteMatriculeTableIndexSpecialite(tableauSpecialite,specialite,matricule);
fread(&matricule , sizeof(int),1,fich);
}
}

fclose(fich);
}
//////////////////////////////////////////////////////////////////////////////////::

void ecrireIndexUniversite(char *nomFich,tableIndexUniversite *tableauUniversite)
{
FILE *fich = fopen(nomFich,"wb+");
char chaine[100];
pointeurListeMatriculeDate p=NULL;
int separateur = 0;

if (fich == NULL)
{
fprintf(stderr, "Erreur ouverture fichier index specialite\n" );
exit(EXIT_FAILURE);
}
fwrite(&tableauUniversite->nbrElement,sizeof(int), 1,fich);
for (int i = 0; i < tableauUniversite->nbrElement; ++i)
{
fwrite(&tableauUniversite->tab[i].universite, sizeof(char[200]), 1,fich);  // l'universite
// inserer la liste des matricules
p = tableauUniversite->tab[i].liste_matricule_date;
while (p != NULL)
{
fwrite(&p->matricule,sizeof(int), 1,fich);
fwrite(&p->date,sizeof(int), 1,fich);
p = p->suivant;
}
fwrite(&separateur, sizeof(int), 1,fich);
}
// fwrite(&laDonne, sizeof(le type de la donne), 1,fich);

fclose(fich);
}

/////////////////////////////////////////////////////////////////
void lireIndexUniversite(char *nomFich,tableIndexUniversite *tableauUniversite)
{
FILE *fich = fopen(nomFich,"rb");
int nbrElement;
tableauUniversite->nbrElement = 0;
int matricule ,date; //
char universite[200];
if (fich == NULL)
{
fprintf(stderr, "Erreur ouverture fichier index universite\n" );
exit(EXIT_FAILURE);
}
fread(&nbrElement , sizeof(int),1,fich);

for (int i = 0; i < nbrElement; ++i)
{
fread(&universite , sizeof(char[200]),1,fich);
fread(&matricule , sizeof(int),1,fich);
// fread(&date , sizeof(int),1,fich);

while (matricule != 0)
{ fread(&date , sizeof(int),1,fich);
ajouteMatriculeTableIndexUniversite(tableauUniversite,universite,matricule,date);
fread(&matricule , sizeof(int),1,fich);

}
}

fclose(fich);
}
void ecrireIndex(char * nomfichier,tableIndex *index)
{    FILE *F11=malloc(sizeof(FILE));

F11=fopen(nomfichier,"wb+");
    rewind(F11);
    fwrite(index,sizeof(tableIndex),1,F11);
    fclose(F11);}

    //////////////////////////////////////*******************************************************//////////////////////////
void lireIndex(char * nomfichier,tableIndex *index)
    {
    FILE *F11=malloc(sizeof(FILE));

F11=fopen(nomfichier,"rb");
 
    fread(index,sizeof(tableIndex),1,F11);
    fclose(F11);
    }
    Enregistrement* decompChamp(char *chaine)
    {    Enregistrement *enre=malloc(sizeof(Enregistrement));
    char  champ[12][100]={"","","","","","","","","","","",""};
    int i=0;
    int j=0;
    int n=0;
    while((i!=strlen(chaine) )&&(n!=11))
    {  
    champ[n][j]=chaine[i];
    i++;
    j++;
    if ((chaine[i]=='#')||(i==6) )
    {   if (i!=6)i++;
   
    n++;
    j=0;

    }

    }
   
   

       enre->matricule=atoi(champ[0]);
       strcpy(enre->nom,champ[1]);
       enre->dateDeNaissance=atoi(champ[2]);
       strcpy(enre->wilaya,champ[3]);
       strcpy(enre->sexe,champ[4]);
       strcpy(enre->groupeSanguin,champ[5]);
       enre->dateDeRecrutement=atoi(champ[6]);
       strcpy(enre->grade,champ[7]);
       strcpy(enre->specialite,champ[8]);
       strcpy(enre->DernierDiplome,champ[9]);
        strcpy(enre->EtablisementUniversitaire,champ[10]);
        return enre;
    }
     void supressionLogiqueSpecialite(tableIndexSpecialite *tabSpecialite, tableIndex *index,char * nomfichier )
    {
    char specialite[50];
       int choix;
    char Specialite[25][30]={"Droit", "Sciences Politiques", "Lettres et langues etrangeres" ,
"Lettres et langue arabe", "Informatique", "Mathematiques", "Chimie", "Physique", "Medecine",
"Pharmacologie", "Biologie", "Sciences Commerciales", "Sciences de Gestion", "Sciences Economiques",
"Electronique", "electrotechnique", "Genie Civil", "Genie des procedes", "Architecture", "Genie mecanique",
"hydraulique", "Sciences Islamiques", "Sciences Humaines", "Sociologie", "Agronomie"};
for (int i = 0; i < 25; ++i)
{
printf("%d.%s\n",i,Specialite[i] );
}
printf("entrer l\'indice de la specialite\n");
scanf("%d",&choix);
     strcpy(specialite,Specialite[choix]);
    int indice = rechercheSequencielTableIndexSpecialite(tabSpecialite,specialite);
int i,j,trouve;
   
    if (indice>=0)
    {
    pointeurListeMatricule p = tabSpecialite->tab[indice].liste_matricule;
    while(p != NULL)
    {
    supressionLogique(index,p->matricule,nomfichier);
    p = p -> suivant;
    }
int k;
if (indice < tabSpecialite->nbrElement - 1){
    for (int i = indice; i < tabSpecialite->nbrElement - 1; ++i)
    { k=i+1;
    tabSpecialite->tab[i]=tabSpecialite->tab[k];
    }}
    tabSpecialite->nbrElement = tabSpecialite->nbrElement - 1;
    }

    }


  void   affichageInformationEnseignant(char*chaine)
    {
    	Enregistrement *enre1=malloc(sizeof(Enregistrement));
    	enre1=decompChamp(chaine);
    	 printf("-------------------AFFICHAGE------------------\n");
    	 printf("le matricule : %d\n  le nom :%s\n la date de naissance %d\n wilaya: %s\n sexe:   %s\n groupe sanguin %s\n date de recrutement : %d\n  grade:   %s\n specialite:  %s\n dernier diplome : %s\n Etablisement Universitaire: %s\n \n",enre1->matricule,enre1->nom,enre1->dateDeNaissance,enre1->wilaya,enre1->sexe,enre1->groupeSanguin,enre1->dateDeRecrutement,enre1->grade,enre1->specialite,enre1->DernierDiplome,enre1->EtablisementUniversitaire );
         printf("-------------------FIN DE L'AFFICHAGE-----------\n");
    }

   void ResultatRequeteUniversite(tableIndexUniversite *tableau,tableIndex *index,char *nomfichier)
   { char Etablisement[50];
    int anneemin;
    int anneemax;
    char tabUniversite[106][200]= {  "Universite de Bechar - Mohamed Tahri -",
"Universite  de Mascara - Mustapha Stambouli -", "Universite de Saida - Tahar Moulay -",
"Universite  de Tlemcen - Abou Bekr Belkaid -", "Universite  d'Adrar - Ahmed Draya -",
"Universite  de Tiaret - Ibn Khaldoun -", "Universite  Sidi Bel Abbes - Djillali Liabes -",
"Universite de Mostaganem - Abdelhamid Ibn Badis -", "Universite d'Oran1 - Ahmed Ben Bella -",
"Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf d'Oran -",
"Universite  d'Oran 2 - Mohamed Ben Ahmed -", "Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi -",
"Centre Universitaire  de Ain Temouchent - Belhadj Bouchaib -", "Centre universitaire de Relizane - Ahmed Zabana -",
 "Centre universitaire   de Naama - Ahmed Salhi -", "Centre universitaire   d'El Bayadh - Nour Bachir -",
"Centre universitaire de Tindouf-Ali Kafi-","Centre universitaire de Maghnia",
"Annexe de Sougheur (Voir Universite de Tiaret)","Annexe de Ksar Chellala (Voir Universite de Tiaret)",
"Ecole Nationale Polytechnique d'Oran - Maurice Audin -","Ecole  Superieure d'Informatique (Sidi Bel Abbes)-08 Mai 1945",
"Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen","Ecole Superieure d'Economie d'Oran ex EPSECG Oran",
"Ecole Superieure de Management de Tlemcen ex EPSECG Tlemcen","Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran", "Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem", "Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran", "Ecole Normale Superieure de Mostaganem","Ecole Normale Superieure d'Oran", "Ecole normale superieure de Bechar", "Universite  de Bouira - Akli Mohand Oulhadj -", "Universite  de Djelfa - Ziane Achour -", "Universite de Ghardaia", "Universite  de Khemis Miliana - Djilali Bounaama -", "Universite des sciences et de la technologie d'Alger, Houari Boumediene", "Universite  Medea - Yahia Fares -", "Universite de Bejaia - Abderrahmane Mira -", "Universite  de Chlef - Hassiba Benbouali -", "Universite  de Boumerdes - M'hamed Bougara -", "Universite de Tizi Ouzou - Mouloud Maameri -", "Universite de Laghouat - Amar Telidji -", "Universite  Blida 1 - Saad Dahlab -", "Universite de Blida 2 - Lounici Ali -", "Universite d'Alger 1 - Benyoucef Benkhedda -", "Universite d'Alger 2 - Abou el Kacem Saadallah -", "Universite d'Alger 3 - Brahim Soltane Chaibout -", "Universite de la Formation Continue", "Centre universitaire  de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk -", "Centre universitaire  de Tipaza - Abdallah Morsli -", "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar -", "Centre universitaire Aflou", "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger", "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger", "Ecole Nationale Superieure des sciences politiques", "Ecole nationale superieure de journalisme et des sciences de l'information", "Ecole Nationale Superieure de Technologie", "Ecole nationale superieure de management", "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral", "Ecole Superieure de Commerce - Mouloud Kacem Nait Belkacem -", "Ecole nationale superieure en statistique et en economie appliquee", "Ecole nationale superieure d'informatique ( Alger )", "Ecole des hautes etudes commerciales", "Ecole nationale superieure agronomique - Khalef Abdellah alias Kasdi Merbah -", "Ecole Polytechnique d'architecture et d'Urbanisme - Hocine Ait Ahmed -", "Ecole nationale superieure veterinaire - Rabie Bouchama -", "Ecole nationale superieure des travaux publics -  Francis Jeanson -", "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah -", "Ecole Nationale Polytechnique", "Ecole normale superieure de Laghouat - Taleb Abderrahmane -", "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi-", "Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili-", "Ecole preparatoire en sciences economiques commerciales et sciences de gestion , Kolea", "Universite  de Jijel - Mohammed Seddik Ben yahia -", "Universite de Tebessa - Larbi Tebessi -", "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi -", "Universite d'El Tarf - Chadli Bendjedid -", "Universite  de Khenchela - Abbas Laghrour -", "Universite  de Oum El Bouaghi - Larbi Ben M'hidi -", "Universite d'El Oued - Hamma Lakhdar-", "Universite de Souk Ahras - Mohammed-Cherif Messaadia -", "Universite  de Annaba - Badji Mokhtar -", "Universite  du 20 Aout 1955 de Skikda", "Universite  8 Mai 1945 de Guelma", "Universite de Batna 1 - Hadj Lakhder -", "Universite  de Biskra - Mohamed Khider -", "Universite  de M'sila - Mohamed Boudiaf -", "Universite  de Ouargla - Kasdi Merbah -", "Universite des sciences islamiques Emir Abdelkader de Constantine", "Universite  de Setif 1 - Ferhat Abbas -", "Universite  de Setif 2 - Mohamed Lamine Debaghine -", "Universite  de Constantine 2 - Abdelhamid Mehri -", "Universite  de Constantine 1 - Freres Mentouri -", "Universite de Constantine 3 -Salah Boubnider-", "Universite de Batna 2 - Mustapha Ben Boulaid -", "Centre Universitaire de Mila - Abdelhafid Boussouf -", "Centre Universitaire de Barika - Si El Haoues -", "Ecole nationale superieure des mines et de la metallurgie -Amar Laskri-", "Ecole Nationale Polytechnique de Constantine -Malek Bennabi-", "Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar -", "Ecole Superieure des Sciences de Gestion de Annaba ex EPSECG Annaba", "Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba", "Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine", "Ecole normale superieure de Constantine -Assia Djebar -", "Ecole normale superieure d'enseignement technologique de Skikda", "Ecole normale superieure de setif - Messaoud Zeghar -"};

    int h;
    Tbloc *buf =malloc(sizeof(Tbloc));
    LObarreVC *F=malloc(sizeof(LObarreVC));
    pointeuri_j p=malloc(sizeof(i_j));
    for (int i = 0; i < 106; ++i)
    {
    printf("%d.%s  \n ",i,tabUniversite[i] );
    }
    printf("\n veillez entrer l\'indice de l{'universite  : ");
     scanf("%d",&h);
     printf("veillez entrer l\'annee min : \n" );
     scanf("%d",&anneemin);
     printf("veillez entrer l\'annee max : \n");
     scanf("%d",&anneemax);
     p=requetUniversite(tableau,index,tabUniversite[h], anneemin, anneemax);
     
     if (p==NULL) printf("aucun element ne correspond a votre requete \n");
     else {
      ouvrir(&F,nomfichier,'a');
      int i=0, j=0 ;
     
      char eff[3]="";
      char chaine[250]="";
        printf("les resultat de la requete sont :\n");
      while (p != NULL)
{    if (i!=p->i)
{
i=p->i;
liredir(F,i,buf);
}
      char chaine[250]="";
      char taille[3]="";  



j=p->j;

extraireChaine(3,&i,&j,taille,buf,F);
 
    extraireChaine(1,&i,&j,eff,buf,F);
 
    extraireChaine(atoi(taille),&i,&j,chaine,buf,F);
   
    affichageInformationEnseignant(chaine);
    strcpy(chaine,"");
    strcpy(taille,"");
p=p->suivant;


}

     }
   }

   void requetRegion(tableIndex *region,char *nomfichier)
   {
    pointeuri_j p=malloc(sizeof(i_j));
    Tbloc *buf =malloc(sizeof(Tbloc));
    LObarreVC *F=malloc(sizeof(LObarreVC));

    for (int a = 0; a < region->nbrElement ; ++a)
    {
    p = insertionListei_j (p,region->tab[a].i,region->tab[a].j);
    }
    if (p==NULL) printf("aucun element ne correspond a votre requete \n");
     else {
      ouvrir(&F,nomfichier,'a');
      int i=0, j=0 ;
     
      char eff[3]="";
      char chaine[250]="";
        printf("les resultat de la requete sont :\n");
      while (p != NULL)
{    if (i!=p->i)
{
i=p->i;
liredir(F,i,buf);
}
      char chaine[250]="";
      char taille[3]="";  
j=p->j;

extraireChaine(3,&i,&j,taille,buf,F);
 
    extraireChaine(1,&i,&j,eff,buf,F);
 
    extraireChaine(atoi(taille),&i,&j,chaine,buf,F);
   
    affichageInformationEnseignant(chaine);
    strcpy(chaine,"");
    strcpy(taille,"");
p=p->suivant;
}}}

   void afficherEnseignantIndex(tableIndex* tableau,char* nomfichier)
   {  Tbloc *buf =malloc(sizeof(Tbloc));
    LObarreVC *F=malloc(sizeof(LObarreVC));
    ouvrir(&F,nomfichier,'a');
      int i=0, j=0 ;
      char eff[3]="";
    for (int k = 0; k < tableau->nbrElement; ++k)
    {  
          char chaine[250]="";
      char taille[3]="";
    if (i!=tableau->tab[k].i)
{
i=tableau->tab[k].i;
liredir(F,i,buf);
}
     



j=tableau->tab[k].j;

extraireChaine(3,&i,&j,taille,buf,F);
 
    extraireChaine(1,&i,&j,eff,buf,F);
 
    extraireChaine(atoi(taille),&i,&j,chaine,buf,F);
   
    affichageInformationEnseignant(chaine);
    strcpy(chaine,"");
    strcpy(taille,"");
    }fermer(F);
   }

void ChangementEtablisement(int matricule,tableIndex* tableau,tableIndexUniversite *tabUniversite,tableIndexSpecialite *tabSpecialite,tableIndex* tableauEst,tableIndex* tableauOuest,tableIndex* tableauCentre,char *nomfichier)
{   int indice=0;
int trouve=0;
int i=0,j=0;
char e[256]="";
int nbUniversite=0;
char Universite[106][200]= {"Universite de Bechar - Mohamed Tahri -",
"Universite  de Mascara - Mustapha Stambouli -", "Universite de Saida - Tahar Moulay -",
"Universite  de Tlemcen - Abou Bekr Belkaid -", "Universite  d'Adrar - Ahmed Draya -",
"Universite  de Tiaret - Ibn Khaldoun -", "Universite  Sidi Bel Abbes - Djillali Liabes -",
"Universite de Mostaganem - Abdelhamid Ibn Badis -", "Universite d'Oran1 - Ahmed Ben Bella -",
"Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf d'Oran -",
"Universite  d'Oran 2 - Mohamed Ben Ahmed -", "Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi -",
"Centre Universitaire  de Ain Temouchent - Belhadj Bouchaib -", "Centre universitaire de Relizane - Ahmed Zabana -",
 "Centre universitaire   de Naama - Ahmed Salhi -", "Centre universitaire   d'El Bayadh - Nour Bachir -",
"Centre universitaire de Tindouf-Ali Kafi-","Centre universitaire de Maghnia",
"Annexe de Sougheur (Voir Universite de Tiaret)","Annexe de Ksar Chellala (Voir Universite de Tiaret)",
"Ecole Nationale Polytechnique d'Oran - Maurice Audin -","Ecole  Superieure d'Informatique (Sidi Bel Abbes)-08 Mai 1945",
"Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen","Ecole Superieure d'Economie d'Oran ex EPSECG Oran",
"Ecole Superieure de Management de Tlemcen ex EPSECG Tlemcen","Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran", "Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem", "Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran", "Ecole Normale Superieure de Mostaganem","Ecole Normale Superieure d'Oran", "Ecole normale superieure de Bechar", "Universite  de Bouira - Akli Mohand Oulhadj -", "Universite  de Djelfa - Ziane Achour -", "Universite de Ghardaia", "Universite  de Khemis Miliana - Djilali Bounaama -", "Universite des sciences et de la technologie d'Alger, Houari Boumediene", "Universite  Medea - Yahia Fares -", "Universite de Bejaia - Abderrahmane Mira -", "Universite  de Chlef - Hassiba Benbouali -", "Universite  de Boumerdes - M'hamed Bougara -", "Universite de Tizi Ouzou - Mouloud Maameri -", "Universite de Laghouat - Amar Telidji -", "Universite  Blida 1 - Saad Dahlab -", "Universite de Blida 2 - Lounici Ali -", "Universite d'Alger 1 - Benyoucef Benkhedda -", "Universite d'Alger 2 - Abou el Kacem Saadallah -", "Universite d'Alger 3 - Brahim Soltane Chaibout -", "Universite de la Formation Continue", "Centre universitaire  de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk -", "Centre universitaire  de Tipaza - Abdallah Morsli -", "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar -", "Centre universitaire Aflou", "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger", "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger", "Ecole Nationale Superieure des sciences politiques", "Ecole nationale superieure de journalisme et des sciences de l'information", "Ecole Nationale Superieure de Technologie", "Ecole nationale superieure de management", "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral", "Ecole Superieure de Commerce - Mouloud Kacem Nait Belkacem -", "Ecole nationale superieure en statistique et en economie appliquee", "Ecole nationale superieure d'informatique ( Alger )", "Ecole des hautes etudes commerciales", "Ecole nationale superieure agronomique - Khalef Abdellah alias Kasdi Merbah -", "Ecole Polytechnique d'architecture et d'Urbanisme - Hocine Ait Ahmed -", "Ecole nationale superieure veterinaire - Rabie Bouchama -", "Ecole nationale superieure des travaux publics -  Francis Jeanson -", "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah -", "Ecole Nationale Polytechnique", "Ecole normale superieure de Laghouat - Taleb Abderrahmane -", "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi-", "Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili-", "Ecole preparatoire en sciences economiques commerciales et sciences de gestion , Kolea", "Universite  de Jijel - Mohammed Seddik Ben yahia -", "Universite de Tebessa - Larbi Tebessi -", "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi -", "Universite d'El Tarf - Chadli Bendjedid -", "Universite  de Khenchela - Abbas Laghrour -", "Universite  de Oum El Bouaghi - Larbi Ben M'hidi -", "Universite d'El Oued - Hamma Lakhdar-", "Universite de Souk Ahras - Mohammed-Cherif Messaadia -", "Universite  de Annaba - Badji Mokhtar -", "Universite  du 20 Aout 1955 de Skikda", "Universite  8 Mai 1945 de Guelma", "Universite de Batna 1 - Hadj Lakhder -", "Universite  de Biskra - Mohamed Khider -", "Universite  de M'sila - Mohamed Boudiaf -", "Universite  de Ouargla - Kasdi Merbah -", "Universite des sciences islamiques Emir Abdelkader de Constantine", "Universite  de Setif 1 - Ferhat Abbas -", "Universite  de Setif 2 - Mohamed Lamine Debaghine -", "Universite  de Constantine 2 - Abdelhamid Mehri -", "Universite  de Constantine 1 - Freres Mentouri -", "Universite de Constantine 3 -Salah Boubnider-", "Universite de Batna 2 - Mustapha Ben Boulaid -", "Centre Universitaire de Mila - Abdelhafid Boussouf -", "Centre Universitaire de Barika - Si El Haoues -", "Ecole nationale superieure des mines et de la metallurgie -Amar Laskri-", "Ecole Nationale Polytechnique de Constantine -Malek Bennabi-", "Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar -", "Ecole Superieure des Sciences de Gestion de Annaba ex EPSECG Annaba", "Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba", "Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine", "Ecole normale superieure de Constantine -Assia Djebar -", "Ecole normale superieure d'enseignement technologique de Skikda", "Ecole normale superieure de setif - Messaoud Zeghar -"};

Enregistrement *enregi=malloc(sizeof(Enregistrement));
Tbloc *buf=malloc(sizeof(Tbloc));
LObarreVC *F=malloc(sizeof(LObarreVC));
ouvrir(&F,nomfichier,'a');
   
     indice=rechercheDichotomiqueTableIndexDeCle(tableau,&trouve,matricule,&i ,&j);
     if (trouve==1)
     {  for (int k = 0; k < 106; ++k)
    {
    printf("%d.%s   \n",k,Universite[k] );
    }
    printf("veillez entrer l\'indice de l\'Etablisement universitaire : \n");
    scanf("%d",&nbUniversite);
     
      char chaine[250]="";
      char taille[3]="";
      char e[256]="";
      char eff[3]="";
         liredir(F,i,buf);
         j=tableau->tab[indice].j;

    extraireChaine(3,&i,&j,taille,buf,F);
 
         extraireChaine(1,&i,&j,eff,buf,F);
 
         extraireChaine(atoi(taille),&i,&j,chaine,buf,F);
         fermer(F);
         enregi=decompChamp(chaine);
          supressionLogique(tableau, matricule, nomfichier);
      supressionPhysiqueTableIndex(tableauEst,matricule);
      supressionPhysiqueTableIndex(tableauOuest,matricule);
      supressionPhysiqueTableIndex(tableauCentre,matricule);
         suppressionTableIndexSpecialite(tabSpecialite,enregi->specialite, matricule);
         suppressionTableIndexUniversite( tabUniversite,enregi->EtablisementUniversitaire, matricule );
         strcpy(enregi->EtablisementUniversitaire,Universite[nbUniversite]);
         creerChaine(enregi,e);
         insertion(tableau,tabSpecialite ,tabUniversite ,tableauEst,tableauOuest,tableauCentre, nomfichier,e);

          }
          else printf("%s\n","le matricule n existe pas" );
}
void creerChaine(Enregistrement*enre,char*e)
{
char chaine[256]="";
    strcpy(e,"");

    int matricule=enre->matricule;
ltoa(matricule,chaine,10);
strcpy(e,chaine);
strcpy(chaine,enre->nom); //nom/prenom
strcat(e,chaine);
strcat(e,"#");
int dateDeNaissance=enre->dateDeNaissance;
ltoa(dateDeNaissance,chaine,10); // date de naissance
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->wilaya);
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->sexe);
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->groupeSanguin);
strcat(e,chaine);
strcat(e,"#");
int dateDeRecrutement= enre->dateDeRecrutement;
ltoa(dateDeRecrutement,chaine,10); // date de recrutement
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->grade);
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->specialite);
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->DernierDiplome);
strcat(e,chaine);
strcat(e,"#");
strcpy(chaine,enre->EtablisementUniversitaire);
strcat(e,chaine);

}
// ///////////////////////////////////////////////////////////////////////////////////////
void ajoutNouvelleEnseignant(tableIndex *index,tableIndexSpecialite *tableauSpecialite , tableIndexUniversite *tableauUniversite ,tableIndex *tableauEst, tableIndex *tableauOuest,tableIndex* tableauCentre,char* nomfichier)
{   LObarreVC *F=malloc(sizeof(LObarreVC));
Tbloc *buf=malloc(sizeof(Tbloc));
char chaine[250];
Enregistrement *enregi=malloc(sizeof(Enregistrement));
char tabUniversite[106][200]= {  "Universite de Bechar - Mohamed Tahri -",
"Universite  de Mascara - Mustapha Stambouli -", "Universite de Saida - Tahar Moulay -",
"Universite  de Tlemcen - Abou Bekr Belkaid -", "Universite  d'Adrar - Ahmed Draya -",
"Universite  de Tiaret - Ibn Khaldoun -", "Universite  Sidi Bel Abbes - Djillali Liabes -",
"Universite de Mostaganem - Abdelhamid Ibn Badis -", "Universite d'Oran1 - Ahmed Ben Bella -",
"Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf d'Oran -",
"Universite  d'Oran 2 - Mohamed Ben Ahmed -", "Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi -",
"Centre Universitaire  de Ain Temouchent - Belhadj Bouchaib -", "Centre universitaire de Relizane - Ahmed Zabana -",
 "Centre universitaire   de Naama - Ahmed Salhi -", "Centre universitaire   d'El Bayadh - Nour Bachir -",
"Centre universitaire de Tindouf-Ali Kafi-","Centre universitaire de Maghnia",
"Annexe de Sougheur (Voir Universite de Tiaret)","Annexe de Ksar Chellala (Voir Universite de Tiaret)",
"Ecole Nationale Polytechnique d'Oran - Maurice Audin -","Ecole  Superieure d'Informatique (Sidi Bel Abbes)-08 Mai 1945",
"Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen","Ecole Superieure d'Economie d'Oran ex EPSECG Oran",
"Ecole Superieure de Management de Tlemcen ex EPSECG Tlemcen","Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran", "Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem", "Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran", "Ecole Normale Superieure de Mostaganem","Ecole Normale Superieure d'Oran", "Ecole normale superieure de Bechar", "Universite  de Bouira - Akli Mohand Oulhadj -", "Universite  de Djelfa - Ziane Achour -", "Universite de Ghardaia", "Universite  de Khemis Miliana - Djilali Bounaama -", "Universite des sciences et de la technologie d'Alger, Houari Boumediene", "Universite  Medea - Yahia Fares -", "Universite de Bejaia - Abderrahmane Mira -", "Universite  de Chlef - Hassiba Benbouali -", "Universite  de Boumerdes - M'hamed Bougara -", "Universite de Tizi Ouzou - Mouloud Maameri -", "Universite de Laghouat - Amar Telidji -", "Universite  Blida 1 - Saad Dahlab -", "Universite de Blida 2 - Lounici Ali -", "Universite d'Alger 1 - Benyoucef Benkhedda -", "Universite d'Alger 2 - Abou el Kacem Saadallah -", "Universite d'Alger 3 - Brahim Soltane Chaibout -", "Universite de la Formation Continue", "Centre universitaire  de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk -", "Centre universitaire  de Tipaza - Abdallah Morsli -", "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar -", "Centre universitaire Aflou", "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger", "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger", "Ecole Nationale Superieure des sciences politiques", "Ecole nationale superieure de journalisme et des sciences de l'information", "Ecole Nationale Superieure de Technologie", "Ecole nationale superieure de management", "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral", "Ecole Superieure de Commerce - Mouloud Kacem Nait Belkacem -", "Ecole nationale superieure en statistique et en economie appliquee", "Ecole nationale superieure d'informatique ( Alger )", "Ecole des hautes etudes commerciales", "Ecole nationale superieure agronomique - Khalef Abdellah alias Kasdi Merbah -", "Ecole Polytechnique d'architecture et d'Urbanisme - Hocine Ait Ahmed -", "Ecole nationale superieure veterinaire - Rabie Bouchama -", "Ecole nationale superieure des travaux publics -  Francis Jeanson -", "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah -", "Ecole Nationale Polytechnique", "Ecole normale superieure de Laghouat - Taleb Abderrahmane -", "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi-", "Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili-", "Ecole preparatoire en sciences economiques commerciales et sciences de gestion , Kolea", "Universite  de Jijel - Mohammed Seddik Ben yahia -", "Universite de Tebessa - Larbi Tebessi -", "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi -", "Universite d'El Tarf - Chadli Bendjedid -", "Universite  de Khenchela - Abbas Laghrour -", "Universite  de Oum El Bouaghi - Larbi Ben M'hidi -", "Universite d'El Oued - Hamma Lakhdar-", "Universite de Souk Ahras - Mohammed-Cherif Messaadia -", "Universite  de Annaba - Badji Mokhtar -", "Universite  du 20 Aout 1955 de Skikda", "Universite  8 Mai 1945 de Guelma", "Universite de Batna 1 - Hadj Lakhder -", "Universite  de Biskra - Mohamed Khider -", "Universite  de M'sila - Mohamed Boudiaf -", "Universite  de Ouargla - Kasdi Merbah -", "Universite des sciences islamiques Emir Abdelkader de Constantine", "Universite  de Setif 1 - Ferhat Abbas -", "Universite  de Setif 2 - Mohamed Lamine Debaghine -", "Universite  de Constantine 2 - Abdelhamid Mehri -", "Universite  de Constantine 1 - Freres Mentouri -", "Universite de Constantine 3 -Salah Boubnider-", "Universite de Batna 2 - Mustapha Ben Boulaid -", "Centre Universitaire de Mila - Abdelhafid Boussouf -", "Centre Universitaire de Barika - Si El Haoues -", "Ecole nationale superieure des mines et de la metallurgie -Amar Laskri-", "Ecole Nationale Polytechnique de Constantine -Malek Bennabi-", "Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar -", "Ecole Superieure des Sciences de Gestion de Annaba ex EPSECG Annaba", "Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba", "Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine", "Ecole normale superieure de Constantine -Assia Djebar -", "Ecole normale superieure d'enseignement technologique de Skikda", "Ecole normale superieure de setif - Messaoud Zeghar -"};
  char tabSpecialite[25][30]={"Droit", "Sciences Politiques", "Lettres et langues etrangeres" ,
"Lettres et langue arabe", "Informatique", "Mathematiques", "Chimie", "Physique", "Medecine",
"Pharmacologie", "Biologie", "Sciences Commerciales", "Sciences de Gestion", "Sciences Economiques",
"Electronique", "electrotechnique", "Genie Civil", "Genie des procedes", "Architecture", "Genie mecanique",
"hydraulique", "Sciences Islamiques", "Sciences Humaines", "Sociologie", "Agronomie"};
char tabGroupeSanguin[8][4]={"O+","A+","B+","O-","A-","AB+","B-","AB-"};
char tabWilaya[58][20]={"Adrar", "Chlef", "Laghouat", "Oum El Bouaghi", "Batna", "Bejaia", "Biskra", "Bechar",
"Blida", "Bouira", "Tamanrasset", "Tebessa", "Tlemcen", "Tiaret", "Tizi Ouzou", "Alger", "Djelfa", "Jijel", "Setif",
 "Saida", "Skikda", "Sidi Bel Abbes", "Annaba", "Guelma", "Constantine", "Medea", "Mostaganem", "M'Sila", "Mascara",
  "Ouargla", "Oran", "El Bayadh", "Illizi", "Bordj Bou Arreridj", "Boumerdes", "El Tarf", "Tindouf", "Tissemsilt",
   "El Oued", "Khenchela", "Souk Ahras", "Tipaza", "Mila", "Ain Defla", "Naama", "Ain Temouchent", "Ghardaia",
    "Relizane", "El M'Ghair", "El Meniaa", "Ouled Djellal", "Bordj Baji Mokhtar", "Beni Abbes", "Timimoun",
    "Touggourt", "Djanet", "In Salah", "In Guezzam"};
char tabGrade[6][30]={"Professeur(e)","Maitre de conferences Rang A","Maitre de conferences Rang B",
"Maitre assistant(e) Rang A","Maitre assistant(e) Rang B","Assistant(e)"};
char tabDiplome[5][21]={"Doctorat d Etat","Doctorat en sciences","PhD","HDR","Magister"} ;


    ouvrir(&F,nomfichier,'a');
      int matricule;
     printf("entrez le matricule a inserer :\n");
     scanf("%d",&matricule);
    enregi->matricule=matricule;
    char nom[50];
    printf("entrer le nom de l\'enseignant : \n");
    scanf("%s",nom);
    strcpy(enregi->nom,nom);
    int dateDeNaissance;
    printf("entrer la date de naissance (sous la forme aaaammjj)\n");
scanf("%d",&dateDeNaissance);
enregi->dateDeNaissance=dateDeNaissance;
for (int i = 0; i < 58; ++i)
{
printf("%d.%s\n",i+1,tabWilaya[i] );

}
int nbWilaya;
printf("veillez choisir l\'indice de la wilaya :\n");
scanf("%d",&nbWilaya);
strcpy(enregi->wilaya,tabWilaya[nbWilaya-1]);
int choix;
 choice :printf("choisissez entre :\n");
printf("1.femme            2.homme\n");
scanf("%d",&choix);
if (choix==1)strcpy(enregi->sexe,"f");
if (choix==2)strcpy(enregi->sexe,"m");
if ((choix>2)||(choix<1))
{
printf("entree non valide Veuillez rechoisir \n");
goto choice;
}
for (int i = 0; i <8 ; ++i)
{
printf("%d.%s\n",i,tabGroupeSanguin[i] );

}
int nbgrou;
printf("entrer l\'indice du groupeSanguin\n");
scanf("%d",&nbgrou);
strcpy(enregi->groupeSanguin,tabGroupeSanguin[nbgrou]);
int dateDeRecrutement;
printf("entrer la date de recrutement (sous la forme aaaammjj)\n" );
scanf("%d",&dateDeRecrutement);
enregi->dateDeRecrutement=dateDeRecrutement;
for (int i = 0; i < 6; ++i)
{printf("%d.%s \n",i,tabGrade[i] );

} int nbgrade;
printf("entrer l\'indice du grade\n");
scanf("%d",&nbgrade);
strcpy(enregi->grade,tabGrade[nbgrade]);
int nbspec;
for (int i = 0; i < 25; ++i)
{
printf("%d.%s \n",i,tabSpecialite[i] );
}
printf("entrer l\'indice de la specialite\n");
scanf("%d",&nbspec);
strcpy(enregi->specialite,tabSpecialite[nbspec]);
int nbdip;
for (int i = 0; i < 5; ++i)
{
printf("%d.%s \n",i,tabDiplome[i] );
}
printf("entrer l\'indice du diplome\n");
scanf("%d",&nbdip);
strcpy(enregi->DernierDiplome,tabDiplome[nbdip]);
int nbuniv;
for (int i = 0; i < 106; ++i)
{
printf("%d.%s \n",i,tabUniversite[i] );
}
printf("entrer l\'indice de l\'universite\n");
scanf("%d",&nbuniv);
strcpy(enregi->EtablisementUniversitaire,tabUniversite[nbuniv]);
 creerChaine(enregi,chaine);
 
 insertion(index,tableauSpecialite ,tableauUniversite ,tableauEst,tableauOuest,tableauCentre,nomfichier,chaine);

}


void afficherInfo(int i,int j,char* nomfichier)
{
Tbloc *buf=malloc(sizeof(Tbloc));
LObarreVC *F=malloc(sizeof(LObarreVC));

        ouvrir(&F,nomfichier,'a');
    char chaine[250]="";
      char taille[4]="";
      char eff[3]="";
         liredir(F,i,buf);
      extraireChaine(3,&i,&j,taille,buf,F);
         extraireChaine(1,&i,&j,eff,buf,F);  
         extraireChaine(atoi(taille),&i,&j,chaine,buf,F);
         fermer(F);
         affichageInformationEnseignant(chaine);

}