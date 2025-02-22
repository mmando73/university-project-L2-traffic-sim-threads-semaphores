#include "../include/gantt.h"

// Imprime le diagramme de Gantt qui visualise la durée du passage de chaque véhicule dans le rond-point.
void printGanttDiagram(ganttEntry_t* ganttEntries, int ganttIndex) {
    printf("Diagramme de Gantt :\n"); // Affiche l'en-tête du diagramme de Gantt.
    
    // Itère sur chaque entrée du diagramme de Gantt.
    for (int i = 0; i < ganttIndex; i++) {
        // Pour chaque entrée, imprime l'identifiant du véhicule pour chaque unité de temps qu'il passe dans le rond-point.
        for (int j = 0; j < ganttEntries[i].duration; j++) {
            printf("V%d", ganttEntries[i].vehicleId); // Affiche l'identifiant du véhicule.
            
            // Ajoute un séparateur '|' après chaque unité de temps, sauf après la dernière unité du dernier véhicule.
            if (!(i == ganttIndex - 1 && j == ganttEntries[i].duration - 1)) {
                printf("|");
            }
        }
    }
    printf("\n"); // Nouvelle ligne après la fin du diagramme pour une meilleure lisibilité.
}