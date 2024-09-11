#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 3

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char date_de_naissance[15];
    char departement[50];
    float note;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nbEtudiants = 0;

void ajouterEtudiant() {
    if (nbEtudiants < MAX_ETUDIANTS) {
        printf("\n--- Ajouter un nouvel etudiant ---\n");
        printf("Entrez l'ID de l'etudiant : ");
        scanf("%d", &etudiants[nbEtudiants].id);
        printf("Entrez le nom de l'etudiant : ");
        scanf("%s", etudiants[nbEtudiants].nom);
        printf("Entrez le prenom de l'etudiant : ");
        scanf("%s", etudiants[nbEtudiants].prenom);
        printf("Entrez la date de naissance (format JJ/MM/AAAA) : ");
        scanf("%s", etudiants[nbEtudiants].date_de_naissance);
        printf("Entrez le departement : ");
        scanf("%s", etudiants[nbEtudiants].departement);
        printf("Entrez la note : ");
        scanf("%f", &etudiants[nbEtudiants].note);
        nbEtudiants++;
    } else {
        printf("Nombre maximum d'etudiants atteint.\n");
    }
}

void afficherEtudiants() {
    if (nbEtudiants == 0) {
        printf("\nAucun etudiant disponible.\n");
    } else {
        printf("\n--- Liste des etudiants ---\n");
        for (int i = 0; i < nbEtudiants; i++) {
            printf("ID: %d, Nom: %s, Prenom: %s, Date de naissance: %s, Departement: %s, Note: %.2f\n",
                   etudiants[i].id, etudiants[i].nom, etudiants[i].prenom,
                   etudiants[i].date_de_naissance, etudiants[i].departement, etudiants[i].note);
        }
    }
}

void modifierEtudiant() {
    if (nbEtudiants == 0) {
        printf("\nAucun etudiant à modifier.\n");
        return;
    }

    int id;
    printf("\nEntrez l'ID de l'etudiant à modifier : ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            found = 1;
            printf("\n--- Modifier les informations de l'etudiant ID %d ---\n", id);
            printf("Entrez le nouveau nom (actuel : %s) : ", etudiants[i].nom);
            scanf("%s", etudiants[i].nom);
            printf("Entrez le nouveau prenom (actuel : %s) : ", etudiants[i].prenom);
            scanf("%s", etudiants[i].prenom);
            printf("Entrez la nouvelle date de naissance (actuelle : %s) : ", etudiants[i].date_de_naissance);
            scanf("%s", etudiants[i].date_de_naissance);
            printf("Entrez le nouveau departement (actuel : %s) : ", etudiants[i].departement);
            scanf("%s", etudiants[i].departement);
            printf("Entrez la nouvelle note (actuelle : %.2f) : ", etudiants[i].note);
            scanf("%f", &etudiants[i].note);
            printf("\nLes informations de l'etudiant ont ete modifiees avec succès.\n");
            break;
        }
    }

    if (!found) {
        printf("etudiant avec l'ID %d non trouve.\n", id);
    }
}

void calculerMoyenneParDepartement() {
    if (nbEtudiants == 0) {
        printf("\nAucun etudiant disponible pour calculer la note moyenne.\n");
        return;
    }

    char departementRecherche[50];
    printf("Entrez le departement pour calculer la moyenne des notes : ");
    scanf("%s", departementRecherche);

    float totalNotes = 0.0;
    int nombreEtudiantsDepartement = 0;

    for (int i = 0; i < nbEtudiants; i++) {
        if (strcmp(etudiants[i].departement, departementRecherche) == 0) {
            totalNotes += etudiants[i].note;
            nombreEtudiantsDepartement++;
        }
    }

    if (nombreEtudiantsDepartement > 0) {
        float moyenne = totalNotes / nombreEtudiantsDepartement;
        printf("\nNote moyenne pour le departement %s : %.2f\n", departementRecherche, moyenne);
    } else {
        printf("Aucun etudiant trouve pour le departement %s.\n", departementRecherche);
    }
}

void supprimerEtudiant() {
    if (nbEtudiants == 0) {
        printf("\nAucun etudiant à supprimer.\n");
        return;
    }

    int id;
    printf("\nEntrez l'ID de l'etudiant à supprimer : ");
    scanf("%d", &id);

    int trouve = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            trouve = 1;
            for (int j = i; j < nbEtudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            nbEtudiants--;
            printf("L'etudiant avec l'ID %d a ete supprime.\n", id);
            break;
        }
    }

    if (!trouve) {
        printf("L'etudiant avec l'ID %d n'a pas ete trouve.\n", id);
    }
}

void afficherStatistiques() {
    if (nbEtudiants == 0) {
        printf("\nAucun etudiant disponible pour afficher les statistiques.\n");
        return;
    }

    printf("\n--- Statistiques ---\n");

    // Nombre total d'etudiants
    printf("Nombre total d'etudiants inscrits : %d\n", nbEtudiants);

    // Nombre d'etudiants par departement
    printf("\nNombre d'etudiants dans chaque departement :\n");
    int nombreDepartements = 0;
    char departements[nbEtudiants][50];
    int nombreParDepartement[nbEtudiants];
    
    for (int i = 0; i < nbEtudiants; i++) {
        int existe = 0;
        for (int j = 0; j < nombreDepartements; j++) {
            if (strcmp(departements[j], etudiants[i].departement) == 0) {
                nombreParDepartement[j]++;
                existe = 1;
                break;
            }
        }
        if (!existe) {
            strcpy(departements[nombreDepartements], etudiants[i].departement);
            nombreParDepartement[nombreDepartements] = 1;
            nombreDepartements++;
        }
    }

    for (int i = 0; i < nombreDepartements; i++) {
        printf("%s : %d etudiants\n", departements[i], nombreParDepartement[i]);
    }

    // Etudiants ayant une moyenne superieure à un certain seuil
    float seuil;
    printf("\nEntrez le seuil de moyenne generale : ");
    scanf("%f", &seuil);
    printf("etudiants ayant une moyenne superieure à %.2f :\n", seuil);
    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].note > seuil) {
            printf("ID: %d, Nom: %s, Note: %.2f\n", etudiants[i].id, etudiants[i].nom, etudiants[i].note);
        }
    }

    // Les 3 etudiants ayant les meilleures notes
    printf("\nLes 3 etudiants ayant les meilleures notes :\n");
    for (int i = 0; i < nbEtudiants - 1; i++) {
        for (int j = i + 1; j < nbEtudiants; j++) {
            if (etudiants[i].note < etudiants[j].note) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }

    for (int i = 0; i < (nbEtudiants < 3 ? nbEtudiants : 3); i++) {
        printf("ID: %d, Nom: %s, Note: %.2f\n", etudiants[i].id, etudiants[i].nom, etudiants[i].note);
    }

    // Nombre d'etudiants ayant reussi dans chaque departement
    printf("\nNombre d'etudiants ayant reussi (note >= 10/20) dans chaque departement :\n");
    for (int i = 0; i < nombreDepartements; i++) {
        int nbReussite = 0;
        for (int j = 0; j < nbEtudiants; j++) {
            if (strcmp(departements[i], etudiants[j].departement) == 0 && etudiants[j].note >= 10) {
                nbReussite++;
            }
        }
        printf("%s : %d etudiants reussis\n", departements[i], nbReussite);
    }
}

int main() {
    int choix;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher tous les etudiants\n");
        printf("3. Modifier un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Calculer la moyenne des notes par departement\n");
        printf("6. Afficher les statistiques\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                afficherEtudiants();
                break;
            case 3:
                modifierEtudiant();
                break;
            case 4:
                supprimerEtudiant();
                break;
            case 5:
                calculerMoyenneParDepartement();
                break;
            case 6:
                afficherStatistiques();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}