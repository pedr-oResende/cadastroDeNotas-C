#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// struct que armanzena os dados da lista
struct aluno
{
    char nome[31];
    float nota;
};

// struct para armazenar a estrutura aluno e a quantidade de alunos
struct lista
{
    int quantidade;
    Aluno aluno[MAXIMO_ALUNOS];
};

// função para criar a lista vazia
Lista* criaLista()
{
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL)
    {
        lista->quantidade = 0;
        for (int i = 0; i < MAXIMO_ALUNOS; i++)
        {
            lista->aluno[i].nome[0] = '\0';
            lista->aluno[i].nota = -1;
        }
    }
    return lista;
}

//função para retornar o tamanho da lista
int tamanhoLista(Lista* lista)
{
    if (lista == NULL)
    {
        mensagemDeErro(3);
        return -1;
    }
    else
    {
        return lista->quantidade;
    }
}

// função para retornar se a lista está cheia
int listaCheia(Lista *lista)
{
    if (lista == NULL)
        return -1;
    else
        return (lista->quantidade == MAXIMO_ALUNOS);
}

// método para adicionar um registro na lista
int adicionarRegistro(Lista *lista, char *nome, float nota)
{
    if ((nota < 0 || nota > 10) ||  nome[0] == '\0')
    {
        mensagemDeErro(1);
        return 0;
    }
    else
    {
        if (listaCheia(lista) == 1)
        {
            mensagemDeErro(0);
            return 0;
        }
        else
        {
            strcat(lista->aluno[lista->quantidade].nome, nome);
            lista->aluno[lista->quantidade].nota = nota;
            lista->quantidade++;
            return 1;
        }
    }
}

// método para remover um registro da lista
int removerRegistro(Lista *lista, int posicao)
{
    posicao -=1;
    if (posicao > lista->quantidade-1 || posicao < 0)
    {
        mensagemDeErro(2);
        return 0;
    }
    else
    {
        lista->aluno[posicao].nome[0] = '\0';
        lista->aluno[posicao].nota = -1;
        for (int i = posicao; i < lista->quantidade; i++)
            lista->aluno[posicao] = lista->aluno[posicao + 1]; // laço para jogar o resgistro para a ultima posição
        lista->quantidade--;
        return 1;
    }
}

// método para ordenar a lista em ordem alfabética
void ordenaListaNome(Lista *lista)
{
    Aluno aux;
    int j;
    for (int i = 0; i < lista->quantidade; i++)
    {
        aux = lista->aluno[i];
        for (j=i; j>0 && (strcmp(aux.nome, lista->aluno[j-1].nome)<0); j--)
            lista->aluno[j] = lista->aluno[j-1]; // laço para ordenar a lista comparando os nomes

        lista->aluno[j] = aux;
    }
}

// método para ordenar a lista em ordem decrescente de nota
void ordenaListaNota(Lista *lista)
{
    Aluno aux;
    int j;
    for (int i = 0; i < lista->quantidade; i++)
    {
        aux = lista->aluno[i];
        for (j=i; j>0 && (aux.nota > lista->aluno[j-1].nota); j--)
            lista->aluno[j] = lista->aluno[j-1]; // laço para ordenar a lista comparando as notas

        lista->aluno[j] = aux;
    }
}

// método para capturar possiveis erros durante a execução do programa
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
    case 4:
        printf("opção inválida!\n\n");
        break;
    }
    system("pause");
}

// função para retornar o nome de um aluno
char* getNome(Lista *lista, int i)
{
    return lista->aluno[i].nome;
}

// função para retornar a nota de um aluno
float getNota(Lista *lista, int i)
{
    return lista->aluno[i].nota;
}
