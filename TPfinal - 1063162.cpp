// But: Programme de loto.
// Auteur: Harley Lounsbury
// Date Commenc�: 22/11/2018
// Date Livrable: 12/12/2018 � 18h00

#include <iostream>
#include <iomanip>
#include <fstream>
#include "TPfinal - 1063162.h"

using namespace std;

// D�claration de constantes.
// Largeur des menus et ent�tes.
const int iMAX_LARGEUR = 44;
const int iMAX_LARGEUR_FICHIER = 27;

// Titres principales.
const char cTITRE[] = "LOTO DU BONHEUR";
const char cTITRE_SOUSMENU[] = "Acheter un billet";
// Sous-Titre.
const char cSOUS_TITRE[] = "Pr�sent� par : Harley Lounsbury";
// Options de menu.
const char cOPTION1[] = "1. Acheter un billet";
const char cOPTION2[] = "2. Afficher un billet";
const char cOPTION3[] = "3. Valider un billet";
const char cOPTION_QUITTER[] = "0. Quitter le programme";
// Options de sous-menu 1.
const char cOPTION_ACHETER1[] = "1. Choisir ses  propres num�ros";
const char cOPTION_ACHETER2[] = "2. Choisir les num�ros au hasard";
const char cOPTION_RETOUR[] = "0. Revenir au menu pr�c�dent";
// Pour les valeurs possible dans le choix de nombres.
const int iMIN_VALEUR = 1;
const int iMAX_VALEUR = 49;
// Pour le calcul du gain. 
// Les nombres sont aussi petit car le gain est en fonction d'un pourcentage du lot bas� sur combien de nombres sont pareil. 
const float fFACTEUR_TROIS_PAREIL = 0.001;
const float fFACTEUR_QUATRE_PAREIL = 0.01;
const float fFACTEUR_CINQ_PAREIL = 0.1;
const float fFACTEUR_SIX_PAREIL = 1;

// Pour afficher le menu principale. 
void afficherMenu()
{
   // �ffacer l'�cran avant d'afficher.
   system("cls");
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
   // Titre, centr�.
   cout << setw((iMAX_LARGEUR - strlen(cTITRE)) / 2) << setfill(' ') << " " << cTITRE << endl;
   // Sous-titre, centr�.
   cout << setw((iMAX_LARGEUR - strlen(cSOUS_TITRE)) / 2) << setfill(' ') << " " << cSOUS_TITRE << endl;
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
   // Les options de menu.
   cout << endl;
   cout << cOPTION1 << endl;
   cout << cOPTION2 << endl;
   cout << cOPTION3 << endl;
   cout << cOPTION_QUITTER << endl;
   cout << endl;
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl; 
}

// Fonction pour afficher le menu principale.
int validerChoixMenu(int iChoixMenu, const int iPOURQUITTER, const int iMAXOPTIONS)
{
   // Affichage du menu.
   afficherMenu();

   // On fait appel � la fonction qui pose les questions et qui s'occupe de g�rer la r�ponse.
   return demanderChoix(iMAXOPTIONS, iChoixMenu);
}

int demanderChoix(const int iMAX, int iChoixMenu)
{
   // Variable interm�diaire. 
   int iNb;
   // Demander � l'utilisateur son choix. 
   cout << "Veuillez entrer votre choix -->";
   if(iChoixMenu == 1)
      iNb = lireNombre(iMAX, iChoixMenu);

   if (iChoixMenu == 2)
      iNb = lireNombreSousMenu(iMAX, iChoixMenu);

   return iNb;
}

int lireNombre(const int iMAX, int iChoixMenu)
{
   // Pour lire toutes les b�tises que pourrait taper l'utilisateur, on se cr�e une variable de type cha�ne
   // de caract�res suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNbLu;

   cin.getline(cClavier, sizeof(cClavier), '\n');

   // On lit toute ce que l'utilisateur tape au clavier dans une cha�ne de caract�res
   // qui accepte n'importe quel caract�re.

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande � l'utilisateur

   if (!((cClavier[0] >= '0' && cClavier[0] <= '9') || (cClavier[0] == '-' && (cClavier[1] >= '0' && cClavier[1] <= '9'))))
   {
      for (int iCompteur = 0; iCompteur < iMAXCLAVIER; iCompteur++)
      {
         // Reinitialise cClavier pour �viter certains erreurs.
         cClavier[iCompteur] = NULL;
      }
      // Ligne de tirets.
      cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
      // Message.
      cout << endl << "Vous devez entrer un nombre entre " << iQUITTER << " et " << iMAX << endl;
      system("pause");
      // Retourne au menu.
      validerChoixMenu(iChoixMenu, iQUITTER, iMAX_MENUPRINCIPALE);
   }
   else
   {
      // Convertir le nombre lu en entier.
      iNbLu = atoi(cClavier);
      // Pour v�rifier que le nombre, maintenant en entier, est bien entre les limites. 
      if (iNbLu > iMAX || iNbLu < iQUITTER)
      {
         // R�initialiser iNbLu.
         iNbLu = NULL;
         // Ligne de tirets.
         cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
         // Message.
         cout << endl << "Vous devez entrer un nombre entre " << iQUITTER << " et " << iMAX << endl;
         system("pause");
         validerChoixMenu(iChoixMenu, iQUITTER, iMAX);
      }
      else
      {
         return iNbLu;
      }
   }
}

void afficherSousMenu()
{
   // �ffacer l'�cran avant d'afficher. 
   system("cls");
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
   // Afficher le sous-titre, centr�.
   cout << setw((iMAX_LARGEUR - strlen(cTITRE_SOUSMENU)) / 2) << setfill(' ') << " " << cTITRE_SOUSMENU << endl;
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
   cout << endl;
   // Afficher les options.
   cout << cOPTION_ACHETER1 << endl;
   cout << cOPTION_ACHETER2 << endl;
   cout << cOPTION_RETOUR << endl;
   cout << endl;
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
}

int validerChoixSousMenu(int iChoixMenu, const int iPOURRETOURNER, const int iMAXOPTIONS)
{
   // Appel � la fonction pour afficher. 
   afficherSousMenu();

   // Demander le choix de l'utilisateur.
   return demanderChoix(iMAXOPTIONS, iChoixMenu);
}

void demanderNom(char cNomBillet[])
{
   // �ffacer l'�cran avant d'afficher.
   system("cls");

   // Tableaux temporaire pour stock� ce que l'utilisateur frappe, sans cr�er un "Buffer overflow"
   const int iMAX_CLAVIER = 8190;
   char cClavier[iMAX_CLAVIER + 1];
   // Message.
   cout << "Entrez le nom du joueur (maximum 20 caract�res) -->";
   // Le nom sur le billet peut �tre n'importe quoi. 
   cin.getline(cClavier, sizeof(cClavier), '\n');

   // Toute la reste de la fonction � partir d'ici est franchement de patantage.
   // Avec plusieurs tests, j'ai quasiment toujours �t� capable de cr�er un "buffer overflow" � quelque part. 
   // Chaque boucle que j'ai ajout� a aid�, mais je comprend que ce complique le code. 
   // Il doit avoir des places qui ne sont pas n�cessaire comme tel, mais je trouve que l'ensemble fait fonctionner la fonction
   // et comme ca c'est plus s�curitaire. 
   int iCompteurValeurs = 0;
   for (int iCompteur = 0; iCompteur < iMAX_NOM + 1; iCompteur++)
   {
      if (cClavier[iCompteur] != NULL)
      {
         iCompteurValeurs++;
      }
   }

   while (iCompteurValeurs > iMAX_NOM)
   {
      for (int iCompteur = 0; iCompteur < iMAX_CLAVIER; iCompteur++)
      {
         cClavier[iCompteur] = NULL;
      }
      cout << "Erreur: le nom du joueur de peut comporter plus de 20 caract�res." << endl;
      cout << "Entrez le nom du joueur (maximum 20 caract�res) -->";
      cin.getline(cClavier, sizeof(cClavier), '\n');
      iCompteurValeurs = 0;
      for (int iCompteur = 0; iCompteur < iMAX_NOM + 1; iCompteur++)
      {
         if (cClavier[iCompteur] != NULL)
         {
            iCompteurValeurs++;
         }
      }
   }
   for (int iCompteur = 0; iCompteur < iMAX_NOM; iCompteur++)
   {
      cNomBillet[iCompteur] = cClavier[iCompteur];
   }
}

void creerFichier(ofstream& ofCanal, char cNomFichier[])
{
   // Fonction pour ouvrir le ficher.
   ofCanal.open(cNomFichier, ios::out);
   // Message d'erreur en cas d'�chec. 
   if (!ofCanal)
   {
      cerr << "Erreur : Le fichier " << cNomFichier << " n'a pas pu se cr�er" << endl;
      system("pause");
      exit(1);
   }
}

void ecrireEnTeteBillet(ofstream & ofCanal)
{
   // Ligne de tirets.
   ofCanal << setw(iMAX_LARGEUR_FICHIER) << setfill('-') << "-" << setfill(' ') << endl;
   // Titre, centr�.
   ofCanal << setw((iMAX_LARGEUR_FICHIER - strlen(cTITRE)) / 2) << setfill(' ') << " " << cTITRE << endl;
   // Ligne de tirets.
   ofCanal << setw(iMAX_LARGEUR_FICHIER) << setfill('-') << "-" << setfill(' ') << endl;
}

void saisirCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Variable interm�diaire.
   int iNbSaisi;
   // On va poser la question dans un boucle FOR, car on sait combien de fois on doit la poser. 
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE; iCompteur++)
   {
      // On va lire chaque nombre. 
      // J'aurai pu partir iCompteur � 1, aller jusqu'� iCompteur <= iMAX_NOMBRE, et ne pas avoir besoin de ajouter 1 pour l'affichage.
      // Dans ce cas, il aurait fallu que plus tard je fais iCombo[iCompteur - 1] = iNbSaisi. 
      // En bref, je trouve ca revient au m�me, et j'ai d�cid� d'y aller comme ca. 
      cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
      // Appel � la fonction qui s'occupe de bien saisir le nombre.
      iNbSaisi = saisirNombre();
      
      // On doit v�rifier si le nombre saisi est bien entre les limites.
      while (iNbSaisi < iMIN_VALEUR || iNbSaisi > iMAX_VALEUR)
      {
         cout << "Erreur: Le nombre doit �tre compris entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " seulement." << endl;
         cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
         iNbSaisi = NULL;
         iNbSaisi = saisirNombre();
      }
      // On va v�rifier que le nombre saisi n'a pas �t� d�j� saisi.
      // Avant de sortir de la boucle WHILE, on va aussi v�rifier que le nombre est bien entre les limites. 
      while (existe(iNbSaisi, iCombo, iCompteur))
      {
         cout << "Vous avez d�j� choisi ce nombre. Veuillez recommencer." << endl;
         cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
         iNbSaisi = NULL;
         iNbSaisi = saisirNombre();
         while (iNbSaisi < iMIN_VALEUR || iNbSaisi > iMAX_VALEUR)
         {
            cout << "Erreur: Le nombre doit �tre compris entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " seulement." << endl;
            cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
            iNbSaisi = NULL;
            iNbSaisi = saisirNombre();
         }
      }
      // Une fois que le nombre saisi est trouv� d'�tre valide, on peut stocker ce nombre dans la cha�ne d'entiers. 
      iCombo[iCompteur] = iNbSaisi;
   }
}

int saisirNombre()
{
   // Pour lire toutes les b�tises que pourrait taper l'utilisateur, on se cr�e une variable de type cha�ne de caract�res
   // suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNb;

   // On lit toute ce que l'utilisateur tape au clavier dans une cha�ne de caract�res
   // qui accepte n'importe quel caract�re.
   cin.getline(cClavier, sizeof(cClavier), '\n');

   // Il faut s'assurer que cClavier commence par un chiffre ou par un tiret suivi d'un chiffre. Sinon on redemande � l'utilisateur.

   if ((cClavier[0] < '0' || cClavier[0] > '9') && (cClavier[0] != '-' || (cClavier[1] < '0' || cClavier[1] > '9')))
   {
      cout << "Erreur: vous devez entrer un nombre entier." << endl;
      saisirNombre();
   }
   else
   {
      iNb = atoi(cClavier);
   
      return iNb;
   }
}

bool existe(int iNombreAVerifier, int iCombo[], int iPosition)
{
   // On va devoir v�rifier notre nombre contre toutes les nombres d�j� saisis.
   for (int iCompteurVerif = 0; iCompteurVerif < iPosition; iCompteurVerif++)
   {
      // Si le nombre existe, on retourne true.
      if (iCombo[iCompteurVerif] == iNombreAVerifier)
      {
         return true;
      }
   }
   // Si on passe en travers toutes les nombres, on peut dire que le nombre n'existe pas, on retourne false.
   return false;
}

void choisirCombinaisonAuHasard(int iCombo[], const int iMAX_NOMBRE)
{
   // Variable interm�diaire.
   int iNbHasard;
   // Boucle pour passer les nombres g�n�res dans la cha�ne d'entiers. 
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE; iCompteur++)
   {
      iNbHasard = choisirNombreAuHasard(iMIN_VALEUR, iMAX_VALEUR);
      // V�rifier que le nombre n'a pas �t� d�j� g�n�r�. 
      while (existe(iNbHasard, iCombo, iCompteur))
      {
         iNbHasard = NULL;
         iNbHasard = choisirNombreAuHasard(iMIN_VALEUR, iMAX_VALEUR);
      }
      // Stocker le nombre dans la cha�ne d'entiers. 
      iCombo[iCompteur] = iNbHasard;
   }
}

int choisirNombreAuHasard(const int iMIN, const int iMAX)
{
   // G�n�rer le nombre au hasard, compris entre les limites fournies. 
   return rand() % (iMAX - iMIN + 1) + iMIN;
}

void afficherCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Appel � la fonction pour mettre la combinaison en ordre croissant.
   trierCombinaison(iCombo, iMAX_NOMBRE);
   // Boucle pour traiter chaque nombre de la cha�ne d'entiers. 
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE - 1; iCompteur++)
   {
      cout << setw(2) << setfill(' ') << iCombo[iCompteur] << " - ";
   }
   cout << iCombo[iMAX_NOMBRE - 1] << endl;
}

void initialiserCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Boucle pour traiter chaque nombre de la cha�ne d'entiers.
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE; iCompteur++)
   {
      // � chaque passe, on met le valeur � 0. 
      iCombo[iCompteur] = 0;
   }
}

void trierCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Premi�re boucle pour compter le nombre de passes.
   for (int iNombreDePasses = 1; iNombreDePasses <= iMAX_NOMBRE; iNombreDePasses++)
   {
      // Deuxi�me boucle pour traiter le tableau index par index.
      for (int iCompteur = 0; iCompteur < iMAX_NOMBRE - 1; iCompteur++)
      {
         // On va compar� deux nombres qui sont c�te � c�te, et si celui avec le plus petit index est plus grand, on appelle 
         // la fonction pour les �changer de place. 
         if (iCombo[iCompteur] > iCombo[iCompteur + 1])
         {
            permuter(iCombo[iCompteur], iCombo[iCompteur + 1]);
         }
      }
   }
}

void permuter(int & iChiffre1, int & iChiffre2)
{
   // Variable interm�diaire.
   int iTemp;
   // On copie la valeur du premier nombre dans la variable.
   iTemp = iChiffre1;
   // On �crase le premier avec le deuxi�me.
   iChiffre1 = iChiffre2;
   // On copie le premier dans le deuxi�me.
   iChiffre2 = iTemp;
}

int validerCombinaison(int iCombo1[], const int iCOMBO_GAGNANTE[], int iMAX_NOMBRE)
{
   // Pour comparer les deux tableau, on a besoin d'un compteur pour tenir compte � chaque fois il y a deux chiffres identiques.
   int iCompteur = 0;
   // Premi�re boucle pour l'index du premier tableau.
   for (int iIndex1 = 0; iIndex1 < iMAX_NOMBRE; iIndex1++)
   {
      // Avec la valeur d'un nombre dans le premier tableau, on va comparer � tous les autres nombres dans le tableau gagnant. 
      for (int iIndex2 = 0; iIndex2 < iMAX_NOMBRE; iIndex2++)
      {
         // Si on trouve deux nombres identiques, on augmente le compteur. 
         if (iCombo1[iIndex1] == iCOMBO_GAGNANTE[iIndex2])
         {
            iCompteur++;
         }
      }
   }
   return iCompteur;
}

void afficherValidation(int iComboGagnante[], int iComboAValider[], ifstream& ifCanal, const float fLOT)
{
   // Variable pour stock� le nombre de nombres identique.
   int iNombrePareil = 0;
   // �ffacer l'�cran avant d'afficher.
   system("cls");
   // Titre.
   cout << "Valider le billet" << endl;
   // Montrer le montant du lot complet.
   cout << "La mise est de $" << fixed << setprecision(2) << fLOT << endl;
   // Afficher la combinaison gagnante, choisie � l'ouverture du programme. 
   cout << "La combinaison gagnante: ";
   afficherCombinaison(iComboGagnante, iMAX_COMBO);
   // D�barassage de l'ent�te. 
   lireEnTeteBillet(ifCanal);
   // On tente de lire une premi�re combinaison.
   lireCombinaisonBillet(ifCanal, iComboAValider);
   // Boucle jusqu'� fin du fichier.
   while (!ifCanal.eof())
   {
      // Afficher la combinaison lue.
      cout << "La combinaison du joueur: ";
      afficherCombinaison(iComboAValider, iMAX_COMBO);
      // Voir combien de nombres sont identiques � la combinaison gagnante. 
      iNombrePareil = validerCombinaison(iComboAValider, iComboGagnante, iMAX_COMBO);
      cout << "Nombres identiques: " << iNombrePareil << endl;
      // Appel � la fonction pour afficher les gains (s'il y en a, sinon, le message d'encouragement).
      afficherGains(iNombrePareil, fLOT);
      // On tente de lire une prochaine combinaison. 
      lireCombinaisonBillet(ifCanal, iComboAValider);
   }
}

void ecrireCombinaisonDansBillet(ofstream & ofCanal, int iCombo[])
{
   // Boucle pour traiter la cha�ne d'entiers (5 premiers nombres.).
   for (int iCompteur = 0; iCompteur < iMAX_COMBO - 1; iCompteur++)
   {
      // Imprimer dans le ficher les nombres, s�par�s par un tiret. 
      ofCanal << setw(2) << setfill(' ') << iCombo[iCompteur] << " - ";
   }
   // Imprimer le dernier nombre.
   ofCanal << setw(2) << setfill(' ') <<  iCombo[iMAX_COMBO - 1] << endl;
}

bool ouvrirFichier(ifstream & ifCanal, const char cNOMFICHIER[])
{
   // Ouvrir le fichier, c'est � dire associer au canal le fichier sur le disque dur. 
   ifCanal.open(cNOMFICHIER, ios::in);

   // Pour assurer l'ouverture du fichier. 
   if (!ifCanal)
   {
      cerr << "Erreur: le fichier " << cNOMFICHIER << " n'a pas pu �tre ouvert correctement." << endl;
      system("pause");
      return false;
   }
}

void lireEnTeteBillet(ifstream & ifCanal)
{
   // Variable jetable, qui sera �cras� apr�s la lecture de chaque ligne de l'ent�te.
   char cEntrepot[iMAX_LARGEUR];
   // Lire chaque ligne de l'ent�te, stock� de nouveau dans la variable jetable. 
   ifCanal.getline(cEntrepot, iMAX_LARGEUR + 1, '\n');
   ifCanal.getline(cEntrepot, iMAX_LARGEUR + 1, '\n');
   ifCanal.getline(cEntrepot, iMAX_LARGEUR + 1, '\n');
}

void lireCombinaisonBillet(ifstream & ifCanal, int iCombo[])
{
   // Variable interm�diaire pour stock� un nombre lu, en tant de cha�ne de caract�res.
   char cNb[10];
   // Boucle pour pouvoir lire chaque nombre. 
   for (int iCompteur = 0; iCompteur < iMAX_COMBO; iCompteur++)
   {
      // Les cinq premiers nombres sont s�par�s par un tiret. 
      if (iCompteur < iMAX_COMBO - 1)
      {
         // On va lire tout ce qu'on peut avant d'arriver au tiret. 
         ifCanal.getline(cNb, 10, '-');
         // On met le nombre dans la cha�ne de nombres entiers qui r�presante la combinaison de l'utilisateur. 
         iCombo[iCompteur] = atoi(cNb);
      }
      // Pour le dernier nombre on va lire jusqu'� temps qu'on passe � la ligne. 
      else
      {
         ifCanal.getline(cNb, 10, '\n');
         iCombo[iCompteur] = atoi(cNb);
      }
   }
}

void afficherBillet(ifstream& ifCanal)
{
   // Variable pour stock� chaque ligne du billet.
   char cLigne[iMAX_LARGEUR];
   
   // On tente de lire la premi�re ligne du fichier.
   ifCanal.getline(cLigne, iMAX_LARGEUR, '\n');
   // On part en boucle, tant que la fin du fichier n'est pas atteint. 
   while (!ifCanal.eof())
   {
      // On imprime chaque ligne lu, et on tente de lire un autre. Si on a atteint la fin du fichier, on va pouvoir sortir du boucle. 
      cout << cLigne << endl;
      ifCanal.getline(cLigne, iMAX_LARGEUR, '\n');
   }
}

float choisirMise(const int iMIN_MISE, const int iMAX_MISE)
{
   // La valeur de chaque limite est multipli� par 100 � sa g�n�ration, pour ensuite diviser
   // le r�sultat et avoir un chiffre en argent (pour accommoder les cennes).
   return (rand() % ((iMAX_MISE * 100) - (iMIN_MISE * 100) + 1) + (iMIN_MISE * 100));
}

void afficherGains(int iNombresIdentique, const float fLOT)
{
   // Variable interm�diaire pour stock� le montant gagn�.
   float fGains = 0;
   // Switch pour d�terminer le montant gagn�, d�pendement combien de nombres sont �gal � la combinaison.
   switch (iNombresIdentique)
   {
   case 3:
      fGains = fLOT * fFACTEUR_TROIS_PAREIL;
      break;
   case 4:
      fGains = fLOT * fFACTEUR_QUATRE_PAREIL;
      break;
   case 5:
      fGains = fLOT * fFACTEUR_CINQ_PAREIL;
      break;
   case 6:
      fGains = fLOT * fFACTEUR_SIX_PAREIL;
      break;
   default:
      break;
   }
   // Afficher le message si l'utilisateur a gagn�.
   if (iNombresIdentique >= 3)
   {
      cout << "Vous gagnez $" << fGains << endl;
   }
   // Sinon, on affiche le message d'encouragement.
   else
   {
      cout << "Meilleure chance la prochaine fois." << endl;
   }
}

int lireNombreSousMenu(const int iMAX, int iChoixMenu)
{
   // Pour lire toutes les b�tises que pourrait taper l'utilisateur, on se cr�e une variable de type cha�ne
   // de caract�res suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNbLu;

   cin.getline(cClavier, sizeof(cClavier), '\n');

   // On lit toute ce que l'utilisateur tape au clavier dans une cha�ne de caract�res
   // qui accepte n'importe quel caract�re.

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande � l'utilisateur

   if (!((cClavier[0] >= '0' && cClavier[0] <= '9') || (cClavier[0] == '-' && (cClavier[1] >= '0' && cClavier[1] <= '9'))))
   {
      for (int iCompteur = 0; iCompteur < iMAXCLAVIER; iCompteur++)
      {
         // Reinitialise cClavier pour �viter certains erreurs.
         cClavier[iCompteur] = NULL;
      }
      // Ligne de tirets.
      cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
      // Message.
      cout << endl << "Vous devez entrer un nombre entre " << iQUITTER << " et " << iMAX << endl;
      system("pause");
      // Retourne au menu.
      validerChoixSousMenu(2, iRETOUR, iMAX_SOUSMENU);
   }
   else
   {
      // Convertir le nombre lu en entier.
      iNbLu = atoi(cClavier);
      // Pour v�rifier que le nombre, maintenant en entier, est bien entre les limites. 
      if (iNbLu > iMAX || iNbLu < iQUITTER)
      {
         // R�initialiser iNbLu.
         iNbLu = NULL;
         // Ligne de tirets.
         cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
         // Message.
         cout << endl << "Vous devez entrer un nombre entre " << iQUITTER << " et " << iMAX << endl;
         system("pause");
         validerChoixSousMenu(2, iRETOUR, iMAX_SOUSMENU);
      }
      else
      {
         return iNbLu;
      }
   }
}

