#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "validacao.h"

void telaFuncionario(void){
    char esc;
    
    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                    SIG-GAMES | Menu Funcionario                   |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                     1. Adicionar Funcionario                      |  \n");
    printf("  |                     2. Pesquisar Funcionario                      |  \n");
    printf("  |                     3. Editar Funcionario                         |  \n");
    printf("  |                     4. Remover Funcionario                        |  \n");
    printf("  |                     0. Voltar                                     |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                     Digite a opcao desejada: ");
    scanf("%c", &esc);
    getchar();
    switch(esc){
        case '1':
            telaAdicionarFuncionario();
            break;
        case '2':
            telaPesquisarFuncionario();
            break;
        case '3':
            telaEditarFuncionario();
            break;
        case '4':
            telaRemoverFuncionario();
            break;
        case '0':
            break;
    }
}

void telaAdicionarFuncionario(void){
    char linha[256];
    int tam;
    char *nome, *cargo, *email, *endereco;

    int diaNasc;
    int mesNasc;
    int anoNasc;

    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar funcionario              |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        nome = (char *) malloc(tam+1);
        strcpy(nome, linha);
        getchar();
        printf("                     Cargo: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        cargo = (char *) malloc(tam+1);
        strcpy(cargo, linha);
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
        tam = strlen(linha);
        endereco = (char *) malloc(tam+1);
        strcpy(endereco, linha);
        getchar();
        printf("                     Email: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        email = (char *) malloc(tam+1);
        strcpy(email, linha);
        getchar();
        printf("                     CPF (Apenas numeros): ");
        scanf("%[0-9]", cpf);
        getchar();

        if(!checkData(anoNasc, mesNasc, diaNasc) || !checkCPF(cpf) || !checkEmail(email) || !checkNome(nome) || !checkEndereco(endereco)){
            if(!checkNome(nome)){
                printf("                       *Nome Invalido");
            }
            if(!checkEndereco(endereco)){
                printf("                       *Endereco Invalido");
            }
            if(!checkData(anoNasc, mesNasc, diaNasc)){
                printf("                       *Data Invalida.\n");
            }
            if(!checkCPF(cpf)){
                printf("                       *CPF Invalido.\n");
            }
            if (!checkEmail(email)){
                printf("                       *Email Invalido.\n");
            }
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Tentar novamente                            |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
            free(nome);
            free(cargo);
            free(email);
            free(endereco);
        } else{
            printf("                     Funcionario adicionado.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Cadastrar outro funcionario                 |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
            free(nome);
            free(cargo);
            free(email);
            free(endereco);
        }
       
    } while(esc != '0');
    telaFuncionario();
}

void telaPesquisarFuncionario(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                 SIG-GAMES | Pesquisar funcionario                 |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: \n");
        scanf("%c", cpf);
        getchar();
         if(!checkCPF(cpf)){
            printf("                       *CPF Invalido.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Tentar novamente                            |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        } else {
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                  1. Pesquisar outro funcionario                   |  \n");
            printf("  |                  0. Voltar                                        |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        }
    } while(esc != '0');
    telaFuncionario();
}

void telaEditarFuncionario(void){
    char cpf[12];
    char esc;
    
    do{ 
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                   SIG-GAMES | Editar funcionario                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: ");
        scanf("%[0-9.-]", cpf);
        getchar();
        if(!checkCPF(cpf)){
            printf("                       *CPF Invalido.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Tentar novamente                            |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        } else {
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Editar outro funcionario                    |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        }
    } while(esc != '0');

    telaFuncionario();
}

void telaRemoverFuncionario(void){
    char cpf[12];
    char esc;
    
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                  SIG-GAMES | Remover funcionario                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: ");
        scanf("%[0-9.-]", cpf);
        getchar();
        if(!checkCPF(cpf)){
            printf("                       *CPF Invalido.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Tentar novamente                            |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        } else {
            printf("                     Funcionario removido.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                   1. Remover outro funcionario                    |  \n");
            printf("  |                   0. Voltar                                       |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        }
    }while(esc != '0');
    telaFuncionario();
}
