#ifndef BURGER_H
#define BURGER_H
#include <stdio.h>

typedef struct{ //STRUCT DE SANDUICHE
    int id;
    char nome[50];
    char desc[200];
    char disp[1];
    float preco[3]; // preco do p, m, g
}sanduiche;

typedef struct{ //STRUCT DE BEBIDA
    int id;
    char nome[50];
    char disp[1];
    float preco[3]; //p, m, g
}bebida;

typedef struct{ //STRUCT DE EXTRA
    int id;
    char nome[50];
    char disp[1];
    float preco;
}extra;

typedef struct{ //STRUCT DE SOBREMESA
    int id;
    char nome[50];
    char disp[1];
    float preco;
}sobremesa;

typedef struct{ //STRUCT DE PEDIDO
    int id;
    long long cpf;
    char itens[300]; //armazena os itens do pedido em uma string
    float total;
    int prox;
}pedido;

typedef struct{ //STRUCT DO CABECALHO
    int pos_cabeca; //posicao do inıcio da lista
    int pos_topo; // 1a posicao nao usada no fim do arquivo
    int pos_livre; // posicao do inıcio da lista de nos livres
} cabecalho;

//Mostra o menu de opcoes
//Pre-condicao: Nenhuma
//Pos-condicao: Executa a funcao escolhida
void menu();

//Realiza o cadastro das informacoes de um sanduiche em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de sanduiche com as informacoes completas
void cadastroSanduiche();

//Realiza o cadastro das informacoes da estrutura de um sanduiche no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Sanduiche cadastrado no arquivo
void gravaSanduiche(sanduiche *sand);

//Realiza o cadastro das informacoes de uma bebida em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de bebida com as informacoes completas
void cadastroBebida();

//Realiza o cadastro das informacoes da estrutura de uma bebida no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Bebida cadastrada no arquivo
void gravaBebida(bebida *beb);

//Realiza o cadastro das informacoes de uma sobremesa em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de sobremesa com as informacoes completas
void cadastroSobremesa();

//Realiza o cadastro das informacoes da estrutura de uma sobremesa no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Sobremesa cadastrada no arquivo
void gravaSobremesa(sobremesa *sob);

//Realiza o cadastro das informacoes de um extra em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de um extra com as informacoes completas
void cadastroExtra();

//Realiza o cadastro das informacoes da estrutura de um extra no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Extra cadastrado no arquivo
void gravaExtra(extra *ex);

//Mostra as informacoes na tela de todos os sanduiches cadastrados
//Pre-condicao: Arquivo binario com sanduiches cadastrados
//Pos-condicao: Todos os sanduiches cadastrados mostrados na tela
void printSanduiche();

//Mostra as informacoes na tela de todos as bebidas cadastrados
//Pre-condicao: Arquivo binario com bebidas cadastradas
//Pos-condicao: Todos as bebidas cadastradas mostrados na tela
void printBebida();

//Mostra as informacoes na tela de todos as sobremesas cadastrados
//Pre-condicao: Arquivo binario com sobremesas cadastradas
//Pos-condicao: Todos as sobremesas cadastradas mostrados na tela
void printSobremesa();

//Mostra as informacoes na tela de todos os extras cadastrados
//Pre-condicao: Arquivo binario com extras cadastrados
//Pos-condicao: Todos os extras cadastrados mostrados na tela
void printExtra();

//Cadastra os itens descritos no arquivo passado
//Pre-condicao: Um caminho para um arquivo existente
//Pos-condicao: Registro dos itens nos arquivos binarios
void cleanRegister(FILE *fr);

//Mostra todos os pedidos cadastrados
//Pre-condicao: Arquivo binario com pedidos cadastrados
//Pos-condicao: Todos os pedidos cadastrados mostrados na tela
void printPedidos();

//Realiza o cadastro das informacoes da estrutura de um pedido no arquivo
//Pre-condicao: Estrutura de um pedido e arquivo binario valido
//Pos-condicao: Pedido cadastrado no arquivo
void gravaPedido(FILE *fw, pedido *ped);

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
void atendePedido();

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
void printAtendido();

//Realiza o cadastro das informacoes de um pedido em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de pedido com as informacoes completas
void cadastroPedido();

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
float getTotalPedido(pedido* ped);

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
void cancelaPedido();

//Le o caminho do arquivo passado por input, e cadastra os itens nele
//Pre-condicao: Um caminho para um arquivo existente
//Pos-condicao: Registro dos itens nos arquivos binarios
void loadPath();

//Verifica se o arquivo existe
//Pre-condicao: Um caminho para um arquivo
//Pos-condicao: Retorna se o arquivo e valido ou nao
int loadFile(char* path, FILE* file);

//Le o cabecalho do arquivo contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: retorna o ponteiro para o cabecalho lido
cabecalho* le_cabecalho(FILE * arq);

//Cria uma lista nova em arquivo
//Pre-condicao: arquivo aberto para leitura/escrita
//Pos-condicao: arquivo inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq);

//Escreve no arquivo o cabecalho contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: cabecalho escrito no arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab);

#endif //BURGER_H
