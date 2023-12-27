/**
 * @file Item.h
 * Projet sem04-tp-Cpp1-2
 * @author l'�quipe p�dagogique
 * @version 1 - 29/11/2014
 * @brief Sp�cialisation du type Item
 * Structures de donn�es et algorithmes - DUT1 Paris Descartes
 */

#ifndef _ITEM_
#define _ITEM_

struct Carte {
    char lettre;
    int points;
};

// Sp�cialise Item en Cartes .........................
typedef Carte Item;

#endif
