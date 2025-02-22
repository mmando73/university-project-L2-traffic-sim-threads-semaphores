/** 
 * gantt.h
 * En-tête pour la définition de la structure et des fonctions liées au diagramme de Gantt.
 * Ce fichier contient la définition de la structure ganttEntry_t, qui est utilisée pour stocker
 * les informations de chaque entrée du diagramme de Gantt, telles que l'identifiant du véhicule
 * et la durée de son passage dans le rond-point.
 * Il fournit également la déclaration de la fonction printGanttDiagram, qui est responsable
 * de l'affichage du diagramme de Gantt, illustrant visuellement l'ordonnancement et la durée
 * des passages des véhicules à travers le rond-point.
 */

#ifndef GANTT_H
#define GANTT_H

#include "general.h"

typedef struct ganttEntry {
    int vehicleId;          // Identifiant du véhicule.   
    int duration;           // Durée du passage du véhicule dans le rond-point.
} ganttEntry_t;

/**
 * Affiche un diagramme de Gantt pour visualiser l'ordonnancement et la durée des passages des véhicules dans le rond-point.
 * Chaque véhicule est représenté par une série de segments, indiquant la durée de son passage.
 *
 * @param ganttEntries Un tableau de structures ganttEntry_t, chaque entrée contient:
 *        - vehicleId: Identifiant du véhicule.
 *        - duration: Durée du passage du véhicule dans le rond-point.
 *        Ce tableau doit être préalablement rempli avant d'appeler cette fonction.
 *
 * @param ganttIndex Nombre d'entrées dans le tableau ganttEntries, indiquant le nombre de véhicules à afficher.
 *
 * Fonctionnement:
 * La fonction parcourt chaque entrée du tableau 'ganttEntries'. Pour chaque véhicule, elle affiche:
 * - 'V<vehicleId>|' répété 'duration' fois pour chaque unité de temps.
 * Le dernier véhicule affiché n'ajoute pas de barre verticale supplémentaire à la fin.
 *
 * Exemple d'utilisation:
 * ganttEntry_t entries[3] = {{1, 3}, {2, 2}, {3, 1}};
 * printGanttDiagram(entries, 3); // Affichera: V1|V1|V1|V2|V2|V3
 */
void printGanttDiagram(ganttEntry_t* ganttEntries, int ganttIndex);

#endif // GANTT_H