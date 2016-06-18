#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

void modelo (void );
void imprime (int [][MAX]);
int jogada1 (int [][MAX]);
int jogada2 (int [][MAX]);
int verifica (int [][MAX]);

int main (){
    int tabuleiro [MAX][MAX] = {0}, flag = 0, cont = 0;
    modelo ();
    while (1)
    {
        while (jogada1 (tabuleiro));
        cont++;
        imprime (tabuleiro);
        flag = verifica (tabuleiro);
        if (flag != 0 || cont == 9)
        {
            break;
        }
        printf ("\n");
        while (jogada2 (tabuleiro));
        cont++;
        imprime (tabuleiro);
        flag = verifica (tabuleiro);
        if (flag != 0 || cont == 9)
        {
            break;
        }
        printf ("\n");
    }

    if (flag == 0)
        printf ("\nTIE!");
    if (flag == 88)
        printf ("\nPLAYER 1 HAS WON THE GAME");
    if (flag == 79)
        printf ("\nPLAYER 2 HAS WON THE GAME");
    return 0;
}

void modelo (void){
    printf ("|   1   |   2   |   3   |\n|   4   |   5   |   6   |\n|   7   |   8   |   9   |\n");
}

void imprime (int a [MAX][MAX]){
    int i, j;

    system("cls");
    for (i = 0; i < 3; i++){
        printf ("|");
        for (j = 0; j < 3; j++)
            printf ("   %c   |", a [i][j]);
        printf ("\n");
    }
}

int jogada1 (int tab [MAX][MAX])
{
    int posicao;

    printf ("Player 1: "); scanf ("%d", &posicao);

    switch (posicao)
    {
        case 1: if (tab [0][0] == 0)
                {
                    tab [0][0] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 2: if (tab [0][1] == 0)
                {
                    tab [0][1] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 3: if (tab [0][2] == 0)
                {
                    tab [0][2] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                }
                break;
        case 4: if (tab [1][0] == 0)
                {
                    tab [1][0] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 5: if (tab [1][1] == 0)
                {
                    tab [1][1] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 6: if (tab [1][2] == 0)
                {
                    tab [1][2] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 7: if (tab [2][0] == 0)
                {
                    tab [2][0] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 8: if (tab [2][1] == 0)
                {
                    tab [2][1] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 9: if (tab [2][2] == 0)
                {
                    tab [2][2] = 88;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        default: printf ("Invalid position. Try again!");
                 return (1);
    }
}

int jogada2 (int tab [MAX][MAX])
{
    int posicao;

    printf ("Player 2: "); scanf ("%d", &posicao);

    switch (posicao)
    {
        case 1: if (tab [0][0] == 0)
                {
                    tab [0][0] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 2: if (tab [0][1] == 0)
                {
                    tab [0][1] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 3: if (tab [0][2] == 0)
                {
                    tab [0][2] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 4: if (tab [1][0] == 0)
                {
                    tab [1][0] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 5: if (tab [1][1] == 0)
                {
                    tab [1][1] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 6: if (tab [1][2] == 0)
                {
                    tab [1][2] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 7: if (tab [2][0] == 0)
                {
                    tab [2][0] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 8: if (tab [2][1] == 0)
                {
                    tab [2][1] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        case 9: if (tab [2][2] == 0)
                {
                    tab [2][2] = 79;
                    return (0);
                }
                else
                {
                    printf ("This position has already been occupied. Try again!\n");
                    return (1);
                }
                break;
        default: printf ("Invalid position. Try again!");
                 return (1);
    }
}

int verifica (int a [MAX][MAX])
{
    int i, j, verifica = 0;
    //verifica as linhas
    for (i = 0; i < 3; i++)
    {
        if (a [i][0] == a [i][1] && a [i][1] == a [i][2])
        {
            if (a [i][0] == 88)
            {
                verifica = 88;
            }
            if (a [i][0] == 79)
            {
                verifica = 79;
            }
        }
    }
    //verifica as colunas
    for (i = 0; i < 3; i++)
    {
        if (a [0][i] == a [1][i] && a [1][i] == a [2][i])
        {
            if (a [0][i] == 88)
            {
                verifica = 88;
            }
            if (a [0][i] == 79)
            {
                verifica = 79;
            }
        }
    }
    //verifica a diagonal principal
    if (a [0][0] == a [1][1] && a [1][1] == a [2][2])
    {
        if (a [0][0] == 88)
        {
            verifica = 88;
        }
        if (a [0][0] == 79)
        {
            verifica = 79;
        }
    }
    //verifica a diagonal secundaria
    if (a [0][2] == a [1][1] && a [1][1] == a [2][0])
    {
        verifica = a [0][2];
    }
    return (verifica);
}
