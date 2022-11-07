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
    sanduiche* sand = malloc(sizeof(sanduiche));
    printf("Código: "); scanf("%d%*c", &sand->id);
    printf("Nome: "); scanf("%[^\n]%*c", sand->nome);
    printf("Descricao: "); scanf("%[^\n]%*c", sand->desc);
    printf("Disponibilidade: "); scanf("%s", sand->disp);
    printf("Preco (Tam. P): "); scanf("%f", &sand->preco[0]);
    printf("Preco (Tam. M): "); scanf("%f", &sand->preco[1]);
    printf("Preco (Tam. G): "); scanf("%f%*c", &sand->preco[2]);
    gravaSand(sand);
    free(sand);

}

void gravaSand(sanduiche *sand) {
    FILE* fw;
    fw = openBin("../sanduiche.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(sand,sizeof(sanduiche),1,fw);
    fclose(fw);

}

void cadastroBebida(){
    bebida* beb = malloc(sizeof(bebida));
    printf("Código: "); scanf("%d%*c", &beb->id);
    printf("Nome: "); scanf("%[^\n]%*c", beb->nome);
    printf("Disponibilidade: "); scanf("%s", beb->disp);
    printf("Preco (Tam. P): "); scanf("%f", &beb->preco[0]);
    printf("Preco (Tam. M): "); scanf("%f", &beb->preco[1]);
    printf("Preco (Tam. G): "); scanf("%f%*c", &beb->preco[2]);
    gravaBebida(beb);
    free(beb);
}

void gravaBebida(bebida *beb) {
    FILE* fw;
    fw = openBin("../bebida.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(beb,sizeof(bebida),1,fw);
    fclose(fw);

}

void cadastroSobremesa(){
    sobremesa* sob = malloc(sizeof(sobremesa));
    printf("Código: "); scanf("%d%*c", &sob->id);
    printf("Nome: "); scanf("%[^\n]%*c", sob->nome);
    printf("Disponibilidade: "); scanf("%s", sob->disp);
    printf("Preco: "); scanf("%f", &sob->preco);
    gravaSobremesa(sob);
    free(sob);
}

void gravaSobremesa(sobremesa *sob) {
    FILE* fw;
    fw = openBin("../sobremesa.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(sob,sizeof(sobremesa),1,fw);
    fclose(fw);

}

void cadastroExtra(){
    extra* ex = malloc(sizeof(extra));
    printf("Código: "); scanf("%d%*c", &ex->id);
    printf("Nome: "); scanf("%[^\n]%*c", ex->nome);
    printf("Disponibilidade: "); scanf("%s", ex->disp);
    printf("Preco: "); scanf("%f", &ex->preco);
    gravaExtra(ex);
    free(ex);
}

void gravaExtra(extra *ex) {
    FILE* fw;
    fw = openBin("../extra.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(ex,sizeof(extra),1,fw);
    fclose(fw);

}

void printSanduiche(){
    FILE* fw;
    sanduiche* sand = malloc(sizeof(sanduiche));
    fw = openBin("../sanduiche.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(sand,sizeof(sanduiche),1,fw) != 0) {
        printf("Código: %d\n", sand->id);
        printf("Nome: %s\n", sand->nome);
        printf("Descricao: %s\n", sand->desc);
        printf("Disponibilidade: %s\n", sand->disp);
        printf("Preco (Tam. P): %.2f\n", sand->preco[0]);
        printf("Preco (Tam. M): %.2f\n", sand->preco[1]);
        printf("Preco (Tam. G): %.2f\n\n", sand->preco[2]);
    }
    free(sand);
    fclose(fw);
}

void printBebida(){
    FILE* fw;
    bebida* beb = malloc(sizeof(bebida));
    fw = openBin("../bebida.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(beb,sizeof(bebida),1,fw) != 0) {
        printf("Código: %d\n", beb->id);
        printf("Nome: %s\n", beb->nome);
        printf("Disponibilidade: %s\n", beb->disp);
        printf("Preco (Tam. P): %.2f\n", beb->preco[0]);
        printf("Preco (Tam. M): %.2f\n", beb->preco[1]);
        printf("Preco (Tam. G): %.2f\n\n", beb->preco[2]);
    }
    free(beb);
    fclose(fw);
}

void printSobremesa(){
    FILE* fw;
    sobremesa* sob = malloc(sizeof(sobremesa));
    fw = openBin("../sobremesa.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(sob,sizeof(sobremesa),1,fw) != 0) {
        printf("Código: %d\n", sob->id);
        printf("Nome: %s\n", sob->nome);
        printf("Disponibilidade: %s\n", sob->disp);
        printf("Preco: %.2f\n", sob->preco);
    }
    free(sob);
    fclose(fw);
}

void printExtra(){
    FILE* fw;
    extra* ex = malloc(sizeof(extra));
    fw = openBin("../extra.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(ex,sizeof(extra),1,fw) != 0) {
        printf("Código: %d\n", ex->id);
        printf("Nome: %s\n", ex->nome);
        printf("Disponibilidade: %s\n", ex->disp);
        printf("Preco: %.2f\n", ex->preco);
    }
    free(ex);
    fclose(fw);
}
//---------------//
void printPedido(){

}
void printPedidoAtendido(){

}
void cadastroPedido(){

}
//---------------//
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