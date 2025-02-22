#include "../include/scheduler.h"

// Compare deux véhicules selon leur temps de traitement pour l'ordonnanceur Shortest Job First (SJF).
int compareSJF(const void *a, const void *b) {
    vehicle_t *vehA = (vehicle_t *)a;
    vehicle_t *vehB = (vehicle_t *)b;
    // Retourne la différence des temps de traitement pour déterminer l'ordre.
    return vehA->processTime - vehB->processTime;
}

// Compare deux véhicules en donnant la priorité aux véhicules prioritaires pour l'ordonnanceur First Come, First Served (FCFS).
int comparePriorityFCFS(const void *a, const void *b) {
    vehicle_t *vehA = (vehicle_t *)a;
    vehicle_t *vehB = (vehicle_t *)b;
    // Priorise les véhicules prioritaires, sinon compare par ordre d'arrivée.
    if (vehA->priority != vehB->priority)
        return vehB->priority - vehA->priority;
    return vehA->id - vehB->id;
}

// Compare deux véhicules pour un ordonnanceur Shortest Job First (SJF) en tenant compte des priorités.
int comparePrioritySJF(const void *a, const void *b) {
    vehicle_t *vehA = (vehicle_t *)a;
    vehicle_t *vehB = (vehicle_t *)b;
    // Priorise les véhicules prioritaires, puis compare par temps de traitement si les priorités sont égales.
    if (vehA->priority != vehB->priority)
        return vehB->priority - vehA->priority;
    return vehA->processTime - vehB->processTime;
}

// Ordonnance les véhicules selon le type spécifié à l'aide de la fonction de tri qsort() appropriée.
void scheduler(unsigned int schedulerType, vehicle_t* vehicles, int numVehicles) {
        switch(schedulerType) {
        case 1: 
            // FCFS : par défaut les véhicules sont listés dans l'ordre d'arrivée. Aucun tri n'est nécessaire.
            break;
        case 2: 
            // Tri des véhicules selon SJF sans priorité.
            qsort(vehicles, numVehicles, sizeof(vehicle_t), compareSJF); 
            break;
        case 3:
            // Tri des véhicules selon FCFS avec priorité.
            qsort(vehicles, numVehicles, sizeof(vehicle_t), comparePriorityFCFS);
            break;
        case 4: 
             // Tri des véhicules selon SJF avec priorité.
            qsort(vehicles, numVehicles, sizeof(vehicle_t), comparePrioritySJF);
            break;     
    }
}
