#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "validacao.h"

typedef struct funcionario Funcionario;

struct funcionario{
    char nome[255];
    char cargo[20];
    char email[255];
    char endereco[255];
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char cpf[12];
    char status;
};

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
    FILE* file;
    Funcionario* fun;
    char esc;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar funcionario              |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf(" %255[^\n]", fun->nome);
        getchar();
        printf("                     Cargo: ");
        scanf(" %20[^\n]", fun->cargo);
        getchar();
        printf("                     Dia de nascimento: ");
        scanf("%d", &fun->diaNasc);
        getchar();
        printf("                     Mes de nascimento: ");
        scanf("%d", &fun->mesNasc);
        getchar();
        printf("                     Ano de nascimento: ");
        scanf("%d", &fun->anoNasc);
        getchar();
        printf("                     Endereco: ");
        scanf(" %255[^\n]", fun->endereco);
        getchar();
        printf("                     Email: ");
        scanf(" %255[^\n]", fun->email);
        getchar();
        printf("                     CPF (Apenas numeros): ");
        scanf("%[0-9]", fun->cpf);
        getchar();
        fun->status = 'c';

        if(!checkData(fun->anoNasc, fun->mesNasc, fun->diaNasc) || !checkCPF(fun->cpf) || !checkEmail(fun->email) || !checkNome(fun->nome) || !checkEndereco(fun->endereco) || !checkCargo(fun->cargo)){
            if(!checkNome(fun->nome)){
                printf("                       *Nome Invalido");
            }
            if(!checkEndereco(fun->endereco)){
                printf("                       *Endereco Invalido");
            }
            if(!checkData(fun->anoNasc, fun->mesNasc, fun->diaNasc)){
                printf("                       *Data Invalida.\n");
            }
            if(!checkCPF(fun->cpf)){
                printf("                       *CPF Invalido.\n");
            }
            if(!checkEmail(fun->email)){
                printf("                       *Email Invalido.\n");
            }
            if(!checkCargo(fun->cargo)){
                printf("                       *Cargo Invalido");
            }
            do{
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while (!checkDigit(esc));

        } else{
            file = fopen("funcionarios.dat", "ab");
            if (file){
                fwrite(fun, sizeof(Funcionario), 1, file);
                fclose(file);
            } else{
                printf("Ocorreu um erro com a criação do arquivo!");
                exit(1);
            }
            free(fun);

            do{
                printf("                     Funcionario adicionado.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Cadastrar outro funcionario                 |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while (!checkDigit(esc));
        }
    } while(esc != '0');
    telaFuncionario();
}

void telaPesquisarFuncionario(void){
    FILE* file;
    Funcionario* fun;
    char cpf[12];
    char esc;
    char situacao[20];
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                 SIG-GAMES | Pesquisar funcionario                 |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: ");
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
            file = fopen("funcionarios.dat", "rb");
            if (file == NULL){
                printf("Ocorreu um erro ao ler o arquivo!");
                exit(1);
            }
            while(!feof(file)){
                fread(fun, sizeof(Funcionario), 1, file);
                if((strcmp(fun->cpf, cpf) == 0) && (fun->status != 'x')){
                    printf("Nome: %s\n", fun->nome);
                    printf("Cargo: %s\n", fun->cargo);
                    printf("CPF: %s\n", fun->cpf);
                    printf("Data de nascimento: %d/%d/%d\n", fun->diaNasc, fun->mesNasc, fun->anoNasc);
                    printf("Endereco: %s\n", fun->endereco);
                    printf("Email: %s\n", fun->email);
                    if(fun->status == 'c'){
                        strcpy(situacao, "Cadastrado");
                    } else if (fun->status == 'x'){
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
                printf("  |                  1. Pesquisar outro funcionario                   |  \n");
                printf("  |                  0. Voltar                                        |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
    
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
                printf("  |                    1. Editar outro funcionario                    |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
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
                printf("                     Funcionario removido.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                   1. Remover outro funcionario                    |  \n");
                printf("  |                   0. Voltar                                       |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while(!checkDigit(esc));
        }
    }while(esc != '0');
    telaFuncionario();
}
