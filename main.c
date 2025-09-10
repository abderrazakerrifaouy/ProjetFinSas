#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

typedef struct
{
    int id;
    char nom[50];
    char Prenom[50];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
} Joueur;

Joueur equipe[100];
int conteur = 0;
int genereId = 0;

int StringIsValide(char nom[])
{
    int isValide = 0;
    for (int i = 0; i < strlen(nom); i++)
    {
        if (nom[i] != ' ')
        {
            isValide = 1;
            break;
        }
    }
    if (strlen(nom) < 3)
    {
        isValide = 0;
    }

    return isValide;
}

int valideNumeroMaillot(int numeroMaillot)
{
    // if (numeroMaillot <= 0)
    // {
    //     return 0;
    // }

    for (int i = 0; i < conteur; i++)
    {
        if (equipe[i].numeroMaillot == numeroMaillot)
        {
            return 0;
        }
    }
    return 1;
}

int validePoste(char poste[])
{
    char postes[4][20] = {"gardien", "defenseur", "milieu", "attaquant"};
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(poste, postes[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void ajouterUnJoueur(int i)
{

    system("cls");
    printf("                          +*******************************************************************************+\n");
    printf("                          |                               Add joueur %-*d                                |\n", 5, i + 1);
    printf("                          |                                                                               |\n");
    printf("                          +*******************************************************************************+\n");

    int isValide;

    do
    {
        printf("                             Entrez le nom du joueur %d : ", i + 1);
        scanf("%s", equipe[conteur].nom);
        printf("                          |                                                                               |\n");

        isValide = StringIsValide(equipe[conteur].nom);
        if (!isValide)
        {
            printf("                          |      " RED "Le nom du joueur doit etre valide !!!" RESET "                                    |\n");
            printf("                          |                                                                               |\n");
        }

    } while (!isValide);

    do
    {
        printf("                             Entrez le prenom du joueur %d : ", i + 1);
        scanf("%s", equipe[conteur].Prenom);
        printf("                          |                                                                               |\n");

        isValide = StringIsValide(equipe[conteur].Prenom);
        if (!isValide)
        {
            printf("                          |      " RED "Le prenom du joueur doit etre valide !!!" RESET "                                 |\n");
            printf("                          |                                                                               |\n");
        }
    } while (!isValide);

    do
    {
        printf("                             Entrez le numero de maillot du joueur %d : ", i + 1);
        scanf("%d", &equipe[conteur].numeroMaillot);
        printf("                          |                                                                               |\n");

        isValide = valideNumeroMaillot(equipe[conteur].numeroMaillot);
        if (!isValide)
        {
            printf("                          |      " RED "Ce numero de maillot (%d) existe deja dans l'equipe !!!" RESET "                  |\n", equipe[conteur].numeroMaillot);
            printf("                          |                                                                               |\n");
        }
    } while (!isValide);

    do
    {
        printf("                             Entrez le poste du joueur %d (gardien, defenseur, milieu, attaquant) : ", i + 1);
        scanf("%s", equipe[conteur].poste);
        printf("                          |                                                                               |\n");

        isValide = validePoste(equipe[conteur].poste);
        if (!isValide)
        {
            printf("                          |      " RED "Ce poste est invalide !!!" RESET "                                                |\n");
            printf("                          |                                                                               |\n");
        }
    } while (!isValide);

    do
    {
        printf("                             Entrez l'age du joueur %d : ", i + 1);
        scanf("%d", &equipe[conteur].age);
        printf("                          |                                                                               |\n");

        isValide = (equipe[conteur].age > 0 && equipe[conteur].age <= 99);
        if (!isValide)
        {
            printf("                          |      " RED "L'age doit etre entre 1 et 99 !!!" RESET "                                        |\n");
            printf("                          |                                                                               |\n");
        }
    } while (!isValide);

    do
    {
        printf("                             Entrez le nombre de buts du joueur %d : ", i + 1);
        scanf("%d", &equipe[conteur].buts);
        printf("                          |                                                                               |\n");

        isValide = (equipe[conteur].buts >= 0);
        if (!isValide)
        {
            printf("                          |      " RED "Le nombre de buts ne peut pas etre negatif !!!" RESET "                           |\n");
            printf("                          |                                                                               |\n");
        }
    } while (!isValide);

    equipe[conteur].id = ++genereId;

    printf("                          +*******************************************************************************+\n\n");
    printf(GREEN " Le joueur %s %s a ete ajoute avec succes !!! \n" RESET, equipe[conteur].nom, equipe[conteur].Prenom);
    conteur++;
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
}

void menuAjouterUnJoueur()
{
    int le_choi;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf(CYAN "                          |*************************************************|   \n");
        printf("                          |               Ajouter un joueur                 |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n");
        printf("                          |                                                 |   \n");
        printf(BLUE "                          |       1. jouter un nouveau joueur               |   \n");
        printf("                          |                                                 |   \n");
        printf(YELLOW "                          |       2. Ajouter plusieurs joueurs en           |   \n");
        printf("                          |             une seule operation                 |   \n" RESET);
        printf("                          |                                                 |   \n");
        printf("                          |       3. Quite                                  |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|  \n\n\n");
        printf("Quel est votre choix ? : ");
        scanf("%d", &le_choi);

        switch (le_choi)
        {
        case 1:
            ajouterUnJoueur(0);
            break;
        case 2:
            int nJoueurs;

            printf("Combien de joueurs voulez-vous ajouter ? ");
            scanf("%d", &nJoueurs);

            for (int i = 0; i < nJoueurs; i++)
            {
                ajouterUnJoueur(i);
            }
            break;
        default:
            break;
        }
    } while (le_choi != 3);
}

void afficherToutLesJoueur()
{
    system("cls");
    if (conteur > 0)
    {
        printf("                     +************************************************************************************************************************************************************************************+\n");
        printf("                    ||                        ||                        ||                        ||                        ||                        ||                        ||                        ||\n");
        printf("                    || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s ||\n", 22, "id", 22, "nom", 22, "prenom", 22, "Numero Maillot", 22, "Post", 22, "Age", 22, "buts");
        printf("                    ||                        ||                        ||                        ||                        ||                        ||                        ||                        ||\n");
        printf("                    +*************************************************************************************************************************************************************************************+\n");
        printf("                    ||                        ||                        ||                        ||                        ||                        ||                        ||                        ||\n");

        for (int i = 0; i < conteur; i++)
        {
            printf("                    || %-*d || %-*s || %-*s || %-*d || %-*s || %-*d || %-*d ||\n", 22, equipe[i].id, 22, equipe[i].nom, 22, equipe[i].Prenom, 22, equipe[i].numeroMaillot, 22, equipe[i].poste, 22, equipe[i].age, 22, equipe[i].buts);
            printf("                    ||                        ||                        ||                        ||                        ||                        ||                        ||                        ||\n");
        }
    }
    else
    {
        printf(RED "Aucun joueur dans l'equipe !!!" RESET);
    }
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
}

int menu()
{
    int le_choi;
    do
    {
        system("cls");
        printf(YELLOW "\n\n\n");
        printf("                          |*************************************************|   \n");
        printf("                          |                   Menu                          |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n");
        printf("                          |                                                 |   \n");
        printf(GREEN "                          |       1. Ajouter une joueur                     |   \n" RESET);
        printf(YELLOW "                          |       2. Afficher tous les joueur               |   \n" RESET);
        printf("                          |       3. Quitter                                |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n\n\n");
        printf("Quel est votre choix ? : ");
        scanf("%d", &le_choi);

        switch (le_choi)
        {
        case 1:
            menuAjouterUnJoueur();
            break;
        case 2:
            afficherToutLesJoueur();
        default:
            break;
        }

    } while (le_choi != 3);
}

int main()
{
    menu();
}
