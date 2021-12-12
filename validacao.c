#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include "validacao.h"
int checkBissexto(int ano){
    if ((ano % 4 == 0) && (ano % 100 != 0)){
        return 1;
    } else if (ano % 400 == 0){
        return 1;
    } else{
        return 0;
    }
}

int checkData(int ano, int mes, int dia){
    int maiorDia;
    if (ano > 0 && mes >= 1 && mes <= 12 && dia >= 1){
        if(mes == 2){
            if(checkBissexto(ano)){
                maiorDia = 29;
            } else{
                maiorDia = 28;
            }
        }else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
            maiorDia = 30;
        } else {
            maiorDia = 31;
        }
        if(dia >= 1 && dia <= maiorDia){
            return 1;
        } else{
            return 0;
        }
    } else{
        return 0;
    }
}

int checkCPF(char *cpf){
    if(strlen(cpf) == 11){
        return 1;
    } else{
        return 0;
    }
}

int checkEmail(char *email){
    int achou = procurarChar(email, '@');
    if (achou == 0 || achou > 1){
        return 0;
    } else {
        return 1;
    }
}
    


int checkNome(char *nome){
    int check = 0;
    for(int i = 0; nome[i]!='\0';i++){
        if ((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == ' '){
            ;
        } else {
            check++;
        }
    }

    if (check > 0){
        return 0;
    } else{
        return 1;
    }

}

int checkEndereco(char *endereco){
    if (strlen(endereco) <= 256){
        return 1;
    } else {
        return 0;
    }
}

int checkResumo(char *resumo){
    if (strlen(resumo) <= 256){
        return 1;
    } else {
        return 0;
    }
}


int checkDigit(char num){
    if (num >= '0' && num <= '9'){
        return 1;
    } else {
        return 0;
    }
}