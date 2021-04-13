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

// programa principal
int main()
{
    caractereEspecial();
    Lista *lista = criaLista();
    int numeroAluno;
    for(;;)
    {
        int resposta = printMenu();
        char nome[31];
        float nota;
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
            if (adicionarRegistro(lista, nome, nota) == 1) // condição para verificar se foi inserido com sucesso
            {
                system("cls");
                printf("Nome: %s\t", nome);
                printf("Nota: %.1f\n\nAdicionado com sucesso!\n\n", nota);
                system("pause");
            }
            break;
        case 2:
            if(tamanhoLista(lista) == 0) // condição para não imprimir a lista case ela esteja vazia
            {
                mensagemDeErro(3);
                break;
            }
            printLista(lista, 1);
            printf("\nDigite o numero do aluno que deseja remover: ");
            scanf("%d", &numeroAluno);
            clear_keyboard_buffer();
            if (removerRegistro(lista, numeroAluno) == 1) // condição para verificar se foi removido com sucesso
            {
                system("cls");
                printf("Removido com sucesso!\n\n");
                system("pause");
            }
            break;
        case 3:
            if(tamanhoLista(lista) == 0) // condição para não imprimir a lista caso ela esteja vazia
            {
                mensagemDeErro(3);
                break;
            }
            printLista(lista, 1);
            system("pause");
            break;
        case 4:
            if(tamanhoLista(lista) == 0) // condição para não imprimir a lista caso ela esteja vazia
            {
                mensagemDeErro(3);
                break;
            }
            printLista(lista, 2);
            system("pause");
            break;
        case 5:
            if(tamanhoLista(lista) == 0) // condição para não imprimir a média case ela esteja vazia
            {
                mensagemDeErro(3);
                break;
            }
            system("cls");
            printf("A média da turma é %.1f\n\n", calculaMedia(lista));
            system("pause");
            break;
        default:
            mensagemDeErro(4);
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
    setlocale(LC_ALL, "Portuguese");
}

// função para printar o layout do menu
int printMenu()
{
    int resp;
    system("cls");
    printf("--------------------------------------\n");
    printf("----------Cadastro de alunos----------\n");
    printf("--------------------------------------\n\n");
    printf("1 - Inserir registro.\n");
    printf("2 - Remover registro.\n");
    printf("3 - Listar registros.\n");
    printf("4 - Rank em ordem decrescente de nota.\n");
    printf("5 - Média de todas as notas.\n");
    printf("0 - Sair.\n\n");
    scanf("%d", &resp);
    clear_keyboard_buffer();

    return resp;
}

// método para exibir a listra da registros
void printLista(Lista *lista, int n)
{
    system("cls");
    switch (n) // switch para verificar qual será a ordenação da lista
    {
    case 1:
        ordenaListaNome(lista);
        break;
    case 2:
        ordenaListaNota(lista);
        break;
    }
    for (int i = 0; i < tamanhoLista(lista); i++) // laço para imprimir a lista
    {
        printf("%d\t%s\t\t%.1f\n", i+1, getNome(lista, i), getNota(lista, i));
    }
    printf("\n");
}

// função para calcular a média das notas
float calculaMedia(Lista *lista)
{
    float media = 0;
    for (int i = 0; i < tamanhoLista(lista); i++) // laço para percorrer a lista
    {
        media += getNota(lista, i); //expressão para calcular a média total
    }
    media = media/tamanhoLista(lista);
    return media;
}
