#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lista.h"

// protótipo das funçõs
void clear_keyboard_buffer(void);
void caractereEspecial(void);
int printMenu(void);
void printLista(Lista*, int);
float calculaMedia(Lista*);

int main()
{
    caractereEspecial();
    Lista *lista;
    int numeroAluno;
    char nome[31];
    float nota;
    lista = criaLista();
    for(;;)
    {
        int resposta = printMenu();
        switch (resposta)
        {
        case 0:
            exit(1);
            break;
        case 1:
            system("cls");
            printf("Digite o nome do aluno: ");
            gets(nome);
            printf("\nDigite a nota do aluno: ");
            scanf("%f", &nota);
            clear_keyboard_buffer();
            adicionarRegistro(lista, nome, nota);
            break;
        case 2:
            printLista(lista, 1);
            printf("\nDigite o numero do aluno que deseja remover: ");
            scanf("%d", &numeroAluno);
            clear_keyboard_buffer();
            removerRegistro(lista, numeroAluno);
            break;
        case 3:
            printLista(lista, 1);
            system("pause");
            break;
        case 4:
            printLista(lista, 2);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("A média da turma é %.1f\n\n", calculaMedia(lista));
            system("pause");
            break;
        default:
            break;
        }
    }
}



// -------funções-------

//Função para limpar o buffer do teclado
void clear_keyboard_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

// método para permitir caracteres especiais no programa
void caractereEspecial()
{
    printf("%s",setlocale(LC_ALL,""));
    system("cls");
}

int printMenu()
{
    int resp;
    system("cls");
    printf("--------------------------------------\n");
    printf("----------Cadastro de alunos----------\n");
    printf("--------------------------------------\n\n");
    printf("1 - Inserir registro\n");
    printf("2 - Remover registro\n");
    printf("3 - Listar registros\n");
    printf("4 - Rank em ordem decrescente de nota\n");
    printf("5 - Média de todas as notas\n");
    printf("0 - Sair\n\n");
    scanf("%d", &resp);
    clear_keyboard_buffer();

    return resp;
}

void printLista(Lista *lista, int n)
{
    system("cls");
    if (tamanhoLista(lista) == 0)
    {
        printf("Lista vazia!");
    }
    else
    {
        switch (n)
        {
        case 1:
            ordenaListaNome(lista);
            break;
        case 2:
            ordenaListaNota(lista);
            break;
        }
        for (int i = 0; i < tamanhoLista(lista); i++)
        {
            printf("%d\t%s\t\t%.1f\n", i+1, getNome(lista, i), getNota(lista, i));
        }
    }
    printf("\n");
}

float calculaMedia(Lista *lista)
{
    float media = 0;
    for (int i = 0; i < tamanhoLista(lista); i++)
    {
        media += getNota(lista, i);
    }
    media = media/tamanhoLista(lista);
    return media;
}
