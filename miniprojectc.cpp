#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D�finition de la structure Voiture
typedef struct Voiture {
    char marque[50];
    char modele[50];
    int annee;
    float prixlocationparjour;
    char carburant[20];
    int nombrdeplaces;
    char disponibilite[20];
    int id;
    char nomdutilisateur[50];
    char transmission[20];
} voiture;

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour afficher le menu du programme~~~~~~~~~~~~~~~~~~~~~~
void menu(void) {
    printf("**************************************************\n");
    printf("entrez votre choix\n");
    printf("1- ajouter une voiture\n");
    printf("2- supprimer une voiture\n");
    printf("3- modifier une voiture\n");
    printf("4- afficher la liste des voitures\n");
    printf("5- rechercher une voiture par indice\n");
    printf("6- trier les voitures\n");
    printf("0- quitter le programme\n");
    printf("**************************************************\n");
}

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour ajouter une voiture~~~~~~~~~~~~~~~~~~~~~~~~
void ajouter(voiture *voit, int n) {
    FILE *fichier = fopen("voitures.txt", "a"); // Ouvrir le fichier en mode ajout

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        // Demander et enregistrer les informations de la voiture
        printf("Entrez la marque de la voiture : ");
        scanf("%s", voit[i].marque);
        fprintf(fichier, "%s\n", voit[i].marque);
        
        printf("Entrez le mod�le de la voiture : ");
        scanf("%s", voit[i].modele);
        fprintf(fichier, "%s\n", voit[i].modele);

        printf("Entrez l'ann�e de la voiture : ");
        scanf("%d", &voit[i].annee);
        fprintf(fichier, "%d\n", voit[i].annee);

        printf("Entrez le prix de location par jour : ");
        scanf("%f", &voit[i].prixlocationparjour);
        fprintf(fichier, "%.2f\n", voit[i].prixlocationparjour);

        printf("Entrez le type de carburant : ");
        scanf("%s", voit[i].carburant);
        fprintf(fichier, "%s\n", voit[i].carburant);

        printf("Entrez le nombre de places : ");
        scanf("%d", &voit[i].nombrdeplaces);
        fprintf(fichier, "%d\n", voit[i].nombrdeplaces);

        printf("Entrez la disponibilite : ");
        scanf("%s", voit[i].disponibilite);
        fprintf(fichier, "%s\n", voit[i].disponibilite);

        printf("Entrez l'ID : ");
        scanf("%d", &voit[i].id);
        fprintf(fichier, "%d\n", voit[i].id);

        printf("Entrez le nom de l'utilisateur : ");
        scanf("%s", voit[i].nomdutilisateur);
        fprintf(fichier, "%s\n", voit[i].nomdutilisateur);

        printf("Entrez la transmission : ");
        scanf("%s", voit[i].transmission);
        fprintf(fichier, "%s\n", voit[i].transmission);
    }

    fclose(fichier); // Fermer le fichier
}
// ~~~~~~~~~~~~~~~~~~~~~~ fin de Fonction pour ajouter une voiture~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour afficher la liste des voitures~~~~~~~~~~~~~~~~~~~~~~
void afficherListe(voiture *voit, int n) {
    printf("Liste des voitures :\n");
    for (int i = 0; i < n; i++) {
        // Afficher les informations de chaque voiture
        printf("Voiture %d :\n", i+1);
        printf("Marque : %s\n", voit[i].marque);
        printf("Mod�le : %s\n", voit[i].modele);
        printf("Ann�e : %d\n", voit[i].annee);
        printf("Prix de location par jour : %.2f\n", voit[i].prixlocationparjour);
        printf("Carburant : %s\n", voit[i].carburant);
        printf("Nombre de places : %d\n", voit[i].nombrdeplaces);
        printf("Disponibilit� : %s\n", voit[i].disponibilite);
        printf("ID : %d\n", voit[i].id);
        printf("Nom de l'utilisateur : %s\n", voit[i].nomdutilisateur);
        printf("Transmission : %s\n", voit[i].transmission);
        printf("\n");
    }
}
// ~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour afficher la liste des voitures~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour supprimer une voiture~~~~~~~~~~~~~~~~~~~~~~
void supprimer(voiture *voit, int *n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Indice invalide.\n");
        return;
    }

    // Supprimer la voiture � l'indice donn� en d�calant les autres
    for (int i = indice; i < *n - 1; i++) {
        voit[i] = voit[i + 1];
    }

    (*n)--;
}
// ~~~~~~~~~~~~~~~~~~~~~~ fin de Fonction pour supprimer une voiture~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~ Fonction pour modifier les informations d'une voiture~~~~~~~~~~~~~~~~~~~~~~
void modifier(voiture *voit, int n, int indice) {
    if (indice < 0 || indice >= n) {
        printf("Indice invalide.\n");
        return;
    }

    // Demander et enregistrer les nouvelles informations de la voiture
    printf("Entrez la nouvelle marque de la voiture : ");
    scanf("%s", voit[indice].marque);

    printf("Entrez le nouveau mod�le de la voiture : ");
    scanf("%s", voit[indice].modele);

    printf("Entrez la nouvelle ann�e de la voiture : ");
    scanf("%d", &voit[indice].annee);

    printf("Entrez le nouveau prix de location par jour : ");
    scanf("%f", &voit[indice].prixlocationparjour);

    printf("Entrez le nouveau type de carburant : ");
    scanf("%s", voit[indice].carburant);

    printf("Entrez le nouveau nombre de places : ");
    scanf("%d", &voit[indice].nombrdeplaces);

    printf("Entrez la nouvelle disponibilite : ");
    scanf("%s", voit[indice].disponibilite);

    printf("Entrez le nouvel ID : ");
    scanf("%d", &voit[indice].id);

    printf("Entrez le nouveau nom de l'utilisateur : ");
    scanf("%s", voit[indice].nomdutilisateur);

    printf("Entrez la nouvelle transmission : ");
    scanf("%s", voit[indice].transmission);
}
//~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour modifier les informations d'une voiture~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour rechercher une voiture par son indice~~~~~~~~~~~~~~~~~~~~~~
void rechercherParIndice(voiture *voit, int n, int indice) {
    if (indice < 0 || indice >= n) {
        printf("Indice invalide.\n");
        return;
    }

    // Afficher les informations de la voiture � l'indice donn�
    printf("Voiture %d :\n", indice + 1);
    printf("Marque : %s\n", voit[indice].marque);
    printf("Mod�le : %s\n", voit[indice].modele);
    printf("Ann�e : %d\n", voit[indice].annee);
    printf("Prix de location par jour : %.2f\n", voit[indice].prixlocationparjour);
    printf("Carburant : %s\n", voit[indice].carburant);
    printf("Nombre de places : %d\n", voit[indice].nombrdeplaces);
    printf("Disponibilit� : %s\n", voit[indice].disponibilite);
    printf("ID : %d\n", voit[indice].id);
    printf("Nom de l'utilisateur : %s\n", voit[indice].nomdutilisateur);
    printf("Transmission : %s\n", voit[indice].transmission);
}
// ~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour rechercher une voiture par son indice~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour rechercher des voitures par marque et disponibilit�~~~~~~~~~~~~~~~~~~~~~~
void rechercherParMarqueDisponibilite(voiture *voit, int n, char marqueRecherchee[], char disponibiliteRecherchee[]) {
    printf("Voitures correspondantes :\n");
    for (int i = 0; i < n; i++) {
        // Si la marque et la disponibilit� correspondent, afficher les informations de la voiture
        if (strcmp(voit[i].marque, marqueRecherchee) == 0 && strcmp(voit[i].disponibilite, disponibiliteRecherchee) == 0) {
            printf("Voiture %d :\n", i+1);
            printf("Marque : %s\n", voit[i].marque);
            printf("Mod�le : %s\n", voit[i].modele);
            printf("Ann�e : %d\n", voit[i].annee);
            printf("Prix de location par jour : %.2f\n", voit[i].prixlocationparjour);
            printf("Carburant : %s\n", voit[i].carburant);
            printf("Nombre de places : %d\n", voit[i].nombrdeplaces);
            printf("Disponibilit� : %s\n", voit[i].disponibilite);
            printf("ID : %d\n", voit[i].id);
            printf("Nom de l'utilisateur : %s\n", voit[i].nomdutilisateur);
            printf("Transmission : %s\n", voit[i].transmission);
            printf("\n");
        }
    }
}
// ~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour rechercher des voitures par marque et disponibilit�~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~ Fonction pour trier les voitures par marque puis par prix de location~~~~~~~~~~~~~~~~~~~~~~
void trierParMarquePrixLocation(voiture *voit, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Trie d'abord par marque
            if (strcmp(voit[j].marque, voit[j + 1].marque) > 0) {
                // �change des �l�ments
                voiture temp = voit[j];
                voit[j] = voit[j + 1];
                voit[j + 1] = temp;
            }
            // Si les marques sont les m�mes, trie par prix de location par jour
            else if (strcmp(voit[j].marque, voit[j + 1].marque) == 0 && voit[j].prixlocationparjour > voit[j + 1].prixlocationparjour) {
                // �change des �l�ments
                voiture temp = voit[j];
                voit[j] = voit[j + 1];
                voit[j + 1] = temp;
            }
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour trier les voitures par marque puis par prix de location~~~~~~~~~~~~~~~~~~~~~~
int main() {
    int choix, N;
    voiture *voitures = malloc(sizeof(voiture) * 100); // Allouer de la m�moire pour le tableau de voitures

    menu(); // Afficher le menu du programme
    printf("Donnez votre choix : ");
    scanf("%d", &choix);

    // Boucle principale du programme
    while (choix != 0) {
        switch (choix) {
            case 1:
                printf("Entrez le nombre de voitures � ajouter : ");
                scanf("%d", &N);
                ajouter(voitures, N); // Appeler la fonction pour ajouter des voitures
                break;
            case 2: {
                int indice;
                printf("Entrez l'indice de la voiture � supprimer : ");
                scanf("%d", &indice);
                supprimer(voitures, &N, indice); // Appeler la fonction pour supprimer une voiture
                break;
            }
            case 3: {
                int indice;
                printf("Entrez l'indice de la voiture � modifier : ");
                scanf("%d", &indice);
                modifier(voitures, N, indice); // Appeler la fonction pour modifier une voiture
                break;
            }
            case 4:
                afficherListe(voitures, N); // Appeler la fonction pour afficher la liste des voitures
                break;
            case 5: {
               int indice;
                printf("Entrez l'indice de la voiture � rechercher : ");
                scanf("%d", &indice);
                rechercherParIndice(voitures, N, indice); // Appeler la fonction pour rechercher une voiture par son indice
                break;
            }
            case 6:
                 trierParMarquePrixLocation(voitures, N); // Appeler la fonction pour trier les voitures
                 afficherListe(voitures, N); // Afficher la liste tri�e des voitures
                break;
            default:
                printf("Choix invalide.\n");
        }

        menu(); // Afficher � nouveau le menu
        printf("Donnez votre choix : ");
        scanf("%d", &choix);
    }

    free(voitures); // Lib�rer la m�moire allou�e pour le tableau de voitures

    return 0;
}

