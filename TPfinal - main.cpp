// But: Programme de loto.
// Auteur: Harley Lounsbury
// Date Commencé: 22/11/2018
// Date Livrable: 12/12/2018 à 18h00



// Bibliothèques nécessaire pour le bon fonctionnement du programme.
// Permet d'afficher et ramasser des données de l'utilisateur.
#include <iostream>

// Permet le manipulation de caractères et chiffres.
#include <iomanip>

// Permet le manipulation de fichiers en entrant et sortant.
#include <fstream>

// Bibliothèque fait maison.
#include "TPfinal - 1063162.h"

// Permet l'utilisation de l'éspace de noms std; un regroupement de noms.
using namespace std;

// Fonction principale du programme.
int main()
{
   // La fonction setlocale permet d'afficher de caractères accentués.
   setlocale(LC_ALL, "");

   // Permet d'initialiser le random seed
   srand(time(NULL));

   // Déclaration de variables.
   int iChoixBillet;
   int iChoixAcheterBillet;
   // Pour le nom d'usager.
   char cNom[iMAX_NOM] = "";
   // Pour le nom d'un billet existant.
   char cNomBillet[iMAX_NOM] = "";

   // Tableau pour  les numéros choisis par l'utilisateur.
   int iCombinaison[iMAX_COMBO];  

   // Tableau pour stocké les valeurs du billet gagnant.
   int iCombinaisonGagnante[iMAX_COMBO];
   // On va toute de suite générer la combinaison.
   choisirCombinaisonAuHasard(iCombinaisonGagnante, iMAX_COMBO);
   // On va aussi générer la valeur du lot.  
   const float fLOT = choisirMise(iMIN_MISE, iMAX_MISE) / 100;

   // Déclaration de variables pour établir les liens vers les fichiers d'entrée et de sortie
   ifstream ifFichierEntree;
   ofstream ofFichierSortie;

   // Déclare les noms des fichiers. Maximum est le maximum nombre de caractères dans un nom + .txt.
   char cNomFichierEntree[iMAX_NOM + 4];
   char cNomFichierSortie[iMAX_NOM + 4];

   // Afficher le menu principale. 
   iChoixBillet = validerChoixMenu(1, iQUITTER, iMAX_MENUPRINCIPALE);

   // Tant que l'utilisateur ne veut pas quitter. 
   while (iChoixBillet != iQUITTER)
   {
      switch (iChoixBillet)
      {
      case iACHETER_UN_BILLET:
         demanderNom(cNom);
         strcpy_s(cNomFichierSortie, cNom);
         strcat_s(cNomFichierSortie, ".txt");
         creerFichier(ofFichierSortie, cNomFichierSortie);
         ecrireEnTeteBillet(ofFichierSortie);
         iChoixAcheterBillet = validerChoixSousMenu(2, iRETOUR, iMAX_SOUSMENU);

         while (iChoixAcheterBillet != iRETOUR)
         {
            switch (iChoixAcheterBillet)
            {
            case iCHOISIR_SES_NUMEROS:
               system("cls");
               afficherCombinaison(iCombinaisonGagnante, iMAX_COMBO);
               saisirCombinaison(iCombinaison, iMAX_COMBO);
               afficherCombinaison(iCombinaison, iMAX_COMBO);
               iChoixAcheterBillet = validerChoixSousMenu(iCHOISIR_SES_NUMEROS, iRETOUR, iMAX_SOUSMENU);
               ecrireCombinaisonDansBillet(ofFichierSortie, iCombinaison);
               initialiserCombinaison(iCombinaison, iMAX_COMBO);
               break;  
            case iNUMEROS_AU_HASARD:
               choisirCombinaisonAuHasard(iCombinaison, iMAX_COMBO);
               system("cls");
               afficherCombinaison(iCombinaison, iMAX_COMBO);
               ecrireCombinaisonDansBillet(ofFichierSortie, iCombinaison);
               initialiserCombinaison(iCombinaison, iMAX_COMBO);
               system("pause");
               iChoixAcheterBillet = validerChoixSousMenu(iNUMEROS_AU_HASARD, iRETOUR, iMAX_SOUSMENU);
               break;
            default:
               break;
            }
         }
         // Fermer le fichier du joueur avant de retourner au menu principale.
         ofFichierSortie.close();
         break;
      case iAFFICHER_UN_BILLET:
         demanderNom(cNomBillet);
         strcpy_s(cNomFichierEntree, cNomBillet);
         strcat_s(cNomFichierEntree, ".txt");
         if (!(ouvrirFichier(ifFichierEntree, cNomFichierEntree)))
         {
            break;
         }
         afficherBillet(ifFichierEntree);
         ifFichierEntree.close();
         system("pause");
         break;
      case iVALIDER_UN_BILLET:
         demanderNom(cNomBillet);
         strcpy_s(cNomFichierEntree, cNomBillet);
         strcat_s(cNomFichierEntree, ".txt");
         ouvrirFichier(ifFichierEntree, cNomFichierEntree);
         afficherValidation(iCombinaisonGagnante, iCombinaison, ifFichierEntree, fLOT);
         ifFichierEntree.close();
         system("pause");
         break;
      case iQUITTER:
         break;
      }
      iChoixBillet = validerChoixMenu(1, iQUITTER, iMAX_MENUPRINCIPALE);
   }

   // Pour assurer le bon fonctionnement du programme, on retourne 0 dans le cas qu'il a executer sans erreur.
   return 0;
}