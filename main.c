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

int StringIsValide(char str[])
{
    int isValide = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            isValide = 1;
            break;
        }
    }
    if (strlen(str) < 3)
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

int checkString(char str1[], char str2[])
{
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] < str2[i])
        {
            return 1;
        }
        else if (str1[i] > str2[i])
        {
            return 0;
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

        isValide = (equipe[conteur].age > 16 && equipe[conteur].age <= 45);
        if (!isValide)
        {
            printf("                          |      " RED "L'age doit etre entre 16 et 45 !!!" RESET "                                        |\n");
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

void afficherToutLesJoueur(Joueur joueurs[] , int nJoueur)
{
    system("cls");
    if (nJoueur > 0)
    {
        printf(YELLOW "                     +****************************************************************************************************************************+\n");
        printf("                    ||                ||                ||                ||                ||                ||                ||                ||\n");
        printf("                    || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s ||\n", 14, "id", 14, "nom", 14, "prenom", 14, "Numero Maillot", 14, "Post", 14, "Age", 14, "buts");
        printf("                    ||                ||                ||                ||                ||                ||                ||                ||\n");
        printf("                    +*****************************************************************************************************************************+\n");
        printf("                    ||                ||                ||                ||                ||                ||                ||                ||\n");

        for (int i = 0; i < nJoueur; i++)
        {
            printf("                    || %-*d || %-*s || %-*s || %-*d || %-*s || %-*d || %-*d ||\n", 14, joueurs[i].id, 14, joueurs[i].nom, 14, joueurs[i].Prenom, 14, joueurs[i].numeroMaillot, 14, joueurs[i].poste, 14, joueurs[i].age, 14, joueurs[i].buts);
            printf("                    ||                ||                ||                ||                ||                ||                ||                ||\n");
        }
        printf("                    +*****************************************************************************************************************************+\n");
    }
    else
    {
        printf(RED "Aucun joueur dans l'equipe !!!" RESET);
    }
    getchar();
    printf(RESET "\nAppuyez sur Entrer pour continuer...");
    getchar();
}

void afficherJoueursByNom()
{
    Joueur joueurs[100];
    for (int i = 0; i < conteur; i++)
    {
        joueurs[i] = equipe[i];
    }
    for (int i = 0; i < conteur; i++)
    {
        for (int j = 0; j < conteur - 1; j++)
        {
            if (!checkString(joueurs[j].nom, joueurs[j + 1].nom))
            {
                Joueur tmp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = tmp;
            }
        }
    }
    afficherToutLesJoueur(joueurs , conteur);
}

void affcherJoueursByAge()
{
    Joueur joueurs[100];
    for (int i = 0; i < conteur; i++)
    {
        joueurs[i] = equipe[i];
    }
    for (int i = 0; i < conteur; i++)
    {
        for (int j = 0; j < conteur - 1; j++)
        {
            if (joueurs[j].age > joueurs[j + 1].age)
            {
                Joueur tmp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = tmp;
            }
        }
    }
    afficherToutLesJoueur(joueurs , conteur);
}

void afficherJoueursByPoste()
{
    printf(" les postes sont : gardien, defenseur, milieu, attaquant \n");
    char poste[20];
    printf("Entrez le poste : ");
    scanf("%s", poste);
    if (validePoste(poste))
    {
        Joueur joueurs[100];
        int c = 0;
        for (int i = 0; i < conteur; i++)
        {
            if (strcmp(poste, equipe[i].poste) == 0)
            {
                joueurs[c] = equipe[i];
                c++;
            }
        }
        if (c > 0)
        {
            afficherToutLesJoueur(joueurs , c);
        }
        else
        {
            printf(RED "Aucun joueur avec le poste %s dans l'equipe !!!" RESET, poste);
            getchar();
            printf(RESET "\nAppuyez sur Entrer pour continuer...");
            getchar();
        }
    }
    else
    {
        printf(RED "Ce poste est invalide !!!" RESET);
        getchar();
        printf(RESET "\nAppuyez sur Entrer pour continuer...");
        getchar();
    }
}

int rechercherById(int id)
{
    for (int i = 0; i < conteur; i++)
    {
        if (equipe[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int rechercherByNom(char nom[])
{
    for (int i = 0; i < conteur; i++)
    {
        if (strcmp(nom, equipe[i].nom) == 0)
        {
            return i;
        }
    }
    return -1;
}

void menuAfficher()
{
    int le_choi;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("                          |**************************************************|   \n");
        printf("                          |               Afficher un joueur                 |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 1.Trier les joueurs par ordre alphabetique (Nom) |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 2. Trier les joueurs par age.                    |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 3.Afficher les joueurs par poste                 |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 4. Quite                                         |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|  \n\n\n");
        printf("Quel est votre choix ? : ");
        scanf("%d", &le_choi);

        switch (le_choi)
        {
        case 1:
            afficherJoueursByNom();
            break;
        case 2:
            affcherJoueursByAge();
            break;
        case 3:
            afficherJoueursByPoste();
        default:
            break;
        }
    } while (le_choi != 4);
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

void menuRechercher()
{
    int le_choi;
    do
    {

        system("cls");
        printf("\n\n\n");
        printf("                          |**************************************************|   \n");
        printf("                          |               Rechercher un joueur               |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 1. Rechercher un joueur par ID                   |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 2. Rechercher un joueur par Nom                  |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 3. Quite                                         |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|  \n\n\n");
        printf("Quel est votre choix ? : ");
        scanf("%d", &le_choi);
        switch (le_choi)
        {
        case 1:
            int id;
            printf("Entrez l'ID du joueur : ");
            scanf("%d", &id);
            int indexI = rechercherById(id);
            if (indexI != -1)
            {
                Joueur joueurs[1];
                joueurs[0] = equipe[indexI];
                afficherToutLesJoueur(joueurs , 1);
            }
            else
            {
                printf(RED "Aucun joueur avec l'ID %d dans l'equipe !!!" RESET, id);
                getchar();
                printf(RESET "\nAppuyez sur Entrer pour continuer...");
                getchar();
            }
            break;
        case 2:
            char nom[50];
            printf("Entrez l'nom du joueur ");
            scanf("%s", nom);
            int indexN = rechercherByNom(nom);
            if (indexN != -1)
            {
                Joueur joueurs[1];
                joueurs[0] = equipe[indexN];
                afficherToutLesJoueur(joueurs , 1);
            }
            else
            {
                printf(RED "Aucun joueur avec l'nom %s dans l'equipe !!!" RESET, nom);
                getchar();
                printf(RESET "\nAppuyez sur Entrer pour continuer...");
                getchar();
            }
            break;
        default:
            break;
        }
    } while (le_choi != 3);
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
        printf(YELLOW "                          |       2. Afficher les joueur                    |   \n" RESET);
        printf(BLUE "                          |       3. Rechercher un joueur                   |   \n" RESET);
        printf("                          |       4. Quitter                                |   \n");
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
            menuAfficher();
            break;
        case 3:
            menuRechercher();
            break;
        default:
            break;
        }

    } while (le_choi != 4);
}



int main()
{
    menu();
}
