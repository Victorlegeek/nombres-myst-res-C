#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

    char ouinon[10];


void jouer(int limitmin, int limitmax, int tentativesmax) {
    int tentatives = 0;
    srand(time(NULL));

    int x = rand()%(limitmax-limitmin+1) + limitmin; /*le +1 est pour que le nombre max soit inclus dans les possibilités*/
    while (1){
        int choix;
        
        scanf("%d", &choix);
        if (tentatives > tentativesmax){ /*pas ==10 car il jouera 9 fois et non 10 fois*/
            printf("Perdu\n");
            break;
        }
        tentatives++;
        if (choix<x) { 
            printf("C'est plus, il reste %d tentatives\n", tentativesmax);
        } else if (choix>x) {
            printf("C'est moins, il reste %d tentatives\n", tentativesmax);
        }else if (choix==x) {
            printf("Bravo vous avez trouvé en %d tentatives\n", tentatives);
            break;
        } else {
            printf("Choisis un nombre entre %d et %d, il reste %d tentatives\n",limitmin, limitmax, tentativesmax);
        }          
    }
}
void choisir_difficulte(int *tentativesmax, int *limitmax, int *limitmin){
    int diffnb;
    int choixinter;

    while (1) {
        printf("   ---------------\n");
        printf("   | Choix de la |\n");
        printf("   |  Difficulté |\n");
        printf("   ---------------\n");
        printf("1. faciles (15 essais)\n");
        printf("2. moyen (10 essais)\n");
        printf("3. difficile (5 essais)\n");
        printf("4. Personalisée\n");
        printf("Quelle difficulté (Ecrivez le chiffre de la difficulté) : ");
        scanf("%d", &diffnb);

        if (diffnb == 1) {
            *tentativesmax = 15;
            printf("La difficulté est réglée en facile (15 essais)\n");
            break;
        } else if (diffnb == 2) {
            *tentativesmax = 10;
            printf("La difficulté est réglée en moyen (10 essais)\n");
            break;
        } else if (diffnb == 3) {
            *tentativesmax = 5;
            printf("La difficulté est réglée en difficile (5 essais)\n");
            break;
        } else if (diffnb == 4) {
            printf("Combien d'essais max voulez vous : ");
            scanf("%d", tentativesmax);
            break;
        } else {
            printf("Merci de rentrer un chiffre valide\n");
        }
    } while(1) {
        printf("   ---------------\n");
        printf("   | Choix de l' |\n");
        printf("   |  Intervalle |\n");
        printf("   ---------------\n");
        printf("1. faciles (1-50 essais)\n");
        printf("2. moyen (1-100 essais)\n");
        printf("3. difficile (1-500 essais)\n");
        printf("4. Personalisée\n");
        printf("Quelle Intervalle (Ecrivez le chiffre de l'intervalle : )\n");
        scanf("%d", &choixinter);

        if (choixinter == 1) {
            *limitmin = 1;
            *limitmax = 50;
            break;
        } else if (choixinter == 2) {
            *limitmin = 1;
            *limitmax = 100;
            break;
        } else if (choixinter == 3) {
            *limitmin = 1;
            *limitmax = 500;
            break;
        } else if (choixinter == 4) {
            printf("Quelle est le premier chiffre de l'intervalle : ");
            scanf("%d", limitmin);
            printf("Quelle est le deuxiième chiffre de l'intervalle : ");
            scanf("%d", limitmax);
            break;
        }
    }
    printf("Limite réglé entre %d et %d \n", *limitmin, *limitmax);
    printf("Entrez un nombre entre %d et %d : ", *limitmin, *limitmax);
    jouer(*limitmin, *limitmax, *tentativesmax);
}

int main(){
    int limitmin = 0;
    int limitmax = 0;
    int tentatives = 0;
    int tentativesmax;

    printf("=====================\n");
    printf("| Jeu nombre mystère |\n");
    printf("=====================\n");

    choisir_difficulte(&tentativesmax, &limitmax, &limitmin);

    return 0;
}
