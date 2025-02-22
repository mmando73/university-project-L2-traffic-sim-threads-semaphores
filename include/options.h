/**
 * options.h
 * Fournit des fonctionnalités pour analyser les options de ligne de commande et les entrées
 * des véhicules pour le simulateur de gestion du trafic de véhicules autonomes.
 * Ce fichier contient des déclarations de fonctions pour traiter les options de la ligne de commande
 * et pour analyser la chaîne d'entrée des véhicules selon les options spécifiées.
 *
 * Fonctions :
 * - isValidEntry : Vérifie si un caractère d'entrée est valide pour identifier un point d'entrée de véhicule.
 * - parseInput : Analyse les arguments de la ligne de commande pour extraire les options et la chaîne d'entrée des véhicules.
 * - processOptions : Traite spécifiquement les options de ligne de commande pour définir les types d'ordonnanceur et les priorités.
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "general.h"
#include "vehicle.h"

/**
 * Vérifie si le caractère donné est un point d'entrée valide pour un véhicule.
 *
 * @param ch Le caractère à vérifier.
 * @return true si le caractère est un point d'entrée valide (A, R, C, E, J), sinon false.
 */
bool isValidEntry(char ch);

/**
 * Traite les options de ligne de commande pour déterminer le type d'ordonnanceur et les priorités.
 *
 * @param argc Nombre d'arguments de la ligne de commande.
 * @param argv Tableau des arguments de la ligne de commande.
 * @param schedulerType Pointeur vers un entier pour stocker le type d'ordonnanceur déterminé par les options.
 */
void processOptions(int argc, char *argv[], unsigned int *schedulerType);

/**
 * Analyse les arguments de la ligne de commande pour configurer le simulateur de trafic.
 *
 * @param argc Nombre d'arguments de la ligne de commande.
 * @param argv Tableau des arguments de la ligne de commande.
 * @param vehicles Pointeur vers le tableau de véhicules qui sera alloué et rempli par cette fonction.
 * @param vehicleCount Pointeur vers un entier où le nombre de véhicules analysés sera stocké.
 * @param schedulerType Pointeur vers un entier où le type d'ordonnanceur choisi sera stocké.
 */
void parseInput(int argc, char *argv[], vehicle_t **vehicles, int *vehicleCount, unsigned int *schedulerType);

#endif // OPTIONS_H