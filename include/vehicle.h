/**
 * vehicle.h
 * Définit les structures de données et déclare les fonctions pour la manipulation des véhicules
 * dans le simulateur de gestion du trafic de véhicules autonomes. Ce fichier inclut des définitions
 * pour les véhicules, les arguments passés aux threads de véhicules, et les fonctions de cycle de vie
 * des véhicules dans le rond-point.
 */

#ifndef VEHICLE_H
#define VEHICLE_H

#include "general.h"
#include "gantt.h"

/**
 * Structure représentant un véhicule dans le simulateur.
 * Contient toutes les informations nécessaires pour gérer le passage d'un véhicule à travers le rond-point.
 */
typedef struct vehicle {
    int id;             // Identifiant unique du véhicule
    char entry;         // Lettre représentant la rue d'entrée du véhicule
    int processTime;    // Temps requis pour traverser le rond-point, en secondes
    bool priority;      // Indicateur de priorité, true si le véhicule est prioritaire (ex. ambulance)
} vehicle_t;

/**
 * Structure pour passer des arguments aux threads de véhicule.
 * Cette structure permet de transmettre les données nécessaires aux fonctions de thread.
 */
typedef struct threadArgs {
    vehicle_t *veh;             // Pointeur sur le véhicule associé au thread
    sem_t *roundaboutSem;       // Sémaphore contrôlant l'accès au rond-point
    ganttEntry_t *ganttEntries; // Tableau des entrées de Gantt pour enregistrer les durées
    int *ganttIndex;            // Pointeur sur l'index courant dans le tableau des entrées de Gantt
} threadArgs_t;

/**
 * Simule l'arrivée d'un véhicule au rond-point.
 * @param veh Pointeur sur le véhicule qui arrive.
 */
void arrive(vehicle_t *veh);

/**
 * Simule le traversée du rond-point par le véhicule.
 * @param veh Pointeur sur le véhicule qui traverse.
 * @param ganttEntries Tableau pour enregistrer l'activité du véhicule dans le diagramme de Gantt.
 * @param ganttIndex Index courant pour l'insertion dans le tableau de Gantt.
 */
void traverse(vehicle_t *veh, ganttEntry_t *ganttEntries, int *ganttIndex);


/**
 * Simule la sortie d'un véhicule du rond-point.
 * @param veh Pointeur sur le véhicule qui sort.
 */
void sort(vehicle_t *veh);

/**
 * Fonction exécutée par chaque thread de véhicule.
 * Gère l'intégralité du cycle de vie d'un véhicule à travers le rond-point.
 * @param arg Pointeur sur une structure threadArgs contenant les données nécessaires au thread.
 */
void *vehicleThreadFunction(void *arg);

#endif // VEHICLE_H