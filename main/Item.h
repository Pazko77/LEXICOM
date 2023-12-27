/**
 * @file Item.h
 * Projet sem04-tp-Cpp1-2
 * @author l'équipe pédagogique
 * @version 1 - 29/11/2014
 * @brief Spécialisation du type Item
 * Structures de données et algorithmes - DUT1 Paris Descartes
 */

#ifndef _ITEM_
#define _ITEM_

struct Carte {
    char lettre;
    int points;
};

// Spécialise Item en Cartes .........................
typedef Carte Item;

#endif
