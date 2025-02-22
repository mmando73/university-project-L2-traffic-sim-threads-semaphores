#include "../include/vehicle.h"

// Simule l'arrivée d'un véhicule au rond-point.
void arrive(vehicle_t *veh) {
    // Affiche un message indiquant l'arrivée du véhicule, son point d'entrée et s'il est prioritaire.
    printf("Véhicule V%d arrive depuis %c avec priorité %d entre le rond-point.\n", veh->id, veh->entry, veh->priority);
}

// Simule le passage d'un véhicule à travers le rond-point.
void traverse(vehicle_t *veh, ganttEntry_t *ganttEntries, int *ganttIndex) {
    // Affiche le temps nécessaire pour le passage du véhicule et simule ce passage avec un délai.
    printf("Véhicule V%d traverse le rond-point. Temps nécessaire pour le passage : %d\n", veh->id, veh->processTime);
    sleep(veh->processTime);    // Simule le temps de traversée avec un appel à sleep().
    
    // Enregistre l'activité du véhicule dans le diagramme de Gantt.
    ganttEntries[*ganttIndex].vehicleId = veh->id;
    ganttEntries[*ganttIndex].duration = veh->processTime;
    (*ganttIndex)++;    // Incrémente l'index pour la prochaine entrée de Gantt.
}

// Simule la sortie d'un véhicule du rond-point.
void sort(vehicle_t *veh) {
    // Affiche un message indiquant que le véhicule quitte le rond-point.
    printf("Véhicule V%d sort du rond-point.\n", veh->id);
}

// Fonction exécutée par chaque thread représentant un véhicule.
void *vehicleThreadFunction(void *arg) {
    threadArgs_t *args = (threadArgs_t *)arg;   // Récupère les arguments passés au thread.
    vehicle_t *veh = args->veh;                 // Véhicule à traiter.
    sem_t *roundaboutSem = args->roundaboutSem; // Sémaphore pour contrôler l'accès au rond-point.
    ganttEntry_t *ganttEntries = args->ganttEntries;    // Tableau pour le diagramme de Gantt.
    int *ganttIndex = args->ganttIndex;                 // Indice pour les entrées de Gantt.

    sem_wait(roundaboutSem);    // Attend que le sémaphore soit disponible pour entrer dans le rond-point.
    arrive(veh);                // Simule l'arrivée du véhicule.
    traverse(veh, ganttEntries, ganttIndex);    // Simule le passage du véhicule.
    sort(veh);                  // Simule la sortie du véhicule.
    sem_post(roundaboutSem);    // Libère le sémaphore pour le prochain véhicule.

    pthread_exit(args);         // Termine le thread proprement en renvoyant les arguments pour nettoyage.
}