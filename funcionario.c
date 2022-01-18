#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "validacao.h"

typedef struct funcionario Funcionario;

struct funcionario{
    char *nome, *cargo, *email, *endereco;
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char cpf[12];
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
    char linha[256];
    int tam;
    char esc;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar funcionario              |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        fun->nome = (char *) malloc(tam+1);
        strcpy(fun->nome, linha);
        getchar();
        printf("                     Cargo: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        fun->cargo = (char *) malloc(tam+1);
        strcpy(fun->cargo, linha);
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
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        fun->endereco = (char *) malloc(tam+1);
        strcpy(fun->endereco, linha);
        getchar();
        printf("                     Email: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        fun->email = (char *) malloc(tam+1);
        strcpy(fun->email, linha);
        getchar();
        printf("                     CPF (Apenas numeros): ");
        scanf("%[0-9]", fun->cpf);
        getchar();

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
                free(fun->nome);
                free(fun->cargo);
                free(fun->email);
                free(fun->endereco);
            
            } while (!checkDigit(esc));
        } else{
            file = fopen("funcionarios.txt", "at");
            if (file){
                fprintf(file, "%s\n", fun->cpf);
                fprintf(file, "%s\n", fun->nome);
                fprintf(file, "%s\n", fun->cargo);
                fprintf(file, "%s\n", fun->email);
                fprintf(file, "%s\n", fun->endereco);
                fprintf(file, "%d\n", fun->diaNasc);
                fprintf(file, "%d\n", fun->mesNasc);
                fprintf(file, "%d\n", fun->anoNasc); 
                fclose(file);
            } else{
                printf("Ocorreu um erro com a criação do arquivo!");
                exit(1);
            }
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
            free(fun->nome);
            free(fun->cargo);
            free(fun->email);
            free(fun->endereco);
        }
    } while(esc != '0');
    telaFuncionario();
}

void telaPesquisarFuncionario(void){
    FILE* file;
    char linha[255];
    int achou;
    char cpf[12];
    char esc;

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
            file = fopen("funcionarios.txt", "rt");
            if (file == NULL){
                printf("Ocorreu um erro ao ler o arquivo!");
                exit(1);
            }
            achou = 0;
            while(fscanf(file, "%[^\n]", linha) == 1 && achou != 1){
                if (strcmp(cpf, linha) == 0){
                    achou = 1;
                    for(int i = 0; i <= 8; i++){
                        printf("%s\n", linha);
                        fgets(linha, 255, file);
                        
                    }
                }
                fgetc(file);
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
