#include "../include/options.h"
#include "../include/vehicle.h"
#include "../include/scheduler.h"
#include "../include/gantt.h"

sem_t roundaboutSem; // Déclaration d'une sémaphore pour contrôler l'accès au rond-point.

int main(int argc, char *argv[]) {
    // Vérification des arguments fournis lors du lancement du programme.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-o ordonnanceur] [-p priorité] séquence de véhicules\n", argv[0]);
        return 1;
    }

    vehicle_t *vehicles;        // Tableau pour stocker les informations des véhicules.
    int numVehicles;            // Nombre de véhicules à simuler.
    pthread_t *threads;         // Tableau de threads pour chaque véhicule.
    unsigned int schedulerType; // Type de l'ordonnanceur sélectionné par les options.

    // Analyse les options de ligne de commande et prépare les données des véhicules.
    parseInput(argc, argv, &vehicles, &numVehicles, &schedulerType);
    threads = malloc(numVehicles * sizeof(pthread_t));
    if (threads == NULL) {
            fprintf(stderr, "main() : Erreur de malloc()");
            exit(EXIT_FAILURE);
        }

    ganttEntry_t ganttEntries[numVehicles]; // Tableau pour enregistrer les données pour le diagramme de Gantt.
    int ganttIndex = 0;

    // Initialisation de la sémaphore.
    sem_init(&roundaboutSem, 0, 1);         

    // Applique l'ordonnancement spécifié pour organiser l'ordre de passage des véhicules.
    scheduler(schedulerType, vehicles, numVehicles);
    
    // Création de threads pour gérer le passage de chaque véhicule à travers le rond-point.
    for (int i = 0; i < numVehicles; i++) {
        threadArgs_t *args = malloc(sizeof(threadArgs_t));  // Allocation de la structure pour les arguments des threads.
        args->veh = &vehicles[i];
        args->roundaboutSem = &roundaboutSem;
        args->ganttEntries = ganttEntries;
        args->ganttIndex = &ganttIndex;

        // Création du thread pour le véhicule.
        if (pthread_create(&threads[i], NULL, vehicleThreadFunction, (void *)args) != 0) {
            perror("main.c : Échec de la création du thread");
            free(args); // Nettoyage en cas d'échec de la création du thread.
            return -1;
        }
    }

    // Attente de la terminaison de tous les threads et libération des ressources allouées.
    for (int i = 0; i < numVehicles; i++) {
        void *status;
        pthread_join(threads[i], &status);  // Attend que le thread termine.
        free(status);   // Libère la mémoire allouée pour les arguments du thread.
    }

    // Affichage du diagramme de Gantt basé sur les activités enregistrées.
    printGanttDiagram(ganttEntries, ganttIndex);

    // Nettoyage final : libération des ressources et destruction de la sémaphore.
    free(threads);
    free(vehicles);
    sem_destroy(&roundaboutSem);
    return 0;
}