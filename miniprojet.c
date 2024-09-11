#include <stdio.h>
#include <string.h>  

#define MAX_ETUDIANTS 3 

typedef struct {
    int id;              
    char nom[50];        
    char prenom[50];     
    char departement[50]; 
    float note;          
} Etudiant;


Etudiant etudiants[MAX_ETUDIANTS]; 
int nbr_Etudiants = 0;  


void ajouterEtudiant() {
    if (nbr_Etudiants < MAX_ETUDIANTS) {
        printf("\n--- Ajouter un nouvel étudiant ---\n");
        printf("Entrez l'ID de l'étudiant : ");
        scanf("%d", &etudiants[nbr_Etudiants].id);
        
        printf("Entrez le nom de l'étudiant : ");
        scanf("%s", etudiants[nbr_Etudiants].nom);
        
        printf("Entrez le prénom de l'étudiant : ");
        scanf("%s", etudiants[nbr_Etudiants].prenom);
        
        printf("Entrez le département : ");
        scanf("%s", etudiants[nbr_Etudiants].departement);
        
        printf("Entrez la note : ");
        scanf("%f", &etudiants[nbr_Etudiants].note);
        
        nbr_Etudiants++; 
    } else {
        printf("Nombre maximum d'étudiants atteint.\n");
    }
}

void afficherEtudiants() {
    if (nbr_Etudiants == 0) {
        printf("\nAucun étudiant disponible.\n");
    } else {
        printf("\n--- Liste des étudiants ---\n");
        for (int i = 0; i < nbr_Etudiants; i++) {
            printf("ID: %d, Nom: %s, Prénom: %s, Département: %s, Note: %.2f\n",
                   etudiants[i].id, etudiants[i].nom, etudiants[i].prenom, 
                   etudiants[i].departement, etudiants[i].note);
        }
    }
}


int main() {
    int choix;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher les étudiants\n");
        printf("3. Quitter\n");
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
                return 0;  // Quitter le programme
            default:
                printf("Choix invalide ! Veuillez réessayer.\n");
        }
    }

    return 0;




int main() {

