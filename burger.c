#include "burger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Mostra o menu de opcoes
//Pre-condicao: Nenhuma
//Pos-condicao: Executa a funcao desejada
void menu(){
    int op;
    printf("1 - Cadastrar sanduiche\n2 - Cadastrar bebida\n3 - Cadastrar sobremesa\n4 - Cadastrar extra\n");
    printf("5 - Imprimir lista de sanduiches\n6 - Imprimir lista de bebidas\n7 - Imprimir lista de sobremesas\n8 - Imprimir lista de extras\n");
    printf("9 - Imprimir pedidos\n10 - Imprimir pedidos atendidos (-)\n11 - Cadastrar um pedido\n12 - Inclusao em lote\n13 - Atender pedido (-)\n");
    printf("0 - Sair do programa\n");
    printf("Opcao:");
    scanf("%d",&op);
    while(op < 0 || op > 13){
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
            printPedidos();
            break;
        case 10:
            printAtendido();
            break;
        case 11:
            cadastroPedido();
            break;
        case 12:
            loadPath();
            break;
        case 13:
            atendePedido();
            break;
        default:
            break;
    }
    menu();
}

//Abre um arquivo binario
//Pre-condicao: Um caminho para um arquivo existente
//Pos-condicao: Retorna o ponteiro para o arquivo binario
FILE* openBin(char* path){
    FILE *fwr;
    do{
        fwr = fopen(path, "a+b");
    }
    while(loadFile(path, fwr));
    return fwr;
}

//Cria uma lista nova em arquivo
//Pre-condicao: arquivo aberto para leitura/escrita
//Pos-condicao: arquivo inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = 1;
    cab->pos_topo = 1;
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

//Le o caminho do arquivo passado por input, e cadastra os itens nele
//Pre-condicao: Um caminho para um arquivo existente
//Pos-condicao: Registro dos itens nos arquivos binarios
void loadPath(){
    FILE *fr;
    char path[50];
    do{
        printf("Nome do arquivo:");
        scanf("%s%*c", path);
        fr = fopen(path, "r");
    }
    while(loadFile(path, fr));
    cleanRegister(fr);
    printf("\n");
    fclose(fr);
}

//Cadastra os itens descritos no arquivo passado
//Pre-condicao: Um caminho para um arquivo existente
//Pos-condicao: Registro dos itens nos arquivos binarios
void cleanRegister(FILE *fr){
    char text[200], *aux, *p;
    int i;
    while(fscanf(fr,"%[^\n]%*c", text) != EOF){
        char* token = strtok(text,";"); //pega o tipo
        if(strcmp(token,"SD") == 0){
            sanduiche* sand = malloc(sizeof(sanduiche));
            sand->id = atoi(strtok(NULL,";"));
            strcpy(sand->nome,strtok(NULL,";"));
            strcpy(sand->desc,strtok(NULL,";"));
            strcpy(sand->disp,strtok(NULL,";"));
            for(i=0;i < 3;i++){
                for(p = aux = strtok(NULL,";");*aux != 0; aux++) if(*aux == ',') *aux = '.';
                sand->preco[i] = atof(p);
            }
            gravaSanduiche(sand);
            free(sand);
        }
        else if(strcmp(token,"BB") == 0){
            bebida* beb = malloc(sizeof(bebida));
            beb->id = atoi(strtok(NULL,";"));
            strcpy(beb->nome,strtok(NULL,";"));
            strcpy(beb->disp,strtok(NULL,";"));
            for(i=0;i < 3;i++){
                for(p = aux = strtok(NULL,";");*aux != 0; aux++) if(*aux == ',') *aux = '.';
                beb->preco[i] = atof(p);
            }
            gravaBebida(beb);
            free(beb);
        }
        else if(strcmp(token,"EX") == 0){
            extra* ex = malloc(sizeof(extra));
            ex->id = atoi(strtok(NULL,";"));
            strcpy(ex->nome,strtok(NULL,";"));
            strcpy(ex->disp,strtok(NULL,";"));
            for(p = aux = strtok(NULL,";");*aux != 0; aux++) if(*aux == ',') *aux = '.';
            ex->preco = atof(p);
            gravaExtra(ex);
            free(ex);
        }
        else if(strcmp(token,"SM") == 0){
            sobremesa* sob = malloc(sizeof(sobremesa));
            sob->id = atoi(strtok(NULL,";"));
            strcpy(sob->nome,strtok(NULL,";"));
            strcpy(sob->disp,strtok(NULL,";"));
            for(p = aux = strtok(NULL,";");*aux != 0; aux++) if(*aux == ',') *aux = '.';
            sob->preco = atof(p);
            gravaSobremesa(sob);
            free(sob);
        }
    }
}

//Verifica se o arquivo existe
//Pre-condicao: Um caminho para um arquivo
//Pos-condicao: Retorna se o arquivo e valido ou nao
int loadFile(char* path, FILE* file){
    if(file == NULL){
        printf("Falha ao ler arquivo!\n\n");
        return 1;
    }
    else return 0;
}

//Escreve no arquivo o cabecalho contendo as informacoes da lista
//Pre-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pos-condicao: cabecalho escrito no arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET); //posiciona no inıcio do arquivo
    fwrite(cab,sizeof(cabecalho),1,arq);
}

//Realiza o cadastro das informacoes de um sanduiche em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de sanduiche com as informacoes completas
void cadastroSanduiche(){
    sanduiche* sand = malloc(sizeof(sanduiche));
    printf("Codigo: "); scanf("%d%*c", &sand->id);
    printf("Nome: "); scanf("%[^\n]%*c", sand->nome);
    printf("Descricao: "); scanf("%[^\n]%*c", sand->desc);
    printf("Disponibilidade: "); scanf("%s", sand->disp);
    printf("Preco (Tam. P): "); scanf("%f", &sand->preco[0]);
    printf("Preco (Tam. M): "); scanf("%f", &sand->preco[1]);
    printf("Preco (Tam. G): "); scanf("%f%*c", &sand->preco[2]);
    gravaSanduiche(sand);
    free(sand);

}

//Realiza o cadastro das informacoes da estrutura de um sanduiche no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Sanduiche cadastrado no arquivo
void gravaSanduiche(sanduiche *sand) {
    FILE* fw;
    fw = openBin("../sanduiche.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(sand,sizeof(sanduiche),1,fw);
    fclose(fw);

}

//Realiza o cadastro das informacoes de uma bebida em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de bebida com as informacoes completas
void cadastroBebida(){
    bebida* beb = malloc(sizeof(bebida));
    printf("Codigo: "); scanf("%d%*c", &beb->id);
    printf("Nome: "); scanf("%[^\n]%*c", beb->nome);
    printf("Disponibilidade: "); scanf("%s", beb->disp);
    printf("Preco (Tam. P): "); scanf("%f", &beb->preco[0]);
    printf("Preco (Tam. M): "); scanf("%f", &beb->preco[1]);
    printf("Preco (Tam. G): "); scanf("%f%*c", &beb->preco[2]);
    gravaBebida(beb);
    free(beb);
}

//Realiza o cadastro das informacoes da estrutura de uma bebida no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Bebida cadastrada no arquivo
void gravaBebida(bebida *beb) {
    FILE* fw;
    fw = openBin("../bebida.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(beb,sizeof(bebida),1,fw);
    fclose(fw);

}

//Realiza o cadastro das informacoes de uma sobremesa em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de sobremesa com as informacoes completas
void cadastroSobremesa(){
    sobremesa* sob = malloc(sizeof(sobremesa));
    printf("Codigo: "); scanf("%d%*c", &sob->id);
    printf("Nome: "); scanf("%[^\n]%*c", sob->nome);
    printf("Disponibilidade: "); scanf("%s", sob->disp);
    printf("Preco: "); scanf("%f", &sob->preco);
    gravaSobremesa(sob);
    free(sob);
}

//Realiza o cadastro das informacoes da estrutura de uma sobremesa no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Sobremesa cadastrada no arquivo
void gravaSobremesa(sobremesa *sob) {
    FILE* fw;
    fw = openBin("../sobremesa.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(sob,sizeof(sobremesa),1,fw);
    fclose(fw);

}

//Realiza o cadastro das informacoes de um extra em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de um extra com as informacoes completas
void cadastroExtra(){
    extra* ex = malloc(sizeof(extra));
    printf("Codigo: "); scanf("%d%*c", &ex->id);
    printf("Nome: "); scanf("%[^\n]%*c", ex->nome);
    printf("Disponibilidade: "); scanf("%s", ex->disp);
    printf("Preco: "); scanf("%f", &ex->preco);
    gravaExtra(ex);
    free(ex);
}

//Realiza o cadastro das informacoes da estrutura de um extra no arquivo
//Pre-condicao: Arquivo binario valido
//Pos-condicao: Extra cadastrado no arquivo
void gravaExtra(extra *ex) {
    FILE* fw;
    fw = openBin("../extra.bin");
    fseek(fw, 0, SEEK_SET);
    fwrite(ex,sizeof(extra),1,fw);
    fclose(fw);

}

//Mostra as informacoes na tela de todos os sanduiches cadastrados
//Pre-condicao: Arquivo binario com sanduiches cadastrados
//Pos-condicao: Todos os sanduiches cadastrados mostrados na tela
void printSanduiche(){
    FILE* fw;
    sanduiche* sand = malloc(sizeof(sanduiche));
    fw = openBin("../sanduiche.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(sand,sizeof(sanduiche),1,fw) != 0) {
        printf("Codigo: %d\n", sand->id);
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

//Mostra as informacoes na tela de todos as bebidas cadastrados
//Pre-condicao: Arquivo binario com bebidas cadastradas
//Pos-condicao: Todos as bebidas cadastradas mostrados na tela
void printBebida(){
    FILE* fw;
    bebida* beb = malloc(sizeof(bebida));
    fw = openBin("../bebida.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(beb,sizeof(bebida),1,fw) != 0) {
        printf("Codigo: %d\n", beb->id);
        printf("Nome: %s\n", beb->nome);
        printf("Disponibilidade: %s\n", beb->disp);
        printf("Preco (Tam. P): %.2f\n", beb->preco[0]);
        printf("Preco (Tam. M): %.2f\n", beb->preco[1]);
        printf("Preco (Tam. G): %.2f\n\n", beb->preco[2]);
    }
    free(beb);
    fclose(fw);
}

//Mostra as informacoes na tela de todos as sobremesas cadastrados
//Pre-condicao: Arquivo binario com sobremesas cadastradas
//Pos-condicao: Todos as sobremesas cadastradas mostrados na tela
void printSobremesa(){
    FILE* fw;
    sobremesa* sob = malloc(sizeof(sobremesa));
    fw = openBin("../sobremesa.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(sob,sizeof(sobremesa),1,fw) != 0) {
        printf("Codigo: %d\n", sob->id);
        printf("Nome: %s\n", sob->nome);
        printf("Disponibilidade: %s\n", sob->disp);
        printf("Preco: %.2f\n\n", sob->preco);
    }
    free(sob);
    fclose(fw);
}

//Mostra as informacoes na tela de todos os extras cadastrados
//Pre-condicao: Arquivo binario com extras cadastrados
//Pos-condicao: Todos os extras cadastrados mostrados na tela
void printExtra(){
    FILE* fw;
    extra* ex = malloc(sizeof(extra));
    fw = openBin("../extra.bin");
    fseek(fw, 0, SEEK_SET);
    while(fread(ex,sizeof(extra),1,fw) != 0) {
        printf("Codigo: %d\n", ex->id);
        printf("Nome: %s\n", ex->nome);
        printf("Disponibilidade: %s\n", ex->disp);
        printf("Preco: %.2f\n\n", ex->preco);
    }
    free(ex);
    fclose(fw);
}

//Realiza o cadastro das informacoes de um pedido em sua estrutura
//Pre-condicao: Nenhuma
//Pos-condicao: Estrutura de pedido com as informacoes completas
void cadastroPedido() {
    FILE *fw;
    cabecalho *cab;
    pedido *ped = (pedido *) malloc(sizeof(pedido));
    fw = openBin("../pedidos.bin");
    printf("CPF: "); scanf("%lld%*c", &ped->cpf);
    printf("(SD - Sanduiche) (BB - Bebida) (EX - Extra) (SM - Sobremesa)\n");
    printf("Formato do pedido: (SD,ID,QUANTIDADE,TAMANHO) (BB,ID,QUANTIDADE,TAMANHO) (EX,ID,QUANTIDADE) (SM,ID,QUANTIDADE)\n");
    printf("Exemplo de pedido: (SD,1,2,M);(BB,2,3,M);(SM,2,2)\n");
    scanf("%[^\n]%*c", ped->itens);
    cab = le_cabecalho(fw);
    if(cab->pos_livre != -1) {
        cria_lista_vazia(fw);
        cab = le_cabecalho(fw);
    }
    escreve_cabecalho(fw,cab);
    ped->id = cab->pos_topo;
    cab->pos_topo++;
    ped->prox = cab->pos_topo;
    ped->total = 0; //getTotalPedido(ped);
    gravaPedido(fw, ped);
    escreve_cabecalho(fw,cab);
    free(cab);
    free(ped);
    fclose(fw);
}

//Realiza o cadastro das informacoes da estrutura de um pedido no arquivo
//Pre-condicao: Estrutura de um pedido e arquivo binario valido
//Pos-condicao: Pedido cadastrado no arquivo
void gravaPedido(FILE *fw, pedido *ped){
    fseek(fw,sizeof(cabecalho) + (sizeof(pedido) * (ped->id - 1)), SEEK_SET);
    fwrite(ped, sizeof(pedido), 1, fw);
}

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
void atendePedido(){
    /*cabecalho *cab;
    FILE *fw;
    fw = openBin("../pedidos.bin");
    cab = le_cabecalho(fw);
    cab->pos_cabeca++;
    fseek(fw,sizeof(cabecalho) + (sizeof(pedido) * (cab->pos_cabeca)),SEEK_SET);
    fwrite('\0',sizeof(pedido),1,fw);
    free(cab);
    fclose(fw);*/
}

//Mostra todos os pedidos cadastrados
//Pre-condicao: Arquivo binario com pedidos cadastrados
//Pos-condicao: Todos os pedidos cadastrados mostrados na tela
void printPedidos(){
    FILE *fw;
    pedido *ped = (pedido *) malloc(sizeof(pedido));
    fw = openBin("../pedidos.bin");
    fseek(fw,sizeof(cabecalho),SEEK_SET);
    while(fread(ped,sizeof(pedido),1,fw) != 0) {
        printf("ID: %d\n", ped->id);
        printf("CPF: %lld\n", ped->cpf);
        printf("Itens: %s\n", ped->itens);
        printf("Total: %.2f\n", ped->total);
        printf("Proximo pedido: %d\n\n", ped->prox);
    }
    free(ped);
    fclose(fw);
}

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
void printAtendido(){

}

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
float getTotalPedido(pedido* ped){
    /*float tot;
    char* token = strtok(ped->itens,";"); //pega o tipo
    if(strcmp(token,"SD") == 0){
        sanduiche* sand = malloc(sizeof(sanduiche));
        sand->id = atoi(strtok(NULL,";"));
        strcpy(sand->nome,strtok(NULL,";"));
        strcpy(sand->desc,strtok(NULL,";"));
        strcpy(sand->disp,strtok(NULL,";"));
        free(sand);
    }
    else if(strcmp(token,"BB") == 0){
        bebida* beb = malloc(sizeof(bebida));
        beb->id = atoi(strtok(NULL,";"));
        strcpy(beb->nome,strtok(NULL,";"));
        strcpy(beb->disp,strtok(NULL,";"));
        free(beb);
    }
    else if(strcmp(token,"EX") == 0){
        extra* ex = malloc(sizeof(extra));
        ex->id = atoi(strtok(NULL,";"));
        strcpy(ex->nome,strtok(NULL,";"));
        strcpy(ex->disp,strtok(NULL,";"));
        for(p = aux = strtok(NULL,";");*aux != 0; aux++) if(*aux == ',') *aux = '.';
        free(ex);
    }
    else if(strcmp(token,"SM") == 0){
        sobremesa* sob = malloc(sizeof(sobremesa));
        sob->id = atoi(strtok(NULL,";"));
        strcpy(sob->nome,strtok(NULL,";"));
        strcpy(sob->disp,strtok(NULL,";"));
        for(p = aux = strtok(NULL,";");*aux != 0; aux++) if(*aux == ',') *aux = '.';
        free(sob);
    }*/
}

//NAO IMPLEMENTADA
//Pre-condicao:
//Pos-condicao:
void cancelaPedido(){
    //pede o cpf
    //imprime os pedidos do cpf
    //pede o id do pedido pra retirar
    //atualiza o cabecalho
}