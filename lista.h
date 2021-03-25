#define MAXIMO_ALUNOS 30

typedef struct aluno Aluno;
typedef struct lista Lista;

Lista* criaLista();
int tamanhoLista(Lista*);
int listaCheia(Lista*);
void adicionarRegistro(Lista*, char*, float);
void removerRegistro(Lista*, int);
void ordenaListaNota(Lista*);
void ordenaListaNome(Lista*);
void mensagemDeErro(int);
char* getNome(Lista*, int);
float getNota(Lista*, int);
