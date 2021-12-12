#include <stdio.h>
#include <string.h>
#include "funcoes.h"
int procurarChar(char *str, char q){
    //Retorna o número de ocorrências de um char na string
    int achou;

    for (int i = 0; str[i]!='\0'; i++){
        if (str[i] == q){
            achou++;
        } 
    }

    return achou;
}
