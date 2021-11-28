#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"


void telaCliente(void){
    char esc;

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
    char nome[100];
    char dataNasc[11];
    char email[100];
    char cpf[12];
    char endereco[100];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar Cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
        getchar();
        printf("                     Data de nascimento (DD/MM/AA): ");
        scanf("%[0-9/]", dataNasc);
        getchar();
        printf("                     Endereco: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâêôãõ0-9./-]", endereco);
        getchar();
        printf("                     Email: ");
        scanf("%[A-Za-z@._]", email);
        getchar();
        printf("                     CPF (Apenas Numeros): ");
        scanf("%[0-9.-]", cpf);
        getchar();
        printf("                     Cliente cadastrado.");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    1. Cadastrar outro cliente                     |  \n");
        printf("  |                    0. Voltar                                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     1. Pesquisar outro cliente                    |  \n");
        printf("  |                     0. Voltar                                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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
        
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      1. Editar outro cliente                      |  \n");
        printf("  |                      0. Voltar                                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                       1. Remover outro cliente                    |  \n");
        printf("  |                       0. Voltar                                   |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaCliente();
}
