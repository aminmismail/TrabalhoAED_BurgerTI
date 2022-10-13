#include "burger.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 500

void menu(){
    int op;
    printf("1 - Cadastrar sanduiche\n2 - Cadastrar bebida\n3 - Cadastrar sobremesa\n4 - Cadastrar extra\n");
    printf("5 - Imprimir lista de sanduiches\n6 - Imprimir lista de bebidas\n7 - Imprimir lista de sobremesas\n8 - Imprimir lista de extras\n");
    printf("9 - Imprimir pedido\n10 - Imprimir lista de pedidos atendidos\n11 - Registrar novo pedido\n12 - Inclusao em lote\n0 - Sair do programa\n");
    printf("Opcao:");
    scanf("%d%*c",&op);
    while(op < 0 || op > 12){
        printf("Opcao invalida! Selecione uma opcao valida.\n\nOpcao:");
        scanf("%d",&op);
    }
    switch(op) {
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
            break;
    }
    menu();
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
    int i,n;
    char path[50], pedline[MAX][MAX];
    printf("Nome do arquivo:");
    scanf("%s%*c", path);
    fr = fopen(path,"r");
    while(fr == NULL){
        printf("Arquivo nao encontrado!\n");
        printf("Nome do arquivo:");
        scanf("%s%*c", path);
        fr = fopen(path,"r");
    }
    printf("Arquivo carregado!\n\n");
    for(i=n=0 ; fscanf(fr,"%[^\n]%*c",pedline[i]) != EOF ; i++);
    n = i;
    for(i=0; i<n ;i++) printf("%s\n",pedline[i]);

    fclose(fr);
}