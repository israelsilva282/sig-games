#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
#include "cliente.h"

typedef struct cliente Cliente;

struct cliente{
    char nome[255];
    char email[255];
    char endereco[255];
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char cpf[12];
    char status;
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
        printf("  |                        5. Listar Clientes                         |  \n");
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
        case '5':
            telaListarCliente();
            break;
        case '0':
            break;
    }
}

void telaAdicionarCliente(void){
    FILE* file;
    Cliente* cl;
    char esc;
    cl = (Cliente*) malloc(sizeof(Cliente));

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar Cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf(" %255[^\n]", cl->nome);
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
        scanf(" %255[^\n]", cl->endereco);
        getchar();
        printf("                     Email: ");
        scanf(" %255[^\n]", cl->email);
        getchar();
        printf("                     CPF (Apenas Numeros): ");
        scanf("%[0-9]", cl->cpf);
        getchar();
        cl->status = 'c';
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
            } while(!checkDigit(esc));

        } else {
            file = fopen("clientes.dat", "ab");
            if (file){
                fwrite(cl, sizeof(Cliente), 1, file);
                fclose(file);
            } else{
                printf("Ocorreu um erro com a criação do arquivo!");
                exit(1);
            }
            free(cl);
            
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
        } 
    } while(esc != '0');
}

void telaPesquisarCliente(void){
    FILE* file;
    Cliente* cl;
    char cpf[12];
    char esc;
    char situacao[20];
    cl = (Cliente*) malloc(sizeof(Cliente));
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
            file = fopen("clientes.dat", "rb");
            if (file == NULL){
                printf("Ocorreu um erro ao ler o arquivo!");
                exit(1);
            }
            while(!feof(file)){
                fread(cl, sizeof(Cliente), 1, file);
                if((strcmp(cl->cpf, cpf) == 0) && (cl->status != 'x')){
                    printf("CPF: %s\n", cl->cpf);
                    printf("Nome: %s\n", cl->nome);
                    printf("Data de nascimento: %d/%d/%d\n", cl->diaNasc, cl->mesNasc, cl->anoNasc);
                    printf("Endereco: %s\n", cl->endereco);
                    printf("Email: %s\n", cl->email);
                    if(cl->status == 'c'){
                        strcpy(situacao, "Cadastrado");
                    } else if (cl->status == 'x'){
                        strcpy(situacao, "Excluido");
                    } else {
                        strcpy(situacao, "Nao informado");
                    }
                    printf("Situacao: %s\n", situacao);
                    fclose(file);
                    break;
                }
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

}

void telaRemoverCliente(void){
    Cliente* cl;
    FILE* file;
    char cpf[12];
    char esc;
    cl = (Cliente*) malloc(sizeof(Cliente));

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Remover cliente                   |  \n");
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
            file = fopen("clientes.dat", "r+b");
            if (file == NULL){
                printf("Ocorreu um erro ao ler o arquivo!");
                exit(1);
            }
            while(!feof(file)){
                fread(cl, sizeof(Cliente), 1, file);
                if((strcmp(cl->cpf, cpf) == 0) && (cl->status != 'x')){
                    cl->status = 'x';
                    fseek(file,-1*sizeof(Cliente), SEEK_CUR);
                    fwrite(cl, sizeof(Cliente), 1, file);
                    printf("Cliente excluido!\n");
                    break;
                }
            }
            fclose(file);

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
}

void telaListarCliente(void){
    FILE* file;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    char situacao[30];
    char esc;
    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      SIG-GAMES | Listar clientes                  |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      1. Listar todos                              |  \n");
    printf("  |                      2. Listar cadastrados                        |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                     Digite a opcao desejada: ");
    scanf("%c",&esc);
    getchar();

    file = fopen("clientes.dat", "r+b");
    if(file == NULL){
        printf("Ocorreu um erro ao ler o arquivo!");
        exit(1);
    }

    if (esc == '1'){
        while(fread(cl, sizeof(Cliente), 1, file)){
            printf("---------------------------------------------------------------------  \n");
            printf("Nome: %s\n", cl->nome);
            printf("CPF: %s\n", cl->cpf);
            printf("Data de nascimento: %d/%d/%d\n", cl->diaNasc, cl->mesNasc, cl->anoNasc);
            printf("Endereco: %s\n", cl->endereco);
            printf("Email: %s\n", cl->email);
            if(cl->status == 'c'){
                strcpy(situacao, "Cadastrado");
            } else if (cl->status == 'x'){
                strcpy(situacao, "Excluido");
            }else {
                strcpy(situacao, "Nao informado");
            }
            printf("Situacao: %s\n", situacao);
        }
        printf("  ---------------------------------------------------------------------  \n");
        printf("                   Pressione enter para sair...                       |  \n");
        getchar();
    } else if (esc == '2'){
        while(fread(cl, sizeof(Cliente), 1, file)){
            if(cl->status != 'x'){
                printf("---------------------------------------------------------------------  \n");
                printf("Nome: %s\n", cl->nome);
                printf("CPF: %s\n", cl->cpf);
                printf("Data de nascimento: %d/%d/%d\n", cl->diaNasc, cl->mesNasc, cl->anoNasc);
                printf("Endereco: %s\n", cl->endereco);
                printf("Email: %s\n", cl->email);
                if(cl->status == 'c'){
                strcpy(situacao, "Cadastrado"); 
                }else {
                    strcpy(situacao, "Nao informado");
                }
                printf("Situacao: %s\n", situacao);
            }
        }
        printf("  ---------------------------------------------------------------------  \n");
        printf("                   Pressione enter para sair...                       |  \n");
        getchar();
    }
    fclose(file);
    // printf("  ---------------------------------------------------------------------  \n");
    // printf("  |                     Pressione enter para sair...                  |  \n");
    // printf("  ---------------------------------------------------------------------  \n");
    // getchar();
}


