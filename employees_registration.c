#include <stdio.h>
#define smin 800
#define MAX 100

void cadastro_nomes_pecas_sexos (char [][MAX], int [MAX], char [MAX], int);
void calculo_salarios (float [MAX], int [MAX], int);
float folha_de_pagamento (float [MAX], int);
float media_salario_homens (char [MAX], float [MAX], int);
int pecas_fabricadas_mulheres (char [MAX], int [MAX], int);
void funcionario_maior_salario (char [][MAX], char [MAX], int [MAX], float [MAX], int);

int main ()
{
    int opcao, pecas [MAX], qtd;
    float salarios [MAX];
    char nomes [MAX][MAX], sexos [MAX];
    printf ("Total de funcionarios: "); scanf ("%d", &qtd);

    do
    {
        printf ("\n(1)Cadastrar nome, pecas fabricadas e sexo de cada funcionario.\n(2)Cadastrar o salario de cada funcionario.\n(3)Total da folha de pagamento da fabrica.\n(4)Media do salario dos homens.\n(5)Media das pecas das mulheres de cada classe.\n(6)Funcionario com o maior salario.\n\nOpcao desejada: ");
        scanf ("%d", &opcao);
        switch (opcao)
        {
            case 1: cadastro_nomes_pecas_sexos (nomes, pecas, sexos, qtd);
                    break;
            case 2: calculo_salarios (salarios, pecas, qtd);
                    break;
            case 3: printf ("\n\nTotal da folha de pagamento: %.2f", folha_de_pagamento (salarios, qtd));
                    break;
            case 4: printf ("\n\nMedia do salario dos homens: %.2f", media_salario_homens (sexos, salarios, qtd));
                    break;
            case 5: printf ("Total de pecas fabricadas pelas mulheres: %d", pecas_fabricadas_mulheres (sexos, pecas, qtd));
                    break;
            case 6: funcionario_maior_salario (nomes, sexos, pecas, salarios, qtd);
                    break;
            default: printf ("Opcao invalida!");
        }

        printf ("\n\nDeseja continuar? (0) Nao // (1) Sim"); scanf ("%d", &opcao);

    }while (opcao == 1);

    return 0;
}

void cadastro_nomes_pecas_sexos (char nomes [MAX][MAX], int pecas [MAX], char sexos [MAX], int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        fflush (stdin);
        printf ("\n-Funcionario %d\n", i + 1);
        printf ("Nome: ");
        fflush (stdin);
        gets (nomes [i]);
        printf ("Pecas fabricadas por mes: ");
        fflush (stdin);
        scanf ("%d", &pecas [i]);
        printf ("Sexo: ");
        fflush (stdin);
        scanf ("%c", &sexos [i]);
    }
}

void calculo_salarios (float salarios [MAX], int pecas [MAX], int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        fflush (stdin);
        if (pecas [i] <= 30)
        {
            salarios [i] = smin;
        }
        if (pecas [i] >= 31 && pecas [i] <= 35)
        {
            salarios [i] = smin + (pecas [i] - 30) * (0.03 * smin);
        }
        if (pecas [i] > 35)
        {
            salarios [i] = smin + (pecas [i] - 30) * (0.05 * smin);
        }
    }
    printf ("\n\nTeste:\n");
    for (i = 0; i < qtd; i++)
    {
        printf ("\nSalario do funcionario %d: %.2f", i + 1, salarios [i]);
    }
}

float folha_de_pagamento (float salarios [MAX], int qtd)
{
    int i;
    float soma = 0;
    for (i = 0; i < qtd; i++)
    {
        soma = soma + salarios [i];
    }

    return (soma);
}

float media_salario_homens (char sexos [MAX], float salarios [MAX], int qtd)
{
    int i, total_homens = 0;
    float soma = 0;

    for (i = 0; i < qtd; i++)
    {
        if (sexos [i] == 'M')
        {
            soma = soma + salarios [i];
            total_homens++;
        }
    }

    return (soma/total_homens);
}

int pecas_fabricadas_mulheres (char sexos [MAX], int pecas [MAX], int qtd)
{
    int i, total_pecas_mulheres = 0, total_mulheres = 0;
    for (i = 0; i < qtd; i++)
    {
        if (sexos [i] == 'F')
        {
            total_pecas_mulheres = total_pecas_mulheres + pecas [i];
            total_mulheres++;
        }
    }
    return (total_pecas_mulheres/total_mulheres);
}

void funcionario_maior_salario (char nomes [MAX][MAX], char sexos [MAX], int pecas [MAX], float salarios [MAX], int qtd)
{
    int i, aux;
    float maior = salarios [0];
    for (i = 0; i < qtd; i++)
    {
        if (maior < salarios [i])
        {
            maior = salarios [i];
            aux = i;
        }
    }
    printf ("\n\nFuncionario com o maior salario:\n%s\nSexo:%c\nPecas fabricadas por mes: %d\nSalario: %0.2f", nomes [aux], sexos [aux], pecas [aux], salarios [aux]);
}
