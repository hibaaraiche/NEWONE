
#include <stdio.h>
typedef struct{
    char titre ;
    char auteur ;
    int nombredepage ;
    float prix ;
} livre ;

int main() {
    livre L[50];
    int choix ,i ,n ;
    char a[50];
   
    do {
        printf("cliquer 1 pour les details des livres\n");
        printf("cliquer 2 pour afficher les details des livres\n");
        printf("3 pour le livre de l'auteur\n"); 
        printf("4 pour le nombre de livre\n");
        printf("cliquer 5 pour sortie\n"); 
        printf("votre choix :");
        scanf("%d",&choix);
        switch ( choix ){
            case 1:
            printf("combioen de livre :");
            scanf("%d",&n);
            for (i=0;i<n;i++){
                printf("combier de livre :\n",i+1);
                printf("titre :");
                scanf("%[^\n]s",&L[i].titre);
                printf("auteur :");
                scanf("%[^\n]s",&L[i].auteur);
                printf("nombre de page :");
                scanf("%[^\n]s",&L[i].nombredepage);
                printf("prix :");
               scanf("%[^\n]s",&L[i].prix);
                
            }
            break ;
            case 2:
            printf("les details des livres: \n");
            for (i=0;i<n;i++){
                printf("livre num %d : \n",i+1);
                printf("titre : %s-auteur : %s-nombre de page : %d-prix : - prix : %.2feuro\n",L[i].titre,L[i].auteur,L[i].nombredepage,L[i].prix);
            }
            break;
            case 3:
            printf("le nom de l'auteur :\n");
             scanf("%[^\n]s",&a);
            for (i=0;i<n;i++){
                if(strcmp(L[i].auteur,a)==0)
                printf("%s \t %.2f\n",L[i].titre,L[i].prix);
                
            }
            break;
            
            case 4:
            printf("nombre totale de livre dans la bibliotique : %d \n",n);
            
            case 5:
            exit(0);
            
            
            
            
            
        }
        
    }while(choix != 5);

    return 0;
}