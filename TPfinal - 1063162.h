// But: Programme de loto.
// Auteur: Harley Lounsbury
// Date Commencé: 22/11/2018
// Date Livrable: 12/12/2018 à 18h00

#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

// Déclaration des constantes

// Pour le maximum nombre d'options dans le menu PRINCIPALE.
const int iMAX_MENUPRINCIPALE = 3;
// Pour les options du menu PRINCIPALE.
const int iACHETER_UN_BILLET = 1;
const int iAFFICHER_UN_BILLET = 2;
const int iVALIDER_UN_BILLET = 3;
const int iQUITTER = 0;
// Pour le maximum nombre d'options dans le SOUS-MENU.
const int iMAX_SOUSMENU = 2;
// Pour le maximum nombre de caractères dans un nom.
const int iMAX_NOM = 20;
// Pour les options du sous-menu "Acheter un billet".
const int iCHOISIR_SES_NUMEROS = 1;
const int iNUMEROS_AU_HASARD = 2;
const int iRETOUR = 0;
// Pour le nombre de chiffres dans un combinaison.
const int iMAX_COMBO = 6;
// Le minimum et maximum valeur du lot.
const int iMIN_MISE = 2000;
const int iMAX_MISE = 7500;


using namespace std;

// Déclaration de fonctions.
void afficherMenu();
int validerChoixMenu(int iChoixMenu, const int iPOURQUITTER, const int iMAXOPTIONS);
int demanderChoix(const int iMAX, int iChoixMenu);
int lireNombre(const int iMAX, int iChoixMenu);
void afficherSousMenu();
int validerChoixSousMenu(int iChoixMenu, const int iPOURRETOURNER, const int iMAXOPTIONS);
void demanderNom(char cNomBillet[]);
void creerFichier(ofstream& ofCanal, char cNomFichier[]);
void ecrireEnTeteBillet(ofstream& ofCanal);
void saisirCombinaison(int iCombo[], const int iMAX_NOMBRE);
int saisirNombre();
bool existe(int iNombreAVerifier, int iCombo[], int iPosition);
void choisirCombinaisonAuHasard(int iCombo[], const int iMAX_NOMBRE);
int choisirNombreAuHasard(const int iMIN, const int iMAX);
void afficherCombinaison(int iCombo[], const int iMAX_NOMBRE);
void initialiserCombinaison(int iCombo[], const int iMAX_NOMBRE);
void trierCombinaison(int iCombo[], const int iMAX_NOMBRE);
void permuter(int& iChiffre1, int& iChiffre2);
int validerCombinaison(int iCombo1[], const int iCOMBO_GAGNANTE[], int iMAX_NOMBRE);
void afficherValidation(int iComboGagnante[], int iComboAValider[], ifstream& ifCanal, const float fLOT);
void ecrireCombinaisonDansBillet(ofstream& ofCanal, int iCombo[]);
bool ouvrirFichier(ifstream& ifCanal, const char cNOMFICHIER[]);
void lireEnTeteBillet(ifstream& ifCanal);
void lireCombinaisonBillet(ifstream& ifCanal, int iCombo[]);
void afficherBillet(ifstream& ifCanal);
float choisirMise(const int iMIN_MISE, const int iMAX_MISE);
void afficherGains(int iNombresIdentique, const float fLOT);
int lireNombreSousMenu(const int iMAX, int iChoixMenu);