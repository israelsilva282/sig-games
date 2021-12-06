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
    int tam = strlen(email);
    if (tam <= 200){
        if (achou == 0 || achou > 1){
            return 0;
        } else {
            return 1;
        }
    } else{
        return 0;
    }
    
}

int checkNome(char *nome){
    if (strlen(nome) <= 255){
        return 1;
    } else {
        return 0;
    }
}

int checkEndereco(char *endereco){
    if (strlen(endereco) <= 255){
        return 1;
    } else {
        return 0;
    }
}

int checkResumo(char *resumo){
    if (strlen(resumo) <= 2048){
        return 1;
    } else {
        return 0;
    }
}