#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct aluno
{
    char nome[31];
    float nota;
};

struct lista
{
    int quantidade;
    Aluno aluno[MAXIMO_ALUNOS];
};

Lista* criaLista()
{
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL)
    {
        lista->quantidade = 0;
        for (int i = 0; i < MAXIMO_ALUNOS; i++)
        {
            lista->aluno[i].nome[0] = '\n';
            lista->aluno[i].nota = -1;
        }
    }
    return lista;
}

int tamanhoLista(Lista* lista)
{
    if (lista == NULL)
    {
        mensagemDeErro(3);
        return -1;
    } else
    {
        return lista->quantidade;
    }
}

int listaCheia(Lista *lista)
{
    if (lista == NULL)
        return -1;
    else
        return (lista->quantidade == MAXIMO_ALUNOS);
}

void adicionarRegistro(Lista *lista, char *nome, float nota)
{
    if (listaCheia(lista) == 1)
    {
        mensagemDeErro(0);
    }
    else
    {
        int i;
        for (i = 0; i < strlen(nome); i++)
        {
            lista->aluno[lista->quantidade].nome[i] = nome[i];
        }
        lista->aluno[lista->quantidade].nome[i] = '\0';
        lista->aluno[lista->quantidade].nota = nota;
        if ((lista->aluno[lista->quantidade].nota < 0 || lista->aluno[lista->quantidade].nota > 10) ||  lista->aluno[lista->quantidade].nome[0] == '\n')
        {
            lista->aluno[lista->quantidade].nome[0] = '\0';
            mensagemDeErro(1);
        }
        else
        {
            system("cls");
            printf("Nome: %s\t", lista->aluno[lista->quantidade].nome);
            printf("Nota: %.1f\nAdicionado com sucesso!\n\n", lista->aluno[lista->quantidade].nota);
            lista->quantidade++;
            system("pause");
        }

    }
}

void removerRegistro(Lista *lista, int posicao)
{
    posicao -=1;
    if (lista->aluno[posicao].nota >= 0)
    {
        lista->aluno[posicao].nome[0] = '\n';
        lista->aluno[posicao].nota = -1;
        for (int i = posicao; i < lista->quantidade; i++)
        {
            lista->aluno[posicao] = lista->aluno[posicao + 1];
        }

        lista->quantidade--;
        system("cls");
        printf("Removido com sucesso!\n");
        system("pause");
    }
    else
    {
        mensagemDeErro(2);
    }
}

void ordenaListaNome(Lista *lista)
{
    Aluno aux;
    int j, i;
    for (i = 0; i < lista->quantidade; i++)
    {
        aux = lista->aluno[i];
        for (j=i; j>0 && (strcmp(aux.nome, lista->aluno[j-1].nome)<0); j--)
            lista->aluno[j] = lista->aluno[j-1];

        lista->aluno[j] = aux;
    }
}

void ordenaListaNota(Lista *lista)
{
    Aluno aux;
    int j, i;
    for (i = 0; i < lista->quantidade; i++)
    {
        aux = lista->aluno[i];
        for (j=i; j>0 && (aux.nota > lista->aluno[j-1].nota); j--)
            lista->aluno[j] = lista->aluno[j-1];

        lista->aluno[j] = aux;
    }
}

void mensagemDeErro(int n)
{
    system("cls");
    printf("Erro: ");
    switch (n)
    {
    case 0:
        printf("a lista de alunos está cheia!\n\n");
        break;
    case 1:
        printf("nome ou nota inválida!\n\n");
        break;
    case 2:
        printf("registro inválido!\n\n");
        break;
    case 3:
        printf("lista vazia!\n\n");
        break;
    }
    system("pause");
}

char* getNome(Lista *lista, int i)
{
    return lista->aluno[i].nome;
}
float getNota(Lista *lista, int i)
{
    return lista->aluno[i].nota;
}
