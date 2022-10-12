#include "burger.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 500

void menu(){
    int op;
    printf("1 - Cadastrar sanduiche\n2 - Cadastrar bebida\n3 - Cadastrar sobremesa\n4 - Cadastrar extra\n");
    printf("5 - Imprimir lista de sanduíches\n6 - Imprimir lista de bebidas\n7 - Imprimir lista de sobremesas\n8 - Imprimir lista de extras\n");
    printf("9 - Imprimir pedido\n10 - Imprimir lista de pedidos atendidos\n11 - Registrar novo pedido\n12 - Inclusão em lote\n0 - Sair do programa\n");
    printf("Opção: ");
    scanf("%d",&op);
    switch (op) {
        case 0:
            exit(0);
            break;
        case 1:
            cadastroSanduiche();
            break;
        case 2:
            cadastroBebida();
            break;
        case 3:
            cadastroSobremesa();
            break;
        case 4:
            cadastroExtra();
            break;
        case 5:
            printSanduiche();
            break;
        case 6:
            printBebida();
            break;
        case 7:
            printSobremesa();
            break;
        case 8:
            printExtra();
            break;
        case 9:
            printPedido();
            break;
        case 10:
            printPedidoAtendido();
            break;
        case 11:
            cadastroPedido();
            break;
        case 12:
            loadArquivo();
            break;
        default:
            printf("Opção inválida! Selecione uma opção válida.\n\n");
            menu();
            break;
    }
}

void cadastroSanduiche(){

}
void cadastroBebida(){

}
void cadastroSobremesa(){

}
void cadastroExtra(){

}
void printSanduiche(){

}
void printBebida(){

}
void printSobremesa(){

}
void printExtra(){

}
void printPedido(){

}
void printPedidoAtendido(){

}
void cadastroPedido(){

}

void loadArquivo(){
    FILE* fr;
    char path[50], pedline[MAX][MAX];
    printf("Nome do arquivo: ");
    scanf("%s", path);
    fr = fopen(path,"r");

    fclose(fr);
}