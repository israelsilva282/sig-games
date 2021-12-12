#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
#include "cliente.h"


void telaCliente(void){
    char esc;
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      SIG-GAMES | Menu Cliente                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                        1. Adicionar Cliente                       |  \n");
        printf("  |                        2. Pesquisar cliente                       |  \n");
        printf("  |                        3. Editar Cliente                          |  \n");
        printf("  |                        4. Remover Cliente                         |  \n");
        printf("  |                        0. Voltar                                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                           Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(!checkDigit(esc));
    
    switch (esc){
        case '1':
            telaAdicionarCliente();
            break;
        case '2':
            telaPesquisarCliente();
            break;
        case '3':
            telaEditarCliente();
            break;
        case '4':
            telaRemoverCliente();
            break;
        case '0':
            break;
    }
}

void telaAdicionarCliente(void){
    char linha[256];
    int tam;
    char *nome, *email, *endereco;
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar Cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf(" %255[^\n]", linha);
        tam =  strlen(linha);
        nome = (char*) malloc(tam+1);
        strcpy(nome, linha);
        getchar();
        printf("                     Dia de nascimento: ");
        scanf("%d", &diaNasc);
        getchar();
        printf("                     Mes de nascimento: ");
        scanf("%d", &mesNasc);
        getchar();
        printf("                     Ano de nascimento: ");
        scanf("%d", &anoNasc);
        getchar();
        printf("                     Endereco: ");
        scanf(" %255[^\n]", linha);
        tam =  strlen(linha);
        endereco = (char *) malloc(tam+1);
        strcpy(endereco, linha);
        getchar();
        printf("                     Email: ");
        scanf(" %255[^\n]", linha);
        tam =  strlen(linha);
        email = (char *) malloc(tam+1);
        strcpy(email, linha);
        getchar();
        printf("                     CPF (Apenas Numeros): ");
        scanf("%[0-9]", cpf);
        getchar();
        if(!checkData(anoNasc, mesNasc, diaNasc) || !checkCPF(cpf) || !checkEmail(email) || !checkNome(nome) || !checkEndereco(endereco)){
            if(!checkNome(nome)){
                printf("                       *Nome Invalido\n");
            }
            if(!checkEndereco(endereco)){
                printf("                       *Endereco Invalido\n");
            }
            if(!checkData(anoNasc, mesNasc, diaNasc)){
                printf("                       *Data Invalida.\n");
            }
            if (!checkEmail(email)){
                printf("                       *Email Invalido.\n");
            }
            if(!checkCPF(cpf)){
                printf("                       *CPF Invalido.\n");
            }
            do{
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
            
            free(nome);
            free(email);
            free(endereco);
        } else {
            do{
                printf("                     Cliente cadastrado.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Cadastrar outro cliente                     |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
            
            free(nome);
            free(email);
            free(endereco);
        } 
       
    } while(esc != '0');
    telaCliente();
}

void telaPesquisarCliente(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Pesquisar cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente: ");
        scanf("%[0-9.-]", cpf);
        getchar();

        if(!checkCPF(cpf)){
            do{
                printf("                       *CPF Invalido.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
            
        } else {
            do{
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                     1. Pesquisar outro cliente                    |  \n");
                printf("  |                     0. Voltar                                     |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
            
        }
    } while(esc != '0');
    telaCliente();   
}

void telaEditarCliente(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Editar cliente                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente : ");
        scanf("%[0-9.-]", cpf);
        getchar();
         if(!checkCPF(cpf)){
            do{
                printf("                       *CPF Invalido.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
           
        } else { 
            do{
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                      1. Editar outro cliente                      |  \n");
                printf("  |                      0. Voltar                                    |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
            
        }
    } while(esc != '0');

    telaCliente();
}

void telaRemoverCliente(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Remover cliente                   |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente: ");
        scanf("%[0-9.-]", cpf);
        getchar();
        printf("                     Cliente removido.");
         if(!checkCPF(cpf)){
            do{
                printf("                       *CPF Invalido.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
           
        } else {
            do{
                 printf("  ---------------------------------------------------------------------  \n");
                printf("  |                       1. Remover outro cliente                    |  \n");
                printf("  |                       0. Voltar                                   |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
           
        }
    } while(esc != '0');
    telaCliente();
}

