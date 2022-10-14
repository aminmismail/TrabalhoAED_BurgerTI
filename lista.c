#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include "burger.h"
#define MAX 500

void lwBin(){ //TODO
    FILE *frw;
    char path[50], pedline[MAX][MAX];
    do{
        printf("Nome do arquivo:");
        scanf("%s%*c", path);
        frw = fopen(path, "w+b");
    }
    while(loadFile(path, frw));
    printf("\n");
    fclose(frw);
}
