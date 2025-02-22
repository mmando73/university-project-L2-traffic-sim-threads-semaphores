#include "../include/options.h"

// Vérifie si un caractère donné représente une entrée valide pour le point de départ d'un véhicule.
bool isValidEntry(char ch) {
    // Convertir le caractère en majuscule pour standardiser la comparaison.
    ch = toupper(ch);
    // Retourne vrai si le caractère est l'une des lettres valides pour les entrées.
    return ch == 'A' || ch == 'R' || ch == 'C' || ch == 'E' || ch == 'J';
}

// Traite les options de ligne de commande pour définir le type d'ordonnanceur et la gestion des priorités.
void processOptions(int argc, char *argv[], unsigned int *schedulerType) {
    int scheduler = 0;  // Définit SJF comme type d'ordonnanceur par défaut
    int priority = 0;   // Par défaut, aucune priorité n'est prise en compte
    int option;
    // Boucle pour analyser les options de ligne de commande
    while ((option = getopt(argc, argv, "o:p:")) != -1) {
        switch (option) {
            case 'o':   // Option pour le type d'ordonnanceur
                scheduler = atoi(optarg);   // Convertit la chaîne en entier
                break;
            case 'p':   // Option pour la priorité
                priority = atoi(optarg);    // Convertit la chaîne en entier
                break;
            default:    // Gère les options inconnues ou malformées
                fprintf(stderr, "Usage: %s [-o ordonnanceur] [-p priorité] séquence de véhicules\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Détermine le type d'ordonnanceur en combinant les valeurs de scheduler et priority
    if (scheduler == 0 && priority == 0) {
        *schedulerType = 2;  // SJF sans priorité
    } else if (scheduler == 0 && priority == 1) {
        *schedulerType = 4;  // SJF avec priorité
    } else if (scheduler == 1 && priority == 0) {
        *schedulerType = 1;  // FCFS sans priorité
    } else if (scheduler == 1 && priority == 1) {
        *schedulerType = 3;  // FCFS avec priorité
    } else {
        fprintf(stderr, "options.c => processOptions() : 0 et 1 sont les seules valeurs acceptées pour -o et -p.\n");
        exit(EXIT_FAILURE);
    }
}

// Analyse l'entrée utilisateur pour configurer les véhicules à simuler.
void parseInput(int argc, char *argv[], vehicle_t **vehicles, int *vehicleCount, unsigned int *schedulerType) {
    // Traite d'abord les options pour déterminer le type d'ordonnanceur.
    processOptions(argc, argv, schedulerType);

     // Continue avec l'analyse de la séquence de véhicules si les options sont valides.
    if (optind < argc) {
        const char *input = argv[optind]; // Pointe sur l'argument contenant la séquence des véhicules
        int n = strlen(input);
        int count = 0;
        vehicle_t *tempVehicles = malloc(n * sizeof(vehicle_t));
        if (tempVehicles == NULL) {
            fprintf(stderr, "options.c => parseInput() : Erreur de malloc()");
            exit(EXIT_FAILURE);
        }

        // Parcours la chaîne de caractères de l'entrée utilisateur pour extraire les véhicules.
        for (int i = 0; i < n; i++) {
            char ch = input[i];
            if (isalpha(ch)) {
                if (isValidEntry(ch)) {
                    bool priority = isupper(ch);    // Détermine la priorité selon la casse du caractère
                    int processTime = 1;    // Par défaut, le temps de traitement est de 1
                    char entry = toupper(ch);

                    // Vérifie si le caractère suivant est un chiffre pour le temps de traitement
                    if (i + 1 < n && isdigit(input[i + 1])) {
                        processTime = input[i + 1] - '0';
                        i++;    // Avance l'index pour sauter le chiffre déjà lu
                    }

                    // Remplit la structure du véhicule
                    tempVehicles[count].id = count + 1;
                    tempVehicles[count].entry = entry;
                    tempVehicles[count].processTime = processTime;
                    tempVehicles[count].priority = priority;
                    count++;
                } else { 
                    fprintf(stderr, "Erreur : '%c' n'est pas un point d'entrée valide. Les entrées autorisées sont A, R, C, E ou J.\n", ch);
                    free(tempVehicles);
                    exit(EXIT_FAILURE);
                }
            } else {
                // Génère une erreur si le caractère rencontré n'est pas une lettre correspondant à une entrée valide ou un chiffre immédiatement après une lettre.
                // Cette vérification assure que chaque lettre d'entrée peut être suivie d'un seul chiffre représentant le temps de traversée, sans répétitions ni caractères inattendus.
                fprintf(stderr, "Erreur : caractère invalide '%c'.\n"
                "Les séquences valides doivent être constituées de lettres valides (A, R, C, E, J) pouvant être suivies par un unique chiffre indiquant le temps de traversée.\n", ch);
                free(tempVehicles);
                exit(EXIT_FAILURE);
            }
        }

        // Réalloue le tableau pour correspondre exactement au nombre de véhicules trouvés.
        *vehicles = realloc(tempVehicles, count * sizeof(vehicle_t));
        if (vehicles == NULL) {
            fprintf(stderr, "options.c => parseInput() : Erreur de realloc()");
            free(tempVehicles);
            exit(EXIT_FAILURE);
        }
        *vehicleCount = count;  // Met à jour le nombre de véhicules.
    }
}