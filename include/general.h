/**
 * general.h
 * En-tête global pour le projet de gestion du trafic de véhicules autonomes. 
 * Ce fichier inclut les bibliothèques standards nécessaires pour le projet,
 * fournissant des fonctionnalités essentielles telles que l'entrée/sortie,
 * la gestion de la mémoire, la manipulation de chaînes, et la concurrence.
 * Il sert de point d'inclusion central pour simplifier la gestion des dépendances
 * dans les autres fichiers du projet.
 */

#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>      // Pour les opérations d'entrée/sortie.
#include <stdlib.h>     // Pour la gestion de la mémoire dynamique et d'autres fonctions utilitaires comme exit().
#include <pthread.h>    // Pour le support de la programmation multithread avec POSIX threads.
#include <semaphore.h>  // Pour la gestion des sémaphores, utilisés ici pour contrôler l'accès au rond-point.
#include <ctype.h>      // Pour les fonctions de test et de mappage de caractères.
#include <string.h>     // Pour la manipulation de chaînes de caractères.
#include <unistd.h>     // Pour divers appels système POSIX comme sleep().
#include <stdbool.h>    // Pour l'utilisation du type bool pour la représentation des valeurs booléennes.
#include <getopt.h>     // Pour l'analyse des options de ligne de commande, utilisé pour traiter les arguments -o et -p.

#endif // GENERAL_H