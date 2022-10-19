#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include "burger.h"
#define MAX 500

FILE* openBin(char* path){
    FILE *fwr;
    do{
        fwr = fopen(path, "ab+");
    }
    while(loadFile(path, fwr));
    printf("\n");
    return fwr;
}

//Escreve no arquivo o cabecalho contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: cabecalho escrito no arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET); //posiciona no inıcio do arquivo
    fwrite(cab,sizeof(cabecalho),1,arq);
}

//Cria uma lista nova em arquivo
//Pre-condicao: arquivo aberto para leitura/escrita
//Pos-condicao: arquivo e inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

//Le o cabecalho do arquivo contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: retorna o ponteiro para o cabecalho lido
cabecalho* le_cabecalho(FILE * arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq,0,SEEK_SET); // posiciona no inıcio do arquivo
    fread(cab,sizeof(cabecalho),1,arq);
    return cab;
}

//Le um no em uma determinada posicao do arquivo
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista; pos deve ser uma posicao valida da lista
//Pos-condicao: ponteiro para no lido e retornado
no* le_no(FILE* arq, int pos) {
    no* x = malloc(sizeof(no));
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fread(x,sizeof(no),1,arq);
    return x;
}

//Escreve um no em uma determinada posicao do arquivo
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista; pos deve ser uma posicao valida do arquivo
//Pos-condicao: no escrito no arquivo
void escreve_no(FILE* arq, no* x, int pos){
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fwrite(x,sizeof(no),1,arq);
}

//Insere um no na lista encadeada no arquivo
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: no inserido no arquivo
void insere(FILE* arq, int info){
    cabecalho* cab = le_cabecalho(arq);
    no x;
    x.info = info;
    x.prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // nao ha nos livres, entao usar o topo
        escreve_no(arq,&x,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar no da lista de livres
        no* aux = le_no(arq,cab->pos_livre);
        escreve_no(arq,&x,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab);
    free(cab);
}

//Retira um no da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: no retirado da lista caso pertenca a ela
void retira(FILE* arq, int x){
    cabecalho* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    no* aux = NULL;
    while(pos_aux != -1 && // procura o elemento a ser retirado
          ((aux = le_no(arq,pos_aux))!= NULL) &&
          aux->info != x){
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remocao na cabeca
            cab->pos_cabeca = aux->prox;
        }
        else { // remocao no meio
            no * ant = le_no(arq,pos_ant);
            ant->prox = aux->prox;
            escreve_no(arq,ant,pos_ant);
            free(ant);
        }
        aux->prox = cab->pos_livre; // torna o no removido um no livre
        cab->pos_livre = pos_aux;
        escreve_no(arq,aux,pos_aux);
        escreve_cabecalho(arq,cab);
        free(aux);
    }
    free(cab);
}
