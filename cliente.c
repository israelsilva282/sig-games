#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
#include "cliente.h"

typedef struct cliente Cliente;

struct cliente{
    char *nome, *email, *endereco;
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char cpf[12];
};


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
    FILE* file;
    Cliente* cl;
    char esc;
    char linha[256];
    int tam;
    cl = (Cliente*) malloc(sizeof(Cliente));

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar Cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf(" %255[^\n]", linha);
        tam =  strlen(linha);
        cl->nome = (char *) malloc(tam+1);
        strcpy(cl->nome, linha);
        getchar();
        printf("                     Dia de nascimento: ");
        scanf("%d", &cl->diaNasc);
        getchar();
        printf("                     Mes de nascimento: ");
        scanf("%d", &cl->mesNasc);
        getchar();
        printf("                     Ano de nascimento: ");
        scanf("%d", &cl->anoNasc);
        getchar();
        printf("                     Endereco: ");
        scanf(" %255[^\n]", linha);
        tam =  strlen(linha);
        cl->endereco = (char *) malloc(tam+1);
        strcpy(cl->endereco, linha);
        getchar();
        printf("                     Email: ");
        scanf(" %255[^\n]", linha);
        tam =  strlen(linha);
        cl->email = (char *) malloc(tam+1);
        strcpy(cl->email, linha);
        getchar();
        printf("                     CPF (Apenas Numeros): ");
        scanf("%[0-9]", cl->cpf);
        getchar();
        if(!checkData(cl->anoNasc, cl->mesNasc, cl->diaNasc) || !checkCPF(cl->cpf) || !checkEmail(cl->email) || !checkNome(cl->nome) || !checkEndereco(cl->endereco)){
            if(!checkNome(cl->nome)){
                printf("                       *Nome Invalido\n");
            }
            if(!checkEndereco(cl->endereco)){
                printf("                       *Endereco Invalido\n");
            }
            if(!checkData(cl->anoNasc, cl->mesNasc, cl->diaNasc)){
                printf("                       *Data Invalida.\n");
            }
            if (!checkEmail(cl->email)){
                printf("                       *Email Invalido.\n");
            }
            if(!checkCPF(cl->cpf)){
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
                free(cl->nome);
                free(cl->endereco);
                free(cl->email);
            } while(!checkDigit(esc));

        } else {
            file = fopen("clientes.txt", "at");
            if (file){
                fprintf(file,"%s\n",cl->cpf);
                fprintf(file,"%s\n",cl->nome);
                fprintf(file,"%s\n",cl->email);
                fprintf(file,"%s\n",cl->endereco);
                fprintf(file, "%d\n", cl->diaNasc);
                fprintf(file, "%d\n", cl->mesNasc);
                fprintf(file, "%d\n", cl->anoNasc); 
                fclose(file);
            } else{
                printf("Ocorreu um erro com a criação do arquivo!");
                exit(1);
            }

            
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
            free(cl->nome);
            free(cl->endereco);
            free(cl->email);
        } 
    } while(esc != '0');
    telaCliente();
}

void telaPesquisarCliente(void){
    FILE* file;
    char linha[255];
    char cpf[12];
    char esc;
    int achou;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Pesquisar cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente: ");
        scanf("%[0-9]", cpf);
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
            file = fopen("clientes.txt", "rt");
            if (file == NULL){
                printf("Ocorreu um erro ao ler o arquivo!");
                exit(1);
            }
            achou = 0;
            while(fscanf(file, "%[^\n]", linha) == 1 && achou != 1){
                if (strcmp(cpf, linha) == 0){
                    achou = 1;
                    for(int i = 0; i <= 7; i++){
                        printf("%s\n", linha);
                        fgets(linha, 255, file);
                        
                    }
                }
                fgetc(file);
            }
            fclose(file);
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

