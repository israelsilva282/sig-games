#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

void telaJogo(void){
    char esc;

    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      SIG-GAMES | Menu Jogo                        |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                        1. Adicionar Jogo                          |  \n");
    printf("  |                        2. Pesquisar jogo                          |  \n");
    printf("  |                        3. Listar jogo                             |  \n");
    printf("  |                        4. Editar jogo                             |  \n");
    printf("  |                        5. Remover jogo                            |  \n");
    printf("  |                        0. Voltar                                  |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                     Digite a opcao desejada: ");
    scanf("%c", &esc);
    getchar();
    
    switch(esc){
        case '1':
            telaAdicionarJogo();
            break;
        case '2':
            telaPesquisarJogo();
            break;
        case '3':
            telaListarJogos();
            break;
        case '4':
            telaEditarJogo();
            break;
        case '5':
            telaRemoverJogo();
            break;
        case '0':
            
            break;
    }
}

void telaAdicionarJogo(void){
    char nome[100];
    char dataLanc[11];
    char resumo[2048];
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Adicionar jogo                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
        getchar();
        printf("                     Data de lancamento (DD/MM/AA): ");
        scanf("%[0-9/]", dataLanc);
        getchar();
        printf("                     Resumo: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâàêôãõ0-9./-]", resumo);
        getchar();
        printf("                     ID: ");
        scanf("%d", &id);
        getchar();
        printf("                     Jogo adicionado.\n");

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     1. Adicionar outro jogo                       |  \n");
        printf("  |                     0. Voltar                                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaJogo();
}

void telaPesquisarJogo(void){
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Pesquisar jogo                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID/Nome do jogo: ");
        scanf("%d", &id);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     1. Pesquisar outro jogo                       |  \n");
        printf("  |                     0. Voltar                                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    }while (esc != '0');
    telaJogo();
}

void telaListarJogos(void){
    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      SIG-GAMES | Listar jogos                     |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                         1. jogo1");
    printf("                         2. jogo2");
    printf("                         3. jogo3");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                     Pressione enter para sair...                  |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    getchar();
}

void telaEditarJogo(void){
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      SIG-GAMES | Editar jogo                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID/Nome do jogo: ");
        scanf("%d", &id);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                        1. Editar outro jogo                       |  \n");
        printf("  |                        0. Voltar                                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    }while (esc != '0');
    telaJogo();
}

void telaRemoverJogo(void){
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      SIG-GAMES | Remover jogo                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID/Nome do jogo: ");
        scanf("%d", &id);
        getchar();
        printf("                     Jogo removido.");

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                       1. Remover outro jogo                       |  \n");
        printf("  |                       0 Voltar                                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaJogo();
}
