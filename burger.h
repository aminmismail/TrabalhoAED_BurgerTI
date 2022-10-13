#ifndef BURGER_H
#define BURGER_H
#include <stdio.h>

void menu();
void cadastroSanduiche();
void cadastroBebida();
void cadastroSobremesa();
void cadastroExtra();
void printSanduiche();
void printBebida();
void printSobremesa();
void printExtra();
void printPedido();
void printPedidoAtendido();
void cadastroPedido();
void loadPath();
int loadFile(char* path, FILE* file);

#endif //BURGER_H
