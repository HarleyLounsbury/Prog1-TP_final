// But: Programme de loto.
// Auteur: Harley Lounsbury
// Date Commencé: 22/11/2018
// Date Livrable: 12/12/2018 à 18h00

#include <iostream>
#include <iomanip>
#include <fstream>
#include "TPfinal - 1063162.h"

using namespace std;

// Déclaration de constantes.
// Largeur des menus et entêtes.
const int iMAX_LARGEUR = 44;
const int iMAX_LARGEUR_FICHIER = 27;

// Titres principales.
const char cTITRE[] = "LOTO DU BONHEUR";
const char cTITRE_SOUSMENU[] = "Acheter un billet";
// Sous-Titre.
const char cSOUS_TITRE[] = "Présenté par : Harley Lounsbury";
// Options de menu.
const char cOPTION1[] = "1. Acheter un billet";
const char cOPTION2[] = "2. Afficher un billet";
const char cOPTION3[] = "3. Valider un billet";
const char cOPTION_QUITTER[] = "0. Quitter le programme";
// Options de sous-menu 1.
const char cOPTION_ACHETER1[] = "1. Choisir ses  propres numéros";
const char cOPTION_ACHETER2[] = "2. Choisir les numéros au hasard";
const char cOPTION_RETOUR[] = "0. Revenir au menu précédent";
// Pour les valeurs possible dans le choix de nombres.
const int iMIN_VALEUR = 1;
const int iMAX_VALEUR = 49;
// Pour le calcul du gain. 
// Les nombres sont aussi petit car le gain est en fonction d'un pourcentage du lot basé sur combien de nombres sont pareil. 
const float fFACTEUR_TROIS_PAREIL = 0.001;
const float fFACTEUR_QUATRE_PAREIL = 0.01;
const float fFACTEUR_CINQ_PAREIL = 0.1;
const float fFACTEUR_SIX_PAREIL = 1;

// Pour afficher le menu principale. 
void afficherMenu()
{
   // Éffacer l'écran avant d'afficher.
   system("cls");
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
   // Titre, centré.
   cout << setw((iMAX_LARGEUR - strlen(cTITRE)) / 2) << setfill(' ') << " " << cTITRE << endl;
   // Sous-titre, centré.
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

   // On fait appel à la fonction qui pose les questions et qui s'occupe de gérer la réponse.
   return demanderChoix(iMAXOPTIONS, iChoixMenu);
}

int demanderChoix(const int iMAX, int iChoixMenu)
{
   // Variable intermédiaire. 
   int iNb;
   // Demander à l'utilisateur son choix. 
   cout << "Veuillez entrer votre choix -->";
   if(iChoixMenu == 1)
      iNb = lireNombre(iMAX, iChoixMenu);

   if (iChoixMenu == 2)
      iNb = lireNombreSousMenu(iMAX, iChoixMenu);

   return iNb;
}

int lireNombre(const int iMAX, int iChoixMenu)
{
   // Pour lire toutes les bétises que pourrait taper l'utilisateur, on se crée une variable de type chaîne
   // de caractères suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNbLu;

   cin.getline(cClavier, sizeof(cClavier), '\n');

   // On lit toute ce que l'utilisateur tape au clavier dans une chaîne de caractères
   // qui accepte n'importe quel caractère.

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande à l'utilisateur

   if (!((cClavier[0] >= '0' && cClavier[0] <= '9') || (cClavier[0] == '-' && (cClavier[1] >= '0' && cClavier[1] <= '9'))))
   {
      for (int iCompteur = 0; iCompteur < iMAXCLAVIER; iCompteur++)
      {
         // Reinitialise cClavier pour éviter certains erreurs.
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
      // Pour vérifier que le nombre, maintenant en entier, est bien entre les limites. 
      if (iNbLu > iMAX || iNbLu < iQUITTER)
      {
         // Réinitialiser iNbLu.
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
   // Éffacer l'écran avant d'afficher. 
   system("cls");
   // Ligne de tirets.
   cout << setw(iMAX_LARGEUR) << setfill('-') << "-" << setfill(' ') << endl;
   // Afficher le sous-titre, centré.
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
   // Appel à la fonction pour afficher. 
   afficherSousMenu();

   // Demander le choix de l'utilisateur.
   return demanderChoix(iMAXOPTIONS, iChoixMenu);
}

void demanderNom(char cNomBillet[])
{
   // Éffacer l'écran avant d'afficher.
   system("cls");

   // Tableaux temporaire pour stocké ce que l'utilisateur frappe, sans créer un "Buffer overflow"
   const int iMAX_CLAVIER = 8190;
   char cClavier[iMAX_CLAVIER + 1];
   // Message.
   cout << "Entrez le nom du joueur (maximum 20 caractères) -->";
   // Le nom sur le billet peut être n'importe quoi. 
   cin.getline(cClavier, sizeof(cClavier), '\n');

   // Toute la reste de la fonction à partir d'ici est franchement de patantage.
   // Avec plusieurs tests, j'ai quasiment toujours été capable de créer un "buffer overflow" à quelque part. 
   // Chaque boucle que j'ai ajouté a aidé, mais je comprend que ce complique le code. 
   // Il doit avoir des places qui ne sont pas nécessaire comme tel, mais je trouve que l'ensemble fait fonctionner la fonction
   // et comme ca c'est plus sécuritaire. 
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
      cout << "Erreur: le nom du joueur de peut comporter plus de 20 caractères." << endl;
      cout << "Entrez le nom du joueur (maximum 20 caractères) -->";
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
   // Message d'erreur en cas d'échec. 
   if (!ofCanal)
   {
      cerr << "Erreur : Le fichier " << cNomFichier << " n'a pas pu se créer" << endl;
      system("pause");
      exit(1);
   }
}

void ecrireEnTeteBillet(ofstream & ofCanal)
{
   // Ligne de tirets.
   ofCanal << setw(iMAX_LARGEUR_FICHIER) << setfill('-') << "-" << setfill(' ') << endl;
   // Titre, centré.
   ofCanal << setw((iMAX_LARGEUR_FICHIER - strlen(cTITRE)) / 2) << setfill(' ') << " " << cTITRE << endl;
   // Ligne de tirets.
   ofCanal << setw(iMAX_LARGEUR_FICHIER) << setfill('-') << "-" << setfill(' ') << endl;
}

void saisirCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Variable intermédiaire.
   int iNbSaisi;
   // On va poser la question dans un boucle FOR, car on sait combien de fois on doit la poser. 
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE; iCompteur++)
   {
      // On va lire chaque nombre. 
      // J'aurai pu partir iCompteur à 1, aller jusqu'à iCompteur <= iMAX_NOMBRE, et ne pas avoir besoin de ajouter 1 pour l'affichage.
      // Dans ce cas, il aurait fallu que plus tard je fais iCombo[iCompteur - 1] = iNbSaisi. 
      // En bref, je trouve ca revient au même, et j'ai décidé d'y aller comme ca. 
      cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
      // Appel à la fonction qui s'occupe de bien saisir le nombre.
      iNbSaisi = saisirNombre();
      
      // On doit vérifier si le nombre saisi est bien entre les limites.
      while (iNbSaisi < iMIN_VALEUR || iNbSaisi > iMAX_VALEUR)
      {
         cout << "Erreur: Le nombre doit être compris entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " seulement." << endl;
         cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
         iNbSaisi = NULL;
         iNbSaisi = saisirNombre();
      }
      // On va vérifier que le nombre saisi n'a pas été déjà saisi.
      // Avant de sortir de la boucle WHILE, on va aussi vérifier que le nombre est bien entre les limites. 
      while (existe(iNbSaisi, iCombo, iCompteur))
      {
         cout << "Vous avez déjà choisi ce nombre. Veuillez recommencer." << endl;
         cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
         iNbSaisi = NULL;
         iNbSaisi = saisirNombre();
         while (iNbSaisi < iMIN_VALEUR || iNbSaisi > iMAX_VALEUR)
         {
            cout << "Erreur: Le nombre doit être compris entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " seulement." << endl;
            cout << "Veuillez entrer le nombre #" << iCompteur + 1 << " entre " << iMIN_VALEUR << " et " << iMAX_VALEUR << " -->";
            iNbSaisi = NULL;
            iNbSaisi = saisirNombre();
         }
      }
      // Une fois que le nombre saisi est trouvé d'être valide, on peut stocker ce nombre dans la chaîne d'entiers. 
      iCombo[iCompteur] = iNbSaisi;
   }
}

int saisirNombre()
{
   // Pour lire toutes les bétises que pourrait taper l'utilisateur, on se crée une variable de type chaîne de caractères
   // suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNb;

   // On lit toute ce que l'utilisateur tape au clavier dans une chaîne de caractères
   // qui accepte n'importe quel caractère.
   cin.getline(cClavier, sizeof(cClavier), '\n');

   // Il faut s'assurer que cClavier commence par un chiffre ou par un tiret suivi d'un chiffre. Sinon on redemande à l'utilisateur.

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
   // On va devoir vérifier notre nombre contre toutes les nombres déjà saisis.
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
   // Variable intermédiaire.
   int iNbHasard;
   // Boucle pour passer les nombres généres dans la chaîne d'entiers. 
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE; iCompteur++)
   {
      iNbHasard = choisirNombreAuHasard(iMIN_VALEUR, iMAX_VALEUR);
      // Vérifier que le nombre n'a pas été déjà généré. 
      while (existe(iNbHasard, iCombo, iCompteur))
      {
         iNbHasard = NULL;
         iNbHasard = choisirNombreAuHasard(iMIN_VALEUR, iMAX_VALEUR);
      }
      // Stocker le nombre dans la chaîne d'entiers. 
      iCombo[iCompteur] = iNbHasard;
   }
}

int choisirNombreAuHasard(const int iMIN, const int iMAX)
{
   // Générer le nombre au hasard, compris entre les limites fournies. 
   return rand() % (iMAX - iMIN + 1) + iMIN;
}

void afficherCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Appel à la fonction pour mettre la combinaison en ordre croissant.
   trierCombinaison(iCombo, iMAX_NOMBRE);
   // Boucle pour traiter chaque nombre de la chaîne d'entiers. 
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE - 1; iCompteur++)
   {
      cout << setw(2) << setfill(' ') << iCombo[iCompteur] << " - ";
   }
   cout << iCombo[iMAX_NOMBRE - 1] << endl;
}

void initialiserCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Boucle pour traiter chaque nombre de la chaîne d'entiers.
   for (int iCompteur = 0; iCompteur < iMAX_NOMBRE; iCompteur++)
   {
      // À chaque passe, on met le valeur à 0. 
      iCombo[iCompteur] = 0;
   }
}

void trierCombinaison(int iCombo[], const int iMAX_NOMBRE)
{
   // Première boucle pour compter le nombre de passes.
   for (int iNombreDePasses = 1; iNombreDePasses <= iMAX_NOMBRE; iNombreDePasses++)
   {
      // Deuxième boucle pour traiter le tableau index par index.
      for (int iCompteur = 0; iCompteur < iMAX_NOMBRE - 1; iCompteur++)
      {
         // On va comparé deux nombres qui sont côte à côte, et si celui avec le plus petit index est plus grand, on appelle 
         // la fonction pour les échanger de place. 
         if (iCombo[iCompteur] > iCombo[iCompteur + 1])
         {
            permuter(iCombo[iCompteur], iCombo[iCompteur + 1]);
         }
      }
   }
}

void permuter(int & iChiffre1, int & iChiffre2)
{
   // Variable intermèdiaire.
   int iTemp;
   // On copie la valeur du premier nombre dans la variable.
   iTemp = iChiffre1;
   // On écrase le premier avec le deuxième.
   iChiffre1 = iChiffre2;
   // On copie le premier dans le deuxième.
   iChiffre2 = iTemp;
}

int validerCombinaison(int iCombo1[], const int iCOMBO_GAGNANTE[], int iMAX_NOMBRE)
{
   // Pour comparer les deux tableau, on a besoin d'un compteur pour tenir compte à chaque fois il y a deux chiffres identiques.
   int iCompteur = 0;
   // Première boucle pour l'index du premier tableau.
   for (int iIndex1 = 0; iIndex1 < iMAX_NOMBRE; iIndex1++)
   {
      // Avec la valeur d'un nombre dans le premier tableau, on va comparer à tous les autres nombres dans le tableau gagnant. 
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
   // Variable pour stocké le nombre de nombres identique.
   int iNombrePareil = 0;
   // Éffacer l'écran avant d'afficher.
   system("cls");
   // Titre.
   cout << "Valider le billet" << endl;
   // Montrer le montant du lot complet.
   cout << "La mise est de $" << fixed << setprecision(2) << fLOT << endl;
   // Afficher la combinaison gagnante, choisie à l'ouverture du programme. 
   cout << "La combinaison gagnante: ";
   afficherCombinaison(iComboGagnante, iMAX_COMBO);
   // Débarassage de l'entête. 
   lireEnTeteBillet(ifCanal);
   // On tente de lire une première combinaison.
   lireCombinaisonBillet(ifCanal, iComboAValider);
   // Boucle jusqu'à fin du fichier.
   while (!ifCanal.eof())
   {
      // Afficher la combinaison lue.
      cout << "La combinaison du joueur: ";
      afficherCombinaison(iComboAValider, iMAX_COMBO);
      // Voir combien de nombres sont identiques à la combinaison gagnante. 
      iNombrePareil = validerCombinaison(iComboAValider, iComboGagnante, iMAX_COMBO);
      cout << "Nombres identiques: " << iNombrePareil << endl;
      // Appel à la fonction pour afficher les gains (s'il y en a, sinon, le message d'encouragement).
      afficherGains(iNombrePareil, fLOT);
      // On tente de lire une prochaine combinaison. 
      lireCombinaisonBillet(ifCanal, iComboAValider);
   }
}

void ecrireCombinaisonDansBillet(ofstream & ofCanal, int iCombo[])
{
   // Boucle pour traiter la chaîne d'entiers (5 premiers nombres.).
   for (int iCompteur = 0; iCompteur < iMAX_COMBO - 1; iCompteur++)
   {
      // Imprimer dans le ficher les nombres, séparés par un tiret. 
      ofCanal << setw(2) << setfill(' ') << iCombo[iCompteur] << " - ";
   }
   // Imprimer le dernier nombre.
   ofCanal << setw(2) << setfill(' ') <<  iCombo[iMAX_COMBO - 1] << endl;
}

bool ouvrirFichier(ifstream & ifCanal, const char cNOMFICHIER[])
{
   // Ouvrir le fichier, c'est à dire associer au canal le fichier sur le disque dur. 
   ifCanal.open(cNOMFICHIER, ios::in);

   // Pour assurer l'ouverture du fichier. 
   if (!ifCanal)
   {
      cerr << "Erreur: le fichier " << cNOMFICHIER << " n'a pas pu être ouvert correctement." << endl;
      system("pause");
      return false;
   }
}

void lireEnTeteBillet(ifstream & ifCanal)
{
   // Variable jetable, qui sera écrasé aprés la lecture de chaque ligne de l'entête.
   char cEntrepot[iMAX_LARGEUR];
   // Lire chaque ligne de l'entête, stocké de nouveau dans la variable jetable. 
   ifCanal.getline(cEntrepot, iMAX_LARGEUR + 1, '\n');
   ifCanal.getline(cEntrepot, iMAX_LARGEUR + 1, '\n');
   ifCanal.getline(cEntrepot, iMAX_LARGEUR + 1, '\n');
}

void lireCombinaisonBillet(ifstream & ifCanal, int iCombo[])
{
   // Variable intermèdiaire pour stocké un nombre lu, en tant de chaîne de caractères.
   char cNb[10];
   // Boucle pour pouvoir lire chaque nombre. 
   for (int iCompteur = 0; iCompteur < iMAX_COMBO; iCompteur++)
   {
      // Les cinq premiers nombres sont séparés par un tiret. 
      if (iCompteur < iMAX_COMBO - 1)
      {
         // On va lire tout ce qu'on peut avant d'arriver au tiret. 
         ifCanal.getline(cNb, 10, '-');
         // On met le nombre dans la chaîne de nombres entiers qui répresante la combinaison de l'utilisateur. 
         iCombo[iCompteur] = atoi(cNb);
      }
      // Pour le dernier nombre on va lire jusqu'à temps qu'on passe à la ligne. 
      else
      {
         ifCanal.getline(cNb, 10, '\n');
         iCombo[iCompteur] = atoi(cNb);
      }
   }
}

void afficherBillet(ifstream& ifCanal)
{
   // Variable pour stocké chaque ligne du billet.
   char cLigne[iMAX_LARGEUR];
   
   // On tente de lire la première ligne du fichier.
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
   // La valeur de chaque limite est multiplié par 100 à sa génération, pour ensuite diviser
   // le résultat et avoir un chiffre en argent (pour accommoder les cennes).
   return (rand() % ((iMAX_MISE * 100) - (iMIN_MISE * 100) + 1) + (iMIN_MISE * 100));
}

void afficherGains(int iNombresIdentique, const float fLOT)
{
   // Variable intermèdiaire pour stocké le montant gagné.
   float fGains = 0;
   // Switch pour déterminer le montant gagné, dépendement combien de nombres sont égal à la combinaison.
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
   // Afficher le message si l'utilisateur a gagné.
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
   // Pour lire toutes les bétises que pourrait taper l'utilisateur, on se crée une variable de type chaîne
   // de caractères suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNbLu;

   cin.getline(cClavier, sizeof(cClavier), '\n');

   // On lit toute ce que l'utilisateur tape au clavier dans une chaîne de caractères
   // qui accepte n'importe quel caractère.

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande à l'utilisateur

   if (!((cClavier[0] >= '0' && cClavier[0] <= '9') || (cClavier[0] == '-' && (cClavier[1] >= '0' && cClavier[1] <= '9'))))
   {
      for (int iCompteur = 0; iCompteur < iMAXCLAVIER; iCompteur++)
      {
         // Reinitialise cClavier pour éviter certains erreurs.
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
      // Pour vérifier que le nombre, maintenant en entier, est bien entre les limites. 
      if (iNbLu > iMAX || iNbLu < iQUITTER)
      {
         // Réinitialiser iNbLu.
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

