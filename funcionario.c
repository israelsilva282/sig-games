#include <stdio.h>
#include <stdlib.h>
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
    char nome[100];
    char cargo[34];
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char email[100];
    char cpf[12];
    char endereco[100];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar funcionario              |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
        getchar();
        printf("                     Cargo: ");
        scanf("%[A-Z a-z]", cargo);
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
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâêôãõ0-9./-]", endereco);
        getchar();
        printf("                     Email: ");
        scanf("%[A-Za-z@._]", email);
        getchar();
        printf("                     CPF (Apenas numeros): ");
        scanf("%[0-9]", cpf);
        getchar();

        if(!checkData(anoNasc, mesNasc, diaNasc) || !checkCPF(cpf)){
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
        } else{
            printf("                     Funcionario adicionado.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Cadastrar outro funcionario                 |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
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

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                  1. Pesquisar outro funcionario                   |  \n");
        printf("  |                  0. Voltar                                        |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    1. Editar outro funcionario                    |  \n");
        printf("  |                    0. Voltar                                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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
        printf("                     Funcionario removido.\n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                   1. Remover outro funcionario                    |  \n");
        printf("  |                   0. Voltar                                       |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    }while(esc != '0');
    telaFuncionario();
}
