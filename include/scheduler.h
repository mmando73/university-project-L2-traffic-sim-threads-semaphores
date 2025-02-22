/**
 * scheduler.h
 * Déclarations des fonctions pour la gestion de l'ordonnancement des véhicules autonomes dans le simulateur de rond-point.
 * Inclut des fonctions de comparaison pour différents types d'ordonnanceurs ainsi qu'une fonction d'ordonnancement principale.
 *
 * Fonctions de comparaison :
 * Ces fonctions sont utilisées pour trier les véhicules selon différents critères en fonction du type d'ordonnanceur choisi.
 *
 * Fonction d'ordonnanceur :
 * Applique un algorithme d'ordonnancement pour déterminer l'ordre de passage des véhicules à travers le rond-point.
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "general.h"
#include "vehicle.h"

/**
 * Compare deux véhicules selon la durée nécessaire pour traverser le rond-point (Shortest Job First).
 *
 * @param a Pointeur vers le premier véhicule (vehicle_t).
 * @param b Pointeur vers le deuxième véhicule (vehicle_t).
 * @return Un entier négatif si 'a' a une durée inférieure à 'b', zéro si égales, positif si 'a' a une durée supérieure.
 */
int compareSJF(const void *a, const void *b);

/**
 * Compare deux véhicules en donnant la priorité aux véhicules prioritaires, puis en utilisant l'ordre d'arrivée (First Come First Served).
 *
 * @param a Pointeur vers le premier véhicule (vehicle_t).
 * @param b Pointeur vers le deuxième véhicule (vehicle_t).
 * @return Un entier négatif si 'a' est prioritaire ou est arrivé en premier, zéro si égaux, positif sinon.
 */
int comparePriorityFCFS(const void *a, const void *b);

/**
 * Compare deux véhicules en donnant la priorité aux véhicules prioritaires, puis selon la durée nécessaire pour traverser (Shortest Job First).
 *
 * @param a Pointeur vers le premier véhicule (vehicle_t).
 * @param b Pointeur vers le deuxième véhicule (vehicle_t).
 * @return Un entier négatif si 'a' est prioritaire ou nécessite moins de temps pour traverser, zéro si égaux, positif sinon.
 */
int comparePrioritySJF(const void *a, const void *b);

/**
 * Fonction principale pour ordonnancer les véhicules selon le type spécifié en utilisant qsort().
 *
 * @param schedulerType Type de l'ordonnanceur (1 pour FCFS sans priorité, 2 pour SJF sans priorité, etc.).
 * @param vehicles Tableau de véhicules à ordonnancer.
 * @param numVehicles Nombre de véhicules dans le tableau.
 */
void scheduler(unsigned int schedulerType, vehicle_t* vehicles, int numVehicles);

#endif // SCHEDULER_H