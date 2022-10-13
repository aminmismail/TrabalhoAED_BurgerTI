#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 500

void lwBin(){
    FILE* fwr;
    int i,n;
    char path[50], pedline[MAX][MAX];
    printf("Nome do arquivo:");
    scanf("%s%*c", path);
    fwr = fopen(path,"r");
    while(fwr == NULL){
        printf("Arquivo nao encontrado!\n");
        printf("Nome do arquivo:");
        scanf("%s%*c", path);
        fwr = fopen(path,"r");
    }
    printf("Arquivo carregado!\n\n");
    for(i=n=0 ; fscanf(fwr,"%[^\n]%*c",pedline[i]) != EOF ; i++);
    n = i;
    for(i=0; i<n ;i++) printf("%s\n",pedline[i]);

    fclose(fwr);
}
