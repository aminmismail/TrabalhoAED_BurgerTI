#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>

// cabecalho do arquivo
typedef struct{
    int pos_cabeca; //posicao do inıcio da lista
    int pos_topo; // 1a posicao nao usada no fim do arquivo
    int pos_livre; // posicao do inıcio da lista de nos livres
} cabecalho;

// estrutura de no para lista encadeada
typedef struct {
    int info;
    int prox;
} no;

//
//Pre-condicao:
//Pos-condicao:
FILE* openBin();

//Escreve no arquivo o cabecalho contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: cabecalho escrito no arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab);

//Cria uma lista nova em arquivo
//Pre-condicao: arquivo aberto para leitura/escrita
//Pos-condicao: arquivo e inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq);

//Le o cabecalho do arquivo contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: retorna o ponteiro para o cabecalho lido
cabecalho* le_cabecalho(FILE * arq);

//Le um no em uma determinada posicao do arquivo
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista; pos deve ser uma posicao valida da lista
//Pos-condicao: ponteiro para no lido e retornado
no* le_no(FILE* arq, int pos);

//Escreve um no em uma determinada posicao do arquivo
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista; pos deve ser uma posicao valida do arquivo
//Pos-condicao: no escrito no arquivo
void escreve_no(FILE* arq, no* x, int pos);

//Insere um no na lista encadeada no arquivo
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: no inserido no arquivo
void insere(FILE* arq, int info);

//Retira um no da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: no retirado da lista caso pertenca a ela
void retira(FILE* arq, int x);

#endif //LISTA_H
