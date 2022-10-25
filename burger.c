#include "burger.h"
#include "lista.h"
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
            loadPath();
            break;
        default:
            break;
    }
    menu();
}

void cadastroSanduiche(){
    sanduiche* sand;
    printf("Código: "); scanf("%d%*c", &sand->id);
    printf("Nome: "); scanf("%[^\n]%*c", sand->nome);
    printf("Descricao: "); scanf("%[^\n]%*c", sand->desc);
    printf("Disponibilidade: "); scanf("%s%*c", sand->disp);
    printf("Preco (P): "); scanf("%f%*c", &sand->preco[0]);
    printf("Preco (M): "); scanf("%f%*c", &sand->preco[1]);
    printf("Preco (G): "); scanf("%f%*c", &sand->preco[2]);
    gravaSand(sand);

}

void gravaSand(sanduiche *sand) {
    FILE* fw;
    fw = openBin("../sanduiche.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(sand,sizeof(sanduiche),1,fw);
    fclose(fw);
    //CONTINUAR
}

void cadastroBebida(){

}
void cadastroSobremesa(){

}
void cadastroExtra(){

}
void printSanduiche(){
    FILE* fw;
    char lsand[2][300];
    fw = openBin("../sanduiche.bin");
    fseek(fw, 0, SEEK_SET);
    fread(lsand,sizeof(sanduiche),1,fw);
    fclose(fw);
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

void loadPath(){ //Le o caminho do arquivo, juntamente com o conteudo do arquivo
    int i,n;
    FILE *fr;
    char path[50], pedline[MAX][MAX];
    do{
        printf("Nome do arquivo:");
        scanf("%s%*c", path);
        fr = fopen(path, "r");
    }
    while(loadFile(path, fr));
    for(i=n=0 ; fscanf(fr,"%[^\n]%*c",pedline[i]) != EOF ; i++);
    n = i;
    for(i=0; i<n ;i++) printf("%s\n",pedline[i]);
    printf("\n");
    fclose(fr);
}

int loadFile(char* path, FILE* file){
    if(file == NULL){
        printf("Falha ao ler arquivo!\n");
        return 1;
    }
    else{
        printf("Arquivo lido com sucesso!\n");
        return 0;
    }
}