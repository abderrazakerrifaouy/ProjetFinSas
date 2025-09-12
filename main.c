#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define CYAN_title "\033[1;36m"

typedef struct
{
    int id;
    char nom[50];
    char Prenom[50];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
    char dateInscription[11];
    char statut[20];
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

void getdateInscription(char *dateInscription)
{
    time_t t = time(0);
    struct tm tm = *localtime(&t);
    sprintf(dateInscription, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
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
        isValide = scanf("%d", &equipe[conteur].numeroMaillot);
        printf("                          |                                                                               |\n");
        if (isValide != 1)
        {
            printf("                          |      " RED "Le numero de maillot doit etre un nombre !!!" RESET "                             |\n");
            printf("                          |                                                                               |\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            isValide = valideNumeroMaillot(equipe[conteur].numeroMaillot);
            if (!isValide)
            {
                printf("                          |      " RED "Ce numero de maillot (%d) existe deja dans l'equipe !!!" RESET "                  |\n", equipe[conteur].numeroMaillot);
                printf("                          |                                                                               |\n");
            }
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
        isValide = scanf("%d", &equipe[conteur].age);
        if (isValide != 1)
        {
            printf("                          |      " RED "L'age doit etre un nombre !!!" RESET "                                        |\n");
            printf("                          |                                                                               |\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            printf("                          |                                                                               |\n");

            isValide = (equipe[conteur].age > 16 && equipe[conteur].age <= 45);
            if (!isValide)
            {
                printf("                          |      " RED "L'age doit etre entre 16 et 45 !!!" RESET "                                        |\n");
                printf("                          |                                                                               |\n");
            }
        }
    } while (!isValide);

    do
    {
        printf("                             Entrez le nombre de buts du joueur %d : ", i + 1);
        isValide = scanf("%d", &equipe[conteur].buts);
        printf("                          |                                                                               |\n");
        if (isValide != 1)
        {
            printf("                          |      " RED "Le nombre de buts doit etre un nombre !!!" RESET "                           |\n");
            printf("                          |                                                                               |\n");
            while (getchar() != '\n')
                ;
        }
        else
        {

            isValide = (equipe[conteur].buts >= 0);
            if (!isValide)
            {
                printf("                          |      " RED "Le nombre de buts ne peut pas etre negatif !!!" RESET "                           |\n");
                printf("                          |                                                                               |\n");
            }
        }
    } while (!isValide);

    do
    {
        isValide = 0;
        int statut;
        printf("                             Entrez le statut du joueur %d (1 ==> titulaire, 2 ==> remplacant ) : ", i + 1);
        isValide = scanf("%d", &statut);
        printf("                          |                                                                               |\n");
        if (isValide == 1 && (statut == 1 || statut == 2))
        {
            if (statut == 1)
            {
                strcpy(equipe[conteur].statut, "titulaire");
            }
            else
            {
                strcpy(equipe[conteur].statut, "remplacant");
            }
        }
        else
        {
            printf("                          |      " RED "Le statut doit etre 1 ou 2 !!!" RESET "                                           |\n");
            printf("                          |                                                                               |\n");
            while (getchar() != '\n')
                ;
        }

    } while (!isValide);

    getdateInscription(equipe[conteur].dateInscription);
    equipe[conteur].id = ++genereId;

    printf("                          +*******************************************************************************+\n\n");
    printf(GREEN " Le joueur %s %s a ete ajoute avec succes !!! \n" RESET, equipe[conteur].nom, equipe[conteur].Prenom);
    conteur++;
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
}

void afficherLesJoueur(Joueur joueurs[], int nJoueur)
{

    if (nJoueur > 0)
    {
        printf("             +********************************************************************************************************************************************************************+\n");
        printf("            ||                ||                ||                ||                ||                ||                ||                ||                  ||                  ||\n");
        printf("            || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s || %-*s ||\n", 14, "id", 14, "nom", 14, "prenom", 14, "Numero Maillot", 14, "Post", 14, "Age", 14, "buts", 14, "Date Inscription", 16, "statut");
        printf("            ||                ||                ||                ||                ||                ||                ||                ||                  ||                  ||\n");
        printf("             +*********************************************************************************************************************************************************************+\n");
        printf("            ||                ||                ||                ||                ||                ||                ||                ||                  ||                  ||\n");

        for (int i = 0; i < nJoueur; i++)
        {
            printf("            || %-*d || %-*s || %-*s || %-*d || %-*s || %-*d || %-*d || %-*s || %-*s ||\n", 14, joueurs[i].id, 14, joueurs[i].nom, 14, joueurs[i].Prenom, 14, joueurs[i].numeroMaillot, 14, joueurs[i].poste, 14, joueurs[i].age, 14, joueurs[i].buts, 16, joueurs[i].dateInscription, 16, joueurs[i].statut);
            printf("            ||                ||                ||                ||                ||                ||                ||                ||                  ||                  ||\n");
        }
        printf("             +*********************************************************************************************************************************************************************+\n");
    }
    else
    {
        printf(RED "Aucun joueur dans l'equipe !!!" RESET);
    }
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
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
    system("cls");
    printf("\n\n\n");
    printf("les joueurs tries par ordre alphabetique (Nom) : \n");
    afficherLesJoueur(joueurs, conteur);
}

void afficherJoueursByPrenom()
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
            if (!checkString(joueurs[j].Prenom, joueurs[j + 1].Prenom))
            {
                Joueur tmp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = tmp;
            }
        }
    }
    system("cls");
    printf("\n\n\n");
    printf("les joueurs tries par ordre alphabetique (Prenom) : \n");
    afficherLesJoueur(joueurs, conteur);
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
    system("cls");
    printf("\n\n\n");
    printf("les joueurs tries par age croissant : \n");
    afficherLesJoueur(joueurs, conteur);
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
            system("cls");
            printf("les joueurs tries par poste (%s) : \n", poste);
            afficherLesJoueur(joueurs, c);
        }
        else
        {
            printf(RED "Aucun joueur avec le poste %s dans l'equipe !!!" RESET, poste);
            getchar();
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
        }
    }
    else
    {
        printf(RED "Ce poste est invalide !!!" RESET);
        getchar();
        printf("\nAppuyez sur Entrer pour continuer...");
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

void modifier()
{
    char nom[50];
    printf("Entrez le nom du joueur a modifier : ");
    scanf("%s", nom);
    int index = rechercherByNom(nom);
    if (index != -1)
    {
        int le_choix;
        do
        {
            Joueur joueurs[1];
            joueurs[0] = equipe[index];
            system("cls");
            afficherLesJoueur(joueurs, 1);

            int isValide = 0;

            printf("\n\n\n");
            printf("                             ****************************************************************\n");
            printf("                             |                   Modifier un joueur                         |\n");
            printf("                             ****************************************************************\n");
            printf("                             |   1. Modifier le poste d'un joueur.                          |\n");
            printf("                             |   2. Modifier l'age d'un joueur.                             |\n");
            printf("                             |   3. Modifier le nombre de buts marques par un joueur.       |\n");
            printf("                             |   4. Quitter.                                                |\n");
            printf("                             ****************************************************************\n");
            printf("Quel est votre choix ? : ");
            isValide = scanf("%d", &le_choix);
            if (isValide != 1)
            {
                while (getchar() != '\n');
                printf(RED "Le choix doit etre un nombre !!!" RESET);
                printf("\nAppuyez sur Entrer pour continuer...");
                getchar();

                le_choix = 0;
            }

            switch (le_choix)
            {
            case 1:
                do
                {
                    printf("Entrez le nouveau poste du joueur %s (gardien, defenseur, milieu, attaquant) : ", nom);
                    scanf("%s", equipe[index].poste);

                    isValide = validePoste(equipe[index].poste);
                    if (!isValide)
                    {
                        printf(RED "Ce poste est invalide !!!\n" RESET);
                    }
                } while (!isValide);
                break;
            case 2:
                do
                {
                    printf("Entrez le nouvel age du joueur %s : ", nom);
                    isValide = scanf("%d", &equipe[index].age);
                    if (isValide != 1)
                    {
                        printf(RED "L'age doit etre un nombre !!!\n" RESET);
                        while (getchar() != '\n')
                            ;
                    }
                    else
                    {
                        isValide = (equipe[index].age > 16 && equipe[index].age <= 45);
                        if (!isValide)
                        {
                            printf(RED "L'age doit etre entre 16 et 45 !!!\n" RESET);
                        }
                    }
                } while (!isValide);
                break;
            case 3:
                do
                {
                    printf("Entrez le nouveau nombre de buts du joueur %s : ", nom);
                    isValide = scanf("%d", &equipe[index].buts);
                    if (isValide != 1)
                    {
                        printf(RED "Le nombre de buts doit etre un nombre !!!\n" RESET);
                        while (getchar() != '\n')
                            ;
                    }
                    else
                    {
                        isValide = (equipe[index].buts >= 0);
                        if (!isValide)
                        {
                            printf(RED "Le nombre de buts ne peut pas etre negatif !!!\n" RESET);
                        }
                    }
                } while (!isValide);
                break;
            default:
                break;
            }
        } while (le_choix != 4);
    }
    else
    {
        printf(RED "Aucun joueur avec le nom %s dans l'equipe !!!" RESET, nom);
        getchar();
        printf("\nAppuyez sur Entrer pour continuer...");
        getchar();
    }
}

void Supprimer()
{
    int isValide = 0;
    int le_choix;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("                          |**************************************************|   \n");
        printf("                          |               Supprimer un joueur                |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 1. Supprimer un joueur par ID                    |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 2. Supprimer un joueur par Nom                   |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 3. Quite                                         |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|  \n\n\n");
        printf("Quel est votre choix ? : ");
        isValide = scanf("%d", &le_choix);
        if (isValide != 1)
        {
            while (getchar() != '\n')
                ;
            printf(RED "Le choix doit etre un nombre !!!" RESET);
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();

            le_choix = 0;
        }

        char confirme;
        Joueur joueurs[1];
        switch (le_choix)
        {
        case 1:
            int id;

            printf("Entrez l'ID du joueur a supprimer : ");
            isValide = scanf("%d", &id);
            if (isValide != 1)
            {
                printf(RED "L'ID doit etre un nombre !!!" RESET);
                while (getchar() != '\n')
                    ;
                break;
            }
            else
            {
                int indexI = rechercherById(id);
                if (indexI != -1)
                {
                    joueurs[0] = equipe[indexI];
                    system("cls");
                    printf("Le joueur a supprimer est : \n");
                    afficherLesJoueur(joueurs, 1);
                    printf(RED "Etes-vous sur de vouloir supprimer ce joueur ? (Y/N) : " RESET);
                    scanf(" %c", &confirme);
                    if (confirme == 'Y' || confirme == 'y')
                    {
                        for (int i = indexI; i < conteur - 1; i++)
                        {
                            equipe[i] = equipe[i + 1];
                        }
                        conteur--;
                    }
                }
                else
                {
                    printf(RED "Aucun joueur avec l'ID %d dans l'equipe !!!" RESET, id);
                    getchar();
                    printf("\nAppuyez sur Entrer pour continuer...");
                    getchar();
                }
            }
            break;
        case 2:
            char nom[50];
            printf("Entrez l'nom du joueur a supprimer ; ");
            isValide = scanf("%s", nom);
            if (isValide != 1)
            {
                printf(RED "Le nom doit etre une chaine de caracteres !!!" RESET);
                while (getchar() != '\n')
                    ;
                break;
            }
            else
            {
                int indexN = rechercherByNom(nom);
                if (indexN != -1)
                {
                    joueurs[0] = equipe[indexN];
                    system("cls");
                    printf("Le joueur a supprimer est : \n");
                    afficherLesJoueur(joueurs, 1);
                    printf(RED "Etes-vous sur de vouloir supprimer ce joueur ? (Y/N) : " RESET);
                    scanf(" %c", &confirme);
                    if (confirme == 'Y' || confirme == 'y')
                    {
                        for (int i = indexN; i < conteur - 1; i++)
                        {
                            equipe[i] = equipe[i + 1];
                        }
                        conteur--;
                    }
                }
                else
                {
                    printf(RED "Aucun joueur  %s dans l'equipe !!!" RESET, nom);
                    getchar();
                    printf("\nAppuyez sur Entrer pour continuer...");
                    getchar();
                }
            }
            break;
        default:
            break;
        }

    } while (le_choix != 3);
}

void menuAfficher()
{
    int isValide = 0;
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
        printf("                          | 4. Afficher les joueurs par prenom               |   \n");
        printf("                          |                                                  |   \n");
        printf("                          | 5. Quitter                                       |   \n");
        printf("                          |                                                  |   \n");
        printf("                          |**************************************************|  \n\n\n");
        printf("Quel est votre choix ? : ");
        isValide = scanf("%d", &le_choi);

        if (isValide != 1)
        {
            while (getchar() != '\n')
                ;
            printf(RED "Le choix doit etre un nombre !!!" RESET);

            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
            le_choi = 0;
        }
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
            break;
        case 4:
            afficherJoueursByPrenom();
            break;
        default:
            break;
        }
    } while (le_choi != 5);
}

void menuAjouterUnJoueur()
{
    int isValide = 0;
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
        isValide = scanf("%d", &le_choi);
        if (isValide != 1)
        {
            while (getchar() != '\n')
                ;
            printf(RED "Le choix doit etre un nombre !!!" RESET);
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();

            le_choi = 0;
        }

        switch (le_choi)
        {
        case 1:
            ajouterUnJoueur(0);
            break;
        case 2:
            int nJoueurs;
            int isValideN;
            do
            {
                printf("Combien de joueurs voulez-vous ajouter ? ");
                isValideN = scanf("%d", &nJoueurs);
                if (isValideN != 1 || nJoueurs <= 0)
                {
                    while (getchar() != '\n')
                        ;
                    printf(RED "Le nombre de joueurs doit etre un nombre positif !!!" RESET);
                    printf("\nAppuyez sur Entrer pour continuer...");
                    getchar();
                }
            } while (isValideN != 1 || nJoueurs <= 0);

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
    int isValide = 0;
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
        isValide = scanf("%d", &le_choi);
        if (isValide != 1)
        {
            while (getchar() != '\n')
                ;
            printf(RED "Le choix doit etre un nombre !!!" RESET);
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
            le_choi = 0;
        }
        switch (le_choi)
        {
        case 1:
            int id;
            printf("Entrez l'ID du joueur : ");
            isValide = scanf("%d", &id);
            if (isValide != 1)
            {
                printf(RED "L'ID doit etre un nombre !!!" RESET);
                while (getchar() != '\n')
                    ;
            }
            else
            {
                int indexI = rechercherById(id);
                if (indexI != -1)
                {
                    Joueur joueurs[1];
                    joueurs[0] = equipe[indexI];
                    system("cls");
                    printf("Le joueur avec l'ID %d est : \n", id);
                    afficherLesJoueur(joueurs, 1);
                }
                else
                {
                    printf(RED "Aucun joueur avec l'ID %d dans l'equipe !!!" RESET, id);
                    getchar();
                    printf("\nAppuyez sur Entrer pour continuer...");
                    getchar();
                }
            }
            break;
        case 2:
            char nom[50];
            printf("Entrez l'nom du joueur : ");
            scanf("%s", nom);
            int indexN = rechercherByNom(nom);
            if (indexN != -1)
            {
                Joueur joueurs[1];
                joueurs[0] = equipe[indexN];
                system("cls");
                printf("Le joueur avec le nom %s est : \n", nom);
                afficherLesJoueur(joueurs, 1);
            }
            else
            {
                printf(RED "Aucun joueur avec l'nom %s dans l'equipe !!!" RESET, nom);
                getchar();
                printf("\nAppuyez sur Entrer pour continuer...");
                getchar();
            }
            break;
        default:
            break;
        }
    } while (le_choi != 3);
}

void nombreTotalJoueur()
{
    printf("le nombre total des joueurs est : %d", conteur);
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
}

void moyenAge()
{
    if (conteur > 0)
    {
        int somme = 0;
        for (int i = 0; i < conteur; i++)
        {
            somme += equipe[i].age;
        }
        printf("le moyen age des joueurs est : %.2f", (float)somme / conteur);
    }
    else
    {
        printf(RED "Aucun joueur dans l'equipe !!!" RESET);
    }
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
}

void afficherJoueursPlusDeXButs()
{
    int isValide = 0;
    int numBut;
    Joueur joueurs[100];
    int c = 0;
    printf("Entrez le nombre de buts : ");
    isValide = scanf("%d", &numBut);
    if (isValide != 1)
    {
        printf(RED "Le nombre de buts doit etre un nombre !!!" RESET);
        while (getchar() != '\n');
    }
    else
    {
        for (int i = 0; i < conteur; i++)
        {
            if (equipe[i].buts >= numBut)
            {
                joueurs[c] = equipe[i];
                c++;
            }
        }
        if (c > 0)
        {
            system("cls");
            printf("les joueurs avec plus de %d buts sont : \n", numBut);
            afficherLesJoueur(joueurs, c);
        }
        else
        {
            printf(RED "Aucun joueur avec plus de %d buts dans l'equipe !!!" RESET, numBut);
            getchar();
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
        }
    }
}

void meilleurButeur()
{
    Joueur joueurs[100];
    joueurs[0] = equipe[0];
    for (int i = 1; i < conteur; i++)
    {
        if (joueurs[0].buts < equipe[i].buts)
        {
            joueurs[0] = equipe[i];
        }
    }
    system("cls");
    printf("le meilleur buteur est : \n");
    afficherLesJoueur(joueurs, 1);
}

void joueurPlusAge()
{
    Joueur joueurs[100];
    joueurs[0] = equipe[0];
    for (int i = 1; i < conteur; i++)
    {
        if (joueurs[0].age < equipe[i].age)
        {
            joueurs[0] = equipe[i];
        }
    }
    system("cls");
    printf("le joueur le plus age est : \n");
    afficherLesJoueur(joueurs, 1);
}

void joueurPlusJeune()
{
    Joueur joueurs[100];
    joueurs[0] = equipe[0];
    for (int i = 1; i < conteur; i++)
    {
        if (joueurs[0].age > equipe[i].age)
        {
            joueurs[0] = equipe[i];
        }
    }
    system("cls");
    printf("le joueur le plus jeune est : \n");
    afficherLesJoueur(joueurs, 1);
}

void menu()
{
    int isValide = 0;
    int le_choi;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("                          |*************************************************|   \n");
        printf("                          |                   " CYAN_title "Menu" RESET "                          |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n");
        printf("                          |                                                 |   \n");
        printf(GREEN "                          |   1. Ajouter un joueur                          |   \n" RESET);
        printf(BLUE "                          |   2. Afficher les joueurs                       |   \n" RESET);
        printf(CYAN "                          |   3. Rechercher un joueur                       |   \n" RESET);
        printf(YELLOW "                          |   4. Modifier un joueur                         |   \n" RESET);
        printf(RED "                          |   5. Supprimer un joueur                        |   \n" RESET);
        printf(GREEN "                          |   6. Nombre total des joueurs                   |   \n" RESET);
        printf(BLUE "                          |   7. Moyenne d'age des joueurs                  |   \n" RESET);
        printf(CYAN "                          |   8. Afficher les joueurs avec +X buts          |   \n" RESET);
        printf(YELLOW "                          |   9. Afficher le meilleur buteur                |   \n" RESET);
        printf(GREEN "                          |  10. Afficher le joueur le plus age             |   \n" RESET);
        printf(BLUE "                          |  11. Afficher le joueur le plus jeune           |   \n" RESET);
        printf(RED "                          |  12. Quitter                                    |   \n" RESET);
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n\n\n");

        printf("Quel est votre choix ? : ");
        isValide = scanf("%d", &le_choi);

        if (isValide != 1)
        {
            printf(RED "Le choix doit etre un nombre !!!" RESET);

            while (getchar() != '\n')
                ;
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
            le_choi = 0;
        }

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
        case 4:
            modifier();
            break;
        case 5:
            Supprimer();
            break;
        case 6:
            nombreTotalJoueur();
            break;
        case 7:
            moyenAge();
            break;
        case 8:
            afficherJoueursPlusDeXButs();
            break;
        case 9:
            meilleurButeur();
            break;
        case 10:
            joueurPlusAge();
            break;
        case 11:
            joueurPlusJeune();
            break;
        default:
            break;
        }

    } while (le_choi != 12);
}

void inialiserData()
{
    equipe[0].id = ++genereId;
    strcpy(equipe[0].nom, "abderrazak");
    strcpy(equipe[0].Prenom, "errifaouy");
    equipe[0].numeroMaillot = 7;
    strcpy(equipe[0].poste, "attaquant");
    equipe[0].age = 23;
    equipe[0].buts = 850;
    getdateInscription(equipe[0].dateInscription);
    strcpy(equipe[0].statut, "titulaire");

    equipe[1].id = ++genereId;
    strcpy(equipe[1].nom, "yassin");
    strcpy(equipe[1].Prenom, "errifaouy");
    equipe[1].numeroMaillot = 10;
    strcpy(equipe[1].poste, "attaquant");
    equipe[1].age = 36;
    equipe[1].buts = 800;
    getdateInscription(equipe[1].dateInscription);
    strcpy(equipe[1].statut, "titulaire");

    equipe[2].id = ++genereId;
    strcpy(equipe[2].nom, "hassan");
    strcpy(equipe[2].Prenom, "younes");
    equipe[2].numeroMaillot = 11;
    strcpy(equipe[2].poste, "attaquant");
    equipe[2].age = 30;
    equipe[2].buts = 400;
    getdateInscription(equipe[2].dateInscription);
    strcpy(equipe[2].statut, "titulaire");

    equipe[3].id = ++genereId;
    strcpy(equipe[3].nom, "abdollah");
    strcpy(equipe[3].Prenom, "mohamed");
    equipe[3].numeroMaillot = 7;
    strcpy(equipe[3].poste, "milieu");
    equipe[3].age = 27;
    equipe[3].buts = 50;
    getdateInscription(equipe[3].dateInscription);
    strcpy(equipe[3].statut, "titulaire");

    equipe[4].id = ++genereId;
    strcpy(equipe[4].nom, "ahmed");
    strcpy(equipe[4].Prenom, "ben");
    equipe[4].numeroMaillot = 9;
    strcpy(equipe[4].poste, "attaquant");
    equipe[4].age = 25;
    equipe[4].buts = 100;
    getdateInscription(equipe[4].dateInscription);
    strcpy(equipe[4].statut, "titulaire");

    equipe[5].id = ++genereId;
    strcpy(equipe[5].nom, "younes");
    strcpy(equipe[5].Prenom, "mohamed");
    equipe[5].numeroMaillot = 4;
    strcpy(equipe[5].poste, "defenseur");
    equipe[5].age = 40;
    equipe[5].buts = 200;
    getdateInscription(equipe[5].dateInscription);
    strcpy(equipe[5].statut, "titulaire");

    equipe[6].id = ++genereId;
    strcpy(equipe[6].nom, "karim");
    strcpy(equipe[6].Prenom, "benzema");
    equipe[6].numeroMaillot = 19;
    strcpy(equipe[6].poste, "attaquant");
    equipe[6].age = 35;
    equipe[6].buts = 300;
    getdateInscription(equipe[6].dateInscription);
    strcpy(equipe[6].statut, "titulaire");

    equipe[7].id = ++genereId;
    strcpy(equipe[7].nom, "yassine");
    strcpy(equipe[7].Prenom, "bounou");
    equipe[7].numeroMaillot = 1;
    strcpy(equipe[7].poste, "milieu");
    equipe[7].age = 31;
    equipe[7].buts = 0;
    getdateInscription(equipe[7].dateInscription);
    strcpy(equipe[7].statut, "titulaire");

    equipe[8].id = ++genereId;
    strcpy(equipe[8].nom, "rachid");
    strcpy(equipe[8].Prenom, "guernaoui");
    equipe[8].numeroMaillot = 5;
    strcpy(equipe[8].poste, "defenseur");
    equipe[8].age = 29;
    equipe[8].buts = 10;
    getdateInscription(equipe[8].dateInscription);
    strcpy(equipe[8].statut, "titulaire");

    equipe[9].id = ++genereId;
    strcpy(equipe[9].nom, "samir");
    strcpy(equipe[9].Prenom, "nasri");
    equipe[9].numeroMaillot = 8;
    strcpy(equipe[9].poste, "milieu");
    equipe[9].age = 34;
    equipe[9].buts = 20;
    getdateInscription(equipe[9].dateInscription);
    strcpy(equipe[9].statut, "titulaire");

    conteur = 10;
}

int main()
{
    inialiserData();
    menu();
}
