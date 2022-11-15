#ifndef BURGER_H
#define BURGER_H
#include <stdio.h>

typedef struct{ //SD
    int id;
    char nome[50];
    char desc[200];
    char disp[1];
    float preco[3]; // preco do p, m, g
}sanduiche;

typedef struct{ //BB
    int id;
    char nome[50];
    char disp[1];
    float preco[3]; //p, m, g
}bebida;

typedef struct{ //EX
    int id;
    char nome[50];
    char disp[1];
    float preco;
}extra;

typedef struct{ //SM
    int id;
    char nome[50];
    char disp[1];
    float preco;
}sobremesa;

typedef struct{ //PD
    int id;
    int cpf[11];
    char itens[300]; //armazena os itens do pedido em uma string
    float total;
}pedido;

void menu();

void cadastroSanduiche();

void gravaSand(sanduiche *sand);

void cadastroBebida();

void gravaBebida(bebida *beb);

void cadastroSobremesa();

void gravaSobremesa(sobremesa *sob);

void cadastroExtra();

void gravaExtra(extra *ex);

void printSanduiche();

void printBebida();

void printSobremesa();

void printExtra();

void cleanInput(FILE *fr);

void printPedido();

void printPedidoAtendido();

void cadastroPedido();

void loadPath();

int loadFile(char* path, FILE* file);

#endif //BURGER_H
